// Lab11_API.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "Lab11_API.h"


#define MAX_LOADSTRING 100 //����� �������. ������

// ���������� ����������:
HINSTANCE hInst;								// ������� ��������� 
TCHAR szTitle[MAX_LOADSTRING];					// ����� ������ ��������� 
TCHAR szWindowClass[MAX_LOADSTRING];			// ��� ������ �������� ����



///////////
static int counter = 0;
HWND window_mass[7];
HWND hMain;
wchar_t counterString[256];
static int X = 300, Y = 250;
///////////

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM				MyRegisterClass(HINSTANCE hInstance);// ������������ ����� ����.
BOOL				InitInstance(HINSTANCE, int);//��������� ��������� ���������� � ������� ������� ����.
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);//���������� ������� �-�
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);//������� About ����� ���������� �������� ��� ��������� ���������, ���������� ���� �������.

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,//����������
	_In_opt_ HINSTANCE hPrevInstance,// �������� ��� ������������� � ����������� �������� 
	_In_ LPTSTR    lpCmdLine,//��������� �� ������
	_In_ int       nCmdShow)//�������� ������ ������ ����������� ����.
{//��������� ��������� ������ ������
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);//��� ����������, ������� �� ���� �� ��������������.

									  // TODO: ���������� ��� �����.
	MSG msg;
	HACCEL hAccelTable;

	// ������������� ���������� �����
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//��������� ������ ������ �� ������������ �����, �������� ������ � ����� � ��������� � ����� ������ ������������ ����.
	LoadString(hInstance, IDC_LAB11_API, szWindowClass, MAX_LOADSTRING);
	/*���������� ���������� ������, ����������� ���� �������� �������� � ���� ������ ������.
	��������� ������������� ������������� ������, ������� ����� ���������.
	��������� �� �����, ������� ������ ������.
	���������� ������ ������
	*/
	MyRegisterClass(hInstance);//����������� �������� ������ 

							   // ��������� ������������� ����������:
	if (!InitInstance(hInstance, nCmdShow))//������������ ������������� ���������� � ��������� ���������� ���������� hInstance
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB11_API));
	//��������� �������� ������� ������-�����������
	/*���������� ������, ����������� ���� �������� �������� ����������� ������� ������-�����������.
	��������� �� ���������� ������ � ����� � �����, ������� �������� ��� ����������� ������� ������-�����������.*/

	// ���� ���������� ���������:
	while (GetMessage(&msg, NULL, 0, 0))
	{//��������� ��������� �� ������� ��������� ����������� ������ � �������� ��� � �������� ���������
	 /*��������� �� ��������� MSG, ������� ��������� ���������� �� ������� ��������� ������.
	 ��������� ��������� ��� ������ ����, ������� ����������� ����������� ������
	 */
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{//������������ ������� ��������� ��� ������ ����
		 /*���������� ����, ��������� �������� ������ ���� �������������.
		 ���������� ������� ������-�����������.
		 ��������� �� ��������� MSG, ������� �������� ���������� � ���������,
		 */
			TranslateMessage(&msg);//��������� ��������� ����������� ������ � ���������� ���������
			DispatchMessage(&msg);//������������, ����� ��������� ���������, ����������� �������� GetMessage
		}
	}

	return (int)msg.wParam;
}



//  �������: MyRegisterClass() 
//  ����������: ������������ ����� ����. 
//  �����������: 
//     ��� ������� � �� ������������� ���������� ������ � ������, 
//     ���� �����, ����� ������ ��� 
//     ��� ��������� � ��������� Win32, �� �������� ������� RegisterClassEx'
//     ������� ���� ��������� � Windows 95. ����� ���� ������� ����� ��� ����,
//     ����� ���������� �������� "������������" ������ ������ � ���������� �����
//     � ����. 
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;//�������� ���������� � ������ ����

	wcex.cbSize = sizeof(WNDCLASSEX);//������ ��������� � ������   

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;//���������� ��� ������� ���������.
	wcex.cbClsExtra = 0;//�������������� ������ ��� ������.
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;//��������� ����������, ����������� � ������ �����.
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB11_API));//������ ��� ���� ����������.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);//������������� ��� ������� � ���� ����������.
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW - 2);//����� ����� ��� �������� ����. HBR-���������� �����
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_LAB11_API);//������ ���� ��� ���� ����������.
	wcex.lpszClassName = szWindowClass;//��������� �� ������� �����.
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}//������������ ����� ���� ��� ������������ �������������,��������� �� ��������� WNDCLASSEX. 


 //   �������: InitInstance(HINSTANCE, int) 
 //   ����������: ��������� ��������� ���������� � ������� ������� ����.
 //   �����������:
 //    � ������ ������� ���������� ���������� ����������� � ���������� ����������, � ����� 
 //    ��������� � ��������� �� ����� ������� ���� ���������. 
 //
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

	hMain = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		400, 300, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);// ������� �������������, ������������� ��� �������� ����. 
																 /*LPCTSTR lpClassName,   // ��������� �� ������������������ ��� ������
																 LPCTSTR lpWindowName,  // ��������� �� ��� ����
																 DWORD dwStyle,         // ����� ����
																 int x,                 // �������������� ������� ����
																 int y,                 // ������������ ������� ����
																 int nWidth,            // ������ ����
																 int nHeight,           // ������ ����
																 HWND hWndParent,       // ���������� ������������� ��� ���� ���������
																 HMENU hMenu,           // ���������� ���� ��� ID ��������� ����
																 HANDLE hInstance,      // ���������� ���������� ����������
																 LPVOID lpParam         // ��������� �� ������ �������� ����
																 */

	if (!hMain)
	{
		return FALSE;
	}

	ShowWindow(hMain, nCmdShow);//������������� ��������� ������ ������������� ����, ���������� ����, ��������� ������ ����
	UpdateWindow(hMain);//��������� ���������� ������� ���������� ����

	return TRUE;
}


//  �������: WndProc(HWND, UINT, WPARAM, LPARAM) 
//   ����������:  ������������ ��������� � ������� ����. 
//  WM_COMMAND - ��������� ���� ����������
//  WM_PAINT	- ��������� ������� ����
//  WM_DESTROY	- ������ ��������� � ������ � ���������.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;//�������� ���������� ��� ����������
	HDC hdc;//���������� ��������� ���������� 


	switch (message)
	{

	case WM_COMMAND://� ������ ������������� ����� �� ������ ����
					//wmId    = LOWORD(wParam);//�������� �� 32-�������� �������������� �������� ������� �����.
		wmEvent = HIWORD(wParam);//�������� �� 32-�������� �������������� �������� �������� �����.
	case WM_PAINT://���������� ���� � ���, ��� �p������� ��p�p������� ��� ��� ����� ��� ������� ������������.
		hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY://����������� ����
	{
		if (hWnd == hMain)
		{
			PostQuitMessage(0);//������ ���������� ���� ��������
		}
		else
		{
			DestroyWindow(hWnd);//���������� ����
		}
		break;
	}
	case WM_RBUTTONDOWN:
		SetWindowText(hWnd, _T("������� ����"));//������� ������ ���������
		break;
	case WM_LBUTTONUP:// ���� ��������
	{
		if (counter < 7)
		{
			wsprintfW(counterString, L"%d", counter + 1);//����� ���������� ������� � ���������
			window_mass[counter] = CreateWindow(szWindowClass, counterString, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 200, 200, nullptr, nullptr, hInst, nullptr);//�������� ����
									/*LPCTSTR lpClassName,   // ��������� �� ������������������ ��� ������
									LPCTSTR lpWindowName,  // ��������� �� ��� ����
									DWORD dwStyle,         // ����� ����
									int x,                 // �������������� ������� ����
									int y,                 // ������������ ������� ����
									int nWidth,            // ������ ����
									int nHeight,           // ������ ����
									WND hWndParent,       // ���������� ������������� ��� ���� ���������
									HMENU hMenu,           // ���������� ���� ��� ID ��������� ����
									HANDLE hInstance,      // ���������� ���������� ����������
									LPVOID lpParam         // ��������� �� ������ �������� ����
									*/
			ShowWindow(window_mass[counter], 1);
			counter++;
		}
		else
		{
			MessageBox(hWnd, L"������������ ���������� ����", L"��������", MB_OKCANCEL);//�������� ���������(�����������)
		}
		break;
	}

	case WM_CHAR: //�������� ���� � 7 � 1
	{
		if (counter > 0)
		{
			DestroyWindow(window_mass[counter - 1]);
			counter--;

		}
		break;
	}


	case WM_MOUSEMOVE:
	{
		
		SetWindowPos(hWnd, 0, 500, 100, X, Y, SWP_SHOWWINDOW);
		
	}break;

	case WM_CLOSE://������� ������
		if (IDOK == MessageBox(hWnd, L"������� ����?", L"Windows",

			MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1))
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);//����������� ��������� � ����������� ����
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{//������� About ����� ���������� �������� ��� ��������� ���������, ���������� ���� �������.
 //HWND  Windows-��������� ���� �������;
 //UINT  � ��� ���������;
 //WPARAM, LPARAM  � ��� ���������, �������������� ���������.
 //����� �������� ��� ��� �������� ���������. 
	UNREFERENCED_PARAMETER(lParam);//�������� �������� �������������� ����������� � ������� ����������, �� ������� ��� ������ (�������������� ����������)
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));//���������� ��������� ���������� ����, ��������� ����������� ����, ��������, ������������ ���������� �� �������, ��������� ���������� ����
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
