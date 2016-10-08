
#include<stdio.h>
#include <cstdlib>
#include<math.h>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
char maze[12][13] =  //not 12*12 since need 0\ for end at each row
{ { "############" },
{ "#...#......#" },
{ "..#.#.####.#" },
{ "###.#....#.#" },
{ "#....###.#.." },
{ "####.#.#.#.#" },
{ "#..#.#.#.#.#" },
{ "##.#.#.#.#.#" },
{ "#........#.#" },
{ "######.###.#" },
{ "#......#...#" },
{ "############" } };
class main_maze_function
{
public:

	int start_row, start_col, end_row, end_col;
	bool unsol, retry;
	vector<int> path_row, path_col;

	main_maze_function()
	{
		start_row = 2, start_col = 0, end_row = 4, end_col = 11;
		unsol = false, retry = false;
		show_map();

	}
	void solver()  //DFS but not recursive solution
	{

		int row = start_row, col = start_col;
		system("cls");
		system("pause");
		show_map();
		path_row.push_back(start_row);
		path_col.push_back(start_col);
		while (1)
		{
			show_map();
			system("pause");
			system("cls");
			if (path_row.at(path_row.size() - 1) == end_row&&path_col.at(path_col.size() - 1) == end_col)
			{
				cout << "Reach exit! " << endl;
				break;
			}
			else if (maze[row - 1][col] == '.')
			{
				row--;
				maze[row][col] = '@';
				path_row.push_back(row);
				path_col.push_back(col);
			}
			else if (maze[row + 1][col] == '.')
			{
				row++;
				maze[row][col] = '@';
				path_row.push_back(row);
				path_col.push_back(col);
			}
			else if (maze[row][col + 1] == '.')
			{
				col++;
				maze[row][col] = '@';
				path_row.push_back(row);
				path_col.push_back(col);
			}
			else if (maze[row][col - 1] == '.')
			{
				col--;
				maze[row][col] = '@';
				path_row.push_back(row);
				path_col.push_back(col);
			}
			else
			{
				cout << "Get stucked!!" << endl;
				retry = false;
				for (int i = 0, j = 0;; i++, j++) // find the past path
				{
					if (maze[path_row.at(i) - 1][path_col.at(i)] == '.')
					{
						row = path_row.at(i);
						col = path_col.at(i);
						retry = true;
						break;
					}
					else if (maze[path_row.at(i) + 1][path_col.at(i)] == '.')
					{
						row = path_row.at(i);
						col = path_col.at(i);
						retry = true;
						break;
					}
					else if (maze[path_row.at(i)][path_col.at(i) - 1] == '.')
					{
						row = path_row.at(i);
						col = path_col.at(i);
						retry = true;
						break;
					}
					else if (maze[path_row.at(i)][path_col.at(i) + 1] == '.')
					{
						row = path_row.at(i);
						col = path_col.at(i);
						retry = true;
						break;
					}
					if (!retry&&i == path_row.size() - 1)
					{
						unsol = true;
						break;
					}
				}
			}
			if (unsol)
			{
				break;
			}
		}
	}
		void show_map()
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					cout << maze[i][j];
				}
				cout << endl;
			}
		}
		void show_solution()
		{

			if (!unsol)
			{
				cout << "Map traverse walked path (mouse DFS): ";
				for (int i = 0; i < path_row.size(); i++)
				{
					cout << path_row[i] << "," << path_col[i] << "->";
				}
			}
			else
			{
				cout << "No solution for maze" << endl;
			}

		}
	};

