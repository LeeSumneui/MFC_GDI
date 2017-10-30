
// 2014111624_이수민View.h : CMy2014111624_이수민View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"
#define ID_MODE_NONE 0
#define ID_MODE_DRAW 1
#define ID_MODE_MOVE 2

class CMy2014111624_이수민View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy2014111624_이수민View();
	DECLARE_DYNCREATE(CMy2014111624_이수민View)

// 특성입니다.
public:
	CMy2014111624_이수민Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy2014111624_이수민View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	bool m_bSelectedPoint;
	int m_nMode;
	bool m_bStart;
	CPoint m_ptOrigin;
	CPoint m_ptPrev;
	COLORREF m_colorPoint;
	COLORREF m_colorPolygon;
	COLORREF m_colorCurve;
	bool m_bVisiblePolygon;
	bool m_bVisibleCurve;
	int m_nCtrlPointNum;
	CPoint m_ptControl[50];
	CPoint m_ptCurve[50];
	void DrawControlPolygon(CDC * pDC, bool bDrawLine);
	CPoint ComputeCurvePoint(int nDegree, CPoint AryCtrlPoint[], float fDelta);
	void CreateCurvePoint(int nDegree, int nPointNum, CPoint ptControl[], CPoint ptCurve[]);
	void DrawBezierCurve(CDC * pDC, bool bLine);
	int m_nResolution;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_nSelectedPointIndex;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawBezier();
	afx_msg void OnViewPolygon();
	afx_msg void OnViewBezier();
	afx_msg void OnCurveRes16();
	afx_msg void OnCurveRes32();
	afx_msg void OnCurveRes4();
	afx_msg void OnCurveRes64();
	afx_msg void OnCurveRes8();
	afx_msg void OnColorBezier();
	afx_msg void OnColorPolygon();
	afx_msg void OnColorPoint();
	afx_msg void OnSelectedPoint();
	afx_msg void OnUpdateViewPolygon(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewBezier(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // 2014111624_이수민View.cpp의 디버그 버전
inline CMy2014111624_이수민Doc* CMy2014111624_이수민View::GetDocument() const
   { return reinterpret_cast<CMy2014111624_이수민Doc*>(m_pDocument); }
#endif

