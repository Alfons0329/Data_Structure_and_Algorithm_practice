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
		root2_new = NULL;
	}
	~bin_tree_main()
	{

	}
	void input_data();
	void create_tree(T);
	void create_2nd_tree(T);
	void preorder_collect_node(node<T>*);
	void preorder_traverse(node<T>*);
	void inorder_traverse(node<T>*);
	void inorder_traverse_iterative();
	void postorder_traverse(node<T>*);
	void breath_first_search(node<T>*);
	void delete_node_at(node<T>*, T);
	void cleantag(node<T>*);
	void delete_tree(node<T>*);
	//below are forest
	void merge_2trees(node<T>*, node<T>*);
	void three_wayjoin(node<T>*, node<T>*);
	void split_between(T, T);

	bool find_value(node<T>*);

	node<T>* find_value_DFS_iterative();
	node<T>* binary_search(node<T>*, T);
	node<T>* find_max(node<T>*);
	node<T>* find_min(node<T>*);
	node<T>* find_succeesor(node<T>*, T);
	node<T>* least_common_ancestor(T, T);

	T operator /(const T&);
private:
	node<T>* root;
	node<T>* root2_new;
	T search_value, add_value, add_after, del_value;
	int nodes_cnt, leaves_cnt;
	vector<node<T>*> node_collector;
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
	node<T>* newnode = new node < T > ;
	newnode->data = in;
	newnode->parent = NULL;
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
		node<T>* prev = NULL; //save prev data before current reach NULL for insertion   current reach NULL and prev before 1 level of current

		//start the top-down from root to build the binary tree ,and traverse to the node before newnode to implement insertion
		while (current != NULL)
		{
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
		//now at the right node's place before the newnode's insertion to ensure the connection
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
template <typename T>    //Top-down from root node construction and Time complexity is
void bin_tree_main<T>::create_2nd_tree(T in) //Not bin_tree_main:: since it is a template class
{
	node<T>* newnode = new node < T > ;
	newnode->data = in;
	newnode->left_ch = NULL;
	newnode->right_ch = NULL;
	newnode->visit = false;
	if (root2_new == NULL)
	{
		root2_new = newnode;
	}
	else
	{

		node<T>* current = root2_new; //current is used for traverse
		node<T>* prev = NULL; //save prev data before current reach NULL for insertion   current reach NULL and prev before 1 level of current

		//start the top-down from root to build the binary tree ,and traverse to the node before newnode to implement insertion
		while (current != NULL)
		{
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
		//now at the right node's place before the newnode's insertion to ensure the connection
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
void bin_tree_main<T>::preorder_collect_node(node<T>* current)
{
	if (current == NULL)
	{
		return;
	}
	node_collector.push_back(current);
	preorder_traverse(current->left_ch);
	preorder_traverse(current->right_ch);
}
template <typename T>
void bin_tree_main<T>::preorder_traverse(node<T>* current)
{
	if (current == NULL)
	{
		return;
	}
	current->visit = false;
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
void bin_tree_main<T>::inorder_traverse_iterative()
{
	node<T>* current = root;
	vector<node<T>*> inorder_itr;
	while (1)
	{
		if (current)
		{
			inorder_itr.push_back(current);
			current = current->left_ch;
		}
		else
		{
			if (inorder_itr.size())
			{
				current = inorder_itr.back();
				inorder_itr.pop_back();
				cout << "Visit   " << current->data << "           " ;	
				current = current->right_ch;
			}
			else
			{
				break;
			}
		}
		cout << "Stack: ";
		for (int i = 0; i < inorder_itr.size(); i++)
		{
			cout<<inorder_itr[i]->data << " ";
		}
		cout << endl;
	}
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
void bin_tree_main<T>::delete_node_at(node<T>* current, T value) //value of node to be deleted
{
	node<T>* before_delete = NULL; //3cases 0chils 1 child and hardest 2 choldren!!!
	node<T>* deltmp = NULL;
	node<T>* to_be_deleted = NULL;
	if (current == NULL)
	{
		cout << "Root is NULL! Nothing to be deleted !" << endl;
		return;
	}
	before_delete = binary_search(root, value)->parent; //should search the node before deleted or will cause dangling pointer
	//dont forget this, or pointer will crash while traversaling since the node is not connected well
	to_be_deleted = binary_search(root, value);
	//case 1:  leaf
	if (to_be_deleted->left_ch == NULL&&to_be_deleted->right_ch == NULL)
	{
		if (to_be_deleted == root)
		{
			root = NULL;
		}
		else if (before_delete->left_ch == to_be_deleted)
		{
			deltmp = before_delete->left_ch;
			before_delete->left_ch = NULL;
			delete deltmp;

		}
		else if (before_delete->right_ch == to_be_deleted)
		{
			deltmp = before_delete->right_ch;
			before_delete->right_ch = NULL;
			delete deltmp;
		}

	}
	//case 2: 1 child node
	else if ((to_be_deleted->left_ch&&to_be_deleted->right_ch == NULL) || (to_be_deleted->left_ch == NULL&&to_be_deleted->right_ch))
	{

		cout << "Delete a 1 child node " << to_be_deleted->data << endl;
		if (to_be_deleted == root)
		{
			if (to_be_deleted->right_ch == NULL)
			{
				deltmp = root;
				root = root->left_ch;
				delete deltmp;
			}
			else if (before_delete->left_ch == NULL)
			{
				deltmp = root;
				root = root->right_ch;
				delete deltmp;
			}
		}

		else if (to_be_deleted->right_ch == NULL)
		{
			if (before_delete->left_ch == to_be_deleted)
			{
				deltmp = before_delete->left_ch;
				before_delete->left_ch = to_be_deleted->left_ch;
				delete deltmp;
			}
			else if (before_delete->right_ch == to_be_deleted)
			{
				deltmp = before_delete->right_ch;
				before_delete->right_ch = to_be_deleted->left_ch;
				delete deltmp;
			}
		}

		else if (to_be_deleted->left_ch == NULL)
		{
			if (before_delete->left_ch == to_be_deleted)
			{
				deltmp = before_delete->left_ch;
				before_delete->left_ch = to_be_deleted->right_ch;
				delete deltmp;
			}
			else if (before_delete->right_ch == to_be_deleted)
			{
				deltmp = before_delete->right_ch;
				before_delete->right_ch = to_be_deleted->right_ch;
				delete deltmp;
			}
		}

	}
	//case 3: 2 child node (full node)
	else if (to_be_deleted->left_ch&&to_be_deleted->right_ch) //replace the deleted node with the largest in left subtree or the smallest in right subtree , still obey BST
	{
		node<T>* left_subtree_max = NULL;
		node<T>* before_lsub_max = NULL;
		T keep_data;
		left_subtree_max = find_max(to_be_deleted->left_ch);
		before_lsub_max = binary_search(root, left_subtree_max->data)->parent;
		cout << "Delete 2 children node :" << to_be_deleted->data << " Replace with lsubtree max node: " << left_subtree_max->data << endl;
		if (to_be_deleted == root)
		{
			keep_data = left_subtree_max->data;
			delete_node_at(root, left_subtree_max->data);
			root->data = keep_data;
		}
		else
		{
			keep_data = left_subtree_max->data;
			delete_node_at(root, left_subtree_max->data);
			to_be_deleted->data = keep_data;
		}
	}
}
template <typename T>
void bin_tree_main<T>::cleantag(node <T>* current)
{
	preorder_traverse(current);
}
template <typename T>
void bin_tree_main<T>::merge_2trees(node<T>*r1, node<T>*r2)
{
	root = NULL;
	preorder_collect_node(r1);
	preorder_collect_node(r2);
	root = node_collector[0];
	for (int i = 0; i < node_collector.size(); i++)
	{
		cout << node_collector[i]->data<<" ";
		create_2nd_tree(node_collector[i]->data);
	}
}
template <typename T>
void bin_tree_main<T>::three_wayjoin(node<T>* current1, node<T>* current2)
{
	T mid = (current1->data + current2->data) / 2;
	root = NULL;
	root->parent = NULL;
	root->data = mid;
	if (current1->data < current2->data)
	{
		root->left_ch = current1;
		root->right_ch = current2;
	}
	else
	{
		root->left_ch = current2;
		root->right_ch = current1;
	}
}
template <typename T>
T bin_tree_main<T>::operator/(const T& in)
{
	return (*this + in)*0.5;
}
template <typename T>
void bin_tree_main<T>::split_between(T value1, T value2)
{
	root2_new = binary_search(root,value2);
	node<T>* splittedd = NULL;
	splittedd = binary_search(root,value1);
	if (splittedd->left_ch == root2_new)
	{
		splittedd->left_ch = NULL;
	}
	else if (splittedd->right_ch == root2_new)
	{
		splittedd->right_ch = NULL;
	}
}
template<typename T>
bool bin_tree_main<T>::find_value(node<T>* current) //by DFS recursive
{

	if (current != NULL)
	{
		if (current->data == search_value)
			return true;
		else
		{
			if (search_value < current->data)
			{
				find_value(current->left_ch);
			}
			else
			{
				find_value(current->right_ch);
			}

		}
	}
	else
		return false;
}
template <typename T>
node<T>* bin_tree_main<T>::find_value_DFS_iterative() 
{

	node<T>* current = root;
	cleantag(current);
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
template <typename T>
node<T>* bin_tree_main<T>::binary_search(node<T>* current, T value)
{
	while (current != NULL)
	{
		if (value < current->data)
		{
			current = current->left_ch;
		}
		else if (value > current->data)
		{
			current = current->right_ch;
		}
		else
		{
			return current;
		}
	}
	return NULL;

}
template <typename T>
node<T>* bin_tree_main<T>::find_max(node<T>* current)
{
	node<T>* temp_root = current;
	if (current == NULL)
	{
		cout << "Max value in BST: NULL" << endl;
		return NULL;
	}
	else
	{
		while (current->right_ch != NULL) //head to the leftmost node, which is the smallest
		{
			current = current->right_ch;
		}
		cout << "Max value in root " << temp_root->data << " BST is " << current->data << endl;
		return current;
	}
}
template <typename T>
node<T>* bin_tree_main<T>::find_min(node<T>* current)
{
	node<T>* temp_root = current;
	if (current == NULL)
	{
		cout << "Min value in BST: NULL" << endl;
		return NULL;
	}
	else
	{
		while (current->left_ch != NULL) //head to the leftmost node, which is the smallest
		{
			current = current->left_ch;
		}
		cout << "Min value in root " << temp_root->data << " BST is " << current->data << endl;
		return current;
	}
}
template <typename T>
node<T>* bin_tree_main<T>::find_succeesor(node<T>* current, T value)
{
	node<T>*succeessor = NULL;
	current= binary_search(current,value);
	//case 1: no r_subtree , binary search the closest ancestor to make searched node on l_subtree
	if (current->right_ch == NULL)
	{
		while (current->parent->left_ch != current&&current->parent)
		{
			current = current->parent;
		}
		succeessor = current->parent;
	}
	//case 2: has r_subtree
	else
	{
		succeessor = find_min(current->right_ch);
	}
	return succeessor;
}
template <typename T>
node<T>* bin_tree_main<T>::least_common_ancestor(T value1, T value2)
{
	node<T>* current = root;
	while (1)
	{	
		if (current->data > value1&&current->data > value2)
		{
			current = current->left_ch;
		}
		else if (current->data<value1&&current->data<value2)
		{
			current = current->right_ch;
		}
		else if ((current->data<value1&&current->data>value2) || (current->data>value1&&current->data<value2))
		{
			break;
		}
		else if(current->data == value1 || current->data == value2)
		{
			break;
		}
	}
	return current;
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
	void forest(bin_tree_main<T>);
	template <typename T>
	void command_control(bin_tree_main<T>);
private:
	int command, type_selection;
};
template <typename T>
void bin_tree_exec::command_control(bin_tree_main<T> bin_tree)
{
	cout << "\nCommand: 1 build tree ,2 preorder traverse ,3 inorder traverse ,4 postorder traverse\n" <<
		"5 BFS ,6 DFS ,7 find value ,8 find value iterative ,9 binary search ,10 find max ,11 find min\n" <<
		",13 delete node  ,15 find succeesor ,16 least common ancestor ,18 forest something ,0 quit" << endl;
	T value1, value2; //for least common ancestor
	do
	{
		cout << "\nCommand :";
		cin >> command;
		switch (command)
		{
		case 0:
			return;
			break;
		case 1:
			bin_tree.input_data();
			break;
		case 2:
			bin_tree.preorder_traverse(bin_tree.root);
			break;
		case 3:
			bin_tree.inorder_traverse(bin_tree.root);
			cout << "And by iterative stack inorder: ";
			bin_tree.inorder_traverse_iterative();
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
			if (!bin_tree.find_value(bin_tree.root))
			{
				cout << "Vaule doesn't exist in BST! " << endl;
			}
			else
			{
				cout << "Value exists !";
			}
			break;
		case 8:
			cout << "Search value: ";
			cin >> bin_tree.search_value;
			if (bin_tree.find_value_DFS_iterative() == NULL)
			{
				cout << "Vaule doesn't exist in BST! " << endl;
			}
			else if (bin_tree.find_value_DFS_iterative() == bin_tree.root)
			{
				cout << "Value is root " << bin_tree.find_value_DFS_iterative()->data;
			}
			else
			{
				cout << "Value exists after " << bin_tree.find_value_DFS_iterative()->parent->data;
			}
			break;
		case 9:
			cout << "Search value: ";
			cin >> bin_tree.search_value;
			if (bin_tree.binary_search(bin_tree.root, bin_tree.search_value) == NULL)
			{
				cout << "Vaule doesn't exist in BST! " << endl;
			}
			else if (bin_tree.binary_search(bin_tree.root, bin_tree.search_value) == bin_tree.root)
			{
				cout << "Value is root " << bin_tree.binary_search(bin_tree.root, bin_tree.search_value)->data;
			}
			else
			{
				cout << "Value exists after " << bin_tree.binary_search(bin_tree.root, bin_tree.search_value)->parent->data;
			}
			break;
		case 10:
			cout << "Max value in BST " << bin_tree.find_max(bin_tree.root) << endl;
			break;
		case 11:
			cout << "Min value in BST " << bin_tree.find_min(bin_tree.root) << endl;
			break;
			/*case 12:
			cout << "Add value1 after value2 (v1,v2)(obey BST's rule): ";
			cin >> bin_tree.add_value >> bin_tree.add_after;
			bin_tree.add_node_after(bin_tree.root, bin_tree.add_after, bin_tree.add_value);
			break;*/
		case 13:
			cout << "Delete ";
			cin >> bin_tree.del_value;
			bin_tree.delete_node_at(bin_tree.root, bin_tree.del_value);
			break;
		case 15:
			cout << "Find succeessor of : ";
			cin >> bin_tree.search_value;
			cout<<bin_tree.find_succeesor(bin_tree.root, bin_tree.search_value)->data<<endl;
			break;
		case 16:	
			cout << "Least common ancestor of a_b";
			cin >> value1 >> value2;
			cout << "LCA is " << bin_tree.least_common_ancestor(value1, value2)->data << endl;
			break;
		case 18:
			forest(bin_tree);
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

template <typename T> //Some forest operations 
void bin_tree_exec::forest(bin_tree_main<T> bin_tree)
{
	T value1, value2;
	cout << "Forest operations 0 quit ,1 split the BST ,2 traverse the splitted tree1 and tree2 ,3 merge 2 splitted BST from 2 to a BST \n"
		<< "4 traverse the merged tree from 3  \n";
	int splitted_tree_selection;
	do
	{
		cout << "Command : ";
		cin >> command;
		switch(command)
		{
		case 1:
			cout << "Splitted between: a_b ";
			cin >> value1 >> value2;
			bin_tree.split_between(value1, value2);
			break;
		case 2:
			cout << "Traverse the splitted BST ";
			cout << "0: Node 1:  " << bin_tree.root->data << "   1: Node 2:  " << bin_tree.root2_new->data<<endl;
			cin >> splitted_tree_selection;
			if (splitted_tree_selection)
			{
				cout << "Preorder "; bin_tree.preorder_traverse(bin_tree.root2_new);
				cout << "Inorder "; bin_tree.inorder_traverse(bin_tree.root2_new);
				cout << "Postorder "; bin_tree.postorder_traverse(bin_tree.root2_new);
				cout << endl;
			}
			else
			{
				cout << "Preorder "; bin_tree.preorder_traverse(bin_tree.root);
				cout << "Inorder "; bin_tree.inorder_traverse(bin_tree.root);
				cout << "Postorder "; bin_tree.postorder_traverse(bin_tree.root);
				cout << endl;
			}
			break;
		case 3:
			
			bin_tree.merge_2trees(bin_tree.root, bin_tree.root2_new);
			cout << "Bin tree root is " << bin_tree.root->data<< endl;
			break;
		case 4:
			cout << "Root is " << bin_tree.root->data << endl;
			cout << "Preorder "; bin_tree.preorder_traverse(bin_tree.root);
			cout << "Inorder "; bin_tree.inorder_traverse(bin_tree.root);
			cout << "Postorder "; bin_tree.postorder_traverse(bin_tree.root);
			cout << endl;
			break;
		case 5:
			//bin_tree.three_wayjoin(bin_tree.root, bin_tree.root2_new);
			break;
		}

	} while (command);
}