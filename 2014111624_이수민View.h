
// 2014111624_�̼���View.h : CMy2014111624_�̼���View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"
#define ID_MODE_NONE 0
#define ID_MODE_DRAW 1
#define ID_MODE_MOVE 2

class CMy2014111624_�̼���View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2014111624_�̼���View();
	DECLARE_DYNCREATE(CMy2014111624_�̼���View)

// Ư���Դϴ�.
public:
	CMy2014111624_�̼���Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy2014111624_�̼���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // 2014111624_�̼���View.cpp�� ����� ����
inline CMy2014111624_�̼���Doc* CMy2014111624_�̼���View::GetDocument() const
   { return reinterpret_cast<CMy2014111624_�̼���Doc*>(m_pDocument); }
#endif

