
// text1View.cpp : Ctext1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text1.h"
#endif

#include "text1Doc.h"
#include "text1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext1View

IMPLEMENT_DYNCREATE(Ctext1View, CView)

BEGIN_MESSAGE_MAP(Ctext1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext1View ����/����

Ctext1View::Ctext1View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext1View::~Ctext1View()
{
}

BOOL Ctext1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext1View ����

void Ctext1View::OnDraw(CDC* pDC)
{
	Ctext1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	CString s = _T("����***");
	int A = 1;
	CString a;
	a.Format(_T("%d"), A);
		pDC->TextOutW(200, 200, s);
		pDC->TextOutW(300, 200, a);

   //int b = pDoc->A;
   //CString a;
   //a.Format(_T("%d"), b);
   //pDC->TextOutW(200, 200, pDoc->s);
   //pDC->TextOutW(300, 200, a);

}


// Ctext1View ���

#ifdef _DEBUG
void Ctext1View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext1Doc* Ctext1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext1Doc)));
	return (Ctext1Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext1View ��Ϣ�������


void Ctext1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Ctext1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	pDoc->count += 1;
	CString s;
	CClientDC dc(this);
	s.Format(_T("%d"),pDoc->count);
	dc.TextOutW(400, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
