
// test4View.cpp : Ctest4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// Ctest4View 构造/析构

Ctest4View::Ctest4View()
{
	// TODO: 在此处添加构造代码
	set = true;
}

Ctest4View::~Ctest4View()
{
}

BOOL Ctest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4View 绘制

void Ctest4View::OnDraw(CDC* pDC)
{
	Ctest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//第三题
	/*if (set)
	{
		SetTimer(1,rand() % 400 + 100, NULL);
		set = false;

	}
	pDC->Ellipse(pDoc->m_crlRect);*/


	//第二题
	//pDC->Rectangle(pDoc->m_crlRect);
}


// Ctest4View 诊断

#ifdef _DEBUG
void Ctest4View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4Doc* Ctest4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4Doc)));
	return (Ctest4Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4View 消息处理程序


void Ctest4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	Ctest4Doc* pDoc = GetDocument();
	pDoc->x1 = point.x;
	pDoc->m = 1;
	//第二题
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	Ctest4Doc* pDoc = GetDocument();
	pDoc->x2 = point.x;
	pDoc->m = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Ctest4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//第一题
	Ctest4Doc* pDoc = GetDocument();
	CString s1;
	CString s2;
	CClientDC dc(this);
	if (pDoc->x2 > pDoc->x1)
	{
		s1.Format(_T("横向移动像素:%d "), pDoc->x2 - pDoc->x1);
		dc.TextOut(200, 20, s1);
	}
	if (pDoc->x2 <= pDoc->x1)
	{
		s1.Format(_T("横向移动像素:%d "), pDoc->x1 - pDoc->x2);
		dc.TextOut(200, 20, s1);
	}
	if (pDoc->m)
	{
		pDoc->count++;
	}
	s2.Format(_T("移动了%d次"),pDoc->count);
	dc.TextOut(200, 50, s2);
	CView::OnMouseMove(nFlags, point);
}


void Ctest4View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//第二题
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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
