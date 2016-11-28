#include <iostream>
#include <string>
using namespace std;


template<typename T>
class qsort_functions
{
public:
	qsort_functions()
	{
		cout << "Quick sort algorithm";
		input();
	}
	int tc;
	T* data;
	void input();
	int	 split(T*, int, int);
	void quicksort(T*, int, int);
	void print_arr();
};


template<typename T>
void qsort_functions<T>::input()
{


	T tmp;
	cout << "How many data?: ";
	cin >> tc;
	data = new T[tc];
	for (int i = 0; i < tc; i++)
	{
		cin >> tmp;
		data[i] = tmp;
	}
	quicksort(data, 0, tc - 1);
	print_arr();
}
template<typename T>
int qsort_functions<T>::split(T* data, int start, int end)
{
	T pivot = data[end];
	int left_ptr = start, right_ptr = end , pivotindex = end, flag = 0;
	while (left_ptr < right_ptr)
	{
		while (data[left_ptr] < pivot&&left_ptr < right_ptr)
			left_ptr++;
		while (data[right_ptr] >= pivot&&right_ptr > left_ptr)
			right_ptr--;

		swap(data[left_ptr], data[right_ptr]);
		/*//system("pause");
		cout << "Left " << left_ptr << "Right " << right_ptr << " pvt " << pivot << endl;

		if (data[left_ptr]>pivot)
		{
		cout << "Pivot " << data[pivotindex] << "Left " << data[left_ptr] << endl;
		swap(data[left_ptr], data[pivotindex]);
		pivotindex = left_ptr;
		print_arr();
		}
		else if (data[right_ptr] < pivot)
		{
		cout << "Pivot " << data[pivotindex] << "Rright " << data[right_ptr] << endl;
		swap(data[right_ptr], data[pivotindex]);
		pivotindex = right_ptr;
		print_arr();
		}
		if (!flag)
		{
		left_ptr++;
		}
		else
		{
		right_ptr--;
		}
		flag = !flag;*/
	}
	pivotindex = right_ptr;
	//cout << "Pivot index " << pivotindex << endl;
	swap(data[end], data[right_ptr]);
	//print_arr();
	return pivotindex;
}
template<typename T>
void qsort_functions<T>::quicksort(T* data, int start, int end)
{
	if (start < end)
	{
		int pivotindex = split(data, start, end); //split and set pivot index
		quicksort(data, start, pivotindex - 1); //L sub part
		quicksort(data, pivotindex + 1, end); //R sub part;
	}
	else
		return;
}
template<typename T>
void qsort_functions<T>::print_arr()
{
	cout << "After quicksort: ";
	for (int i = 0; i < tc; i++)
	{
		cout << data[i] << " ";
	}

}
void start()
{
	int type_selection;
	cout << "What type of data? 0:int ,1:double ,2:string ,3:quit";
	cin >> type_selection;
	switch (type_selection)
	{
	case 0:
	{
		qsort_functions<int> qsort_int;
		break;
	}


	case 1:
	{
		qsort_functions<double> qsort_double;
		break;
	}


	case 2:
	{
		qsort_functions<string> qsort_string;
		break;
	}


	default:
		break;
	}
}


