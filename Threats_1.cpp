#include "stdafx.h"
#include "Vars.h"

//рисует линии на поле
void copy(int ar1[19][19], int ar2[19][19])
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			ar2[i][j] = ar1[i][j];
		}
	}
}
int end_game(HDC hdc,int board[19][19])
{
	int x = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				x++;
			}
		}
	}
	if (x == 0)
	{
		return 3;
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (
				(board[i][j] == 1) && (board[i + 1][j] == 1) && (board[i + 2][j] == 1) && (board[i + 3][j] == 1) && (board[i + 4][j] == 1) && (board[i + 5][j] == 1)
				)
			{

				return 1;
			}
			else if (
				(board[i][j] == 1) && (board[i][j + 1] == 1) && (board[i][j + 2] == 1) && (board[i][j + 3] == 1) && (board[i][j + 4] == 1) && (board[i][j + 5] == 1)
				)
			{
				return 1;
			}
			else if (
				(board[i][j] == 1) && (board[i + 1][j + 1] == 1) && (board[i + 2][j + 2] == 1) && (board[i + 3][j + 3] == 1) && (board[i + 4][j + 4] == 1) && (board[i + 5][j + 5] == 1)
				)
			{

				return 1;
			}
			else if (
				(board[i][j] == 1) && (board[i + 1][j - 1] == 1) && (board[i + 2][j - 2] == 1) && (board[i + 3][j - 3] == 1) && (board[i + 4][j - 4] == 1) && (board[i + 5][j - 5] == 1)
				)
			{
				return 1;
			}
			else if (
				(board[i][j] == 2) && (board[i + 1][j] == 2) && (board[i + 2][j] == 2) && (board[i + 3][j] == 2) && (board[i + 4][j] == 2) && (board[i + 5][j] == 2)
				)
			{

				return 2;
			}
			else if (
				(board[i][j] == 2) && (board[i][j + 1] == 2) && (board[i][j + 2] == 2) && (board[i][j + 3] == 2) && (board[i][j + 4] == 2) && (board[i][j + 5] == 2)
				)
			{
				return 2;
			}
			else if (
				(board[i][j] == 2) && (board[i + 1][j + 1] == 2) && (board[i + 2][j + 2] == 2) && (board[i + 3][j + 3] == 2) && (board[i + 4][j + 4] == 2) && (board[i + 5][j + 5] == 2)
				)
			{
				return 2;
			}
			else if (
				(board[i][j] == 2) && (board[i + 1][j - 1] == 2) && (board[i + 2][j - 2] == 2) && (board[i + 3][j - 3] == 2) && (board[i + 4][j - 4] == 2) && (board[i + 5][j - 5] == 2)
				)
			{
				return 2;
			}

		}
	}
	return 0;
}
void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	//board[0][1] = 1;
}
//блок из функций, с помощю которых мы считаем, сколько чЄрный игрок создаЄт угроз на поле
int black_sliding_window_horizontal_offence(int field[19][19])
{
	vector <int> window(6);
	int threats = 0;
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field[i][j];
				window[1] = field[i][j + 1];
				window[2] = field[i][j + 2];
				window[3] = field[i][j + 3];
				window[4] = field[i][j + 4];
				window[5] = field[i][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if ((window[k] == 2) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i][j + a] = 4;
						}
					}

				}
				amount = 0;
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int black_sliding_window_vertical_offence(int field[19][19])
{
	vector <int> window(6);
	int threats = 0;
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field[j][i];
				window[1] = field[j + 1][i];
				window[2] = field[j + 2][i];
				window[3] = field[j + 3][i];
				window[4] = field[j + 4][i];
				window[5] = field[j + 5][i];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if ((window[k] == 2) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i] = 4;
						}
					}
				}
				amount = 0;
			}
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int black_sliding_window_diag_right_offence(int field[19][19])
{
	int threats = 0;
	vector <int> window(6);
	int amount = 0;
	for (int i = 5;i < 19; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((j + 5 <= 18) && (i - j - 5 >= 0))
			{
				window[0] = field[i - j][j];
				window[1] = field[i - j - 1][j + 1];
				window[2] = field[i - j - 2][j + 2];
				window[3] = field[i - j - 3][j + 3];
				window[4] = field[i - j - 4][j + 4];
				window[5] = field[i - j - 5][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if ((window[k] == 2) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i - j - a][j + a] = 4;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 18; j >= i; j--) //идЄм по строчкам
		{
			if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
			{
				window[0] = field[j][i + (18 - j)];
				window[1] = field[j - 1][i + (18 - j) + 1];
				window[2] = field[j - 2][i + (18 - j) + 2];
				window[3] = field[j - 3][i + (18 - j) + 3];
				window[4] = field[j - 4][i + (18 - j) + 4];
				window[5] = field[j - 5][i + (18 - j) + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 2))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i + (18 - j) + a] = 4;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int black_sliding_window_diag_left_offence(int field[19][19])
{
	int threats = 0;
	int amount = 0;
	vector <int> window(6);
	for (int i = 5;i <= 18; i++) //идЄм по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
		{
			if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
			{
				window[0] = field[j][i - (18 - j)];
				window[1] = field[j - 1][i - (18 - j) - 1];
				window[2] = field[j - 2][i - (18 - j) - 2];
				window[3] = field[j - 3][i - (18 - j) - 3];
				window[4] = field[j - 4][i - (18 - j) - 4];
				window[5] = field[j - 5][i - (18 - j) - 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 2))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i - (18 - j) - a] = 4;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
		{
			if ((j + 5 <= 18) && (i + j + 5 <= 18))
			{
				window[0] = field[j][i + j];
				window[1] = field[j + 1][i + j + 1];
				window[2] = field[j + 2][i + j + 2];
				window[3] = field[j + 3][i + j + 3];
				window[4] = field[j + 4][i + j + 4];
				window[5] = field[j + 5][i + j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 2))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i + j + a] = 4;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int black_threats(int field[19][19])
{
	int threat = 0;
	threat = black_sliding_window_horizontal_offence(field) + threat;
	threat = threat + black_sliding_window_vertical_offence(field);
	threat = threat + black_sliding_window_diag_right_offence(field);
	threat = threat + black_sliding_window_diag_left_offence(field);
	return threat;
}
//если у ии угроза и его ход, то он выигрывает
void make_six(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j)
{
	if (black_threats(field) != 0)
	{
		vector <int> window(6);
		int threats = 0;
		int amount = 0;
		int steps = 2;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (j + 5 <= 18)
				{
					window[0] = field[i][j];
					window[1] = field[i][j + 1];
					window[2] = field[i][j + 2];
					window[3] = field[i][j + 3];
					window[4] = field[i][j + 4];
					window[5] = field[i][j + 5];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						else if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[i][j + a] = 1;
								if (steps == 2)
								{
									*current_step1_i = i;
									*current_step1_j = j + a;
								}
								else if (steps == 1)
								{
									*current_step2_i = i;
									*current_step2_j = j + a;
								}
								steps--;
							}
						}
						break;
					}
				}
				amount = 0;
			}
		}
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (j + 5 <= 18)
				{
					window[0] = field[j][i];
					window[1] = field[j + 1][i];
					window[2] = field[j + 2][i];
					window[3] = field[j + 3][i];
					window[4] = field[j + 4][i];
					window[5] = field[j + 5][i];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						else if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[j + a][i] = 1;
								if (steps == 2)
								{
									*current_step1_j = i;
									*current_step1_i = j + a;
								}
								else if (steps == 1)
								{
									*current_step2_j = i;
									*current_step2_i = j + a;
								}
								steps--;
							}
						}

						break;
					}
				}
				amount = 0;
			}
		}
		for (int i = 5; i < 19; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if ((j + 5 <= 18) && (i - j - 5 >= 0))
				{
					window[0] = field[i - j][j];
					window[1] = field[i - j - 1][j + 1];
					window[2] = field[i - j - 2][j + 2];
					window[3] = field[i - j - 3][j + 3];
					window[4] = field[i - j - 4][j + 4];
					window[5] = field[i - j - 5][j + 5];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[i - j - a][j + a] = 1;								
								if (steps == 2)
								{
									*current_step1_i = i - j -a;
									*current_step1_j = j + a;
								}
								else if (steps == 1)
								{
									*current_step2_i = i - j - a;
									*current_step2_j = j + a;
								}
								steps--;
							}
						}

						break;
					}

				}
				amount = 0;
			}
		}
		for (int i = 13;i > 0; i--) //идЄм по столбикам
		{
			for (int j = 18; j >= i; j--) //идЄм по строчкам
			{
				if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
				{
					window[0] = field[j][i + (18 - j)];
					window[1] = field[j - 1][i + (18 - j) + 1];
					window[2] = field[j - 2][i + (18 - j) + 2];
					window[3] = field[j - 3][i + (18 - j) + 3];
					window[4] = field[j - 4][i + (18 - j) + 4];
					window[5] = field[j - 5][i + (18 - j) + 5];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[j - a][i + (18 - j) + a] = 1;
								if (steps == 2)
								{
									*current_step1_i = j - a;
									*current_step1_j = i+(18-j) + a;
								}
								else if (steps == 1)
								{
									*current_step2_i = j - a;
									*current_step2_j =i+(18- j) + a;
								}
								steps--;
							}
						}
						break;
					}
				}
				amount = 0;

			}
		}
		for (int i = 5;i <= 18; i++) //идЄм по столбикам
		{
			for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
			{
				if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
				{
					window[0] = field[j][i - (18 - j)];
					window[1] = field[j - 1][i - (18 - j) - 1];
					window[2] = field[j - 2][i - (18 - j) - 2];
					window[3] = field[j - 3][i - (18 - j) - 3];
					window[4] = field[j - 4][i - (18 - j) - 4];
					window[5] = field[j - 5][i - (18 - j) - 5];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[j - a][i - (18 - j) - a] = 1;
								if (steps == 2)
								{
									*current_step1_i = j - a;
									*current_step1_j = i - (18 - j) - a;
								}
								else if (steps == 1)
								{
									*current_step2_i = j - a;
									*current_step2_j = i - (18 - j) - a;
								}
								steps--;
							}
						}
						break;
					}
				}
				amount = 0;

			}
		}
		for (int i = 13;i > 0; i--) //идЄм по столбикам
		{
			for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
			{
				if ((j + 5 <= 18) && (i + j + 5 <= 18))
				{
					window[0] = field[j][i + j];
					window[1] = field[j + 1][i + j + 1];
					window[2] = field[j + 2][i + j + 2];
					window[3] = field[j + 3][i + j + 3];
					window[4] = field[j + 4][i + j + 4];
					window[5] = field[j + 5][i + j + 5];
					for (int k = 0; k < window.size(); k++)
					{
						if (window[k] == 1)
						{
							amount++;
						}
						if (window[k] == 2)
						{
							amount = -10;
						}
					}
					if ((amount >= 4) && (threats == 0))
					{
						threats++;
						for (int a = 0; a < window.size(); a++)
						{
							if ((window[a] == 0) || (window[a] == 3))
							{
								field[j + a][i + j + a] = 1;
								if (steps == 2)
								{
									*current_step1_i = j + a;
									*current_step1_j = i + +j + a;
								}
								else if (steps == 1)
								{
									*current_step2_i = j + a;
									*current_step2_j = i + +j + a;
								}
								steps--;
							}
						}
						break;
					}
				}

				amount = 0;
			}
		}

	}
}
//окна дл€ проверки угроз со стороны противника, считаем, сколько угроз создаЄт белый игрок
int white_sliding_window_horizontal(int field[19][19])
{
	vector <int> window(6);
	int threats = 0;
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field[i][j];
				window[1] = field[i][j + 1];
				window[2] = field[i][j + 2];
				window[3] = field[i][j + 3];
				window[4] = field[i][j + 4];
				window[5] = field[i][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					else if ((window[k] == 1) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i][j + a] = 4;
						}
					}

				}
				amount = 0;
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int white_sliding_window_vertical(int field[19][19])
{
	vector <int> window(6);
	int threats = 0;
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field[j][i];
				window[1] = field[j + 1][i];
				window[2] = field[j + 2][i];
				window[3] = field[j + 3][i];
				window[4] = field[j + 4][i];
				window[5] = field[j + 5][i];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					else if ((window[k] == 1) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i] = 4;
						}
					}
				}
				amount = 0;
			}
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int white_sliding_window_diag_right(int field[19][19])
{
	int threats = 0;
	vector <int> window(6);
	int amount = 0;
	for (int i = 5;i < 19; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((j + 5 <= 18) && (i - j - 5 >= 0))
			{
				window[0] = field[i - j][j];
				window[1] = field[i - j - 1][j + 1];
				window[2] = field[i - j - 2][j + 2];
				window[3] = field[i - j - 3][j + 3];
				window[4] = field[i - j - 4][j + 4];
				window[5] = field[i - j - 5][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					if ((window[k] == 1) || (window[k] == 4))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i - j - a][j + a] = 4;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 18; j >= i; j--) //идЄм по строчкам
		{
			if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
			{
				window[0] = field[j][i + (18 - j)];
				window[1] = field[j - 1][i + (18 - j) + 1];
				window[2] = field[j - 2][i + (18 - j) + 2];
				window[3] = field[j - 3][i + (18 - j) + 3];
				window[4] = field[j - 4][i + (18 - j) + 4];
				window[5] = field[j - 5][i + (18 - j) + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 1))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i + (18 - j) + a] = 4;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int white_sliding_window_diag_left(int field[19][19])
{
	int threats = 0;
	int amount = 0;
	vector <int> window(6);
	for (int i = 5;i <= 18; i++) //идЄм по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
		{
			if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
			{
				window[0] = field[j][i - (18 - j)];
				window[1] = field[j - 1][i - (18 - j) - 1];
				window[2] = field[j - 2][i - (18 - j) - 2];
				window[3] = field[j - 3][i - (18 - j) - 3];
				window[4] = field[j - 4][i - (18 - j) - 4];
				window[5] = field[j - 5][i - (18 - j) - 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 1))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i - (18 - j) - a] = 4;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
		{
			if ((j + 5 <= 18) && (i + j + 5 <= 18))
			{
				window[0] = field[j][i + j];
				window[1] = field[j + 1][i + j + 1];
				window[2] = field[j + 2][i + j + 2];
				window[3] = field[j + 3][i + j + 3];
				window[4] = field[j + 4][i + j + 4];
				window[5] = field[j + 5][i + j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 2)
					{
						amount++;
					}
					if ((window[k] == 4) || (window[k] == 1))
					{
						amount = -10;
					}
				}
				if (amount >= 4)
				{
					threats++;
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i + j + a] = 4;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (field[i][j] == 4)
			{
				field[i][j] = 0;
			}
		}
	}
	return threats;
}
int white_threats(int field[19][19])
{
	int threat = 0;
	threat = white_sliding_window_horizontal(field) + threat;
	threat = threat + white_sliding_window_vertical(field);
	threat = threat + white_sliding_window_diag_right(field);
	threat = threat + white_sliding_window_diag_left(field);
	return threat;
}
//окно дл€ защиты от угроз противника
int ev_func(vector<int> vec, int a)
{
	int omega = 0;
	vector <int> omegas(6);
	omegas[1] = 64;
	omegas[2] = 32;
	omegas[3] = 16;
	omegas[4] = 8;
	omegas[5] = 4;
	if (a == 0)
	{
		for (int i = 1; i < 6; i++)
		{
			omega = (vec[i] * omegas[i]) + omega;
		}
	}
	else if (a == 5)
	{
		for (int i = a - 1; i >= 0; i--)
		{
			omega = omega + (vec[i] * omegas[5 - i]);
		}
	}
	else if (a == 1)
	{
		omega = omega + vec[0] * omegas[1];
		for (int i = 2; i < 6; i++)
		{
			omega = omega + (vec[i] * omegas[i - 1]);
		}
	}
	else if (a == 2)
	{
		omega = omega + vec[0] * omegas[2];
		omega = omega + vec[1] * omegas[1];
		for (int i = 3; i < 6; i++)
		{
			omega = omega + (vec[i] * omegas[i - 2]);
		}
	}
	else if (a == 3)
	{
		omega = omega + vec[0] * omegas[3];
		omega = omega + vec[1] * omegas[2];
		omega = omega + vec[2] * omegas[1];
		for (int i = 4; i < 6; i++)
		{
			omega = omega + (vec[i] * omegas[i - 3]);
		}
	}
	else if (a == 4)
	{
		omega = omega + vec[5] * omegas[1];
		for (int i = 3; i >= 0; i--)
		{
			omega = omega + vec[i] * omegas[4 - i];
		}
	}
	return omega;
}
int def_sliding_window(int field[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j)
{
	int steps = 2;
	if (white_threats(field) > 0)
	{
		vector <int> window(6);
		int amount = 0;
		if (steps > 0)
		{
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (j + 5 <= 18)
					{
						window[0] = field[i][j];
						window[1] = field[i][j + 1];
						window[2] = field[i][j + 2];
						window[3] = field[i][j + 3];
						window[4] = field[i][j + 4];
						window[5] = field[i][j + 5];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							else if (window[k] == 1)
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[i][j + step[0]] = 1;
									if (steps == 2)
									{
										*current_step1_i = i;
										*current_step1_j = j + step[0];
									}
									else if (steps == 1)
									{
										*current_step2_i = i;
										*current_step2_j = j + step[0];
									}
									
									steps--;
								}
								else if (res[0] < res[1])
								{
									field[i][j + step[1]] = 1;
									if (steps == 2)
									{
										*current_step1_i = i;
										*current_step1_j = j + step[1];
									}
									else if (steps == 1)
									{
										*current_step2_i = i;
										*current_step2_j = j + step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[i][j + a] = 1;
										if (steps == 2)
										{
											*current_step1_i = i;
											*current_step1_j = j + a;
										}
										else if (steps == 1)
										{
											*current_step2_i = i;
											*current_step2_j = j + a;
										}
										steps--;
									}
								}

							}

						}
						amount = 0;
					}

				}
			}

		}
		if (steps > 0)
		{
			vector <int> window(6);
			int amount = 0;
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (j + 5 <= 18)
					{
						window[0] = field[j][i];
						window[1] = field[j + 1][i];
						window[2] = field[j + 2][i];
						window[3] = field[j + 3][i];
						window[4] = field[j + 4][i];
						window[5] = field[j + 5][i];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							else if (window[k] == 1)
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[j + step[0]][i] = 1;
									if (steps == 2)
									{
										*current_step1_j = i;
										*current_step1_i = j + step[0];
									}
									else if (steps == 1)
									{
										*current_step2_j = i;
										*current_step2_i = j + step[0];
									}
									steps--;
								}
								else if (res[0] < res[1])
								{
									field[j + step[1]][i] = 1;
									if (steps == 2)
									{
										*current_step1_j = i;
										*current_step1_i = j + step[1];
									}
									else if (steps == 1)
									{
										*current_step2_j = i;
										*current_step2_i = j + step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[j + a][i] = 1;
										if (steps == 2)
										{
											*current_step1_j = i;
											*current_step1_i = j + a;
										}
										else if (steps == 1)
										{
											*current_step2_j = i;
											*current_step2_i = j + a;
										}
										steps--;
									}
								}
							}
						}
						amount = 0;
					}
				}
			}
		}
		if (steps > 0)
		{
			vector <int> window(6);
			int amount = 0;
			for (int i = 5;i < 19; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if ((j + 5 <= 18) && (i - j - 5 >= 0))
					{
						window[0] = field[i - j][j];
						window[1] = field[i - j - 1][j + 1];
						window[2] = field[i - j - 2][j + 2];
						window[3] = field[i - j - 3][j + 3];
						window[4] = field[i - j - 4][j + 4];
						window[5] = field[i - j - 5][j + 5];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							if (window[k] == 1)
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[i - j - step[0]][j + step[0]] = 1;
									if (steps == 2)
									{
										*current_step1_i = i - j - step[0];
										*current_step1_j = j + step[0];
									}
									else if (steps == 1)
									{
										*current_step2_i = i - j - step[0];
										*current_step2_j = j + step[0];
									}
									steps--;
								}
								else if (res[0] < res[1])
								{
									field[i - j - step[1]][j + step[1]] = 1;
									if (steps == 2)
									{
										*current_step1_i = i - j - step[1];
										*current_step1_j = j + step[1];
									}
									else if (steps == 1)
									{
										*current_step2_i = i - j - step[1];
										*current_step2_j = j + step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[i - j - a][j + a] = 1;
										if (steps == 2)
										{
											*current_step1_i = i - j - a;
											*current_step1_j = j + a;
										}
										else if (steps == 1)
										{
											*current_step2_i = i - j - a;
											*current_step2_j = j + a;
										}
										steps--;
									}
								}

							}
						}
						amount = 0;
					}
				}
			}
			for (int i = 13;i > 0; i--) //идЄм по столбикам
			{
				for (int j = 18; j >= i; j--) //идЄм по строчкам
				{
					if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
					{
						window[0] = field[j][i + (18 - j)];
						window[1] = field[j - 1][i + (18 - j) + 1];
						window[2] = field[j - 2][i + (18 - j) + 2];
						window[3] = field[j - 3][i + (18 - j) + 3];
						window[4] = field[j - 4][i + (18 - j) + 4];
						window[5] = field[j - 5][i + (18 - j) + 5];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							if ((window[k] == 4) || (window[k] == 1))
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[j - step[0]][i + (18 - j) + step[0]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j - step[0];
										*current_step1_j = i + (18-j) + step[0];
									}
									else if (steps == 1)
									{
										*current_step2_i = j - step[0];
										*current_step2_j = i + (18-j) + step[0];
									}
									steps--;

								}
								else if (res[0] < res[1])
								{
									field[j - step[1]][i + (18 - j) + step[1]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j - step[1];
										*current_step1_j = i + (18 - j) + step[1];
									}
									else if (steps == 1)
									{
										*current_step2_i = j - step[1];
										*current_step2_j = i + (18 - j) + step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[j - a][i + (18 - j) + a] = 1;
										if (steps == 2)
										{
											*current_step1_i = j - a;
											*current_step1_j = i + (18 - j) + a;
										}
										else if (steps == 1)
										{
											*current_step2_i = j - a;
											*current_step2_j = i + (18 - j) + a;
										}
										steps--;
									}
								}
							}
						}
					}
					amount = 0;
				}
			}
		}
		if (steps > 0)
		{
			int amount = 0;
			vector <int> window(6);
			for (int i = 5;i <= 18; i++) //идЄм по столбикам
			{
				for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
				{
					if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
					{
						window[0] = field[j][i - (18 - j)];
						window[1] = field[j - 1][i - (18 - j) - 1];
						window[2] = field[j - 2][i - (18 - j) - 2];
						window[3] = field[j - 3][i - (18 - j) - 3];
						window[4] = field[j - 4][i - (18 - j) - 4];
						window[5] = field[j - 5][i - (18 - j) - 5];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							if (window[k] == 1)
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[j - step[0]][i - (18 - j) - step[0]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j - step[0];
										*current_step1_j = i - (18 - j) - step[0];
									}
									else if (steps == 1)
									{
										*current_step2_i = j - step[0];
										*current_step2_j = i - (18 - j) - step[0];
									}
									steps--;
								}
								else if (res[0] < res[1])
								{
									field[j - step[1]][i - (18 - j) - step[1]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j - step[1];
										*current_step1_j = i - (18 - j) - step[1];
									}
									else if (steps == 1)
									{
										*current_step2_i = j - step[1];
										*current_step2_j = i - (18 - j) - step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[j - a][i - (18 - j) - a] = 1;
										if (steps == 2)
										{
											*current_step1_i = j - a;
											*current_step1_j = i - (18 - j) - a;
										}
										else if (steps == 1)
										{
											*current_step2_i = j - a;
											*current_step2_j = i - (18 - j) - a;
										}
										steps--;
									}
								}
							}
						}

					}
					amount = 0;

				}
			}
			for (int i = 13;i > 0; i--) //идЄм по столбикам
			{
				for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
				{
					if ((j + 5 <= 18) && (i + j + 5 <= 18))
					{
						window[0] = field[j][i + j];
						window[1] = field[j + 1][i + j + 1];
						window[2] = field[j + 2][i + j + 2];
						window[3] = field[j + 3][i + j + 3];
						window[4] = field[j + 4][i + j + 4];
						window[5] = field[j + 5][i + j + 5];
						for (int k = 0; k < window.size(); k++)
						{
							if (window[k] == 2)
							{
								amount++;
							}
							if ((window[k] == 4) || (window[k] == 1))
							{
								amount = -10;
							}
						}
						if (steps > 0)
						{
							if (amount == 4)
							{
								vector <int> res;
								vector <int> step;
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										res.push_back(ev_func(window, a));
										step.push_back(a);
									}

								}
								if (res[0] >= res[1])
								{
									field[j + step[0]][i + j + step[0]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j + step[0];
										*current_step1_j = i + j + step[0];
									}
									else if (steps == 1)
									{
										*current_step2_i = j + step[0];
										*current_step2_j = i +j+ step[0];
									}
									steps--;
								}
								else if (res[0] < res[1])
								{
									field[j + step[1]][i + j + step[1]] = 1;
									if (steps == 2)
									{
										*current_step1_i = j + step[1];
										*current_step1_j = i + j + step[1];
									}
									else if (steps == 1)
									{
										*current_step2_i = j + step[1];
										*current_step2_j = i + j + step[1];
									}
									steps--;
								}
							}
							else if (amount == 5)
							{
								for (int a = 0; a < window.size(); a++)
								{
									if (window[a] == 0)
									{
										field[j + a][i + j + a] = 1;
										if (steps == 2)
										{
											*current_step1_i = j + a;
											*current_step1_j = i + j + a;
										}
										else if (steps == 1)
										{
											*current_step2_i = j + a;
											*current_step2_j = i + j + a;
										}
										steps--;
									}
								}
							}
						}
					}
					amount = 0;

				}
			}
		}
		return steps;
	}
	else
	{
		return steps;
	}
}
//функции, которые быстро вычисл€ют сколько угроз создаЄт один камень на поле
int quick_vert_window(int field[19][19], int y)
{
	int threats = 0;
	int amount = 0;
	vector <int> window(6);
	for (int i = 0; i < 19; i++)
	{
		if (i + 5 < 19)
		{
			window[0] = field[i][y];
			window[1] = field[i + 1][y];
			window[2] = field[i + 2][y];
			window[3] = field[i + 3][y];
			window[4] = field[i + 4][y];
			window[5] = field[i + 5][y];
			for (int k = 0; k < window.size(); k++)
			{
				if ((window[k] == 2) || (window[k] == 4))
				{
					amount = -10;
				}
				else if (window[k] == 1)
				{
					amount++;
				}
			}
			if (amount > 3)
			{
				threats++;
				for (int a = 0; a < 6; a++)
				{
					if ((window[a] == 0) || (window[a] == 3) || (window[a] == 5))
					{
						field[i + a][y] = 4;
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		if (field[i][y] == 4)
		{
			field[i][y] = 0;
		}
	}
	return threats;
}
int quick_hor_window(int field[19][19], int x)
{
	int threats = 0;
	int amount = 0;
	vector <int> window(6);
	for (int i = 0; i < 19; i++)
	{
		if (i + 5 < 19)
		{
			window[0] = field[x][i];
			window[1] = field[x][i + 1];
			window[2] = field[x][i + 2];
			window[3] = field[x][i + 3];
			window[4] = field[x][i + 4];
			window[5] = field[x][i + 5];
			for (int k = 0; k < window.size(); k++)
			{
				if ((window[k] == 2) || (window[k] == 4))
				{
					amount = -10;
				}
				else if (window[k] == 1)
				{
					amount++;
				}
			}
			if (amount > 3)
			{
				threats++;
				for (int a = 0; a < 6; a++)
				{
					if ((window[a] == 0) || (window[a] == 3) || (window[a] == 5))
					{
						field[x][i + a] = 4;
					}
				}

			}
			amount = 0;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		if (field[x][i] == 4)
		{
			field[x][i] = 0;
		}
	}

	return threats;
}
int quick_diag_left(int field[19][19], int x, int y)
{
	int threats = 0;
	int amount = 0;
	vector <int> window(6);
	int start_x = x - min(x, y);
	int start_y = y - min(x, y);
	for (int i = 0; max(start_x, start_y) + i + 5 < 19; i++)
	{
		window[0] = field[start_x + i][start_y + i];
		window[1] = field[start_x + i + 1][start_y + i + 1];
		window[2] = field[start_x + 2 + i][start_y + 2 + i];
		window[3] = field[start_x + 3 + i][start_y + 3 + i];
		window[4] = field[start_x + 4 + i][start_y + 4 + i];
		window[5] = field[start_x + 5 + i][start_y + 5 + i];
		for (int k = 0; k < 6; k++)
		{
			if ((window[k] == 2) || (window[k] == 4))
			{
				amount = -10;
			}
			if (window[k] == 1)
			{
				amount++;
			}
		}
		if (amount > 3)
		{
			threats++;
			for (int a = 0; a < 6; a++)
			{
				if ((window[a] == 0) || (window[a] == 5) || (window[a] == 3))
				{
					field[start_x + i + a][start_y + i + a] = 4;
				}
			}
		}
		amount = 0;
	}
	for (int i = 0; max(start_x, start_y) + i < 19; i++)
	{
		if (field[start_x + i][start_y + i] == 4)
		{
			field[start_x + i][start_y + i] = 0;
		}
	}
	return threats;
}
int quick_diag_right(int field[19][19], int x, int y)
{
	int threats = 0;
	int amount = 0;
	int start_x;
	int start_y;
	vector <int> window(6);
	if (x >= y)
	{
		start_x = 0;
		start_y = (x + y) % 18;
	}
	if (x < y)
	{
		start_x = (x + y) % 18;
		start_y = 18;
	}
	for (int i = 0; (start_y - 5 - i > -1) && (start_x + i + 5 < 19); i++)
	{

		window[0] = field[start_x + i][start_y - i];
		window[1] = field[start_x + i + 1][start_y - i - 1];
		window[2] = field[start_x + 2 + i][start_y - 2 - i];
		window[3] = field[start_x + 3 + i][start_y - 3 - i];
		window[4] = field[start_x + 4 + i][start_y - 4 - i];
		window[5] = field[start_x + 5 + i][start_y - 5 - i];
		for (int k = 0; k < window.size(); k++)
		{
			if ((window[k] == 2) || (window[k] == 4))
			{
				amount = -10;
			}
			if (window[k] == 1)
			{
				amount++;
			}
		}
		if (amount > 3)
		{
			threats++;
			for (int a = 0; a < 6; a++)
			{
				if ((window[a] == 0) || (window[a] == 5) || (window[a] == 3))
				{
					field[start_x + a + i][start_y - a - i] = 4;
				}
			}
		}
		amount = 0;
	}


	for (int i = 0; (start_y - 5 - i > -1) && (start_x + i + 5 < 19); i++)
	{
		if (field[start_x - i][start_y + i] == 4)
		{
			field[start_x - i][start_y + i] = 0;
		}
	}
	return threats;
}
int quick_window(int field[19][19], int x, int y)
{
	int threats;
	threats = quick_vert_window(field, y);
	threats = threats + quick_hor_window(field, x);
	threats = threats + quick_diag_left(field, x, y);
	threats = threats + quick_diag_right(field, x, y);
	return threats;
}
// возможные ходы при наличии 3х камней в окне размером 6
void all_p_moves3(int field[19][19],int field1[19][19])
{	
	vector <int> window(6);
	copy(field, field1);
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field1[i][j];
				window[1] = field1[i][j + 1];
				window[2] = field1[i][j + 2];
				window[3] = field1[i][j + 3];
				window[4] = field1[i][j + 4];
				window[5] = field1[i][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[i][j + a] = 5;
						}
					}

				}
				amount = 0;
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field1[j][i];
				window[1] = field1[j + 1][i];
				window[2] = field1[j + 2][i];
				window[3] = field1[j + 3][i];
				window[4] = field1[j + 4][i];
				window[5] = field1[j + 5][i];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j + a][i] = 5;
						}
					}
				}
				amount = 0;
			}
		}
	}
	for (int i = 5;i < 19; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((j + 5 <= 18) && (i - j - 5 >= 0))
			{
				window[0] = field1[i - j][j];
				window[1] = field1[i - j - 1][j + 1];
				window[2] = field1[i - j - 2][j + 2];
				window[3] = field1[i - j - 3][j + 3];
				window[4] = field1[i - j - 4][j + 4];
				window[5] = field1[i - j - 5][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[i - j - a][j + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 18; j >= i; j--) //идЄм по строчкам
		{
			if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
			{
				window[0] = field1[j][i + (18 - j)];
				window[1] = field1[j - 1][i + (18 - j) + 1];
				window[2] = field1[j - 2][i + (18 - j) + 2];
				window[3] = field1[j - 3][i + (18 - j) + 3];
				window[4] = field1[j - 4][i + (18 - j) + 4];
				window[5] = field1[j - 5][i + (18 - j) + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j - a][i + (18 - j) + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 5;i <= 18; i++) //идЄм по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
		{
			if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
			{
				window[0] = field1[j][i - (18 - j)];
				window[1] = field1[j - 1][i - (18 - j) - 1];
				window[2] = field1[j - 2][i - (18 - j) - 2];
				window[3] = field1[j - 3][i - (18 - j) - 3];
				window[4] = field1[j - 4][i - (18 - j) - 4];
				window[5] = field1[j - 5][i - (18 - j) - 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j - a][i - (18 - j) - a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
		{
			if ((j + 5 <= 18) && (i + j + 5 <= 18))
			{
				window[0] = field1[j][i + j];
				window[1] = field1[j + 1][i + j + 1];
				window[2] = field1[j + 2][i + j + 2];
				window[3] = field1[j + 3][i + j + 3];
				window[4] = field1[j + 4][i + j + 4];
				window[5] = field1[j + 5][i + j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j + a][i + j + a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}


}
// возможные ходы при наличии 2х камней в окне размером 6 
void all_p_moves2(int field[19][19], int field1[19][19])
{
	vector <int> window(6);
	copy(field, field1);
	int amount = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field1[i][j];
				window[1] = field1[i][j + 1];
				window[2] = field1[i][j + 2];
				window[3] = field1[i][j + 3];
				window[4] = field1[i][j + 4];
				window[5] = field1[i][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[i][j + a] = 5;
						}
					}

				}
				amount = 0;
			}

		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j + 5 <= 18)
			{
				window[0] = field1[j][i];
				window[1] = field1[j + 1][i];
				window[2] = field1[j + 2][i];
				window[3] = field1[j + 3][i];
				window[4] = field1[j + 4][i];
				window[5] = field1[j + 5][i];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					else if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j + a][i] = 5;
						}
					}
				}
				amount = 0;
			}
		}
	}
	for (int i = 5;i < 19; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((j + 5 <= 18) && (i - j - 5 >= 0))
			{
				window[0] = field1[i - j][j];
				window[1] = field1[i - j - 1][j + 1];
				window[2] = field1[i - j - 2][j + 2];
				window[3] = field1[i - j - 3][j + 3];
				window[4] = field1[i - j - 4][j + 4];
				window[5] = field1[i - j - 5][j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[i - j - a][j + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 18; j >= i; j--) //идЄм по строчкам
		{
			if ((i + (18 - j) + 5 <= 18) && (j - 5 >= 0))
			{
				window[0] = field1[j][i + (18 - j)];
				window[1] = field1[j - 1][i + (18 - j) + 1];
				window[2] = field1[j - 2][i + (18 - j) + 2];
				window[3] = field1[j - 3][i + (18 - j) + 3];
				window[4] = field1[j - 4][i + (18 - j) + 4];
				window[5] = field1[j - 5][i + (18 - j) + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j - a][i + (18 - j) + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 5;i <= 18; i++) //идЄм по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идЄм по строчкам
		{
			if ((j - 5 >= 0) && ((i - (18 - j) - 5) >= 0))
			{
				window[0] = field1[j][i - (18 - j)];
				window[1] = field1[j - 1][i - (18 - j) - 1];
				window[2] = field1[j - 2][i - (18 - j) - 2];
				window[3] = field1[j - 3][i - (18 - j) - 3];
				window[4] = field1[j - 4][i - (18 - j) - 4];
				window[5] = field1[j - 5][i - (18 - j) - 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j - a][i - (18 - j) - a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идЄм по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идЄм по строчкам
		{
			if ((j + 5 <= 18) && (i + j + 5 <= 18))
			{
				window[0] = field1[j][i + j];
				window[1] = field1[j + 1][i + j + 1];
				window[2] = field1[j + 2][i + j + 2];
				window[3] = field1[j + 3][i + j + 3];
				window[4] = field1[j + 4][i + j + 4];
				window[5] = field1[j + 5][i + j + 5];
				for (int k = 0; k < window.size(); k++)
				{
					if (window[k] == 1)
					{
						amount++;
					}
					if (window[k] == 2)
					{
						amount = -10;
					}
				}
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field1[j + a][i + j + a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}


}
//возможные ходы, если других нет, эвристическа€ функци€ по вычислению результата оценки полухода
long long int h_move_evaluation(int field_2d[19][19], int i, int j)
{
	long long int E = 0;
	vector <int> omegas(5);
	omegas[0] = 4096;
	omegas[1] = 2048;
	omegas[2] = 1024;
	omegas[3] = 512;
	omegas[4] = 256;
	long long int E_direct_hor = 1;
	int e = 2;
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i][j + k] == 0) || (field_2d[i][j + k] == 3))
		{
			E_direct_hor = E_direct_hor*e;
		}
		else if (field_2d[i][j + k] == 2)
		{
			E_direct_hor = E_direct_hor*omegas[k - 1];
		}
		else if ((field_2d[i][j + k] == 1) || (j == 18) || (j + k == 19))
		{
			break;
		}
	}
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i][j - k] == 0) || (field_2d[i][j - k] == 3))
		{
			E_direct_hor = E_direct_hor*e;
		}
		else if (field_2d[i][j - k] == 2)
		{
			E_direct_hor = E_direct_hor*omegas[k - 1];
		}
		else if ((field_2d[i][j - k] == 1) || (j == 0) || (j - k == -1))
		{
			break;
		}
	}
	long long int E_direct_vert = 1;
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i - k][j] == 0) || (field_2d[i - k][j] == 3))
		{
			E_direct_vert = E_direct_vert*e;
		}
		else if (field_2d[i - k][j] == 2)
		{
			E_direct_vert = E_direct_vert*omegas[k - 1];
		}
		else if ((field_2d[i - k][j] == 1) || (i == 0) || (i - k == -1))
		{
			break;
		}
	}
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i + k][j] == 0) || (field_2d[i + k][j] == 3))
		{
			E_direct_vert = E_direct_vert*e;
		}
		else if (field_2d[i + k][j] == 2)
		{
			E_direct_vert = E_direct_vert*omegas[k - 1];
		}
		else if ((field_2d[i + k][j] == 1) || (i == 18) || (i + k == 19))
		{
			break;
		}
	}
	long long int E_direct_diag_left = 1;
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i - k][j - k] == 0) || (field_2d[i - k][j - k] == 3))
		{
			E_direct_diag_left = E_direct_diag_left*e;
		}
		else if (field_2d[i - k][j - k] == 2)
		{
			E_direct_diag_left = E_direct_diag_left*omegas[k - 1];
		}
		else if ((field_2d[i - k][j - k] == 1) || (j == 0) || (i == 0) || (j - k == -1) || (i - k == -1))
		{
			break;
		}
	}
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i + k][j + k] == 0) || (field_2d[i + k][j + k] == 3))
		{
			E_direct_diag_left = E_direct_diag_left*e;
		}
		else if (field_2d[i + k][j + k] == 2)
		{
			E_direct_diag_left = E_direct_diag_left*omegas[k - 1];
		}
		else if ((field_2d[i + k][j + k] == 1) || (j == 18) || (j + k == 19) || (i == 18) || (i + k == 19))
		{
			break;
		}
	}
	long long int E_direct_diag_right = 1;
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i - k][j + k] == 0) || (field_2d[i - k][j + k] == 3))
		{
			E_direct_diag_right = E_direct_diag_right*e;
		}
		else if (field_2d[i - k][j + k] == 2)
		{
			E_direct_diag_right = E_direct_diag_right*omegas[k - 1];
		}
		else if ((field_2d[i - k][j + k] == 1) || (j == 18) || (i == 0) || (j + k == 19) || (i - k == -1))
		{
			break;
		}
	}
	for (int k = 1; k <= 5; k++)
	{
		if ((field_2d[i + k][j - k] == 0) || (field_2d[i + k][j - k] == 3))
		{
			E_direct_diag_right = E_direct_diag_right*e;
		}
		else if (field_2d[i + k][j - k] == 2)
		{
			E_direct_diag_right = E_direct_diag_right*omegas[k - 1];
		}
		else if ((field_2d[i + k][j - k] == 1) || (j == 0) || (i == 18) || (i + k == 19) || (j - k == -1))
		{
			break;
		}
	}
	E = E_direct_hor;
	E = E + E_direct_vert;
	E = E + E_direct_diag_right;
	E = E + E_direct_diag_left;
	return E;
}
void empty_points(int arr[19][19], int i, int j)
{
	if (((arr[i][j + 1] == 0) || (arr[i][j + 1] == 3)) && (j + 1 < 19))
	{
		arr[i][j + 1] = 3;
	}
	if (((arr[i][j + 2] == 0) || (arr[i][j + 2] == 3)) && (j + 2 < 19))
	{
		arr[i][j + 2] = 3;
	}
	if (((arr[i][j + 3] == 0) || (arr[i][j + 3] == 3)) && (j + 3 < 19))
	{
		arr[i][j + 3] = 3;
	}
	if ((j - 1 > -1) && ((arr[i][j - 1] == 0) || (arr[i][j - 1] == 3)))
	{
		arr[i][j - 1] = 3;
	}
	if ((j - 2 > -1) && ((arr[i][j - 2] == 0) || (arr[i][j - 2] == 3)))
	{
		arr[i][j - 2] = 3;
	}
	if ((j - 3 > -1) && ((arr[i][j - 3] == 0) || (arr[i][j - 3] == 3)))
	{
		arr[i][j - 3] = 3;
	}
	if (((arr[i + 1][j] == 0) || (arr[i + 1][j] == 3)) && (i + 1 < 19))
	{
		arr[i + 1][j] = 3;
	}
	if (((arr[i + 2][j] == 0) || (arr[i + 2][j] == 3)) && (i + 2 < 19))
	{
		arr[i + 2][j] = 3;
	}
	if (((arr[i + 3][j] == 0) || (arr[i + 3][j] == 3)) && (i + 3 < 19))
	{
		arr[i + 3][j] = 3;
	}
	if ((i - 1 > -1) && ((arr[i - 1][j] == 0) || (arr[i - 1][j] == 3)))
	{
		arr[i - 1][j] = 3;
	}
	if ((i - 2 > -1) && ((arr[i - 2][j] == 0) || (arr[i - 2][j] == 3)))
	{
		arr[i - 2][j] = 3;
	}
	if ((i - 3 > -1) && ((arr[i - 3][j] == 0) || (arr[i - 3][j] == 3)))
	{
		arr[i - 3][j] = 3;
	}
	if (((arr[i + 1][j + 1] == 0) || (arr[i + 1][j + 1] == 3)) && (i + 1 < 19) && (j + 1 < 19))
	{
		arr[i + 1][j + 1] = 3;
	}
	if (((arr[i + 2][j + 2] == 0) || (arr[i + 2][j + 2] == 3)) && (i + 2 < 19) && (j + 2 < 19))
	{
		arr[i + 2][j + 2] = 3;
	}
	if (((arr[i + 3][j + 3] == 0) || (arr[i + 3][j + 3] == 3)) && (i + 3 < 19) && (j + 3 < 19))
	{
		arr[i + 3][j + 3] = 3;
	}
	if ((j - 2 > -1) && (i - 2 > -1) && ((arr[i - 2][j - 2] == 0) || (arr[i - 2][j - 2] == 3)))
	{
		arr[i - 2][j - 2] = 3;
	}
	if ((j - 1 > -1) && (i - 1 > -1) && ((arr[i - 1][j - 1] == 0) || (arr[i - 1][j - 1] == 3)))
	{
		arr[i - 1][j - 1] = 3;
	}
	if ((j - 3 > -1) && (i - 3 > -1) && ((arr[i - 3][j - 3] == 0) || (arr[i - 3][j - 3] == 3)))
	{
		arr[i - 3][j - 3] = 3;
	}
	if ((j + 1 < 19) && (i - 1 > -1) && ((arr[i - 1][j + 1] == 0) || (arr[i - 1][j + 1] == 3)))
	{
		arr[i - 1][j + 1] = 3;
	}
	if ((j + 2 < 19) && (i - 2 > -1) && ((arr[i - 2][j + 2] == 0) || (arr[i - 2][j + 2] == 3)))
	{
		arr[i - 2][j + 2] = 3;
	}
	if ((j + 3 < 19) && (i - 3 > -1) && ((arr[i - 3][j + 3] == 0) || (arr[i - 3][j + 3] == 3)))
	{
		arr[i - 3][j + 3] = 3;
	}
	if ((i + 2 < 19) && (j - 2 > -1) && ((arr[i + 2][j - 2] == 0) || (arr[i + 2][j - 2] == 3)))
	{
		arr[i + 2][j - 2] = 3;
	}
	if ((i + 3 < 19) && (j - 3 > -1) && ((arr[i + 3][j - 3] == 0) || (arr[i + 3][j - 3] == 3)))
	{
		arr[i + 3][j - 3] = 3;
	}
	if ((i + 1 < 19) && (j - 1 > -1) && ((arr[i + 1][j - 1] == 0) || (arr[i + 1][j - 1] == 3)))
	{
		arr[i + 1][j - 1] = 3;
	}
	if ((i + 1 < 19) && (j - 3 > -1) && ((arr[i + 1][j - 3] == 0) || (arr[i + 1][j - 3] == 3)))
	{
		arr[i + 1][j - 3] = 3;
	}
	if ((i + 2 < 19) && (j - 1 > -1) && ((arr[i + 2][j - 1] == 0) || (arr[i + 2][j - 1] == 3)))
	{
		arr[i + 2][j - 1] = 3;
	}
	if ((i + 2 < 19) && (j - 3 > -1) && ((arr[i + 2][j - 3] == 0) || (arr[i + 2][j - 3] == 3)))
	{
		arr[i + 2][j - 3] = 3;
	}
	if ((j + 3 < 19) && (i + 2 < 19) && ((arr[i + 2][j + 3] == 0) || (arr[i + 2][j + 3] == 3)))
	{
		arr[i + 2][j + 3] = 3;
	}
	if ((j + 1 < 19) && (i + 2 < 19) && ((arr[i + 2][j + 1] == 0) || (arr[i + 2][j + 1] == 3)))
	{
		arr[i + 2][j + 1] = 3;
	}
	if ((j + 1 < 19) && (i - 2 > -1) && ((arr[i - 2][j + 1] == 0) || (arr[i - 2][j + 1] == 3)))
	{
		arr[i - 2][j + 1] = 3;
	}
	if ((i - 2 > -1) && (j - 1 > -1) && ((arr[i - 2][j - 1] == 0) || (arr[i - 2][j - 1] == 3)))
	{
		arr[i - 2][j - 1] = 3;
	}
	if ((i - 2 > -1) && (j - 3 > -1) && ((arr[i - 2][j - 3] == 0) || (arr[i - 2][j - 3] == 3)))
	{
		arr[i - 2][j - 3] = 3;
	}
	if ((j + 3 < 19) && (i - 2 > -1) && ((arr[i - 2][j + 3] == 0) || (arr[i - 2][j + 3] == 3)))
	{
		arr[i - 2][j + 3] = 3;
	}
	if ((i - 1 > -1) && (j - 3 > -1) && ((arr[i - 1][j - 3] == 0) || (arr[i - 1][j - 3] == 3)))
	{
		arr[i - 1][j - 3] = 3;
	}
	if ((j + 3 < 19) && (i - 1 > -1) && ((arr[i - 1][j + 3] == 0) || (arr[i - 1][j + 3] == 3)))
	{
		arr[i - 1][j + 3] = 3;
	}
	if ((j + 2 < 19) && (i + 1 < 19) && ((arr[i + 1][j + 2] == 0) || (arr[i + 1][j + 2] == 3)))
	{
		arr[i + 1][j + 2] = 3;
	}
	if ((j + 3 < 19) && (i + 1 < 19) && ((arr[i + 1][j + 3] == 0) || (arr[i + 1][j + 3] == 3)))
	{
		arr[i + 1][j + 3] = 3;
	}
	if ((j + 2 < 19) && (i + 3 < 19) && ((arr[i + 3][j + 2] == 0) || (arr[i + 3][j + 2] == 3)))
	{
		arr[i + 3][j + 2] = 3;
	}
	if ((j + 1 < 19) && (i + 3 < 19) && ((arr[i + 3][j + 1] == 0) || (arr[i + 3][j + 1] == 3)))
	{
		arr[i + 3][j + 1] = 3;
	}
	if ((j + 2 < 19) && (i - 1 > -1) && ((arr[i - 1][j + 2] == 0) || (arr[i - 1][j + 2] == 3)))
	{
		arr[i - 1][j + 2] = 3;
	}
	if ((j + 2 < 19) && (i - 3 > -1) && ((arr[i - 3][j + 2] == 0) || (arr[i - 3][j + 2] == 3)))
	{
		arr[i - 3][j + 2] = 3;
	}
	if ((j + 1 < 19) && (i - 3 > -1) && ((arr[i - 3][j + 1] == 0) || (arr[i - 3][j + 1] == 3)))
	{
		arr[i - 3][j + 1] = 3;
	}
	if ((i + 1 < 19) && (j - 2 > -1) && ((arr[i + 1][j - 2] == 0) || (arr[i + 1][j - 2] == 3)))
	{
		arr[i + 1][j - 2] = 3;
	}
	if ((i + 3 < 19) && (j - 1 > -1) && ((arr[i + 3][j - 1] == 0) || (arr[i + 3][j - 1] == 3)))
	{
		arr[i + 3][j - 1] = 3;
	}
	if ((i + 3 < 19) && (j - 2 > -1) && ((arr[i + 3][j - 2] == 0) || (arr[i + 3][j - 2] == 3)))
	{
		arr[i + 3][j - 2] = 3;
	}
	if ((j - 2 > -1) && (i - 1 > -1) && ((arr[i - 1][j - 2] == 0) || (arr[i - 1][j - 2] == 3)))
	{
		arr[i - 1][j - 2] = 3;
	}
	if ((j - 2 > -1) && (i - 3 > -1) && ((arr[i - 3][j - 2] == 0) || (arr[i - 3][j - 2] == 3)))
	{
		arr[i - 3][j - 2] = 3;
	}
	if ((j - 1 > -1) && (i - 3 > -1) && ((arr[i - 3][j - 1] == 0) || (arr[i - 3][j - 1] == 3)))
	{
		arr[i - 3][j - 1] = 3;
	}

}
void best_move(int field[19][19], int field1[19][19], int i, int last_i1, int last_i2, int last_j2, int last_j1, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j)
{

	if (i == 2)
	{
		copy(field, field1);
		empty_points(field1, last_i1, last_j1);
		empty_points(field1, last_i2, last_j2);
		vector <long long int> moves;
		vector <int> i_index;
		vector <int> j_index;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field1[i][j] == 3)
				{
					moves.push_back(h_move_evaluation(field1, i, j));
					i_index.push_back(i);
					j_index.push_back(j);
				}
			}
		}
		int x;
		long long int Best_move = moves[0];
		for (int i = 0; i < i_index.size(); i++)
		{
			if (moves[i] >= Best_move)
			{
				Best_move = moves[i];
				x = i;
			}
		}
		int a = i_index[x];
		int b = j_index[x];
		
		field[a][b] = 1;

		field1[a][b] = 1;
		*current_step1_i = a;
		*current_step1_j = b;
		moves.clear();
		i_index.clear();
		j_index.clear();
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field1[i][j] == 3)
				{
					moves.push_back(h_move_evaluation(field1, i, j));
					i_index.push_back(i);
					j_index.push_back(j);
				}
			}
		}
		int y;
		long long int Best_move_2 = moves[0];
		for (int i = 0; i < i_index.size(); i++)
		{
			if (moves[i] >= Best_move_2)
			{
				Best_move_2 = moves[i];
				y = i;
			}
		}
		a = i_index[y];
		b = j_index[y];		
		field[a][b] = 1;
		field1[a][b] = 1;
		*current_step2_i = a;
		*current_step2_j = b;		
	}
	else if (i == 1)
	{
		copy(field, field1);
		empty_points(field1, last_i1, last_j1);
		empty_points(field1, last_i2, last_j2);
		vector <long long int> moves;
		vector <int> i_index;
		vector <int> j_index;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field1[i][j] == 3)
				{
					moves.push_back(h_move_evaluation(field1, i, j));
					i_index.push_back(i);
					j_index.push_back(j);
				}
			}
		}
		int x;
		long long int Best_move = moves[0];
		for (int i = 0; i < i_index.size(); i++)
		{
			if (moves[i] >= Best_move)
			{
				Best_move = moves[i];
				x = i;
			}
		}
		int a = i_index[x];
		int b = j_index[x];
		field[a][b] = 1;
		*current_step2_i = a;
		*current_step2_j = b;
		moves.clear();
		i_index.clear();
		j_index.clear();		
	}
	else if (i == 0)
	{

	}
}
// лучший ход из возможных
void attack_1(int field[19][19],int field1[19][19], int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j, int last_i1, int last_i2, int last_j2, int last_j1)
{
	
	if ((white_threats(field) == 0) && (black_threats(field) == 0))
	{		
		vector <int> results;
		vector <int> i_indexes;
		vector <int> j_indexes;
		all_p_moves3(field, field1);
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0;j < 19; j++)
			{
				if (field1[i][j] == 5)
				{
					i_indexes.push_back(i);
					j_indexes.push_back(j);
				}
			}
		}
		if (i_indexes.size() != 0)
		{
			for (int i = 0; i < i_indexes.size(); i++)
			{
				field1[i_indexes[i]][j_indexes[i]] = 1;
				results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));
				field1[i_indexes[i]][j_indexes[i]] = 0;
			}
			int number = 0;
			int Best_move = results[0];
			for (int i = 0; i < results.size(); i++)
			{
				if (Best_move <= results[i])
				{
					Best_move = results[i];
					number = i;
				}
			}
			field[i_indexes[number]][j_indexes[number]] = 1;
			*current_step1_i = i_indexes[number];
			*current_step1_j = j_indexes[number];
			field1[i_indexes[number]][j_indexes[number]] = 1;
			results.erase(results.begin() + number);
			i_indexes.erase(i_indexes.begin() + number);
			j_indexes.erase(j_indexes.begin() + number);
			Best_move = results[0];
			for (int i = 0; i < results.size(); i++)
			{
				if (Best_move <= results[i])
				{
					Best_move = results[i];
					number = i;
				}
			}
			field[i_indexes[number]][j_indexes[number]] = 1;
			*current_step2_i = i_indexes[number];
			*current_step2_j = j_indexes[number];
			field1[i_indexes[number]][j_indexes[number]] = 1;
			
		}
		else if (i_indexes.size() == 0)
		{
			all_p_moves2(field, field1);
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0;j < 19; j++)
				{
					if (field1[i][j] == 5)
					{
						i_indexes.push_back(i);
						j_indexes.push_back(j);
					}
				}
			}
			if (i_indexes.size() != 0)
			{
				vector <int> first_step_i;
				vector <int> first_step_j;
				vector <int> second_step_i;
				vector <int> second_step_j;
				for (int i = 0; i < i_indexes.size(); i++)
				{
					for (int j = i + 1; j < j_indexes.size(); j++)
					{
						field1[i_indexes[i]][j_indexes[i]] = 1;
						field1[i_indexes[j]][j_indexes[j]] = 1;
						results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));
						first_step_i.push_back(i_indexes[i]);
						first_step_j.push_back(j_indexes[i]);
						second_step_i.push_back(i_indexes[j]);
						second_step_j.push_back(j_indexes[j]);
						field1[i_indexes[i]][j_indexes[i]] = 0;
						field1[i_indexes[j]][j_indexes[j]] = 0;
					}
				}
				int Best_move = results[0];
				int number;
				for (int i = 0; i < results.size(); i++)
				{
					if (Best_move <= results[i])
					{
						Best_move = results[i];
						number = i;
					}
				}
				
				field[first_step_i[number]][first_step_j[number]] = 1;
				*current_step1_i = first_step_i[number];
				*current_step1_j = first_step_j[number];
				field[second_step_i[number]][second_step_j[number]] = 1;
				*current_step2_i = second_step_i[number];
				*current_step2_j = second_step_j[number];

			}
			else if (i_indexes.size() == 0)
			{
				best_move(field,field1, 2,last_i1,last_i2, last_j2,last_j1,current_step1_i, current_step1_j, current_step2_i, current_step2_j);// не знаю работает ли
			}
		}
	}
	else if ((white_threats(field) != 0) && (black_threats(field) == 0))
	{
		int steps = def_sliding_window(field,current_step1_i, current_step1_j, current_step2_i, current_step2_j);// вроде работет
		best_move(field,field1, steps, last_i1, last_i2, last_j2, last_j1, current_step1_i, current_step1_j, current_step2_i, current_step2_j);// не знаю работет ли
	}
	else if (black_threats(field) != 0)
	{
		make_six(field, current_step1_i, current_step1_j, current_step2_i, current_step2_j);// вроде работает
	}
}
