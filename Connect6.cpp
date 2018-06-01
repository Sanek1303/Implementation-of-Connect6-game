// Connect6.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Connect6.h"
#include <windowsx.h>
#include "Vars.h"
int mark = 0;
bool step;
int left1;
int top1;


vector <int> steps_i;
vector <int> steps_j;
void TSS(int field[19][19], int copy_field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j, vector <int> *i_first, vector <int> *j_first, vector <int> *i_second, vector <int> *j_second)
{
	copy(field, copy_field);
	/*if (black_threats(field) > 0)
	{
		make_six(field, current_step1_i, current_step1_j, current_step2_i, current_step2_j);
	}*/
	if (white_threats(field) > 0 && black_threats(field) == 0)
	{
		best_move_v2(field, copy_field, 2, current_step1_i, current_step1_j, current_step2_i, current_step2_j);
	}
	else {
		if (i_first->size() == 0)
		{
			if (threat_space_search(copy_field, 0, i_first, j_first, i_second, j_second) == true)
			{
				mark++;
			}
			else if (threat_space_search(copy_field, 0, i_first, j_first, i_second, j_second) == false)
			{
				best_move_v2(field, copy_field, 2, current_step1_i, current_step1_j, current_step2_i, current_step2_j);
			}
		}
		/*if (i_first->size() > 0)
		{
		/*field[(*i_first)[i_first->size() - *mark]][(*j_first)[j_first->size() - *mark]] = 1;
		field[(*i_second)[i_second->size() - *mark]][(*j_second)[j_second->size() - *mark]] = 1;
		*mark++;

		}		*/
	}
}
#define MAX_LOADSTRING 100






int alg = 1;
void is_empty(int board[19][19]);

GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;
Status st = GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

												// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CONNECT6, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONNECT6));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	HBITMAP hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	//wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(255, 175, 0)));
	// window color
	wcex.hbrBackground = CreatePatternBrush(hBitmap);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CONNECT6);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL GetGameBoardRect(HWND hWnd, RECT* pRect)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;

		pRect->left = (width - 20 * CELL_SIZE) / 2;
		pRect->top = (height - 20 * CELL_SIZE) / 2;
		pRect->right = pRect->left + 20 * CELL_SIZE;
		pRect->bottom = pRect->top + 20 * CELL_SIZE;	
		return TRUE;
	}
	


	SetRectEmpty(pRect);
	return FALSE;
}
BOOL GetCellRect(HWND hWnd, RECT *pRect, int row__, int col__)
{
	RECT rcBoard;
	SetRectEmpty(pRect);
	if (col__ < 0 || row__ > 18 || row__ < 0 || col__ > 18)
	{
		return FALSE;
	}
	if (GetGameBoardRect(hWnd, &rcBoard))
	{
		//Row
		//Column
		pRect->left = rcBoard.left + col__ * CELL_SIZE + CELL_SIZE / 2;
		pRect->top = rcBoard.top + row__ * CELL_SIZE + CELL_SIZE / 2;

		pRect->right = CELL_SIZE + pRect->left;
		pRect->bottom = pRect->top + CELL_SIZE;
		x1 = pRect->left;
		y4 = pRect->top;
		x2 = pRect->right;
		y2 = pRect->bottom;
		return TRUE;
	}
	return FALSE;
}

int GetCellNumberFromPoint(HWND hwnd, int x, int y)
{
	RECT rc;
	POINT pt = { x,y };
	if (GetGameBoardRect(hwnd, &rc))
	{
		if (PtInRect(&rc, pt))
		{
			x = pt.x - rc.left;
			y = pt.y - rc.top;
			int col = (x / (CELL_SIZE / 2) - 1) / 2;
			int row = (y / (CELL_SIZE / 2) - 1) / 2;
			col_ = col;
			row_ = row;
			return row;
		}
	}
	return -1;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//






LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	switch (message)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hWnd, WM_SETICON, 1, (LPARAM)hIcon1);
	}
	break;
	case WM_CREATE:
	{
	int l, t, w, h;
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
	l = rc.left + 30;
	t = rc.top + 25;	
	}

	HWND hwndButton = CreateWindow(
	L"BUTTON",  // Predefined class; Unicode assumed
	L"Undo",      // Button text
	WS_TABSTOP | WS_VISIBLE | WS_CHILD | BN_CLICKED,  // Styles
	l,
	t,
	90,
	36,
	hWnd,     // Parent window
	(HMENU) ID_BUTTON1,       // No menu.
	(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	NULL);    // Pointer not needed.
	UpdateWindow(hWnd);




	HWND hwndButton1 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed
		L"New Game",      // Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BN_CLICKED,  // Styles
		l,
		t + 61,
		90,
		36,
		hWnd,     // Parent window
		(HMENU)ID_BUTTON2,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);    // Pointer not needed.
	UpdateWindow(hWnd);

	HWND hwndButton2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed
		L"Level 1",      // Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles
		l,
		t + 122,
		90,
		36,
		hWnd,     // Parent window
		(HMENU)ID_BUTTON3,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);    // Pointer not needed.
	UpdateWindow(hWnd);


	HWND hwndButton3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed
		L"Level 2",      // Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles
		l,
		t + 183,
		90,
		36,
		hWnd,     // Parent window
		(HMENU)ID_BUTTON4,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);    // Pointer not needed.
	UpdateWindow(hWnd);



	HWND hwndButton4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed
		L"Level 3",      // Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles
		l,
		t + 244,
		90,
		36,
		hWnd,     // Parent window
		(HMENU)ID_BUTTON5,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);    // Pointer not needed.
	UpdateWindow(hWnd);
	}
	break;
	
	case WM_COMMAND:
	{
		
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDD_ABOUTBOX:
		{
			MessageBox(hWnd, L"Two players,Black and White, alternately place two stones of their own colour,"
				               " black and white respectively, on empty intersections of a Go-like board, except that Black,"
				               "(the first player) places one stone only for the first move. The one who gets six or more "
				               "stones in a row (horizontally, vertically or diagonally) first wins the game.",L"Rules", MB_OK | MB_ICONINFORMATION);
		}
		break;			
		case ID_BUTTON1:
		{
			if (steps_i.size() > 0)
			{
				if (flag % 3 == 1)
				{
					board[steps_i[steps_i.size() - 1]][steps_j[steps_j.size() - 1]] = 0;
					board[steps_i[steps_i.size() - 2]][steps_j[steps_j.size() - 2]] = 0;
					board[steps_i[steps_i.size() - 3]][steps_j[steps_j.size() - 3]] = 0;
					steps_i.pop_back();
					steps_j.pop_back();
					steps_i.pop_back();
					steps_j.pop_back();
					steps_i.pop_back();
					steps_j.pop_back();
					flag--;
					InvalidateRect(hWnd, NULL, TRUE);
					UpdateWindow(hWnd);
				}
				else if (flag % 3 == 0)
				{
					board[steps_i[steps_i.size() - 1]][steps_j[steps_j.size() - 1]] = 0;
					steps_i.pop_back();
					steps_j.pop_back();
					flag -= 2;
					InvalidateRect(hWnd, NULL, TRUE);
					UpdateWindow(hWnd);
				}
			}
		}
		break;
		case ID_BUTTON2:
		{
			int ret = MessageBoxA(hWnd, "Are you sure you want to start a new game?", "New Game", MB_YESNO| MB_ICONQUESTION);
			
			if (IDYES == ret)
			{
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						board[i][j] = 0;
					}
				}
				flag = 0;
				winner = 0;
				mark = 0;
				i_first.clear();
				j_first.clear();
				i_second.clear();
				j_second.clear();
				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				steps_i.clear();
				steps_j.clear();

			}
			else if (ret == IDNO)
			{

			}
		}
		break;
		case ID_BUTTON3:
		{
			alg = 1;
		}
		break;
		case ID_BUTTON4:
		{
			alg = 2;
		}
		break;
		case ID_BUTTON5:
		{
			alg = 3;
		}
		break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_LBUTTONDOWN:
	{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		int index = GetCellNumberFromPoint(hWnd, xPos, yPos);
		HDC hdc = GetDC(hWnd);
		Pen blackPen(Color(250, 0, 0, 0));
		SolidBrush whiteBrush(Color(255, 230, 230, 230));
		SolidBrush blackBrush(Color(255, 50, 50, 50));
		Graphics el(hdc);
		
		if (NULL != hdc)
		{
			//WCHAR temp[100];
			//wsprintf(temp, L"Index = %d", end_game());
			//TextOut(hdc, xPos, yPos, temp, lstrlen(temp));

			if (index != -1)
			{
				RECT rcCell;


				if (GetCellRect(hWnd,&rcCell,row_,col_))
				{
					HPEN Pen1, Pen2;
					//Pen1 = CreatePen(PS_SOLID, 1, RGB(230, 230, 230));
					//Pen2 = CreatePen(PS_SOLID, 1, RGB(50, 50, 50));
						
					
					if ((flag % 3 == 1)&& (board[row_][col_] == 0) && (end_game(hdc,board) == 0))
					{
						board[row_][col_] = 2;
						steps_i.push_back(row_);
						steps_j.push_back(col_);
						last_i1 = row_;
						last_j1 = col_;
						//HBRUSH hBrush;
						end_game(hdc,board);
						//hBrush = CreateSolidBrush(RGB(230, 230, 230));
						//SelectObject(hdc, hBrush);
						//SelectObject(hdc, Pen1);
						winner = end_game(hdc,board);
						
						//Ellipse(hdc, x1 + 3, y4 + 3, x2 - 3, y2 - 3);
						//if (flag % 4 == 2)
						//{
						//	make_six(board);
						//}
						RectF ellipseRect1(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
						//el.SetSmoothingMode(SmoothingModeHighSpeed);
						SmoothingMode mode1 = el.GetSmoothingMode();
						el.SetSmoothingMode(SmoothingModeHighQuality);
						el.DrawEllipse(&blackPen, ellipseRect1);
						el.FillEllipse(&whiteBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
						

						flag+=2;						
					}
					else if ((flag % 3 == 0) && (board[row_][col_] == 0) && (end_game(hdc,board) == 0))
					{
						
						board[row_][col_] = 2;
						steps_i.push_back(row_);
						steps_j.push_back(col_);
						last_i2 = row_;
						last_j2 = col_;
						HBRUSH hBrush;
						end_game(hdc,board);
						
						RectF ellipseRect2(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
						//el.SetSmoothingMode(SmoothingModeHighSpeed);
						SmoothingMode mode2 = el.GetSmoothingMode();
						el.SetSmoothingMode(SmoothingModeHighQuality);
						el.DrawEllipse(&blackPen, ellipseRect2);
						el.FillEllipse(&whiteBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
						if (end_game(hdc,board) == 0)
						{
							//best_move_v2(board, copy_board, 2,&current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j);
										
								//attack_2(board, copy_board, &current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j);
							//step = false;
							if (alg == 3)
							{
								if (black_threats(board) > 0)
								{
									make_six(board, &current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j);
								}
								else
								{
									if (mark == 0)
									{
										TSS(board, copy_board, &current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j, &i_first, &j_first, &i_second, &j_second);
										///step = true;
									}
									if ((mark > 0) && (i_first.size() - mark >= 0) && (black_threats(board) == 0))
									{
										current_step1_i = i_first[i_first.size() - mark];
										current_step1_j = j_first[j_first.size() - mark];
										current_step2_i = i_second[i_second.size() - mark];
										current_step2_j = j_second[j_second.size() - mark];
										board[i_first[i_first.size() - mark]][j_first[j_first.size() - mark]] = 1;
										board[i_second[i_second.size() - mark]][j_second[j_second.size() - mark]] = 1;
										mark++;
									}
								}
							}
							else if (alg == 2)
							{
								attack_2(board, copy_board, &current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j);
							}
							else if (alg == 1)
							{
								attack_1(board, copy_board, &current_step1_i, &current_step1_j, &current_step2_i, &current_step2_j, last_i1, last_i2, last_j1, last_j2);
							}
							steps_i.push_back(current_step1_i);
							steps_j.push_back(current_step1_j);
							steps_i.push_back(current_step2_i);
							steps_j.push_back(current_step2_j);							
							GetCellRect(hWnd, &rcCell, current_step1_i, current_step1_j);
							RectF ellipseRect3(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
							//el.SetSmoothingMode(SmoothingModeHighSpeed);
							SmoothingMode mode3 = el.GetSmoothingMode();
							el.SetSmoothingMode(SmoothingModeHighQuality);
							el.DrawEllipse(&blackPen, ellipseRect3);
							el.FillEllipse(&blackBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
							GetCellRect(hWnd, &rcCell, current_step2_i, current_step2_j);
							RectF ellipseRect4(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
							//el.SetSmoothingMode(SmoothingModeHighSpeed);
							SmoothingMode mode4 = el.GetSmoothingMode();
							el.SetSmoothingMode(SmoothingModeHighQuality);
							el.DrawEllipse(&blackPen, ellipseRect4);
							el.FillEllipse(&blackBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
							
						}
							winner = end_game(hdc, board);				
						flag++;
					}
					if (winner == 1 || winner == 2)
					{
						MessageBox(hWnd, (winner == 1) ? L"First player is winner!" : L"Second player is winner!",
							L"У нас есть победитель!",
							MB_OK | MB_ICONINFORMATION);

					}
					else if (winner == 3)
					{
						MessageBox(hWnd, L"Oh! We have no winners!", L"It is draw!", MB_OK | MB_ICONEXCLAMATION);
					}
					

				}
			}
			ReleaseDC(hWnd, hdc);
		}

	}
	break;
	case WM_GETMINMAXINFO:
	{
		MINMAXINFO * pinmax = (MINMAXINFO*)lParam;
		pinmax->ptMinTrackSize.x = CELL_SIZE * 28;
		pinmax->ptMinTrackSize.y = CELL_SIZE * 23;
	}
	break;
	
	
	case WM_PAINT:
	{
		
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Pen blackPen(Color(250, 0, 0, 0));
		SolidBrush whiteBrush(Color(255, 230, 230, 230));
		SolidBrush blackBrush(Color(255, 50, 50, 50));
		Graphics el(hdc);
		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...
		RECT rc;
		if (flag == 0)
		{
			//board[9][9] = 1;
			//HBRUSH h_Brush;
			//h_Brush = CreateSolidBrush(RGB(50, 50, 50));
			//SelectObject(hdc, h_Brush);
			//winner = end_game(hdc);
			//SelectObject(hdc, Pen2);
			//Ellipse(hdc, x1 + 3, y4 + 3, x2 - 3, y2 - 3);
			board[9][9] = 1;
			

			flag++;
		}
		if (GetGameBoardRect(hWnd, &rc))
		{
			/*RECT rcClient;
			if (GetClientRect(hWnd, &rcClient))
			{
			    
				const WCHAR szPlayer2 []= L"Второй игрок";
				SetBkColor(hdc, RGB(0,100,0));
				SetBkMode(hdc, TRANSPARENT);
				TextOut(hdc, rc.left ,rc.top, szPlayer1, 12);
				SetTextColor(hdc, RGB(240, 250, 240));
			//	TextOut(hdc, rcClient.right - 104, 16, szPlayer2, 12);
				//ShowTurn(hWnd, hdc);
			}*/
			
			HBRUSH hBrush;
			hBrush = CreateSolidBrush(RGB(212, 144, 72));
			//SelectObject(hdc, Pen2);
			SelectObject(hdc, hBrush);
			//FillRect(hdc, &rc, (HBRUSH)GetStockObject(LTGRAY_BRUSH));
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			int a = rc.left;
			int b = rc.top;
			left1 = a;
			top1 = b;

			
			//bottom1++;
		}
	
		// vert lines
		for (int i = CELL_SIZE; i < 20 * CELL_SIZE; i += CELL_SIZE)
		{
			//SelectObject(hdc, Pen2);

			DrawLine(hdc, rc.left + i, rc.top, rc.left + i, rc.bottom);
			DrawLine(hdc, rc.left, rc.top + i, rc.right, rc.top + i);
		}// hor lines
		HBRUSH hBrush;
		hBrush = CreateSolidBrush(RGB(29, 35, 36));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, rc.left + 4 * CELL_SIZE - 5, rc.top + 4 * CELL_SIZE - 5, 5 + rc.left + 4 * CELL_SIZE, 5 + rc.top + 4 * CELL_SIZE);
		Ellipse(hdc, rc.left + 16 * CELL_SIZE - 5, rc.top + 4 * CELL_SIZE - 5, 5 + rc.left + 16 * CELL_SIZE, 5 + rc.top + 4 * CELL_SIZE);
		Ellipse(hdc, rc.left + 10 * CELL_SIZE - 5, rc.top + 4 * CELL_SIZE - 5, 5 + rc.left + 10 * CELL_SIZE, 5 + rc.top + 4 * CELL_SIZE);
		Ellipse(hdc, rc.left + 4 * CELL_SIZE - 5, rc.top + 10 * CELL_SIZE - 5, 5 + rc.left + 4 * CELL_SIZE, 5 + rc.top + 10 * CELL_SIZE);
		Ellipse(hdc, rc.left + 4 * CELL_SIZE - 5, rc.top + 16 * CELL_SIZE - 5, 5 + rc.left + 4 * CELL_SIZE, 5 + rc.top + 16 * CELL_SIZE);
		Ellipse(hdc, rc.left + 16 * CELL_SIZE - 5, rc.top + 10 * CELL_SIZE - 5, 5 + rc.left + 16 * CELL_SIZE, 5 + rc.top + 10 * CELL_SIZE);
		Ellipse(hdc, rc.left + 16 * CELL_SIZE - 5, rc.top + 16 * CELL_SIZE - 5, 5 + rc.left + 16 * CELL_SIZE, 5 + rc.top + 16 * CELL_SIZE);
		Ellipse(hdc, rc.left + 10 * CELL_SIZE - 5, rc.top + 16 * CELL_SIZE - 5, 5 + rc.left + 10 * CELL_SIZE, 5 + rc.top + 16 * CELL_SIZE);
		Ellipse(hdc, rc.left + 10 * CELL_SIZE - 5, rc.top + 10 * CELL_SIZE - 5, 5 + rc.left + 10 * CELL_SIZE, 5 + rc.top + 10 * CELL_SIZE);
		
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (board[i][j] != 0)
				{
					if (board[i][j] == 1)
					{
						
						x1 = rc.left + j * CELL_SIZE + CELL_SIZE / 2;
						y4 = rc.top + i * CELL_SIZE + CELL_SIZE / 2;
						x2 = CELL_SIZE + x1;
						y2 = y4 + CELL_SIZE;
						RectF ellipseRect_x(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
						//el.SetSmoothingMode(SmoothingModeHighSpeed);
						SmoothingMode mode_x = el.GetSmoothingMode();
						el.SetSmoothingMode(SmoothingModeHighQuality);
						el.DrawEllipse(&blackPen, ellipseRect_x);
						el.FillEllipse(&blackBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
					}
					else if (board[i][j] == 2)
					{
						x1 = rc.left + j*CELL_SIZE + CELL_SIZE / 2;
						y4 = rc.top + i*CELL_SIZE + CELL_SIZE / 2;

						x2 = CELL_SIZE + x1;
						y2 = y4 + CELL_SIZE;
						RectF ellipseRect_y(x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);						
						SmoothingMode mode_y = el.GetSmoothingMode();
						el.SetSmoothingMode(SmoothingModeHighQuality);
						el.DrawEllipse(&blackPen, ellipseRect_y);
						el.FillEllipse(&whiteBrush, x1 + 3, y4 + 3, CELL_SIZE - 6, CELL_SIZE - 6);
					}
				}
			}
		}
		
		
		//end_game(hdc);
		EndPaint(hWnd, &ps);
	}
	break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
	
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}
	RECT rc;
	
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//is_empty(board);

	return TRUE;
}

void is_empty(int field[19][19]) {
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board[i][j] = 0;
		}
	}

	//attack(board);
}
//#include <string>
