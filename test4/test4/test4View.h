
// test4View.h : Ctest4View 类的接口
//

#pragma once


class Ctest4View : public CView
{
protected: // 仅从序列化创建
	Ctest4View();
	DECLARE_DYNCREATE(Ctest4View)

// 特性
public:
	Ctest4Doc* GetDocument() const;

// 操作
public:
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // test4View.cpp 中的调试版本
inline Ctest4Doc* Ctest4View::GetDocument() const
   { return reinterpret_cast<Ctest4Doc*>(m_pDocument); }
#endif

