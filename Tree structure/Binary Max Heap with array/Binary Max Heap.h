#include<stdio.h>
#include<math.h>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include <stdexcept>
using namespace std;
template <typename T>
class max_heap_arr
{
	friend class heap_main;
public:
	max_heap_arr()
	{
		max_heap.push_back(NULL);
	}
	bool is_powoftwo(int);
	void create_max_heap();
	T pop_max();
	void print();
private:
	vector<T> max_heap;

	int step, level;
};
template <typename T>
bool max_heap_arr<T>::is_powoftwo(int num)
{
	return (num&(num - 1)) == 0;  //bitwise and to check whether is power of 2;
}
template <typename T>
void max_heap_arr<T>::create_max_heap()
{
	T tmp;
	int index = 0, swap_index = 0, step = 0, size;
	cout << "How many datas ?";
	cin >> size;
	cout << "Enter " << size << " heap data :  ";
	for (int i = 0; i < size; i++) //should swap while creating not after creating
	{
		cin >> tmp;
		max_heap.push_back(tmp);
		index++;
		swap_index = index;
		if (is_powoftwo(index))
		{
			level++;
		}

		while (swap_index != 1)
		{
			step++;
			if (max_heap[swap_index] > max_heap[swap_index / 2])
			{
				swap(max_heap[swap_index], max_heap[swap_index / 2]);
				step++;
			}
			swap_index /= 2;
		}
	}
	cout << "Build max heap time complexity nlogn (with adjust) " << step << " Level is " << level << endl;
}
template <typename T>
T max_heap_arr<T>::pop_max()
{
	if (max_heap.size() == 1)
	{
		cout << "Nothing to remove! ";
		return NULL;
	}
	int swap_index = 1;
	step = 0;
	T max_value = max_heap[1];
	max_heap[1] = max_heap.back();
	max_heap.pop_back();
	step++;
	if (is_powoftwo(max_heap.size()))
	{
		level--;
	}

	if (max_heap.size() == 3)
	{
		if (max_heap[1] < max_heap[2])
		{
			swap(max_heap[1], max_heap[2]);
		}
	}
	else if(max_heap.size()>3)//special judge for the rest heap like NULL-3-1-2 and 2 is taken out -> NULL-3-1-X if use else sode, will access an undefined area
	{
		while (1)
		{
			//case 1 Left child is bigger
			if ((max_heap[swap_index] < max_heap[2 * swap_index] || max_heap[swap_index]<max_heap[2 * swap_index + 1]) && (max_heap[2 * swap_index]>max_heap[2 * swap_index + 1]))
			{
				/*cout << "Swap no. " << swap_index << "  " << max_heap[swap_index]
					<< " And Swap no." << 2 * swap_index << " " << max_heap[2 * swap_index] << endl;*/ //Visualization
				swap(max_heap[swap_index], max_heap[2 * swap_index]);
				swap_index = swap_index * 2;
				step++;
			}
			//case 2 Right child is bigger
			else if ((max_heap[swap_index] < max_heap[2 * swap_index] || max_heap[swap_index] < max_heap[2 * swap_index + 1]) && (max_heap[2 * swap_index] < max_heap[2 * swap_index + 1]))
			{
				/*cout << "2n+1 Swap no. " << swap_index << "  " << max_heap[swap_index] 
					<< " And Swap no." << 2 * swap_index + 1 << " " << max_heap[2 * swap_index + 1] << endl;*/ //Visualization
				swap(max_heap[swap_index], max_heap[2 * swap_index + 1]);
				swap_index = swap_index * 2 + 1;
				step++;
			}
			if (swap_index * 2 >= max_heap.size() || swap_index * 2 + 1 >= max_heap.size()) //out of range protection
			{
				break;
			}
		}
	}
	cout << "Pop and rearrange max heap time complexity nlogn (with adjust) " << step << " Level is " << level << endl;
	return max_value;
}
template <typename T>
void max_heap_arr<T>::print()
{
	for (int i = 1; i < max_heap.size(); i++)
	{
		cout << max_heap[i] << " ";
	}
	cout << endl;
}
class heap_main
{
public:
	heap_main()
	{

		main_exec();
	}
	void main_exec();
	template <typename T>
	void command_control(max_heap_arr<T>);
private:
	int type_selection, command;
};

void heap_main::main_exec()
{
	cout << "What type of Max heap 0 int ,1 double ,2 string ";
	cin >> type_selection;
	if (!type_selection)
	{
		max_heap_arr<int> max_heap_int;
		command_control(max_heap_int);
	}
	else if (type_selection == 1)
	{
		max_heap_arr<double> max_heap_dou;
		command_control(max_heap_dou);
	}
	else if (type_selection == 2)
	{
		max_heap_arr<string> max_heap_str;
		command_control(max_heap_str);
	}
}
template <typename T>
void heap_main::command_control(max_heap_arr<T> max_heap_arr)
{
	cout << "Command control 0 quit ,1 build heap ,2 access max and remove ,3 print heap";
	do
	{
		cout << "Command: ";
		cin >> command;
		switch (command)
		{
		case 1:
			max_heap_arr.create_max_heap();
			break;
		case 2:
			cout << "Pop and access the max value" << max_heap_arr.pop_max() << endl;
			break;
		case 3:
			cout << "Max heap:  ";
			max_heap_arr.print();
			break;
		default:
			cout << "Wrong input try again ";
			break;
		}
	} while (command);
	return;
}
