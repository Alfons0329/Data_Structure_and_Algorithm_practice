#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#define MAX 1000000;
int* fail_func_ptr;
int result[1000000], pat_size;
char* pat_ptr;
char input[1000000];
using namespace std;
void print_result(int ind_ma)
{
	cout << ind_ma +1<< endl;
	for (int i = 0; result[i] != -1; i++)
	{
		cout << result[i] << " ";
	}
}
int str_match()
{
	int sentence_size = 0, i = 0, j = 0, word_count = 1, match_independent = 0, result_count = 0;
	bool match = false;
	for (int i = 0; input[i] != '@'; i++)
	{
		sentence_size++;
	}

	while (i < sentence_size&&j < pat_size)
	{
		cout << "I is now " << i <<"J is now "<<j<< endl;
		if (input[i] == pat_ptr[j])
		{
			i++;
			j++;

		}
		else
		{
			if (input[i] == ' ' && (input[i + 1] >= 'a') && (input[i + 1] <= 'z'))
			{
				word_count++;
				input[i] = '@'; //IMPORTANT!!! flag for no duplicated count
			}
			if (j)
			{
				j = fail_func_ptr[j - 1];
			}
			else
			{
				i++;  //no previous one can be used for re-locate j 's position
			}

		}

		if (j == pat_size)
		{
			match = true;
			j = 0;
			if ((input[i] >= 'a') && (input[i] <= 'z')) //back 1 space for the case like aa and find in aaa
			{
				i--;
			}
				
		}
		
		if (match)
		{
			if (i != sentence_size && ((input[i]==' '||input[i]=='?'||input[i]==','||input[i]=='.')&&( input[i - pat_size - 1] == ' ' || input[i - pat_size - 1] == '@')))
			{
				//cout << "Match independent " << i << endl;
				match_independent++;
			}
			if (i == sentence_size-1 && (input[i - pat_size - 1] == ' ' || input[i - pat_size - 1] == '@')) // tricky and special condition when it comes to final position
				//and still have a match will need to use this judge
			{
				match_independent++;
			}
			result[result_count] = word_count;
			match = false;
			result_count++;
		}
	}
	return match_independent;
}

void fail_func()
{
	int i = 0, j = 0;
	pat_size = 0;
	for (; input[i] != ' '; i++)
	{
		fail_func_ptr = new int;
		pat_ptr = new char;
		pat_size++;

	}
	for (i = 0; i < pat_size; i++)
	{
		pat_ptr[i] = input[i];
	}
	i = 1;
	fail_func_ptr[0] = 0;
	for (; input[i] != input[j] && i < pat_size;)
	{
		fail_func_ptr[i] = 0;
		i++;
	}
	while (i < pat_size)
	{
		if (input[j] == input[i])
		{
			fail_func_ptr[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			while (input[j] != input[i])
			{
				if (!j)//boundary check if j goes to the LHS most
				{
					j = 0;
					i++;
					break;
				}
				else if (j >= 1)
				{
					j--;
					j = fail_func_ptr[j];
				}

			}
		}
	}
}
int main()
{
	string open, out;
	ifstream fptr; 
	cout << "Enter file name I_O: ";
	cin >> open >> out;
	fptr.open(open);
	//initilaize the array
	memset(input, '@', sizeof(input));
	memset(result, -1, sizeof(result));

	int i = 0, independent_match;
	//open file and get data from it
	while (fptr.get(input[i]))
	{
		i++;
	}
	for (int i = 0; input[i] != '@'; i++)
		cout << input[i];
	//kmp execution for whole text
	fail_func();
	independent_match = str_match();
	print_result(independent_match);
	//output file
	ofstream ofptr(out);
		ofptr << independent_match +1<< endl;

	for (int i = 0; result[i] != -1; i++)
	{
		ofptr << result[i];
	}
	//Dont forget to close file :3
	fptr.close();  
	ofptr.close();
	system("pause");
	return 0;
}