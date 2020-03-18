
// test4View.cpp : Ctest4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "test4.h"
#endif

#include "test4Doc.h"
#include "test4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4View

IMPLEMENT_DYNCREATE(Ctest4View, CView)

BEGIN_MESSAGE_MAP(Ctest4View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctest4View ����/����

Ctest4View::Ctest4View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
}

Ctest4View::~Ctest4View()
{
}

BOOL Ctest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctest4View ����

void Ctest4View::OnDraw(CDC* pDC)
{
	Ctest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//������
	/*if (set)
	{
		SetTimer(1,rand() % 400 + 100, NULL);
		set = false;

	}
	pDC->Ellipse(pDoc->m_crlRect);*/


	//�ڶ���
	//pDC->Rectangle(pDoc->m_crlRect);
}


// Ctest4View ���

#ifdef _DEBUG
void Ctest4View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4Doc* Ctest4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4Doc)));
	return (Ctest4Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4View ��Ϣ�������


void Ctest4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();
	Ctest4Doc* pDoc = GetDocument();
	pDoc->x1 = point.x;
	pDoc->m = 1;
	//�ڶ���
	/*CClientDC dc(this);
	Ctest4Doc* pDoc = GetDocument();
	pDoc->m_crlRect.left = 530;
	pDoc->m_crlRect.top = 30;
	pDoc->m_crlRect.right = 580;
	pDoc->m_crlRect.bottom = 80;
	InvalidateRect(NULL,TRUE);
	CView::OnLButtonDown(nFlags, point);*/
}


void Ctest4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ReleaseCapture();
	Ctest4Doc* pDoc = GetDocument();
	pDoc->x2 = point.x;
	pDoc->m = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Ctest4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//��һ��
	Ctest4Doc* pDoc = GetDocument();
	CString s1;
	CString s2;
	CClientDC dc(this);
	if (pDoc->x2 > pDoc->x1)
	{
		s1.Format(_T("�����ƶ�����:%d "), pDoc->x2 - pDoc->x1);
		dc.TextOut(200, 20, s1);
	}
	if (pDoc->x2 <= pDoc->x1)
	{
		s1.Format(_T("�����ƶ�����:%d "), pDoc->x1 - pDoc->x2);
		dc.TextOut(200, 20, s1);
	}
	if (pDoc->m)
	{
		pDoc->count++;
	}
	s2.Format(_T("�ƶ���%d��"),pDoc->count);
	dc.TextOut(200, 50, s2);
	CView::OnMouseMove(nFlags, point);
}


void Ctest4View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�ڶ���
	/*Ctest4Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_UP:
		if (pDoc->m_crlRect.top>0)
		{
			pDoc->m_crlRect.top -= 5;
			pDoc->m_crlRect.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom <= (clientRec.bottom - clientRec.top))
		{
			pDoc->m_crlRect.top += 5;
			pDoc->m_crlRect.bottom += 5;
		}break;
	case VK_LEFT:
		if (pDoc->m_crlRect.left>0)
		{
			pDoc->m_crlRect.right -= 5;
			pDoc->m_crlRect.left -= 5;
		}break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right<=(clientRec.right- clientRec.left))
		{
			pDoc->m_crlRect.right+=5;
			pDoc->m_crlRect.left+=5; 
		}break;
	case VK_HOME:
		if (pDoc->m_crlRect.left > 0 && pDoc->m_crlRect.top > 0)
		{
			pDoc->m_crlRect.top -=5;
			pDoc->m_crlRect.left -= 5;
		}break;
	case VK_END:
		if (pDoc->m_crlRect.right <= (clientRec.right - clientRec.left) && pDoc->m_crlRect.bottom <= (clientRec.bottom - clientRec.top))
		{
			pDoc->m_crlRect.right += 5;
			pDoc->m_crlRect.bottom += 5;
		}break;

	}InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);*/
}


void Ctest4View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	/*Ctest4Doc* pDoc = GetDocument();
	CRect cr;
	this->GetClientRect(&cr);
	int i = nIDEvent;
	if (pDoc->b==1&&pDoc->m_crlRect.bottom<=cr.bottom)
	{
		pDoc->m_crlRect.top += 30;
		pDoc->m_crlRect.bottom += 30;
		Invalidate();
		
	}
	else pDoc->b = 0;
	if (pDoc->b == 0&& pDoc->m_crlRect.top>0)
	{
		pDoc->m_crlRect.top -= 30;
		pDoc->m_crlRect.bottom -= 30;
		Invalidate();
	}
	
	
	CView::OnTimer(nIDEvent);*/
}
