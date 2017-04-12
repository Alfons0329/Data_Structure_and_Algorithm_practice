#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;


class relation
{
public:
	int x;
	int y;
	bool traversed; //determine whether the relation is traversed or not
};

class equivalence_main
{
public:
	equivalence_main()
	{

	}
	vector<relation> int_relation;
	vector<vector<int>> equivalence_relation;
	void input();
	void find();
	void print_result();

	int step;
};
void equivalence_main::input() //Relation IO part
{
	int cnt;
	relation tmp_relation;
	tmp_relation.traversed = false;
	cout << "How many equivalent relations: ";
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> tmp_relation.x >> tmp_relation.y;
		int_relation.push_back(tmp_relation);
	}
	find();
}

void equivalence_main::find()
{
	vector<int> process; //to imitate stack
	vector<int> tmp_store;
	bool quit1,quit2;
	int index = 0;
	int cnt_relations = int_relation.size(),start; //for timp complexity analysis
	step = 0;
	while (cnt_relations > 0)
	{
		tmp_store.clear(); //clear EACH SAME Equivalent relation container
		for (int i = 0; i < int_relation.size(); i++)//push back first
		{
			if (!int_relation[i].traversed)
			{
				process.push_back(int_relation[i].x);
				tmp_store.push_back(int_relation[i].x);
				start = i;
				index = start;
				break;
			}
			
		}
		while (process.size() > 0)
		{
			index = start;
			for (; index < int_relation.size(); index++)
			{
				if ((int_relation[index].x == process.back() || int_relation[index].y == process.back()) && (!int_relation[index].traversed))
				{
					step++;
					cout << "Index is now : " << index << " stack is : ";
					for (int i = 0; i < process.size(); i++)
					{
						cout << process[i] << " ";
					}
					cout << endl;
					if (int_relation[index].x == process.back())
					{
						if (process.size()>1)
						{
							process.pop_back();
						}
						process.push_back(int_relation[index].y);
						tmp_store.push_back(int_relation[index].y);
						int_relation[index].traversed = true;
					}
					else
					{
						if (process.size()>1)
						{
							process.pop_back();
						}
						process.push_back(int_relation[index].x);
						tmp_store.push_back(int_relation[index].x);
							int_relation[index].traversed = true;
					}
					
				}
				else if (process.size()==2) 
				/*This is tricky since the stack's size wont exceed 2 , and if there's nothing matching with the top element and the cyrrent relation
				we should search other untraversed relations for the top element to determine whether it can still match or not
				*/
				{   //quit1 one flag for the top is unmatch with the rest untraversed relations 
					//quit2 is for the botton (only 2 element for the stack in whole process)
					quit1 = true;  //assume there is no matching for the rest untraversed relations
					
					for (int i = 0; i < int_relation.size(); i++)
					{
						if ((int_relation[i].x == process.back() || int_relation[i].y == process.back()) && (!int_relation[i].traversed))
						{
							index = i-1;
							quit1 = false; //if found any match relation , we should head there and set the index there-1(after the upper for will+1 / watch the tricky part)
							break;
						}
					}
					if (quit1)//pop the top for search the match of the rest ,namely the bottom element to see match with the rest untraversed relations or not
					{
						process.pop_back();
					}
					quit2 = true; //same idea with quit1's application
					for (int i = 0; i < int_relation.size(); i++)
					{
						if ((int_relation[i].x == process.back() || int_relation[i].y == process.back()) && (!int_relation[i].traversed))
						{
							index = i-1;
							quit2 = false;
							break;
						}
					}
				}
			}
			if (quit1&&quit2) //if quit1 and qui2 both true , means current equivalence class are all included, clean the current one and back to find next eq class relation
			{
				cout << "One of the eq class is found!!! " << endl;
				process.clear();
				break;
			}

		}
		equivalence_relation.push_back(tmp_store); //dump the found relations to result container
		cnt_relations -= tmp_store.size(); //IMPORTANT !!!minus the found relations
	}
	print_result();
}
void equivalence_main::print_result()
{
	cout << "Equivalence relations are: " << endl;
	for (int i = 0; i < equivalence_relation.size(); i++)
	{
		for (int j = 0; j < equivalence_relation[i].size(); j++)
		{
			cout << equivalence_relation[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "Total steps: " << step << endl;
}