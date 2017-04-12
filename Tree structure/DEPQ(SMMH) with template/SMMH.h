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
	void deletemax(); //O(logN)
	void deletemin(); //O(logN)
	void print_current_smmh(); //O(N)
	T getmax(); //O(1)
	T getmin(); //O(1)
private:
	int smmh_size;
};

template <typename T>
void SMMH<T>::create_smmh()
{
	cout << "Symmetric Min Max Heap ,how many data?";
	cin >> smmh_size;
	cout << "Enter " << smmh_size << " data: ";
	smmh_size += 2; //since vector[0] vector[1] will not be used
	smmh_vector.resize(smmh_size); //vector 0(empty) vector 1(null root)
	for (int i = 2; i < smmh_size; i++)
	{
		T tmp;
		cin >> tmp;
		insert(tmp,i);
	}
	
}
template <typename T>
void SMMH<T>::insert(const T& data_in, int insert_current_index)
{
	//Property 1: left sib < right sib
	cout << "Insert current index " << insert_current_index << endl;
	if (insert_current_index % 2==0) //insert is left sib
	{
		smmh_vector[insert_current_index] = data_in;
	}
	else// insert is right sib
	{
		smmh_vector[insert_current_index] = data_in;
		if (smmh_vector[insert_current_index] < smmh_vector[insert_current_index - 1])// Property 1: left sib < right sib fix if violate
		{
			swap(smmh_vector[insert_current_index], smmh_vector[insert_current_index - 1]);
		}
	}
	if (insert_current_index >= 3) //Size is more than 3 ()
	{
		
		int current_index = insert_current_index;
		bool finished_adjustment = false;
		while (!finished_adjustment&&current_index>=4/*swapping upper bound of heap structure (top)*/)
		{
			int grandparent_index = current_index / 4;
			int grandparent_left_ch = 2 * grandparent_index;
			int grandparent_right_ch = grandparent_left_ch + 1;
			if (smmh_vector[current_index]<smmh_vector[grandparent_left_ch]) //Property 2: Curent node value >grandparent_left_ch ,fix if violate
			{
				swap(smmh_vector[current_index], smmh_vector[grandparent_left_ch]);
				current_index = grandparent_left_ch;
			}
			else if (smmh_vector[current_index] > smmh_vector[grandparent_right_ch]) //Property 3: Curent node value< grandparent_right_ch ,fix if violate
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
void SMMH<T>::deletemax()
{
	//take the last node and insert it in smmh[3]
	if (smmh_size < 3)
	{
		cout << "Nothing to remove MAX!" << endl;
		return;
	}
	else if (smmh_size == 3)//last special case QQ
	{
		cout << "Access the MAX  " << smmh_vector[2] << "and remove it.";
		smmh_size -= 1;
		smmh_vector.resize(smmh_size);
		return;
	}
	else
	{
		cout << "Access the MAX  " << smmh_vector[3] << "and remove it.";
		smmh_vector[3] = smmh_vector[smmh_size - 1];
		smmh_size -= 1;
		smmh_vector.resize(smmh_size);
	}
	if (smmh_size>=4&&smmh_size <= 7) //special case deal QQ I have no idea for logN method but NlogN
	{
		cout << "Size <=6" << endl;
		for (int i = smmh_size-1; i >= 2; i--)
		{
			int current_index = i;
			bool finished_adjustment = false;
			while (!finished_adjustment&&current_index >= 4/*swapping upper bound of heap structure (top)*/)
			{
				int grandparent_index = current_index / 4;
				int grandparent_left_ch = 2 * grandparent_index;
				int grandparent_right_ch = grandparent_left_ch + 1;
				if (smmh_vector[current_index]<smmh_vector[grandparent_left_ch]) //Property 2: Curent node value >grandparent_left_ch ,fix if violate
				{
					swap(smmh_vector[current_index], smmh_vector[grandparent_left_ch]);
					current_index = grandparent_left_ch;
				}
				else if (smmh_vector[current_index] > smmh_vector[grandparent_right_ch]) //Property 3: Curent node value< grandparent_right_ch ,fix if violate
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
	else if (smmh_size>7)
	{
		int current_index = 3, rchild = current_index * 2 + 1, rchild_of_sibling = 2 * (current_index - 1) + 1;

		while (max(smmh_vector[rchild], smmh_vector[rchild_of_sibling]) > smmh_vector[current_index])
		{
			if (smmh_vector[rchild] > smmh_vector[rchild_of_sibling])//take the bigger one for swapping
			{
				swap(smmh_vector[rchild], smmh_vector[current_index]);
				current_index = rchild;
			}
			else
			{
				swap(smmh_vector[rchild_of_sibling], smmh_vector[current_index]);
				current_index = rchild_of_sibling;
			}
			//swapping ends here

			//the following code makes the swapping process keep tracking down till finished
			rchild = current_index * 2 + 1;
			rchild_of_sibling = 2 * (current_index - 1) + 1;
			if (rchild >= smmh_size || rchild_of_sibling >= smmh_size)
			{
				break; //out or range protection ,it is finished
			}
		}
	}
	
}
template <typename T>
void SMMH<T>::deletemin() //symmetric process of that of delete max
{
	if (smmh_size < 3)
	{
		cout << "Nothing to remove min!" << endl;
		return;
	}
	else
	{
		cout << "Access the min  " << smmh_vector[2] << "and remove it.";

		//take the last node and insert it in smmh[2]
		smmh_vector[2] = smmh_vector[smmh_size - 1];
		smmh_size -= 1;
		smmh_vector.resize(smmh_size);
	}
	
	if (smmh_size >= 4&&smmh_size <= 7) //special case deal QQ I have no idea for logN method but NlogN
	{
		for (int i = smmh_size - 1; i >= 2; i--)
		{
			int current_index = i;
			bool finished_adjustment = false;
			while (!finished_adjustment&&current_index >= 4/*swapping upper bound of heap structure (top)*/)
			{
				int grandparent_index = current_index / 4;
				int grandparent_left_ch = 2 * grandparent_index;
				int grandparent_right_ch = grandparent_left_ch + 1;
				if (smmh_vector[current_index]<smmh_vector[grandparent_left_ch]) //Property 2: Curent node value >grandparent_left_ch ,fix if violate
				{
					swap(smmh_vector[current_index], smmh_vector[grandparent_left_ch]);
					current_index = grandparent_left_ch;
				}
				else if (smmh_vector[current_index] > smmh_vector[grandparent_right_ch]) //Property 3: Curent node value< grandparent_right_ch ,fix if violate
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
	else if (smmh_size>7)
	{
		int current_index = 2, lchild = current_index * 2, lchild_of_sibling = 2 * (current_index + 1);
		while (min(smmh_vector[lchild], smmh_vector[lchild_of_sibling]) < smmh_vector[current_index])
		{
			if (smmh_vector[lchild] < smmh_vector[lchild_of_sibling])//take the smaller one for swapping
			{
				swap(smmh_vector[lchild], smmh_vector[current_index]);
				current_index = lchild;
			}
			else
			{
				swap(smmh_vector[lchild_of_sibling], smmh_vector[current_index]);
				current_index = lchild_of_sibling;
			}
			//swapping ends here

			//the following code makes the swapping process keep tracking down till finished
			lchild = current_index * 2;
			lchild_of_sibling = 2 * (current_index + 1);
			if (lchild >= smmh_size || lchild_of_sibling >= smmh_size)
			{
				break; //out or range protection ,it is finished
			}
		}
	}	
}
template <typename T>
T SMMH<T>::getmax()
{
	return smmh_vector[3];
}
template <typename T>
T SMMH<T>::getmin()
{
	return smmh_vector[2];
}

template <typename T>
void SMMH<T>::print_current_smmh()
{
	cout << "SMMH current size: " << smmh_size << endl;
	for (int i = 2; i < smmh_size; i++)
	{
		if (!(i&(i-1))) //is power of 2 endline
		{
			cout << endl;
		}
		cout << smmh_vector[i] << " ";
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
	cout << "What type of SMMH 0 int ,1 double ,2 string ,else quit";
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
template <typename T>
void SMMH_main_exec::command_control(SMMH<T> smmh)
{
	T tmp;
	cout << "Command control 0 quit ,1 build a SMMH ,2 access MAX ,3 access min ,4 access MAX and remove ,5access min and remove\n" <<
		"6 print current SMMH ,7insert arbitrary priority. ";
	do
	{
		cout << "Command: ";
		cin >> command;
		switch (command)
		{
		case 1:
			smmh.create_smmh();
			break;
		case 2:
			cout << "Access the MAX value" << smmh.getmax() << endl;
			break;
		case 3:
			cout << "Access the min value" << smmh.getmin() << endl;
			break;
		case 4:
			cout << "Access MAX and remove";
			smmh.deletemax();
			break;
		case 5:
			cout << "Access min and remove";
			smmh.deletemin();
			break;
		case 6:
			smmh.print_current_smmh();
			break;
		case 7:
			cout << "Insert arbitrary priority:  ";
			cin >> tmp;
			smmh.smmh_vector.resize(smmh.smmh_vector.size() + 1);
			smmh.insert(tmp,smmh.smmh_vector.size()-1);
			break;
		default:
			cout << "Wrong input try again ";
			break;
		}
	} while (command);
}