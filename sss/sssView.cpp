
// sssView.cpp : implementation of the CsssView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "sss.h"
#endif

#include "sssDoc.h"
#include "sssView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsssView

IMPLEMENT_DYNCREATE(CsssView, CView)

BEGIN_MESSAGE_MAP(CsssView, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CsssView construction/destruction

CsssView::CsssView() noexcept
{
	startpt = -1;
	endpt = -1;

}

CsssView::~CsssView()
{
}

BOOL CsssView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsssView drawing

void CsssView::OnDraw(CDC* /*pDC*/)
{
	CsssDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsssView diagnostics

#ifdef _DEBUG
void CsssView::AssertValid() const
{
	CView::AssertValid();
}

void CsssView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsssDoc* CsssView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsssDoc)));
	return (CsssDoc*)m_pDocument;
}
#endif //_DEBUG


// CsssView message handlers


void CsssView::OnLButtonUp(UINT nFlags, CPoint point)
{
	startpt = -1;

	CView::OnLButtonUp(nFlags, point);
}


void CsssView::OnLButtonDown(UINT nFlags, CPoint point)
{
	startpt.x = point.x;

	startpt.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


//void CsssView::OnMove(int x, int y)
//{
//	CView::OnMove(x, y);
//
//	// TODO: Add your message handler code here
//}


void CsssView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	endpt.x = point.x;

	endpt.y = point.y;

	if (startpt.x != -1)

	{

		dc.MoveTo(startpt.x, startpt.y);

		dc.LineTo(endpt.x, endpt.y);

		startpt.x = endpt.x;

		startpt.y = endpt.y;

	}

	CView::OnMouseMove(nFlags, point);
}
