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
#include <iomanip>
using namespace std;
class kmp_functions
{
public:
	kmp_functions();
	bool match;
	int match_pos;
	void kmp_exec();
	string sentence, pat; //fail_func_str;
	vector<int>fail_func_int, fail_func_int_from_minus_one;
	void fail_function();
	void show_result();
	void kmp_str_match();
};
kmp_functions::kmp_functions()
{
	kmp_exec();
}
void kmp_functions::kmp_exec()
{

	cout << "Enter a sentence for KMP algorithm(EOF to terminate) .: ";
	while (cin >> sentence)
	{
		pat.clear();
		fail_func_int.clear();
		fail_func_int_from_minus_one.clear();
		cout << "Enter a pattern to find.: ";
		cin >> pat;
		fail_function();
		show_result();
		kmp_str_match();
		cout << "\nEnter a sentence for KMP algorithm(EOF to terminate) .: ";

	}


}
void kmp_functions::fail_function()
{
	int i = 1, j = 0;
	fail_func_int.resize(pat.size());
	fail_func_int[0] = 0;
	for (; pat[i] != pat[j] && i < pat.size();)//dont forget the border check for i first initilaization 
	{
		fail_func_int[i] = 0;
		i++;
	}
	while (i < pat.size())
	{
		if (pat[j] == pat[i])
		{
			fail_func_int[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			while (pat[j] != pat[i])
			{
				if (!j)//boundary check if j goes to the LHS most
				{
					j = 0;
					i++;
					break;
				}
				if (j == 1)
				{
					j--;
					j = fail_func_int[j];
				}
				else if (j > 1)
				{
					j--;
					j = fail_func_int[j];
				}

			}
		}
	}
	for (int k = 0; k < fail_func_int.size(); k++)
	{
		fail_func_int_from_minus_one.push_back(fail_func_int[k] - 1);
	}
}
void kmp_functions::kmp_str_match()
{
	match = false, match_pos = 0;
	int i = 0, j = 0; //i for sentence and j for pattern
	while (i < sentence.size() && j < pat.size())
	{
		
		if (sentence[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j)
			{
				j = fail_func_int[j - 1];
			}
			else
			{
				i++;  //no previous one can be used for re-locate j 's position
			}
		}
		if (j == pat.size() - 1)
		{
			match = true;
			break;
		}
		if (i == sentence.size() - 1 && j != pat.size() - 1)
		{
			match = false;
			break;
		}
	}
	if (match)
	{
		cout << "\nPattern match in sentence !"<< endl;
	}
	else
	{
		cout << "\nPattern does not match in sentence !" << endl;
	}

}
void kmp_functions::show_result()
{
	cout << "Fail function: " << endl;
	for (int i = 0; i < fail_func_int.size(); i++)
	{
		cout << right << setw(2) << fail_func_int[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < fail_func_int_from_minus_one.size(); i++)
	{
		cout << right << setw(2) << fail_func_int_from_minus_one[i] << " ";
	}
}