#include <string>
#include <exception>
using namespace std;
template <typename T>
class node
{
public:
	T value;
	node* next;
	bool alive;
};

template<typename T>
class linkedlist_main
{
public:
	linkedlist_main()
	{

	}
	int size = 0, size2 = 0;
	node<T>* current = NULL;
	node<T>*head = NULL;
	node<T>*head2 = NULL;
	node<T>*end = NULL;
	node<T>*end2 = NULL;
	void main_function_insert()
	{
		cout << "How many nodes: " << endl;
		cin >> size;
		cout << "Insert the data :";
		insert();

	}
	void insert()
	{
		if (size2)
		{
			for (int i = 0; i < size2; i++)
			{
				T input;
				cin >> input;
				current = new node < T >;
				if (i == 0)
				{
					current->value = input;
					current->next = NULL;
					head2 = current;
					end2 = current;

				}
				else
				{
					current->value = input; //新增的節點
					current->next = NULL;
					end2->next = current; //上一個做好指向下一個新增的維持聯繫再移過來
					end2 = current; //移過來

				}

			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				T input;
				cin >> input;
				current = new node < T > ;
				if (i == 0)
				{
					current->value = input;
					current->next = NULL;
					head = current;
					end = current;

				}
				else
				{
					current->value = input; //新增的節點
					current->next = NULL;
					end->next = current; //上一個做好指向下一個新增的維持聯繫再移過來
					end = current; //移過來

				}

			}
		}

	}
	void main_function_print()
	{
		printlist(head);
	}
	template <typename T>
	void printlist(node<T>* cur)
	{
		int printed_node = 0;
		cout << "Linked list (size is" << size << ")" << endl;
		if (!size)
		{
			cout << "NULL" << endl;
		}
		else
		{
			while (cur != NULL)
			{
				cout << cur->value << "->";
				cur = cur->next;
			}
			cout << "NULL" << endl;
		}
	}


	void main_function_reverse()
	{
		cout << "Reversed ";
		head = reverse_list(head);
	}
	template <typename T>
	node<T>* reverse_list(node<T>* cur)
	{
		//curin will be the end of a linked list
		node<T>* rev_prev = NULL;
		node<T>* rev_cur_next_tmp;
		while (cur != NULL)
		{
			rev_cur_next_tmp = cur->next;
			cur->next = rev_prev;
			rev_prev = cur;
			cur = rev_cur_next_tmp;
		}
		return rev_prev;
	}


	void main_function_pop_back()
	{
		cout << "Popped back ";
		end = pop_back(head);
	}
	template <typename T>
	node<T>* pop_back(node<T>* cur)
	{
		node<T>* pop_back_end;
		if (size == 0)
		{
			throw exception();
		}
		else if (size == 1)
		{
			cur = NULL;
			size--;
		}
		else
		{
			while (cur->next->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = NULL;
			pop_back_end = cur;
			size--;
		}
		return cur;
	}


	void main_function_pop_front()
	{
		cout << "Popped front ";
		head = pop_front(head);
	}
	template <typename T>
	node<T>* pop_front(node<T>* cur)
	{
		if (size == 0)
		{
			throw exception();
		}
		else if (size == 1)
		{
			cur = NULL;
			size--;
		}
		else
		{
			cur = cur->next;
			size--;
		}
		return cur;
	}


	void main_function_lexico_sort()
	{
		cout << "Sorted ";
		lexico_sort(head);
	}

	template <typename T>
	void lexico_sort(node<T>* cur)
	{
		int boundary = size - 1;
		node<T>* head = cur;
		while (boundary > 0)
		{
			for (int i = 0; i < boundary; i++)
			{

				if (cur->value>cur->next->value)
				{
					swap(cur->value, cur->next->value);
				}

				cur = cur->next;
			}
			cur = head;
			boundary--;
		}
	}


	void main_function_duplicated_remove()
	{
		cout << "Duplicated remove ";
		duplicated_remove(head);
	}
	template <typename T>
	void duplicated_remove(node<T>* head)
	{
		node<T>* cur = head;
		node<T>* next_next;

		if (cur == NULL)
			return;

		while (cur->next != NULL)
		{

			if (cur->value == cur->next->value)
			{
				next_next = cur->next->next;
				free(cur->next);
				size--;
				cur->next = next_next;
			}
			else
			{
				cur = cur->next;
			}
		}
	}


	void main_function_remove_ith()
	{
		cout << "Enter the position you want to delete :";
		head = remove_ith(head);
	}
	template <typename T>
	node<T>* remove_ith(node<T>* cur)
	{

		node<T>* head = cur;
		node<T>* freetmp;
		int pos;
		cin >> pos;
		if (size == 0)
		{
			throw exception();
		}
		else if (size == 1)
		{
			cur = NULL;
		}
		else
		{
			if (pos == 0)
			{
				size--;
				head = cur->next;
			}
			else
			{
				for (int i = 0; i < pos - 1; i++)
				{
					cur = cur->next;
				}
				freetmp = cur->next;
				cur->next = cur->next->next;
				free(freetmp);
				size--;
			}
		}

		return head;
	}

	void main_function_insert_at()
	{
		head = insert_at(head);
	}

	template <typename T>
	node<T>* insert_at(node<T>* head)
	{
		cout << "Enter the position you want to add node and its value :";
		T value;
		int pos;
		cin >> pos >> value;
		node<T>* cur = head;
		for (int i = 0; i < pos - 1; i++)
		{
			cur = cur->next;
		}
		node<T> *newnode = new node < T > ;
		newnode->value = value;
		newnode->next = cur->next;
		cur->next = newnode;
		return head;
	}
	void main_change_all_specified_value()
	{
		change_all_specified_value(head);
	}
	template <typename T>
	void change_all_specified_value(node<T>*cur)
	{
		cout << "Enter the old value and change all the old one two new :";
		T old_val, new_val;
		cin >> old_val >> new_val;
		while (cur != NULL)
		{
			if (cur->value == old_val)
			{
				cur->value = new_val;
			}
			cur = cur->next;
		}
	}
	void main_function_merge_and_sort()
	{
		merge_and_sort(head, head2);
	}
	template <typename T>
	void merge_and_sort(node<T>* head, node<T>*head2)
	{
		node<T>* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = head2;
		lexico_sort(head);
	}
	void main_function_insert_second_linkedlist()
	{
		insert_second_linked_list();
		cout << "h2 value" << head2->value << endl;
		printlist(head2);
	}
	void insert_second_linked_list()
	{
		cout << "How many nodes: " << endl;

		cin >> size2;
		size += size2;
		cout << "Insert the data :";
		insert();
	}
	void main_function_free_all_the_list()
	{
		free_all_the_list(head);
	}
	template <typename T>
	void free_all_the_list(node<T>* cur)
	{
		node<T>* freetmp;
		while (cur != NULL)
		{
			freetmp = cur;
			cur = cur->next;
			free(freetmp);
			size = 0;
		}
	}
};
class exec
{
public:

	int type_selection;
	void main_exec()
	{
		cout << "What type of linked list ? 0=int ,1=double ,2=string ";
		cin >> type_selection;
		if (type_selection == 0)
		{
			linkedlist_main<int> linkedlist;
			command_control(linkedlist);
		}
		else if (type_selection == 1)
		{
			linkedlist_main<double> linkedlist;
			command_control(linkedlist);
		}
		else
		{
			linkedlist_main<string> linkedlist;
			command_control(linkedlist);
		}
	}
	template<typename T>
	void command_control(linkedlist_main<T>  linkedlist)
	{
		show_message();
		int command;
		while (1)
		{
			cout << "Insert command /-1 to quit: ";
			cin >> command;
			if (command < 0)
			{
				exit(1);
				break;
			}

			switch (command)
			{
			case 0:

				linkedlist.main_function_reverse();
				linkedlist.main_function_print();
				break;
			case 1:

				linkedlist.main_function_pop_back();
				linkedlist.main_function_print();
				break;
			case 2:

				linkedlist.main_function_pop_front();
				linkedlist.main_function_print();
				break;
			case 3:

				linkedlist.main_function_lexico_sort();
				linkedlist.main_function_print();
				break;
			case 4:

				linkedlist.main_function_lexico_sort();
				linkedlist.main_function_duplicated_remove();
				linkedlist.main_function_print();
				break;
			case 5:
				linkedlist.main_function_remove_ith();
				linkedlist.main_function_print();
				break;
			case 6:

				linkedlist.main_function_insert_at();
				linkedlist.main_function_print();
				break;
			case 7:
				linkedlist.main_change_all_specified_value();
				linkedlist.main_function_print();
				break;
			case 8:
				linkedlist.insert_second_linked_list();
				break;

			case 9:
				linkedlist.main_function_free_all_the_list();
				linkedlist.main_function_print();
				break;

			case 10:
				linkedlist.main_function_insert();
				linkedlist.main_function_print();
				break;
			case 11:
				linkedlist.main_function_merge_and_sort();
				linkedlist.main_function_print();
			}
		}
	}
	void show_message()
	{
		cout << "Command for Linkedlist 0 reverse , 1 Pop_back , 2 Pop_front , 3 Sort ,\n4 Sort+Remove_duplicated ,5 "
			<< "Remove at ith position , 6 Insert at ith position , 7 Changed all specified value to new ,\n"
			<< "8 Create second list, 9 free all , 10 Createlist ,11 Merge sort of 2 linkedlists. " << endl;
	}
};
