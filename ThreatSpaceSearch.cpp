#include"stdafx.h"
#include"vars.h"
void all_p_moves3_v2(int field[19][19])
{
	vector <int> window(6);
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
							field[i][j + a] = 5;
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
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i] = 5;
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
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i - j - a][j + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идём по столбикам
	{
		for (int j = 18; j >= i; j--) //идём по строчкам
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
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i + (18 - j) + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 5;i <= 18; i++) //идём по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идём по строчкам
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
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i - (18 - j) - a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идём по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идём по строчкам
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
				if (amount == 3)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i + j + a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}


}
// возможные ходы при наличии 2х камней в окне размером 6 
void all_p_moves2_v2(int field[19][19])
{
	vector <int> window(6);
	
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
							field[i][j + a] = 5;
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
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i] = 5;
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
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[i - j - a][j + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 13;i > 0; i--) //идём по столбикам
	{
		for (int j = 18; j >= i; j--) //идём по строчкам
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
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i + (18 - j) + a] = 5;
						}
					}
				}
			}
			amount = 0;
		}
	}
	for (int i = 5;i <= 18; i++) //идём по столбикам
	{
		for (int j = 18; j >= 18 - i; j--) //идём по строчкам
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
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j - a][i - (18 - j) - a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}
	for (int i = 13;i > 0; i--) //идём по столбикам
	{
		for (int j = 0; j <= 18 - i; j++) //идём по строчкам
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
				if (amount == 2)
				{
					for (int a = 0; a < window.size(); a++)
					{
						if ((window[a] == 0) || (window[a] == 3))
						{
							field[j + a][i + j + a] = 5;
						}
					}
				}
			}
			amount = 0;

		}
	}


}

void conservative_defence(int field[19][19], int x, int y)
{
	vector <int> window(6);
	vector <int> i_indexes_def_moves;
	vector <int> j_indexes_def_moves;
	//окно с одной стороны
	int amount = 0;
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
				for (int a = 0; a < 6; a++)
				{
					if ((window[a] == 0) || (window[a] == 3) || (window[a] == 5))
					{
						field[i + a][y] = 4;
					}
				}
			}

		}
		amount = 0;
	}
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

				for (int a = 0; a < 6; a++)
				{
					if ((window[a] == 0) || (window[a] == 3) || (window[a] == 5))
					{
						field[x][i + a] = 4;
					}
				}

			}

		}
		amount = 0;
	}
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
	if (x + y <= 18)
	{
		start_x = 0;
		start_y = x + y;
	}
	if (x + y > 18)
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


	for (int i = 18; i >= 0; i--)
	{
		if (i - 5 > -1)
		{
			window[0] = field[i][y];
			window[1] = field[i - 1][y];
			window[2] = field[i - 2][y];
			window[3] = field[i - 3][y];
			window[4] = field[i - 4][y];
			window[5] = field[i - 5][y];
			for (int k = 0; k < window.size(); k++)
			{
				if (window[k] == 1)
				{
					amount++;
				}
				else if ((window[k] == 2) || (window[k] == 6))
				{
					amount = -10;
				}
			}
			if (amount >= 4)
			{

				for (int a = 0; a < window.size(); a++)
				{
					if ((window[a] == 0) || (window[a] == 4))
					{
						field[i - a][y] = 6;
						if (window[a] == 4)
						{
							i_indexes_def_moves.push_back(i - a);
							j_indexes_def_moves.push_back(y);
						}
					}
				}

			}

		}
		amount = 0;
	}
	for (int i = 18; i >= 0; i--)
	{
		if (i - 5 > -1)
		{
			window[0] = field[x][i];
			window[1] = field[x][i - 1];
			window[2] = field[x][i - 2];
			window[3] = field[x][i - 3];
			window[4] = field[x][i - 4];
			window[5] = field[x][i - 5];
			for (int k = 0; k < window.size(); k++)
			{
				if (window[k] == 1)
				{
					amount++;
				}
				else if ((window[k] == 2) || (window[k] == 6))
				{
					amount = -10;
				}
			}
			if (amount >= 4)
			{
				for (int a = 0; a < window.size(); a++)
				{
					if ((window[a] == 0) || (window[a] == 4))
					{
						field[x][i - a] = 6;
						if (window[a] == 4)
						{
							i_indexes_def_moves.push_back(x);
							j_indexes_def_moves.push_back(i - a);
						}
					}
				}
			}

		}
		amount = 0;
	}
	start_x = 18 - (y - min(x, y));
	start_y = 18 - (x - min(x, y));
	for (int i = 0; min(start_x, start_y) - i - 5 >-1; i++)
	{
		window[0] = field[start_x - i][start_y - i];
		window[1] = field[start_x - i - 1][start_y - i - 1];
		window[2] = field[start_x - 2 - i][start_y - 2 - i];
		window[3] = field[start_x - 3 - i][start_y - 3 - i];
		window[4] = field[start_x - 4 - i][start_y - 4 - i];
		window[5] = field[start_x - 5 - i][start_y - 5 - i];
		for (int k = 0; k < 6; k++)
		{
			if ((window[k] == 2) || (window[k] == 6))
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
			for (int a = 0; a < 6; a++)
			{
				if ((window[a] == 0) || (window[a] == 5) || (window[a] == 3) || (window[a] == 4))
				{
					field[start_x - i - a][start_y - i - a] = 6;
					if (window[a] == 4)
					{
						i_indexes_def_moves.push_back(start_x - i - a);
						j_indexes_def_moves.push_back(start_y - i - a);
					}
				}
			}
		}
		amount = 0;
	}
	if (x + y <= 18)
	{
		start_x = x + y;
		start_y = 0;
	}
	if (x + y > 18)
	{
		start_x = 18;
		start_y = (x + y) % 18;
	}
	for (int i = 0; (start_y + i + 1 < 19) && (start_x - i - 5 > -1); i++)
	{

		window[0] = field[start_x - i][start_y + i];
		window[1] = field[start_x - i - 1][start_y + i + 1];
		window[2] = field[start_x - 2 - i][start_y + 2 + i];
		window[3] = field[start_x - 3 - i][start_y + 3 + i];
		window[4] = field[start_x - 4 - i][start_y + 4 + i];
		window[5] = field[start_x - 5 - i][start_y + 5 + i];
		for (int k = 0; k < window.size(); k++)
		{
			if ((window[k] == 2) || (window[k] == 6))
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
			for (int a = 0; a < 6; a++)
			{
				if ((window[a] == 0) || (window[a] == 5) || (window[a] == 3) || (window[a] == 4))
				{
					field[start_x - a - i][start_y + a + i] = 6;
					if (window[a] == 4)
					{
						i_indexes_def_moves.push_back(start_x - i - a);
						j_indexes_def_moves.push_back(start_y + i + a);
					}
				}
			}
		}
		amount = 0;
	}




	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if ((field[i][j] == 4) || (field[i][j] == 6))
			{
				field[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < i_indexes_def_moves.size(); i++)
	{
		field[i_indexes_def_moves[i]][j_indexes_def_moves[i]] = 2;
	}
}

bool threat_space_search(int field[19][19], int depth, vector <int> *i_first, vector <int> *j_first,vector <int> *i_second, vector <int> *j_second)
{
	if (depth < 7)
	{
		bool result;
		//all_p_moves2(field, copy_field);	
		if (white_threats(field) > 0)
		{
			return false;
		}
		if (black_threats(field) > 0)
		{
			return true;
		}
		/*if (depth == 1)
		{
		print(field);//strange
		cout << endl;
		print(copy_field);//ok
		cout << endl;
		}*/
		all_p_moves3_v2(field);
		all_p_moves2_v2(field);
		/*if (depth == 1)
		{
		print(field);
		cout << endl;
		//print(copy_field);
		cout << endl;
		}*/
		vector <int> possible_moves_i;
		vector <int> possible_moves_j;
		vector <int> two_threat_moves_i_first_step;
		vector <int> two_threat_moves_j_first_step;
		vector <int> two_threat_moves_i_second_step;
		vector <int> two_threat_moves_j_second_step;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field[i][j] == 5)
				{
					possible_moves_i.push_back(i);
					possible_moves_j.push_back(j);
					field[i][j] = 0;
				}
			}
		}
		//clear(copy_field);
		//copy(field, copy_field);
		for (int i = 0; i < possible_moves_i.size(); i++)
		{
			for (int j = i + 1; j < possible_moves_i.size(); j++)
			{
				field[possible_moves_i[i]][possible_moves_j[i]] = 1;
				field[possible_moves_i[j]][possible_moves_j[j]] = 1;
				if (black_threats(field) > 2)
				{
					i_first->push_back(possible_moves_i[i]);
					j_first->push_back(possible_moves_j[i]);
					i_second->push_back(possible_moves_i[j]);
					j_second->push_back(possible_moves_j[j]);
					return true;

				}
				if (black_threats(field) == 2)
				{
					two_threat_moves_i_first_step.push_back(possible_moves_i[i]);
					two_threat_moves_j_first_step.push_back(possible_moves_j[i]);
					two_threat_moves_i_second_step.push_back(possible_moves_i[j]);
					two_threat_moves_j_second_step.push_back(possible_moves_j[j]);
				}
				field[possible_moves_i[i]][possible_moves_j[i]] = 0;
				field[possible_moves_i[j]][possible_moves_j[j]] = 0;
			}
		}
		if (two_threat_moves_i_first_step.size() == 0)
		{
			return false;
		}
		result = false;
		int copy_field[19][19];
		copy(field, copy_field);

		for (int i = 0; i < two_threat_moves_i_first_step.size();i++)
		{
			field[two_threat_moves_i_first_step[i]][two_threat_moves_j_first_step[i]] = 1;
			field[two_threat_moves_i_second_step[i]][two_threat_moves_j_second_step[i]] = 1;
			conservative_defence(field, two_threat_moves_i_first_step[i], two_threat_moves_j_first_step[i]);
			conservative_defence(field, two_threat_moves_i_second_step[i], two_threat_moves_j_second_step[i]);

			/*	cout << endl;
			print(field);
			cout << endl;
			print(copy_field);
			cout << endl;*/

			result = threat_space_search(field, depth++, i_first, j_first, i_second, j_second);
			copy(copy_field, field);
			if (result == true)
			{
				i_first->push_back(two_threat_moves_i_first_step[i]);
				j_first->push_back(two_threat_moves_j_first_step[i]);
				i_second->push_back(two_threat_moves_i_second_step[i]);
				j_second->push_back(two_threat_moves_j_second_step[i]);
				return true;
			}
		}
		return false;
		//print(copy_field);
	}
	else if (depth > 6)
	{
		return false;
	}

}

