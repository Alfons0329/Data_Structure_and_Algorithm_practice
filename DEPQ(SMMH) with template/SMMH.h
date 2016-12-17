#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
template<typename T>
class SMMH
{
public:
	vector<T> smmh_vector;
	

	void create_smmh(); //NlogN for all nodes
	void insert(const T&,int ); //O(logN) For each node 
	void getmax(); //O(1)
	void getmin(); //O(1)
	void deletemax(); //O(logN)
	void deletemin(); //O(logN)
	void print_current_smmh(); //O(N)

private:
	int smmh_size;
};

template <typename T>
void SMMH<T>::create_smmh()
{
	cout << "Symmetric Min Max Heap ,how many data?";
	cin >> smmh_size;
	cout << "Enter " << smmh_size << " data: ";
	smmh_vector.resize(smmh_size + 2); //vector 0(empty) vector 1(null root)
	for (int i = 2; i < smmh_size; i++)
	{
		T tmp;
		cin >> tmp;
		insert(tmp,i);
	}
	
	smmh_vector[0] = NULL;
}
template <typename T>
void SMMH<T>::insert(const T& data_in, int insert_current_index)
{
	//Property 1: left sib < right sib
	if (insert_current_index % 2) //insert is left sib
	{
		smmh_vector[insert_current_index] = data_in;
	}
	else// insert is right sib
	{
		smmh_vector[insert_current_index] = data_in;
		if (smmh_vector[insert_current_index] > smmh_vector[insert_current_index - 1])// Property 1: left sib < right sib
		{
			swap(mmh_vector[insert_current_index], smmh_vector[insert_current_index - 1]);
		}
	}
	if (insert_current_index >= 3) //Size is more than 3 ()
	{
		
		int current_index = insert_current_index;
		bool finished_adjustment = false;
		while (finished_adjustment)
		{
			int grandparent_index = current_index / 4;
			int grandparent_left_ch = 2 * grandparent_index;
			int grandparent_right_ch = grandparent_left_ch + 1;
			if (smmh_vector[current_index]<smmh_vector[grandparent_left_ch]) //Property 2: Curent node value >grandparent_left_ch ,fix if violate
			{
				swap(smmh_vector[current_index], smmh_vector[grandparent_left_ch]);
				current_index = grandparent_left_ch;
			}
			else if (smmh_vector[current_index] > smmh_vector[grandparent_right_ch] //Property 3: Curent node value< grandparent_right_ch ,fix if violate
			{
				swap(smmh_vector[current_index], smmh_vector[grandparent_right_ch]);
				current_index = grandparent_right_ch;
			}
			else //No more violations , done !!
			{
				finished_adjustment = true;
			}
		}

	}
}
template <typename T>
void SMMH<T>::print_current_smmh()
{
	cout << "Current SMMH : " << " Size ( " << smmh_size" )  : ";
	for (int i = 2; i < smmh_size; i++)
	{
		if (!(i&(i - 1)))
		{
			cout << endl;
		}
		cout << smmh_vector[i] << " ";
			//Heap next line (or say level) is power of 2
	}
}
class SMMH_main_exec
{
public:
	SMMH_main_exec()
	{
		main_exec();
	}
	void main_exec();
	template <typename T>
	void command_control(SMMH<T>);
private:
	int type_selection, command;
};

void SMMH_main_exec::main_exec()
{
	cout << "What type of Max heap 0 int ,1 double ,2 string ";
	cin >> type_selection;
	if (!type_selection)
	{
		SMMH<int> SMMH_int;
		command_control(SMMH_int);
	}
	else if (type_selection == 1)
	{
		SMMH<double> SMMH_dou;
		command_control(SMMH_dou);
	}
	else if (type_selection == 2)
	{
		SMMH<string> SMMH_str;
		command_control(SMMH_str);
	}

}