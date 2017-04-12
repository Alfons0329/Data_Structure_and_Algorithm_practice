#include <iostream>
#include <vector>
using namespace std;

class equi_class
{
public:
	equi_class()
	{
		input();
	}
	void input();
	void initlialize_itself_as_parent();
	void union_find();
	int trace_origin(int);
	void print_all_equi_class();
	vector<int> parent;
};

void equi_class::input()
{
	int cnt, tmpx, tmp_parent;
	cout << "Num of elements: ";
	cin >> cnt;
	parent.resize(cnt);
	cout << "Num of relations: ";
	cin >> cnt;
	initlialize_itself_as_parent();
	for (int i = 0; i < cnt; i++)
	{
		cout << "Enter the element and its parent: ";
		cin >> tmpx >> tmp_parent;
		if (tmp_parent > tmpx)
			swap(tmp_parent, tmpx);

		parent[tmpx] = tmp_parent;
	}

	union_find();
	print_all_equi_class();
}
void equi_class::initlialize_itself_as_parent()
{
	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}
}
void equi_class::union_find()
{
	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = trace_origin(i);
	}
}
int equi_class::trace_origin(int in)
{
	int leader, in_parent = parent[in]; //store such as 1-->5-->3-->2 we store 1
	while (in != parent[in]) //set the node to the top most leader
	{
		in = parent[in];
	}
	leader = in;
	while (parent[in_parent] != leader) //collapsing rule
	{
		int tmp = parent[in_parent];
		in_parent = parent[in_parent];
		parent[tmp] = leader;
	}

	return leader;
}
void equi_class::print_all_equi_class()
{
	int print_cnt = 0;
	cout << "Parent of each element from 0 to " << parent.size()<<" is ";
	for (int i = 0; i < parent.size(); i++)
	{
		cout << parent[i] << " ";
	}
	cout << "Equivalence classes are: ";
	for (int i = 0; i < parent.size(); i++)
	{	
		if (parent[i]>-999)
		{
			cout << i << " ";
			for (int j = i+1; j < parent.size(); j++)
			{
				if (parent[i] == parent[j])
				{
					cout << j << " ";
					parent[j] = -1000;
				}
			}
			cout << endl;
		}	
	}

	system("pause");
}