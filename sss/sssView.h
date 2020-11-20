
// sssView.h : interface of the CsssView class
//

#pragma once


class CsssView : public CView
{
protected: // create from serialization only
	CsssView() noexcept;
	DECLARE_DYNCREATE(CsssView)

// Attributes
public:
	CsssDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CsssView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sssView.cpp
inline CsssDoc* CsssView::GetDocument() const
   { return reinterpret_cast<CsssDoc*>(m_pDocument); }
#endif

