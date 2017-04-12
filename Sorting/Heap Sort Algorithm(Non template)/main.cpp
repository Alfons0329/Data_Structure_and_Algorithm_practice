#include <iostream>
using namespace std;
void print_arr(int data[], const int end)
{
	cout << "After heap sort: ";
	for (int i = 0; i < end; i++)
	{
		cout << data[i] << " ";
	}
}
void max_heapify(int data[], const int parent_start, const int data_end)
{
	int parent_index=parent_start, child_index=2*parent_index;
	while (child_index <= data_end)
	{
		if (data[parent_index] > data[child_index] && data[parent_index] > data[child_index + 1])
		{
			break;
		}
		if (data[child_index] > data[child_index + 1]) //L child is bigger
		{
			swap(data[parent_index], data[child_index]);
		}
		else  //R child is bigger
		{
			swap(data[parent_index], data[child_index+1]);
			child_index++;
		}
		//moving down keep swapping to the boundary
		parent_index = child_index;
		child_index *= 2;
	}
}
int* heap_sort(int data[], const int start, const int end)
{
	//initialize the input array to be the max heap
	int heap_size = end;
	int* sorted_data;
	sorted_data = new int[heap_size];
	for (int i = (heap_size / 2); i >= start; i--) //there are only half the nodes
	//are non leaves for swapping
	{
		max_heapify(data, i, end);
	}
	//do heap sorting
	for (; heap_size>=1;)
	{
		sorted_data[heap_size-1] = data[1];　//this takes the largest from heap structure
		data[1] = data[heap_size]; //take the last element and re-max heapify
		heap_size--; // here takes n time
		for (int i = heap_size / 2; i >= 1; i--) //adjust from the last parent
		{
			max_heapify(data,i, heap_size); //max heapify is a tree structure, takes logn time
		}
	}
	return sorted_data;  //n*logn is the final time complexity
}

int main()
{
	int* data;
	int* sorted_data;
	int tc, tmp;
	cout << "Heap Sort Algorithm How many data?";
	cin >> tc;
	cout << "Input " << tc << " data:";
	data = new int[tc];
	for (int i = 1; i <= tc; i++) //data[0]=NULL in heap structure
	{
		cin >> tmp;
		data[i] = tmp;
	}
	sorted_data=heap_sort(data, 1, tc);
	print_arr(sorted_data, tc);
	system("pause");
	return 0;
}
