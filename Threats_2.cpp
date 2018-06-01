#include"stdafx.h"
#include"vars.h"
void empty_points_v2(int arr[19][19], int i, int j)
{
	if (((arr[i][j + 1] == 0) || (arr[i][j + 1] == 3)) && (j + 1 < 19))
	{
		arr[i][j + 1] = 3;
	}
	if (((arr[i][j + 2] == 0) || (arr[i][j + 2] == 3)) && (j + 2 < 19))
	{
		arr[i][j + 2] = 3;
	}	
	if ((j - 1 > -1) && ((arr[i][j - 1] == 0) || (arr[i][j - 1] == 3)))
	{
		arr[i][j - 1] = 3;
	}
	if ((j - 2 > -1) && ((arr[i][j - 2] == 0) || (arr[i][j - 2] == 3)))
	{
		arr[i][j - 2] = 3;
	}	
	if (((arr[i + 1][j] == 0) || (arr[i + 1][j] == 3)) && (i + 1 < 19))
	{
		arr[i + 1][j] = 3;
	}
	if (((arr[i + 2][j] == 0) || (arr[i + 2][j] == 3)) && (i + 2 < 19))
	{
		arr[i + 2][j] = 3;
	}	
	if ((i - 1 > -1) && ((arr[i - 1][j] == 0) || (arr[i - 1][j] == 3)))
	{
		arr[i - 1][j] = 3;
	}
	if ((i - 2 > -1) && ((arr[i - 2][j] == 0) || (arr[i - 2][j] == 3)))
	{
		arr[i - 2][j] = 3;
	}	
	if (((arr[i + 1][j + 1] == 0) || (arr[i + 1][j + 1] == 3)) && (i + 1 < 19) && (j + 1 < 19))
	{
		arr[i + 1][j + 1] = 3;
	}
	if (((arr[i + 2][j + 2] == 0) || (arr[i + 2][j + 2] == 3)) && (i + 2 < 19) && (j + 2 < 19))
	{
		arr[i + 2][j + 2] = 3;
	}	
	if ((j - 2 > -1) && (i - 2 > -1) && ((arr[i - 2][j - 2] == 0) || (arr[i - 2][j - 2] == 3)))
	{
		arr[i - 2][j - 2] = 3;
	}
	if ((j - 1 > -1) && (i - 1 > -1) && ((arr[i - 1][j - 1] == 0) || (arr[i - 1][j - 1] == 3)))
	{
		arr[i - 1][j - 1] = 3;
	}	
	if ((j + 1 < 19) && (i - 1 > -1) && ((arr[i - 1][j + 1] == 0) || (arr[i - 1][j + 1] == 3)))
	{
		arr[i - 1][j + 1] = 3;
	}
	if ((j + 2 < 19) && (i - 2 > -1) && ((arr[i - 2][j + 2] == 0) || (arr[i - 2][j + 2] == 3)))
	{
		arr[i - 2][j + 2] = 3;
	}	
	if ((i + 2 < 19) && (j - 2 > -1) && ((arr[i + 2][j - 2] == 0) || (arr[i + 2][j - 2] == 3)))
	{
		arr[i + 2][j - 2] = 3;
	}	
	if ((i + 1 < 19) && (j - 1 > -1) && ((arr[i + 1][j - 1] == 0) || (arr[i + 1][j - 1] == 3)))
	{
		arr[i + 1][j - 1] = 3;
	}	
	if ((i + 2 < 19) && (j - 1 > -1) && ((arr[i + 2][j - 1] == 0) || (arr[i + 2][j - 1] == 3)))
	{
		arr[i + 2][j - 1] = 3;
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
	if ((j + 2 < 19) && (i + 1 < 19) && ((arr[i + 1][j + 2] == 0) || (arr[i + 1][j + 2] == 3)))
	{
		arr[i + 1][j + 2] = 3;
	}	
	if ((j + 2 < 19) && (i - 1 > -1) && ((arr[i - 1][j + 2] == 0) || (arr[i - 1][j + 2] == 3)))
	{
		arr[i - 1][j + 2] = 3;
	}	
	if ((i + 1 < 19) && (j - 2 > -1) && ((arr[i + 1][j - 2] == 0) || (arr[i + 1][j - 2] == 3)))
	{
		arr[i + 1][j - 2] = 3;
	}	
	if ((j - 2 > -1) && (i - 1 > -1) && ((arr[i - 1][j - 2] == 0) || (arr[i - 1][j - 2] == 3)))
	{
		arr[i - 1][j - 2] = 3;
	}
}

void best_move_v2(int field[19][19], int field1[19][19], int i, int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j)
{

	if (i == 2)
	{
		copy(field, field1);
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field1[i][j] == 2)
				{
					empty_points_v2(field1, i, j);
				}
			}
		}
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
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (field1[i][j] == 2)
				{
					empty_points_v2(field1, i, j);
				}
			}
		}
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

void attack_2(int field[19][19], int field1[19][19],int* current_step1_i, int* current_step1_j, int* current_step2_i, int* current_step2_j)
{
	if ((white_threats(field) == 0) && (black_threats(field) == 0))
	{
		vector <int> results;
		vector <int> i_indexes;
		vector <int> j_indexes;
		
		all_p_moves3(field, field1);
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
		int x = 0;
		if (i_indexes.size() >= 2 )
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
					if ((abs(i_indexes[i] - i_indexes[j])<= 5) && (j_indexes[i] == j_indexes[j]))
					{
						results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));
					}
					else if ((abs(j_indexes[i] - j_indexes[j]) <= 5) && (i_indexes[i] == i_indexes[j]))
					{
						results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));
					}
					else if ((abs(j_indexes[i] - j_indexes[j]) <= 5) && (abs(i_indexes[i] - i_indexes[j])<= 5) && (abs(i_indexes[i] - i_indexes[j]) == (abs(j_indexes[i] - j_indexes[j]))))
					{
						results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));
					}
					else
					{
						results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]) + quick_window(field1, i_indexes[j], j_indexes[j]));
					}
					//results.push_back(quick_window(field1, i_indexes[i], j_indexes[i]));					
					first_step_i.push_back(i_indexes[i]);
					first_step_j.push_back(j_indexes[i]);
					second_step_i.push_back(i_indexes[j]);
					second_step_j.push_back(j_indexes[j]);
					field1[i_indexes[i]][j_indexes[i]] = 0;
					field1[i_indexes[j]][j_indexes[j]] = 0;
				}
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
			if (results[number] >= 2)
			{
				field[first_step_i[number]][first_step_j[number]] = 1;
				*current_step1_i = first_step_i[number];
				*current_step1_j = first_step_j[number];
				field[second_step_i[number]][second_step_j[number]] = 1;
				*current_step2_i = second_step_i[number];
				*current_step2_j = second_step_j[number];
			}
			else if ( results[number] < 2)
			{
				x++;
			}
		}
			
			if ((i_indexes.size() < 2) || (x == 1))
			{
				best_move_v2(field, field1, 2, current_step1_i, current_step1_j, current_step2_i, current_step2_j);
				// не знаю работает ли
				x = 0;
			}
	}	
	else if ((white_threats(field) != 0) && (black_threats(field) == 0))
	{
		int steps = def_sliding_window(field, current_step1_i, current_step1_j, current_step2_i, current_step2_j);// вроде работет
		best_move_v2(field, field1, steps, current_step1_i, current_step1_j, current_step2_i, current_step2_j);// не знаю работет ли
	}
	else if (black_threats(field) != 0)
	{
		make_six(field, current_step1_i, current_step1_j, current_step2_i, current_step2_j);// вроде работает
	}

}