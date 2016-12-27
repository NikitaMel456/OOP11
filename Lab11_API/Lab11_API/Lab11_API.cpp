// Lab11_API.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab11_API.h"


#define MAX_LOADSTRING 100 //длина заголов. строки

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр 
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка 
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна



///////////
static int counter = 0;
HWND window_mass[7];
HWND hMain;
wchar_t counterString[256];
static int X = 300, Y = 250;
///////////

// Отправить объявление функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);// регистрируем класс окна.
BOOL				InitInstance(HINSTANCE, int);//сохраняет обработку экземпляра и создает главное окно.
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);//вывызвется оконная ф-я
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);//Функция About будет вызываться системой для обработки сообщений, посылаемых окну диалога.

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,//дискриптор
	_In_opt_ HINSTANCE hPrevInstance,// параметр для совместимости с предыдущими версиями 
	_In_ LPTSTR    lpCmdLine,//указатель на строку
	_In_ int       nCmdShow)//Параметр задает способ отображения окна.
{//системная обработка пустых ссылок
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);//для переменных, которые ни разу не использовались.

									  // TODO: разместить код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//загружает ресурс строки из исполняемого файла, копирует строку в буфер и добавляет в конец символ завершающего нуля.
	LoadString(hInstance, IDC_LAB11_API, szWindowClass, MAX_LOADSTRING);
	/*Дескриптор экземпляра модуля, исполняемый файл которого содержит в себе ресурс строки.
	Указывает целочисленный идентификатор строки, которая будет загружена.
	Указатель на буфер, который примет строку.
	Определяет размер буфера
	*/
	MyRegisterClass(hInstance);//регистрация оконного класса 

							   // Выполнить инициальзацию приложения:
	if (!InitInstance(hInstance, nCmdShow))//осуществляет инициализацию приложения и формирует дескриптор приложения hInstance
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB11_API));
	//загружает заданную таблицу клавиш-ускорителей
	/*Дескриптор модуля, исполняемый файл которого содержит загружаемую таблицу клавиш-ускорителей.
	Указатель на символьную строку с нулем в конце, которая содержит имя загружаемой таблицы клавиш-ускорителей.*/

	// Цикл основоного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{//извлекает сообщение из очереди сообщений вызывающего потока и помещает его в заданную структуру
	 /*Указатель на структуру MSG, которая принимает информацию из очереди сообщений потока.
	 извлекает сообщения для любого окна, которое принадлежит вызывающему потоку
	 */
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{//обрабатывает клавиши ускорения для команд меню
		 /*Дескриптор окна, сообщения которого должны быть преобразованы.
		 Дескриптор таблицы клавиш-ускорителей.
		 Указатель на структуру MSG, которая содержит информацию о сообщении,
		 */
			TranslateMessage(&msg);//переводит сообщения виртуальных клавиш в символьные сообщения
			DispatchMessage(&msg);//используется, чтобы доставить сообщение, извлеченное функцией GetMessage
		}
	}

	return (int)msg.wParam;
}



//  ФУНКЦИЯ: MyRegisterClass() 
//  НАЗНАЧЕНИЕ: регистрирует класс окна. 
//  КОММЕНТАРИИ: 
//     Эта функция и ее использование необходимы только в случае, 
//     если нужно, чтобы данный код 
//     был совместим с системами Win32, не имеющими функции RegisterClassEx'
//     которая была добавлена в Windows 95. Вызов этой функции важен для того,
//     чтобы приложение получило "качественные" мелкие значки и установило связь
//     с ними. 
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;//содержит информацию о классе окна

	wcex.cbSize = sizeof(WNDCLASSEX);//размер структуры в байтах   

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;//Определяет имя оконной процедуры.
	wcex.cbClsExtra = 0;//Дополнительные данные для класса.
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;//Заголовок приложения, работающего с данным окном.
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB11_API));//Иконка для окна приложения.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);//Устанавливает тип курсора в окне приложения.
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW - 2);//Задет кисть для закраски окна. HBR-Дескриптор кисти
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_LAB11_API);//Задает меню для окна приложения.
	wcex.lpszClassName = szWindowClass;//Указатель на оконный класс.
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}//регистрирует класс окна для последующего использования,Указатель на структуру WNDCLASSEX. 


 //   ФУНКЦИЯ: InitInstance(HINSTANCE, int) 
 //   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
 //   КОММЕНТАРИИ:
 //    В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также 
 //    создается и выводится на экран главное окно программы. 
 //
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	hMain = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		400, 300, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);// создает перекрывающее, выскакивающее или дочернее окно. 
																 /*LPCTSTR lpClassName,   // указатель на зарегистрированное имя класса
																 LPCTSTR lpWindowName,  // указатель на имя окна
																 DWORD dwStyle,         // стиль окна
																 int x,                 // горизонтальная позиция окна
																 int y,                 // вертикальная позиция окна
																 int nWidth,            // ширина окна
																 int nHeight,           // высота окна
																 HWND hWndParent,       // дескриптор родительского или окна владельца
																 HMENU hMenu,           // дескриптор меню или ID дочернего окна
																 HANDLE hInstance,      // дескриптор экземпляра приложения
																 LPVOID lpParam         // указатель на данные создания окна
																 */

	if (!hMain)
	{
		return FALSE;
	}

	ShowWindow(hMain, nCmdShow);//устанавливает состояние показа определяемого окна, дескриптор окна, состояние показа окна
	UpdateWindow(hMain);//обновляет клиентскую область указанного окна

	return TRUE;
}


//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM) 
//   НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне. 
//  WM_COMMAND - обработка меню приложения
//  WM_PAINT	- Закрасить главное окно
//  WM_DESTROY	- ввести сообщение о выходе и вернуться.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;//содержит информации для приложения
	HDC hdc;//Дескриптор контекста устройства 


	switch (message)
	{

	case WM_COMMAND://о выборе пользователем одной из команд меню
					//wmId    = LOWORD(wParam);//Выделяет из 32-битового целочисленного значения младшее слово.
		wmEvent = HIWORD(wParam);//Выделяет из 32-битового целочисленного значения старшего слова.
	case WM_PAINT://Уведомляет окно о том, что тpебуется пеpеpисовать всю или часть его области пользователя.
		hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY://уничтожение окна
	{
		if (hWnd == hMain)
		{
			PostQuitMessage(0);//полное завершение всех поцессов
		}
		else
		{
			DestroyWindow(hWnd);//разрушение окна
		}
		break;
	}
	case WM_RBUTTONDOWN:
		SetWindowText(hWnd, _T("Главное окно"));//функция замены заголовка
		break;
	case WM_LBUTTONUP:// окна каскадом
	{
		if (counter < 7)
		{
			wsprintfW(counterString, L"%d", counter + 1);//вывод порядковых номеров в заголовке
			window_mass[counter] = CreateWindow(szWindowClass, counterString, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 200, 200, nullptr, nullptr, hInst, nullptr);//создание окон
									/*LPCTSTR lpClassName,   // указатель на зарегистрированное имя класса
									LPCTSTR lpWindowName,  // указатель на имя окна
									DWORD dwStyle,         // стиль окна
									int x,                 // горизонтальная позиция окна
									int y,                 // вертикальная позиция окна
									int nWidth,            // ширина окна
									int nHeight,           // высота окна
									WND hWndParent,       // дескриптор родительского или окна владельца
									HMENU hMenu,           // дескриптор меню или ID дочернего окна
									HANDLE hInstance,      // дескриптор экземпляра приложения
									LPVOID lpParam         // указатель на данные создания окна
									*/
			ShowWindow(window_mass[counter], 1);
			counter++;
		}
		else
		{
			MessageBox(hWnd, L"Максимальное количество окон", L"Внимание", MB_OKCANCEL);//сохдание сообщения(уведомления)
		}
		break;
	}

	case WM_CHAR: //закрытия окон с 7 к 1
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

	case WM_CLOSE://событие выхода
		if (IDOK == MessageBox(hWnd, L"Закрыть окно?", L"Windows",

			MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1))
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);//возвращение сообщения и дескриптера окна
	}
	return 0;
}

// Обработчик сообщения для окна "о программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{//Функция About будет вызываться системой для обработки сообщений, посылаемых окну диалога.
 //HWND  Windows-описатель окна диалога;
 //UINT  — код сообщения;
 //WPARAM, LPARAM  — два параметра, сопровождающих сообщение.
 //Целый знаковый тип для точности указателя. 
	UNREFERENCED_PARAMETER(lParam);//Помогает избежать предупреждений компилятора о наличии параметров, на которые нет ссылок (неиспользуемых параметров)
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));//уничтожает модальное диалоговое окно, Описатель диалогового окна, Значение, возвращаемое приложению из функции, создающей диалоговое окно
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
