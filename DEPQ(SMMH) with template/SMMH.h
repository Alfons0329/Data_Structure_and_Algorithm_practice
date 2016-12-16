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
	void create_smmh();
	void insert(const T&);
	void getmax();
	void getmin();
	void deletemax();
	void deletemin();
	void print_current_smmh();
private:
	int smmh_size;
};
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