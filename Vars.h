#pragma once
#include "stdafx.h"
static int board[19][19];
static int copy_board[19][19];
static int current_step1_i = 5, current_step1_j = 5, current_step2_i = 5 , current_step2_j = 5;
static int last_i1, last_i2, last_j2, last_j1;
static int white1, white2;
static int CELL_SIZE = 36;// размер клеток
static int row_,col_,row1,col1,row2,col2;
static int flag = 0;
static int winner;
//static int mark = 0;
static int y = 0;
static int x1, y4, x2, y2;
static vector <int> i_first;//вектора с последовательност€ми ходов с 2 м€ угрозами
static vector <int> j_first;
static vector <int> i_second;
static vector <int> j_second;
struct State //current state of our game
{
	//int board[19][19];//поле игры
	int copy_board[19][19];//поле игры дл€ игры рандомной
	vector <int> i_possible_index;// координаты возможных строк 
	vector <int> j_possible_index;// координаты возможных столбцов
	void make_move(int x, int y, int player)
	{
		copy_board[x][y] = player;
	}
	void print()
	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				cout << copy_board[i][j] << " ";
			}cout << endl;
		}
	}
	void miss_move(int x, int y)
	{
		copy_board[x][y] = 0;
	}
	void possible_moves()
	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (copy_board[i][j] == 3)
				{
					i_possible_index.push_back(i);
					j_possible_index.push_back(j);
					copy_board[i][j] = 0;
				}
			}
		}
	}//собираем возможные ходы  
	void p_moves(int i, int j)
	{
		if ((copy_board[i - 1][j] == 0) && (i - 1 > -1))
		{
			copy_board[i - 1][j] = 3;
		}
		if ((copy_board[i + 1][j] == 0) && (i + 1 < 19))
		{
			copy_board[i + 1][j] = 3;
		}
		if ((copy_board[i][j - 1] == 0) && (j - 1 > -1))
		{
			copy_board[i][j - 1] = 3;
		}
		if ((copy_board[i][j + 1] == 0) && (j + 1 < 19))
		{
			copy_board[i][j + 1] = 3;
		}
		if ((copy_board[i + 1][j + 1] == 0) && (i + 1 < 19) && (j + 1 < 19))
		{
			copy_board[i + 1][j + 1] = 3;
		}
		if ((copy_board[i - 1][j - 1] == 0) && (i - 1 > -1) && (j - 1 > -1))
		{
			copy_board[i - 1][j - 1] = 3;
		}
		if ((copy_board[i + 1][j - 1] == 0) && (i + 1 < 19) && (j - 1 > -1))
		{
			copy_board[i + 1][j - 1] = 3;
		}
		if ((copy_board[i - 1][j + 1] == 0) && (i - 1 > -1) && (j + 1 < 19))
		{
			copy_board[i - 1][j + 1] = 3;
		}

	}//возможные ходы на моЄм поле
	int end_game()
	{
		int x = 0;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (copy_board[i][j] == 0)
				{
					x++;
				}
			}
		}
		if (x == 0)
		{
			return 0;
		}
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (
					(copy_board[i][j] == 1) && (copy_board[i + 1][j] == 1) && (copy_board[i + 2][j] == 1) && (copy_board[i + 3][j] == 1) && (copy_board[i + 4][j] == 1) && (copy_board[i + 5][j] == 1)
					)
				{

					return 10;
				}
				else if (
					(copy_board[i][j] == 1) && (copy_board[i][j + 1] == 1) && (copy_board[i][j + 2] == 1) && (copy_board[i][j + 3] == 1) && (copy_board[i][j + 4] == 1) && (copy_board[i][j + 5] == 1)
					)
				{
					return 10;
				}
				else if (
					(copy_board[i][j] == 1) && (copy_board[i + 1][j + 1] == 1) && (copy_board[i + 2][j + 2] == 1) && (copy_board[i + 3][j + 3] == 1) && (copy_board[i + 4][j + 4] == 1) && (copy_board[i + 5][j + 5] == 1)
					)
				{

					return 10;
				}
				else if (
					(copy_board[i][j] == 1) && (copy_board[i + 1][j - 1] == 1) && (copy_board[i + 2][j - 2] == 1) && (copy_board[i + 3][j - 3] == 1) && (copy_board[i + 4][j - 4] == 1) && (copy_board[i + 5][j - 5] == 1)
					)
				{
					return 10;
				}
				else if (
					(copy_board[i][j] == 2) && (copy_board[i + 1][j] == 2) && (copy_board[i + 2][j] == 2) && (copy_board[i + 3][j] == 2) && (copy_board[i + 4][j] == 2) && (copy_board[i + 5][j] == 2)
					)
				{

					return -10;
				}
				else if (
					(copy_board[i][j] == 2) && (copy_board[i][j + 1] == 2) && (copy_board[i][j + 2] == 2) && (copy_board[i][j + 3] == 2) && (copy_board[i][j + 4] == 2) && (copy_board[i][j + 5] == 2)
					)
				{
					return -10;
				}
				else if (
					(copy_board[i][j] == 2) && (copy_board[i + 1][j + 1] == 2) && (copy_board[i + 2][j + 2] == 2) && (copy_board[i + 3][j + 3] == 2) && (copy_board[i + 4][j + 4] == 2) && (copy_board[i + 5][j + 5] == 2)
					)
				{
					return -10;
				}
				else if (
					(copy_board[i][j] == 2) && (copy_board[i + 1][j - 1] == 2) && (copy_board[i + 2][j - 2] == 2) && (copy_board[i + 3][j - 3] == 2) && (copy_board[i + 4][j - 4] == 2) && (copy_board[i + 5][j - 5] == 2)
					)
				{
					return -10;
				}

			}
		}
		return 1;
	}
};
struct Node1
{
	Node1(State state_, int player_)
	{
		state = state_;
		Wins1 = 0;
		Wins2 = 0;
		Draw = 0;
		Player = player_;
		if (player_ == 1)
		{
			Opponent = 2;
		}
		else if (player_ == 2)
		{
			Opponent = 1;
		}
		Child = nullptr;
		Parent = nullptr;
	}
	double Wins1;// количество посещений узла
	double Wins2;// количество очков в узле 
	int Draw;
	int Player;//игрок который делает ход
	int Opponent; // оппонент
	State state;//состо€не пол€
	Node1* Child;
	Node1* Parent;
};
struct Node {

	Node(State state_, int player_)
	{
		state = state_;
		Wins1 = 0;
		Wins2 = 0;
		Draw = 0;
		Player = player_;
		if (player_ == 1)
		{
			Opponent = 2;
		}
		else if (player_ == 2)
		{
			Opponent = 1;
		}
	}
	double Wins1;// количество посещений узла
	double Wins2;// количество очков в узле 
	int Draw;
	int Player;//игрок который делает ход
	int Opponent; // оппонент
	State state;//состо€не пол€
	vector <Node1*> Children;
};

void copy(int ar1[19][19], int ar2[19][19]);
// поле дл€ игры, основное
int end_game(HDC hdc, int board[19][19]);
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2);//рисует линии на поле
//блок из функций, с помощю которых мы считаем, сколько чЄрный игрок создаЄт угроз на поле (функции анализируют поле но не измен€ют его)
int black_sliding_window_horizontal_offence(int field[19][19]);
int black_sliding_window_vertical_offence(int field[19][19]);
int black_sliding_window_diag_right_offence(int field[19][19]);
int black_sliding_window_diag_left_offence(int field[19][19]);
int black_threats(int field[19][19]);
//если ходит чЄрный и на поле угроза со стороны чЄрных, то он делает ход и выигрывает (функци€ делает ход)
void make_six(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
//окна дл€ проверки угроз со стороны противника, считаем, количество угроз, которое создаЄт белый игрок (функции анализируют поле но не измен€ют его)
int white_sliding_window_horizontal(int field[19][19]);
int white_sliding_window_vertical(int field[19][19]);
int white_sliding_window_diag_right(int field[19][19]);
int white_sliding_window_diag_left(int field[19][19]);
int white_threats(int field[19][19]);
//окно дл€ защиты от угроз противника, у белого угроза, значит мы защищаемс€, при этом чЄрных угроз нет
int ev_func(vector<int> vec, int a);//эвристическа€ оценка дл€ того, чтобы пон€ть, где именно нужно защищатьс€
int def_sliding_window(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);// защитный ход (функци€ делает ход)
//функции, которые быстро вычисл€ют сколько угроз создаЄт один камень на поле
int quick_vert_window(int field[19][19], int y);
int quick_hor_window(int field[19][19], int x);
int quick_diag_left(int field[19][19], int x, int y);
int quick_diag_right(int field[19][19], int x, int y);
int quick_window(int field[19][19], int x, int y);
// возможные ходы при наличии 3х камней в окне размером 6
void all_p_moves3(int field[19][19], int field1[19][19]);

// возможные ходы при наличии 2х камней в окне размером 6 
void all_p_moves2(int field[19][19], int field1[19][19]);

//возможные ходы, если других нет, эвристическа€ функци€ по вычислению результата оценки полухода
void empty_points(int arr[19][19], int i, int j);
void empty_points_v2(int arr[19][19], int i, int j);

void best_move(int field[19][19],int field1[19][19], int i, int last_i1, int last_i2, int last_j2, int last_j1, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
void best_move_v2(int field[19][19], int field1[19][19], int i, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
long long int h_move_evaluation(int field_2d[19][19], int i, int j);
// лучший ход из возможных
void attack_1(int field[19][19], int field1[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j, int last_i1, int last_i2, int last_j2, int last_j1);
void attack_2(int field[19][19], int field1[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);

//Threat space search
void conservative_defence(int field[19][19], int x, int y);
bool threat_space_search(int field[19][19], int depth, vector <int> *i_first, vector <int> *j_first, vector <int> *i_second, vector <int> *j_second);
void all_p_moves3_v2(int field[19][19]);
void all_p_moves2_v2(int field[19][19]);
//void TSS(int field[19][19], int copy_field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j,int* mark ,vector <int> *i_first, vector <int> *j_first, vector <int> *i_second, vector <int> *j_second);