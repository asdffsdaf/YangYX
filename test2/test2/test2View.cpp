
// test2View.cpp : Ctest2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test2.h"
#endif

#include "test2Doc.h"
#include "test2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2View

IMPLEMENT_DYNCREATE(Ctest2View, CView)

BEGIN_MESSAGE_MAP(Ctest2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ctest2View 构造/析构

Ctest2View::Ctest2View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(200);
}

Ctest2View::~Ctest2View()
{
}

BOOL Ctest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest2View 绘制

void Ctest2View::OnDraw(CDC* pDC)
{
	Ctest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	for(int i=0;i<ca.GetSize();i++)
		pDC->Ellipse(ca.GetAt(i));

	CClientDC dc(this);
	dc.Rectangle(100, 0, 200, 200);
	dc.Rectangle(300, 0, 400, 200);
	dc.Rectangle(600, 0, 700, 200);
	CString s1;
	CString s2;
	CString s3;
	s1.Format(_T("A"));
	s2.Format(_T("B"));
	s3.Format(_T("C"));
	pDC->TextOutW(150, 50, s1);
	pDC->TextOutW(350, 50, s2);
	pDC->TextOutW(650, 50, s3);

}


// Ctest2View 诊断

#ifdef _DEBUG
void Ctest2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest2Doc* Ctest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest2Doc)));
	return (Ctest2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest2View 消息处理程序


void Ctest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//第一题
	/*CRect cr;
	int r;
	this->GetClientRect(&cr);
	if (cr.Height() > cr.Width())
		r = cr.Width()/2;
	else r = cr.Height()/2;
	int a = cr.Width() / 2;
	int b = cr.Height() / 2;
	CClientDC dc(this);
	dc.Ellipse(a-r,b-r,a+r,b+r);
	CView::OnLButtonDown(nFlags, point);
	*/
	//第二题
	/*int a = rand() % 50 ;
	int b = 50+rand() % 50;
	CClientDC dc(this);
	CRect cr(point.x - b, point.y - a, point.x + b, point.y + a);
	ca.Add(cr);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);*/

	//第三题

	/*CString s;
	s.Format(_T ("左键正在被按下"));
	CClientDC dc(this);
	if (nFlags == 1)
		dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
	*/

	//第四题
	/*CClientDC dc(this);
	Ctest2Doc* pDoc = GetDocument();
	int a = pDoc->A;
	int b = pDoc->B;
	int c = a + b;
	CString s;
	s.Format(_T("A+B=%d"), c);
	if (nFlags == 1)
		dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);*/



	//第五题
	/*CClientDC dc(this);
	Ctest2Doc* pDoc = GetDocument();
	CString m;
	m.Format(_T("点击无效"));
	if (point.x > 100 && point.x < 200 && point.y < 200) {
		CString a1;
		a1.Format(_T("%d"),pDoc->a);
		dc.TextOutW(150, 170, a1);
	}
	else if (point.x > 300 && point.x < 400 && point.y < 200) {
		CString b1;
		b1.Format(_T("%d"),pDoc->b);
		dc.TextOutW(350, 170, b1);
	}
	else if (point.x > 600 && point.x < 700 && point.y < 200) {
		CString c1;
		c1.Format(_T("%d"),pDoc->c);
		dc.TextOutW(650, 170, c1);
	}
	else dc.TextOutW(500, 500, m);
	CView::OnLButtonDown(nFlags, point);*/
}




/*void Ctest2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s1;
	s1.Format(_T("左键正在被抬起"));
	CClientDC dc(this);
	if (nFlags == 1)
		dc.TextOutW(500, 300, s1);
	CView::OnLButtonUp(nFlags, point);
}
*/