
// 2014111624_이수민View.cpp : CMy2014111624_이수민View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2014111624_이수민.h"
#endif

#include "2014111624_이수민Doc.h"
#include "2014111624_이수민View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2014111624_이수민View

IMPLEMENT_DYNCREATE(CMy2014111624_이수민View, CView)

BEGIN_MESSAGE_MAP(CMy2014111624_이수민View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2014111624_이수민View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_BEZIER, &CMy2014111624_이수민View::OnDrawBezier)
	ON_COMMAND(ID_VIEW_POLYGON, &CMy2014111624_이수민View::OnViewPolygon)
	ON_COMMAND(ID_VIEW_BEZIER, &CMy2014111624_이수민View::OnViewBezier)
	ON_COMMAND(ID_CURVE_RES_16, &CMy2014111624_이수민View::OnCurveRes16)
	ON_COMMAND(ID_CURVE_RES_32, &CMy2014111624_이수민View::OnCurveRes32)
	ON_COMMAND(ID_CURVE_RES_4, &CMy2014111624_이수민View::OnCurveRes4)
	ON_COMMAND(ID_CURVE_RES_64, &CMy2014111624_이수민View::OnCurveRes64)
	ON_COMMAND(ID_CURVE_RES_8, &CMy2014111624_이수민View::OnCurveRes8)
	ON_COMMAND(ID_COLOR_BEZIER, &CMy2014111624_이수민View::OnColorBezier)
	ON_COMMAND(ID_COLOR_POLYGON, &CMy2014111624_이수민View::OnColorPolygon)
	ON_COMMAND(ID_COLOR_POINT, &CMy2014111624_이수민View::OnColorPoint)
	ON_COMMAND(ID_SELECTED_POINT, &CMy2014111624_이수민View::OnSelectedPoint)
	ON_UPDATE_COMMAND_UI(ID_VIEW_POLYGON, &CMy2014111624_이수민View::OnUpdateViewPolygon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_BEZIER, &CMy2014111624_이수민View::OnUpdateViewBezier)
END_MESSAGE_MAP()

// CMy2014111624_이수민View 생성/소멸

CMy2014111624_이수민View::CMy2014111624_이수민View()
	: m_bSelectedPoint(false)
	, m_nMode(0)
	, m_bStart(false)
	, m_ptOrigin(0)
	, m_ptPrev(0)
	, m_bVisiblePolygon(false)
	, m_bVisibleCurve(false)
	, m_nCtrlPointNum(0)
	, m_nResolution(0)
	, m_nSelectedPointIndex(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nCtrlPointNum=0;
	m_colorPolygon = RGB(255,0,0);
	m_colorCurve = RGB(0,0,255);
	m_colorPoint = RGB(0,0,0);
	m_bStart = FALSE;
	m_nMode = ID_MODE_NONE;

	m_bVisiblePolygon = TRUE;
	m_bVisibleCurve = TRUE;

	for(int i = 0; i<50; i++)
		m_ptControl[i]=0;

	m_nResolution = 16;
	m_bSelectedPoint = FALSE;

}

CMy2014111624_이수민View::~CMy2014111624_이수민View()
{
}

BOOL CMy2014111624_이수민View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2014111624_이수민View 그리기

void CMy2014111624_이수민View::OnDraw(CDC* pDC)
{
	CMy2014111624_이수민Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	DrawControlPolygon(pDC,m_bVisiblePolygon);
	DrawBezierCurve(pDC,m_bVisibleCurve);
}


// CMy2014111624_이수민View 인쇄


void CMy2014111624_이수민View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2014111624_이수민View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2014111624_이수민View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2014111624_이수민View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy2014111624_이수민View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2014111624_이수민View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2014111624_이수민View 진단

#ifdef _DEBUG
void CMy2014111624_이수민View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2014111624_이수민View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2014111624_이수민Doc* CMy2014111624_이수민View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2014111624_이수민Doc)));
	return (CMy2014111624_이수민Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2014111624_이수민View 메시지 처리기


void CMy2014111624_이수민View::DrawControlPolygon(CDC * pDC, bool bDrawLine)
{
	CRect rectPoint;
	CPen CtrlPointPen, PolygonPen, *OldPen;

	CtrlPointPen.CreatePen(PS_SOLID,3,m_colorPoint);
	PolygonPen.CreatePen(PS_SOLID,1,m_colorPolygon);
	OldPen = pDC->SelectObject(&CtrlPointPen);

	if(bDrawLine)
	{
		for(int i=0; i<m_nCtrlPointNum;i++)
		{
			rectPoint = CRect(m_ptControl[i].x - 4, m_ptControl[i].y -4,
								m_ptControl[i].x + 4, m_ptControl[i].y +4);
			pDC->SelectObject(&CtrlPointPen);
			pDC->Ellipse(&rectPoint);
		}
		pDC->SelectObject(&PolygonPen);
		pDC->Polyline(m_ptControl,m_nCtrlPointNum);
	}
	pDC->SelectObject(OldPen);
	DeleteObject(CtrlPointPen);
	DeleteObject(PolygonPen);
}


CPoint CMy2014111624_이수민View::ComputeCurvePoint(int nDegree, CPoint AryCtrlPoint[], float fDelta)
{
CPoint fAryCtrlPoint[30];

	float fDelta_T;
	fDelta_T = 1.0f-fDelta;

	for(int i=0; i<=nDegree; i++)
		fAryCtrlPoint[i] = AryCtrlPoint[i];
	
	for(int r=1; r<=nDegree; r++)
		for(int i =0; i<= nDegree-r;i++)
		{
			fAryCtrlPoint[i].x = (int)(fDelta_T * (float)fAryCtrlPoint[i].x + fDelta * (float)fAryCtrlPoint[i+1].x);
			fAryCtrlPoint[i].y = (int)(fDelta_T * (float)fAryCtrlPoint[i].y + fDelta * (float)fAryCtrlPoint[i+1].y);
		}

	return fAryCtrlPoint[0];
}


void CMy2014111624_이수민View::CreateCurvePoint(int nDegree ,int nPointNum, CPoint ptControl[], CPoint ptCurve[])
{
	float fDelta, t;

	fDelta = 1.0f/(float)(nPointNum);
	t = 0.0f;
	for(int i =0; i <= nPointNum; i++)
	{
		ptCurve[i] = ComputeCurvePoint(nDegree, ptControl, t);
		t = t + fDelta;
	}
}


void CMy2014111624_이수민View::DrawBezierCurve(CDC * pDC, bool bLine)
{
	CPen CurvePen, *OldPen;
	CurvePen.CreatePen(PS_SOLID,1,m_colorCurve);
	OldPen = pDC->SelectObject(&CurvePen);
	//CClientDC dc(this);

	if(m_nCtrlPointNum>1)
	{
		CreateCurvePoint(m_nCtrlPointNum-1, m_nResolution, m_ptControl, m_ptCurve);
		if(bLine)
		{
			pDC->Polyline(m_ptCurve, m_nResolution + 1);
			// dc.PolyBezier(m_ptControl,m_nCtrlPointNum);
		}	
	}
	
	pDC->SelectObject(OldPen);
	DeleteObject(CurvePen);
}


void CMy2014111624_이수민View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
	if(m_nMode==ID_MODE_DRAW)
	{
		if(m_bStart == FALSE)
		{
			m_nCtrlPointNum = 0;
			for(int i=0; i<50; i++)
				m_ptControl[i] = 0;

			Invalidate();
		}
		CRect rectPoint(point.x - 4, point.y - 4, point.x + 4, point.y + 4);

		CClientDC dc(this);
		CPen NewPen, *OldPen;
		NewPen.CreatePen(PS_SOLID,3,m_colorPoint);
		OldPen = dc.SelectObject(&NewPen);
		dc.Ellipse(&rectPoint);
		dc.SelectObject(OldPen);
		DeleteObject(NewPen);

		m_ptOrigin = m_ptPrev = point;

		m_ptControl[m_nCtrlPointNum++] = point;

		SetCapture();
		RECT rectClient;
		GetClientRect(&rectClient);
		ClientToScreen(&rectClient);

		::ClipCursor(&rectClient);

		m_bStart = TRUE;
	}
	if(m_nMode == ID_MODE_MOVE)
	{
		for(int i = 0; i<m_nCtrlPointNum; i++)
		{
			CRect rectPoint(m_ptControl[i].x - 4, m_ptControl[i].y - 4, m_ptControl[i].x + 4,
				m_ptControl[i].y + 4);

			if(rectPoint.PtInRect(point)) // 현재 마우스포인터가 컨트롤포인트의 사각형 안에 들어가 있는지
			{
				m_bSelectedPoint = TRUE;
				m_nSelectedPointIndex = i;

				SetCapture();
				RECT rectClient;
				GetClientRect(&rectClient);
				ClientToScreen(&rectClient);

				Invalidate();
			}
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy2014111624_이수민View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_nMode == ID_MODE_DRAW)
	{
		if(m_nCtrlPointNum>1)
		{
			if(m_bStart)
			{
				m_ptControl[m_nCtrlPointNum++] = point;
				CRect rectPoint(point.x - 4, point.y -4, point.x + 4, point.y + 4);
				CClientDC dc(this);
				CPen NewPen, *OldPen;
				NewPen.CreatePen(PS_SOLID, 3, m_colorPoint);
				OldPen = dc.SelectObject(&NewPen);
				dc.Ellipse(&rectPoint);
				dc.SelectObject(OldPen);
				DeleteObject(NewPen);

				DrawControlPolygon(&dc,m_bVisiblePolygon);

				DrawBezierCurve(&dc,m_bVisibleCurve);
				// dc.PolyBezier(m_ptControl,m_nCtrlPointNum);

				m_bStart = FALSE;

				::ReleaseCapture();
				::ClipCursor(NULL);
			}
		}
		else
			AfxMessageBox(_T("적어도 2개 이상의 컨트롤 포인트가 있어야 합니다."));
	}
	CView::OnRButtonDown(nFlags, point);
}


void CMy2014111624_이수민View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	if(m_nMode == ID_MODE_DRAW)
	{
		if(m_bStart)
		{
			dc.SetROP2(R2_NOT);
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(m_ptPrev);

			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);

			m_ptPrev = point;
		}
	}
	if(m_nMode == ID_MODE_MOVE)
	{
		CRect rectClient;
		GetClientRect(&rectClient);

		if(m_bSelectedPoint)
		{
			m_ptControl[m_nSelectedPointIndex] = point;
			//Invalidate(); << 이것도 됨
			InvalidateRect(&rectClient,TRUE);
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2014111624_이수민View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	if(m_nMode == ID_MODE_MOVE)
	{
		if(m_bSelectedPoint)
		{
			m_ptControl[m_nSelectedPointIndex]=point;
			dc.SetROP2(R2_COPYPEN);

			DrawControlPolygon(&dc,m_bVisiblePolygon);
			DrawBezierCurve(&dc,m_bVisibleCurve);

			m_bSelectedPoint = FALSE;
			::ReleaseCapture();
			::ClipCursor(NULL);
			Invalidate();
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy2014111624_이수민View::OnDrawBezier()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nCtrlPointNum = 0;
	m_bStart = FALSE;

	for(int i =0; i<50; i++)
		m_ptControl[i] =0;

	m_nMode = ID_MODE_DRAW;
	Invalidate();
}


void CMy2014111624_이수민View::OnViewPolygon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bVisiblePolygon = !m_bVisiblePolygon;
	Invalidate();
}


void CMy2014111624_이수민View::OnViewBezier()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_bVisibleCurve = !m_bVisibleCurve;
	Invalidate();
}


void CMy2014111624_이수민View::OnCurveRes16()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 16;
	Invalidate();
}


void CMy2014111624_이수민View::OnCurveRes32()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다
	m_nResolution = 32;
	Invalidate();
}


void CMy2014111624_이수민View::OnCurveRes4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 4;
	Invalidate();
}


void CMy2014111624_이수민View::OnCurveRes64()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 64;
	Invalidate();
}


void CMy2014111624_이수민View::OnCurveRes8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nResolution = 8;
	Invalidate();
}


void CMy2014111624_이수민View::OnColorBezier()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog colorDlg;
	if(colorDlg.DoModal()==IDOK)
	{
		m_colorCurve = colorDlg.GetColor();
	}
	Invalidate();
}


void CMy2014111624_이수민View::OnColorPolygon()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog colorDlg;
	if(colorDlg.DoModal()==IDOK)
	{
		m_colorPolygon = colorDlg.GetColor();
	}
	Invalidate();
}


void CMy2014111624_이수민View::OnColorPoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog colorDlg;
	if(colorDlg.DoModal()==IDOK)
	{
		m_colorPoint = colorDlg.GetColor();
	}
	Invalidate();
}


void CMy2014111624_이수민View::OnSelectedPoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nMode = ID_MODE_MOVE;
	m_bVisiblePolygon = TRUE;

	Invalidate();
}


void CMy2014111624_이수민View::OnUpdateViewPolygon(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI -> SetCheck(m_bVisiblePolygon);
}


void CMy2014111624_이수민View::OnUpdateViewBezier(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI -> SetCheck(m_bVisibleCurve);
}
