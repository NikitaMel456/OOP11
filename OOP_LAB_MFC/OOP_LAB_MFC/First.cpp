#include <afxwin.h>
#include <string>
class CMyMainWnd : public CFrameWnd {
public:
	CMyMainWnd() { // конструктор
		Create(NULL, L"OOP lab 12");
		//SetTimer(1, 2000, NULL);
		
	}
	
	char str[50];
	char timStr[50];
	int  i = -1;int  t = 0;
	int x; int y; int point; int n = 10;
	afx_msg void OnLButtonDown(UINT flag, CPoint Loc);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT);
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	afx_msg void OnRButtonDown(UINT, CPoint);
	DECLARE_MESSAGE_MAP()
	
};
BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



class CMyApp : public CWinApp {
public:
	CMyApp() {}; // конструктор
	virtual BOOL InitInstance() {
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
	
};
CMyApp theApp;

void CMyMainWnd::OnRButtonDown(UINT, CPoint)
{}


void CMyMainWnd::OnLButtonDown(UINT, CPoint) 
{
	point = 1;
	SetTimer(1, 1000, NULL);
}
void CMyMainWnd::OnTimer(UINT)
{
	
	
	if (point = 1)
	{
		if (i == 20)
		{
			KillTimer(1);
			i = 0;
			x = 0; y = 0;
		}
		if(i<10)
		{
			CClientDC dc(this);
			dc.TextOutW(x, y, L"");
			x =rand()%990;
			y = rand() % 990;
			dc.TextOutW(x, y, L"TEXT");
			i++;
		}
	}
}

void CMyMainWnd::OnPaint() {
	CPaintDC dc(this);
	CPen mypen;
	switch (t)
	{
	case 1:mypen.CreatePen(PS_SOLID, 10, RGB(255, 0, 0)); dc.SelectObject(mypen); dc.Ellipse(5, 100, 105, 200); break;
	case 2:mypen.CreatePen(PS_SOLID, 20, RGB(172, 189, 16)); dc.SelectObject(mypen); dc.Ellipse(115, 110, 215, 210); break;
	case 3:mypen.CreatePen(PS_SOLID, 9, RGB(150, 102, 44)); dc.SelectObject(mypen); dc.Ellipse(25, 10, 225, 210); break;
	case 4:mypen.CreatePen(PS_SOLID, 20, RGB(77, 22, 160)); dc.SelectObject(mypen); dc.Ellipse(135, 130, 235, 230); break;
	case 5:mypen.CreatePen(PS_SOLID, 15, RGB(13,99, 255)); dc.SelectObject(mypen); dc.Ellipse(45, 140, 95, 190); break;
	case 6:mypen.CreatePen(PS_SOLID, 4, RGB(200, 189, 144)); dc.SelectObject(mypen); dc.Ellipse(155, 150, 160, 155); break;
	}
	
}

void CMyMainWnd::OnKeyDown(UINT ch,UINT,UINT)
{

	switch (ch)
	{
	case '1':t=1; break;
	case '2':t=2; break;
	case '3':t=3; break;
	case '4':t=4; break;
	case '5':t=5; break;
	case '6':t=6; break;
	}
	this->InvalidateRect(0);
}