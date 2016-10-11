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
//testcase: a*(b+c)*d    A/B-C+D*E-A*C
class main_to_postfix_function
{
public:
	string oper, output, data;
	main_to_postfix_function();
	void to_postfix();
	bool not_operator(char in);
	void show();

};
main_to_postfix_function::main_to_postfix_function()
{
	cout << "Enter a infix form(EOF to terminate): ";
	while (cin >> data)
	{
		to_postfix();
		cout << "Enter a infix form(EOF to terminate): ";
	}
}
void main_to_postfix_function::to_postfix()
{

	cout << setw(20) << left << "next token" << setw(20) << left << "stack" << setw(20) << left << "output" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		cout << setw(20) << left << data[i];
		if (not_operator(data[i]))
		{
			output.push_back(data[i]);
		}
		else
		{
			if (oper.size() == 0)
			{
				oper.push_back(data[i]);
			}
			else
			{
				if ((oper.back() == '+' || oper.back() == '-') //lower operator encounter the higher priority operator
					&& (data[i] == '*' || data[i] == '/' || data[i] == '('))
				{
					oper.push_back(data[i]);
				}
				else if ((oper.back() == '+' || oper.back() == '-') //lower operator encounter the same priority operator
					&& (data[i] == '+' || data[i] == '-'))
				{
					while ((oper.back() != '*' || oper.back() != '/') && oper.size() > 0)//watch the tricky logic here!!!
					{
						output.push_back(oper.back());
						oper.pop_back();
					}
					oper.push_back(data[i]); //dont forget this one 
				}
				else if (oper.back() == '(')  //the left parentheses has the very lowest priority
				{
					oper.push_back(data[i]);
				}
				else if ((oper.back() == '*' || oper.back() == '/') //higher priority encounter the left parentheses
					&& (data[i] == '('))
				{
					oper.push_back(data[i]);
				}
				else if ((oper.back() == '*' || oper.back() == '/')
					&& (data[i] != ')')) //higher priority meets lower(or equal) and not right parentheses
				{
					while (!((oper.back() == '+' || oper.back() == '-') && (data[i] == '*' || data[i] == '/' || data[i] == '(')) && oper.size() > 0) //watch the tricky logic here!!!
					{
						output.push_back(oper.back());
						oper.pop_back();
					}
					oper.push_back(data[i]); //dont forget this one 
				}
				else if (data[i] == ')')
				{
					while (oper.back() != '(')
					{
						output.push_back(oper.back());
						oper.pop_back();
					}
					oper.pop_back();
				}
			}
		}
		show();
	}
	while (oper.size()) //dump the remaining to the output string
	{
		output.push_back(oper.back());
		oper.pop_back();
	}
	cout << left << setw(20) << "\ndone";
	show();
	cout << left << "\nPostfix expression: " << output << endl;
}
bool main_to_postfix_function::not_operator(char in)
{
	if (in < 48)
		return false;
	else
		return true;
}
void main_to_postfix_function::show()
{
	if (oper.size())
	{
		cout << setw(20) << left << oper;
	}
	else
	{
		cout << setw(20) << left << "empty";
	}

	if (output.size())
	{
		cout << setw(20) << left << output;
	}
	else
	{
		cout << setw(20) << left << "none";
	}
	cout << endl;
}
