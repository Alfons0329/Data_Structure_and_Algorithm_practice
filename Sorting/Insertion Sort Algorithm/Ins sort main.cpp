#include <iostream>
#include <vector>
using namespace std;
int step;
void print_arr(vector<int> comin)
{
	for (int i = 0; i < comin.size(); i++)
	{
		cout << comin[i] << " ";
	}
	cout << endl;
}
void ins_sort(vector<int> comin)
{
	int tmp;
	step = 0;
	for (int i = 1; i < comin.size(); i++)
	{
		for (int j = i ; j > 0; j--)
		{
			
			if (comin[j] < comin[j-1])
			{
				swap(comin[j-1], comin[j]);
			}
			else
			{
				break;
			}
		}
		print_arr(comin);
	}
	print_arr(comin);
}

int main()
{
	int tmp;
	vector<int> data;
	while (cin >> tmp)
	{
		data.push_back(tmp);
	}
	ins_sort(data);
	system("pause");
	return 0;
}