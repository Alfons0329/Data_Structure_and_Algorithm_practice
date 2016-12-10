#include <iostream>
using namespace std;
void mergesort_merge(int data[], int start, int mid,const int end)
{
	int* temp=new int [end];
	int left_ptr = start, right_ptr = mid + 1,index=start;
	while (left_ptr <= mid&&right_ptr <= end)
	{
		if (data[left_ptr] <= data[right_ptr])
		{
			temp[index] = data[left_ptr];
			left_ptr++;
		}
		else
		{
			temp[index] = data[right_ptr];
			right_ptr++;
		}
		index++;
	}
	if (left_ptr > mid)
	{
		for (int i = right_ptr; i <= end; i++)
		{
			temp[index] = data[i];
			index++;
		}
	}
	else
	{
		for (int i = left_ptr; i <= mid; i++)
		{
			temp[index] = data[i];
			index++;
		}
	}
	for (int i = start; i <= end; i++)
	{
		data[i] = temp[i];
	}
}
void mergesort_split(int data[], int start,int end)
{

	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort_split(data, start, mid);
		mergesort_split(data, mid + 1, end);
		mergesort_merge(data, start, mid, end);
	}
	else
		return;

}
void print_arr(int data[],int size)
{
	cout<<"After quick sort ";
	for (int i = 0; i <= size; i++)
	{
		cout << data[i] << " ";
	}
}
int main()
{
	int tc,tmp;
	int *data;
	cout << "Merge sort algorithm, how many data?";
	cin >> tc;
	data = new int[tc];
	for (int i = 0; i < tc; i++)
	{
		cin >> tmp;
		data[i] = tmp;
	}
	mergesort_split(data, 0, tc - 1);
	print_arr(data,tc-1);

	return 0;
}

