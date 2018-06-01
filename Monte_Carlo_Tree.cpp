#include "stdafx.h"
#include "Vars.h"

void Hydra(Node* root)
{

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (root->state.copy_board[i][j] == 1 || root->state.copy_board[i][j] == 2)
			{
				root->state.p_moves(i, j);
			}
		}
	}
	root->state.possible_moves();
	for (int i = 0; i < root->state.i_possible_index.size(); i++)
	{
		for (int j = i + 1; j < root->state.j_possible_index.size(); j++)
		{
			root->state.make_move(root->state.i_possible_index[i], root->state.j_possible_index[i], root->Player);
			root->state.make_move(root->state.i_possible_index[j], root->state.j_possible_index[j], root->Player);
			//cur_node->state.print();
			//cout << endl;
			Node1* cur = new Node1(root->state, root->Opponent);
			root->Children.push_back(cur);
			root->state.miss_move(root->state.i_possible_index[i], root->state.j_possible_index[i]);
			root->state.miss_move(root->state.i_possible_index[j], root->state.j_possible_index[j]);
		}
	}
}

void RandomPlays(Node1* Child)
{
	for (int i = 0; i < 1000; i++)
	{
		//cout << endl;
		int steps = 0;
		Node1* cur_node = Child;
		while (cur_node->state.end_game() == 1 && steps < 30)
		{
			Node1* c_node;
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (cur_node->state.copy_board[i][j] == 1 || cur_node->state.copy_board[i][j] == 2)
					{
						cur_node->state.p_moves(i, j);
					}
				}
			}
			cur_node->state.possible_moves();
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dist(1, cur_node->state.i_possible_index.size() - 1);
			int a = dist(gen);
			int b = dist(gen);
			while (b == a)
			{
				b = dist(gen);
			}
			cur_node->state.make_move(cur_node->state.i_possible_index[a], cur_node->state.j_possible_index[a], cur_node->Player);
			cur_node->state.make_move(cur_node->state.i_possible_index[b], cur_node->state.j_possible_index[b], cur_node->Player);

			c_node = new Node1(cur_node->state, cur_node->Opponent);
			//c_node->state.print();
			c_node->Parent = cur_node;
			cur_node->Child = c_node;
			cur_node->state.miss_move(cur_node->state.i_possible_index[a], cur_node->state.j_possible_index[a]);
			cur_node->state.miss_move(cur_node->state.i_possible_index[b], cur_node->state.j_possible_index[b]);
			cur_node->state.i_possible_index.clear();
			cur_node->state.j_possible_index.clear();
			cur_node = c_node;
			//cout << endl;
			steps++;
		}
		if (cur_node->state.end_game() == 10)
		{
			Child->Wins1++;
		}
		else if (cur_node->state.end_game() == -10)
		{
			Child->Wins2++;
		}
		else if (cur_node->state.end_game() == 0 || cur_node->state.end_game() == 1)
		{
			Child->Draw++;
		}
		cur_node = cur_node->Parent;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (cur_node; cur_node != Child->Child;cur_node = cur_node->Parent)
		{
			delete cur_node->Child;
		}
		delete Child->Child->Child;

	}
}

void MonteCarlo(Node* root,int board[19][19])
{
	for (int i = 0; i < root->Children.size(); i++)
	{
		RandomPlays(root->Children[i]);
	}
	int a = 0;
	double best = 0;
	for (int i = 0; i < root->Children.size(); i++)
	{
		if ((root->Children[i]->Wins2 / (root->Children[i]->Wins1+root->Children[i]->Draw)) > best)
		{
			best = root->Children[i]->Wins1 / root->Children[i]->Wins2;
			a = i;
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board[i][j] = root->Children[a]->state.copy_board[i][j];
		}
	}	
}


