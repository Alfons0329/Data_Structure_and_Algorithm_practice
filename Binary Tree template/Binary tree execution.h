#include<stdio.h>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include "Binary tree header.h"
using namespace std;
class bin_tree_exec
{
public:
	bin_tree_exec();
	~bin_tree_exec();

	template <typename T>
	command_control(bin_tree_main<T>&);

	int command, type_selection;


};

bin_tree_exec::bin_tree_exec()
{
	cout << "What type of binary tree ? 0:int ,1:double ,2:string ";
	cin >> type_selection;
	switch (type_selection)
	{
		case 0:
		{
			  bin_tree_main<int> bin_tree_int;
			  command_control(bin_tree_int);
			  break;
		}
		case 1:
		{
			  bin_tree_main<double> bin_tree_dou;
			  command_control(bin_tree_dou);
			  break;
		}
		case 2:
		{
			  bin_tree_main<string> bin_tree_str;
			  command_control(bin_tree_str);
			  break;
		}
		default:
		{
			   cout << "Wrong input, please try again.";
			   break;
		}
	}
}
template <typename T>
bin_tree_exec::command_control(bin_tree_main<T>& bin_tree)
{
	cout << "Command: 1 build tree ,2 ";
	while (cin >> command)
	{

	}
}
