#pragma once
#include "stdafx.h"
static int board[19][19];
static int copy_board[19][19];
static int current_step1_i = 5, current_step1_j = 5, current_step2_i = 5 , current_step2_j = 5;
static int last_i1, last_i2, last_j2, last_j1;
static int white1, white2;
static int CELL_SIZE = 36;// ������ ������
static int row_,col_,row1,col1,row2,col2;
static int flag = 0;
static int winner;
//static int mark = 0;
static int y = 0;
static int x1, y4, x2, y2;
static vector <int> i_first;//������� � �������������������� ����� � 2 �� ��������
static vector <int> j_first;
static vector <int> i_second;
static vector <int> j_second;
struct State //current state of our game
{
	//int board[19][19];//���� ����
	int copy_board[19][19];//���� ���� ��� ���� ���������
	vector <int> i_possible_index;// ���������� ��������� ����� 
	vector <int> j_possible_index;// ���������� ��������� ��������
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
	}//�������� ��������� ����  
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

	}//��������� ���� �� ��� ����
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
	double Wins1;// ���������� ��������� ����
	double Wins2;// ���������� ����� � ���� 
	int Draw;
	int Player;//����� ������� ������ ���
	int Opponent; // ��������
	State state;//�������� ����
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
	double Wins1;// ���������� ��������� ����
	double Wins2;// ���������� ����� � ���� 
	int Draw;
	int Player;//����� ������� ������ ���
	int Opponent; // ��������
	State state;//�������� ����
	vector <Node1*> Children;
};

void copy(int ar1[19][19], int ar2[19][19]);
// ���� ��� ����, ��������
int end_game(HDC hdc, int board[19][19]);
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2);//������ ����� �� ����
//���� �� �������, � ������ ������� �� �������, ������� ������ ����� ������ ����� �� ���� (������� ����������� ���� �� �� �������� ���)
int black_sliding_window_horizontal_offence(int field[19][19]);
int black_sliding_window_vertical_offence(int field[19][19]);
int black_sliding_window_diag_right_offence(int field[19][19]);
int black_sliding_window_diag_left_offence(int field[19][19]);
int black_threats(int field[19][19]);
//���� ����� ������ � �� ���� ������ �� ������� ������, �� �� ������ ��� � ���������� (������� ������ ���)
void make_six(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
//���� ��� �������� ����� �� ������� ����������, �������, ���������� �����, ������� ������ ����� ����� (������� ����������� ���� �� �� �������� ���)
int white_sliding_window_horizontal(int field[19][19]);
int white_sliding_window_vertical(int field[19][19]);
int white_sliding_window_diag_right(int field[19][19]);
int white_sliding_window_diag_left(int field[19][19]);
int white_threats(int field[19][19]);
//���� ��� ������ �� ����� ����������, � ������ ������, ������ �� ����������, ��� ���� ������ ����� ���
int ev_func(vector<int> vec, int a);//������������� ������ ��� ����, ����� ������, ��� ������ ����� ����������
int def_sliding_window(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);// �������� ��� (������� ������ ���)
//�������, ������� ������ ��������� ������� ����� ������ ���� ������ �� ����
int quick_vert_window(int field[19][19], int y);
int quick_hor_window(int field[19][19], int x);
int quick_diag_left(int field[19][19], int x, int y);
int quick_diag_right(int field[19][19], int x, int y);
int quick_window(int field[19][19], int x, int y);
// ��������� ���� ��� ������� 3� ������ � ���� �������� 6
void all_p_moves3(int field[19][19], int field1[19][19]);

// ��������� ���� ��� ������� 2� ������ � ���� �������� 6 
void all_p_moves2(int field[19][19], int field1[19][19]);

//��������� ����, ���� ������ ���, ������������� ������� �� ���������� ���������� ������ ��������
void empty_points(int arr[19][19], int i, int j);
void empty_points_v2(int arr[19][19], int i, int j);

void best_move(int field[19][19],int field1[19][19], int i, int last_i1, int last_i2, int last_j2, int last_j1, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
void best_move_v2(int field[19][19], int field1[19][19], int i, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);
long long int h_move_evaluation(int field_2d[19][19], int i, int j);
// ������ ��� �� ���������
void attack_1(int field[19][19], int field1[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j, int last_i1, int last_i2, int last_j2, int last_j1);
void attack_2(int field[19][19], int field1[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j);

//Threat space search
void conservative_defence(int field[19][19], int x, int y);
bool threat_space_search(int field[19][19], int depth, vector <int> *i_first, vector <int> *j_first, vector <int> *i_second, vector <int> *j_second);
void all_p_moves3_v2(int field[19][19]);
void all_p_moves2_v2(int field[19][19]);
//void TSS(int field[19][19], int copy_field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j,int* mark ,vector <int> *i_first, vector <int> *j_first, vector <int> *i_second, vector <int> *j_second);