#include <iostream>
#include <vector>
using namespace std;
int maxbit(vector<int> data) //Get the maxbit in the given data to constraint the sorting algorithm's boundary.
{
	int  div10_power = 0;
	int max_data = data[0];
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i]>max_data)
			max_data = data[i];
	}
	while ((max_data / (int)pow(10, div10_power)))
	{
		div10_power++;
	}
	//cout << "Max bit in the data " << div10_power <<"  And max data in it  "<<max_data<<endl;
	return div10_power;
}
vector<int> radix_sort(vector<int> data)
{
	bool isfinished = false;
	int mod10_power = 1, div10_power = 0,max_bit=maxbit(data);
	vector<vector<int>> temp_radix; //Radix from 0~9 for the digit of the numbers
	//Row from 0~9 (the radix) and each row have some column act as linked list to store the data according to the current radix
	while (mod10_power<=max_bit)
	{
		temp_radix.resize(10);
		for (unsigned int i = 0; i < data.size(); i++) //get the digit number starts from the LSD and then increment the power of 10mod and 10div
		{
			temp_radix[(data[i] % (int)pow(10, mod10_power)) / (int)pow(10, div10_power)].push_back(data[i]);
		}
		//Paste the temp_radix array to the original data array and do again sorting the next base of those integers
		data.clear();
		for (int i = 0; i < temp_radix.size(); i++)
		{
			if (temp_radix[i].size())
			{
				for (int j = 0; j < temp_radix[i].size(); j++)
				{
					data.push_back(temp_radix[i][j]);
				}
			}
		}

		if (mod10_power != max_bit) //always clear the temp_radix since next time it have to be REarrange accoding the next base of integers
		{
			temp_radix.clear();
		}
		mod10_power++;
		div10_power++;	
	}
	
	return data;
}

void print_arr(vector<int> data)
{
	cout << "After radix sort: ";
	for (unsigned int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
}
int main()
{
	int tc,tmp;
	vector<int>data;
	cout << "Radix Sort Algorithm ,How many data?";
	cin >> tc;
	cout << "Input " << tc << " data";
	for (int i = 0; i < tc; i++)
	{
		cin >> tmp;
		data.push_back(tmp);
	}
	data=radix_sort(data);
	print_arr(data);
	system("pause");
	return 0;
}