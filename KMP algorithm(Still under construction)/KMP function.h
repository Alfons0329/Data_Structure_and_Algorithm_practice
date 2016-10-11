#include<stdio.h>
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
class kmp_functions
{
public:
	kmp_functions();
	void kmp_exec();
	string sentence, pat; //fail_func_str;
	vector<int>fail_func_int,fail_func_int_from_minus_one;
	void fail_function();
};
kmp_functions::kmp_functions()
{
	
	cout << "Enter a sentence for KMP algorithm(EOF to terminate) .: ";
	while (cin >> sentence)
	{
		pat.clear();
		fail_func_int.clear();
		fail_func_int_from_minus_one.clear();
		cout << "Enter a pattern to find.: ";
		cin >> pat;
		kmp_exec();
		cout << "\nEnter a sentence for KMP algorithm(EOF to terminate) .: ";
	}
	
}
void kmp_functions::kmp_exec()
{
	fail_function();
	for (int i = 0; i < fail_func_int.size(); i++)
	{
		cout << fail_func_int[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < fail_func_int_from_minus_one.size(); i++)
	{
		cout << fail_func_int_from_minus_one[i] << " ";
	}
}
void kmp_functions::fail_function()
{
	int i = 1, j = 0;
	fail_func_int.resize(pat.size());
	fail_func_int[0] = 0;
	//cout << "i now at :"; //debugging purpose
	for (; pat[i] != pat[j]&&i<pat.size();)//dont forget the border check for i 
	{
		fail_func_int[i] = 0;
		i++;
		//cout << i << " ";
	}
	cout << endl;
	while (i < pat.size())
	{
		//cout<<"i and j at" << i << "," << j<<" ";
		//system("pause");
		if (pat[j] == pat[i])
		{
			//cout << "same" << endl;
			fail_func_int[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			while (pat[j] != pat[i])
			{
				//cout << "not same" << endl;
				
				if (!j)//boundary check if j goes to the LHS most
				{
					j = 0;
					i++;
					break;
				}
				if (j == 1)
				{
					j--;
					fail_func_int[i] = fail_func_int[j];
					i++;
					break;
				}
				else if (j>1)
				{
					j--;
					j = fail_func_int[j];
				}
				
			}
		}
	}
	//just for easier to output loooool;
	for (int k = 0; k < fail_func_int.size(); k++)
	{
		fail_func_int_from_minus_one.push_back(fail_func_int[k] - 1);
	}
}