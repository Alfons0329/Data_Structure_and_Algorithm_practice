#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
template <typename T>
class node
{
public:
	node<T>* parent;
	node<T>* left_ch;
	node<T>* right_ch;
	T data;
	bool visit;
};
template <typename T>
class bin_tree_main
{
friend class bin_tree_exec;
public:
	bin_tree_main()
	{
		root = NULL;
	}
	~bin_tree_main()
	{

	}
	void input_data();
	void create_tree(T);
	void preorder_traverse(node<T>*);
	void inorder_traverse(node<T>*);
	void postorder_traverse(node<T>*);
	void breath_first_search(node<T>*);
	void depth_first_search(node<T>*);
	void add_node_after();
	void delete_node_at();
	void cleantag();
	void delete_tree();

	node<T>* find_value(node<T>*);
	node<T>* find_value_DFS_iterative();
private:
	node<T>* root;
	T search_value;
	int nodes_cnt, leaves_cnt;
};

template <typename T>
void bin_tree_main<T>::input_data()
{
	int total;
	cout << "How many nodes?  ";
	cin >> total;
	cout << total << " Nodes' data: ";
	for (int i = 0; i < total; i++)
	{
		T tmp;
		cin >> tmp;
		create_tree(tmp);
	}
}
template <typename T>    //Top-down from root node construction and Time complexity is
void bin_tree_main<T>::create_tree(T in) //Not bin_tree_main:: since it is a template class
{
	node<T>* newnode = new node<T>;
	newnode->data = in;
	newnode->left_ch = NULL;
	newnode->right_ch = NULL;
	newnode->visit = false;
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		
		node<T>* current = root; //current is used for traverse
		node<T>* prev=NULL; //save prev data before current reach NULL for insertion   current reach NULL and prev before 1 level of current
		
		//start the top-down from root to build the binary tree ,and traverse to the node before newnode to implement insertion
		while (current!=NULL)
		{
			//cout << "Build node " << newnode->data << "After " << current->data << endl;
			prev = current;
			if (in < current->data)
			{
				current = current->left_ch;
			}
			else
			{
				current = current->right_ch;
			}
		}
		//now at the right node's place before the newnode's insertion
		if (in < prev->data)
		{
			prev->left_ch = newnode;
		}
		else
		{
			prev->right_ch = newnode;
		}
		newnode->parent = prev;
	}
}
template <typename T>
void bin_tree_main<T>::preorder_traverse(node<T>* current)
{
	if (current == NULL)
	{
		return;
	}
	cout << current->data << " ";
	preorder_traverse(current->left_ch);
	preorder_traverse(current->right_ch);
}
template<typename T>
void bin_tree_main<T>::inorder_traverse(node<T>* current)
{
	if (current == NULL)
	{
		return;
	}
	inorder_traverse(current->left_ch);
	cout << current->data << " ";
	inorder_traverse(current->right_ch);
}
template <typename T>
void bin_tree_main<T>::postorder_traverse(node<T>* current)
{
	if (current == NULL)
	{
		return;
	}
	postorder_traverse(current->left_ch);
	postorder_traverse(current->right_ch);
	cout << current->data << " ";
}
template <typename T>
void bin_tree_main<T>::breath_first_search(node<T>* current)
{
	queue<node<T>*> bfs_stack;
	bfs_stack.push(current);
	while (bfs_stack.size())
	{
		current = bfs_stack.front();
		bfs_stack.pop();
		cout << current->data << " ";
		if (current->left_ch)
			bfs_stack.push(current->left_ch);
		if (current->right_ch)
			bfs_stack.push(current->right_ch);
	}
}
template <typename T>
node<T>* bin_tree_main<T>::find_value(node<T>* current) //by DFS recursive
{
	if (current != NULL)
	{
		if (current->data == search_value)
			return current;
		else
		{
			 find_value(current->left_ch);    //don't forget return or it will always reach the end's NULL and return false;
			 find_value(current->right_ch);	//don't forget return or it will always reach the end's NULL and return false;
		}
	}
	return NULL;
}
template <typename T>
node<T>* bin_tree_main<T>::find_value_DFS_iterative()
{
	node<T>* current = root;
	vector<node<T>*> dfs_itr;
	dfs_itr.push_back(root);
	bool find = false;
	while (dfs_itr.size() > 0)
	{
		cout << current->data << " ";
		if (current->data == search_value)
		{
			find = true;
			break;
		}
		if (current->left_ch&&!current->left_ch->visit)
		{
			current = current->left_ch;
			dfs_itr.push_back(current);
		}
		else if (current->right_ch&&!current->right_ch->visit)
		{
			current = current->right_ch;
			dfs_itr.push_back(current);
		}
		else
		{
			current->visit = true;
			current = current->parent;
			dfs_itr.pop_back();
		}
	}
	if (find)
	{
		return current;
	}
	else
	{
		return NULL;
	}
	
}


class bin_tree_exec
{
public:
	bin_tree_exec()
	{
		main_exec();
	}
	void main_exec();
	template <typename T>
	void command_control(bin_tree_main<T>);
private:
	int command, type_selection;
};
template <typename T>
void bin_tree_exec::command_control(bin_tree_main<T> bin_tree)
{
	do
	{
		cout << "\nCommand: 1 build tree ,2 preorder traverse ,3 inorder traverse ,4 postorder traverse\n" <<
			"5 BFS ,6 DFS ,7 find value ,8 find value iterative ,9 ,0 end" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			bin_tree.input_data();
			break;
		case 2:
			bin_tree.preorder_traverse(bin_tree.root);
			break;
		case 3:
			bin_tree.inorder_traverse(bin_tree.root);
			break;
		case 4:
			bin_tree.postorder_traverse(bin_tree.root);
			break;
		case 5:
			bin_tree.breath_first_search(bin_tree.root);
			break;
		case 6:
			bin_tree.inorder_traverse(bin_tree.root);
			break;
		case 7: 
			cout << "Search value: ";
			cin >> bin_tree.search_value;
			if (bin_tree.find_value(bin_tree.root) == NULL)
			{
				cout << "Vaule doesn't exist in BST! " << endl;
			}
			else
			{
				cout << "Value exists after " << bin_tree.find_value(bin_tree.root)->parent->data;
			}
			break;
		case 8:
			cout << "Search value: ";
			cin >> bin_tree.search_value;
			if (bin_tree.find_value_DFS_iterative() == NULL)
			{
				cout << "Vaule doesn't exist in BST! " << endl;
			}
			else
			{
				cout << "Value exists after " << bin_tree.find_value_DFS_iterative()->parent->data;
			}
			break;
		default:
				cout << "Wrong input , try again: " << endl;
		}
	} while (command);
}

void bin_tree_exec::main_exec()
{
	cout << "What type of binary tree ? 0:int ,1:double ,2:string ";
	cin >> type_selection;
	switch (type_selection)
	{
	case 0:
	{
			  bin_tree_main<int> bin_tree_int;
			  command_control(bin_tree_int);
			  break;
	}
	case 1:
	{
			  bin_tree_main<double> bin_tree_dou;
			  command_control(bin_tree_dou);
			  break;
	}
	case 2:
	{
			  bin_tree_main<string> bin_tree_str;
			  command_control(bin_tree_str);
			  break;
	}
	default:
	{
			   cout << "Wrong input, please try again.";
			   break;
	}
	}

}