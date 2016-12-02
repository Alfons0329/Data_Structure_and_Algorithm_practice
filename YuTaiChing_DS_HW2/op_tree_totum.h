#include<iostream>
using namespace std;

class node{
public:
	node();
	node(int value);
	~node();
	friend void gothrough(node *p);

private:
	node *left, *right; // the left child and the right child pointer
	int number; // record the node's number
	int is_threadl, is_threadr; //the flag to record whether the pointer is a thread or not

	friend class op_tree_totum;//you could access all valuables in class op_tree_totum
};

//ctor
node::node(){
	left = right = NULL;
	is_threadl = 1;
	is_threadr = 1;
}

//ctor
node::node(int value){
	number = value;
	left = right = NULL;
	is_threadl = 1;
	is_threadr = 1;
}

//dtor
node::~node(){

}

class op_tree_totum{

public:
	op_tree_totum();
	~op_tree_totum();
	void insertion(int s);
	void deletion(int s);
	void inorder_run();
	void reverseorder_run();
	int size();

private:
	node *root, *head, *tail;
	int num;//caculate how many nodes in the totum
};

//ctor
op_tree_totum::op_tree_totum(){
	head = new node();
	tail = new node();
	head->right = tail; //initialize the head node to connect to the tail node
	tail->left = head;
	//tail->right=max ,head->left=min;
	root = NULL;
	num = 0;
}

//dtor
op_tree_totum::~op_tree_totum(){
	node *p = root;
	if (p != NULL)	gothrough(p);
	num = 0;
	if (head != NULL)delete head;
	if (tail != NULL)delete tail;
}

void gothrough(node *p){
	if (p->is_threadl == 0 && p->left != NULL) gothrough(p->left);
	if (p->is_threadr == 0 && p->right != NULL) gothrough(p->right);
	delete p;
}

void op_tree_totum::insertion(int s){
	//TODO: fill in the code to do the insertion of the node with number s
	node* newnode = new node;
	newnode->number = s;
	if (root == NULL)
	{
		root = newnode;
		root->left = head;
		root->right = tail;
		num++;
	}
	else
	{
		node* current = root;//start traverse and find the root before insertion;
		node* before_insert = NULL;//prev data tmp;

		while (1)
		{
			before_insert = current; //back and front ,current will be a node in front of the before insert
			if (s < current->number)
			{
				if (current->is_threadl) //since the thread is kind of reverse pointer, cant use for binary search
					break;

				current = current->left;
			}
			else
			{
				if (current->is_threadr) //since the thread is kind of reverse pointer, cant use for binary search
					break;

				current = current->right;
			}
		}
		if (s < before_insert->number)
		{
			newnode->left = before_insert->left; //ex 5,6,5.5 5.5->left (thr) will point to 6->left(thr) which is 5 .		 
			newnode->right = before_insert;

			before_insert->left = newnode; //connect the previous node to the new one node
			before_insert->is_threadl = 0; //and thus it is not a thread but a real left ptr

			head->left = newnode; //for traverse consistency
			head->is_threadl = 1;
		}
		else
		{
			newnode->right = before_insert->right; //ex 5,3,4 4->right (thr) will point to 3->tight
			newnode->left = before_insert;

			before_insert->right - newnode; //connect the previous node to the new one node
			before_insert->is_threadr = 0; //and thus it is not a thread but a real right ptr

			tail->right = newnode; //for traverse consistency
			tail->is_threadr = 1;
		}
		num++;
	}



}

void op_tree_totum::deletion(int s){
	//TODO: fill in the code to do the deletion of the node with number s
	//binary search the "to_be_deleted" node and "before_delete node"!
	node* current = root;
	node* to_be_deleted = NULL;
	node* before_delete = NULL;
	while (1)//binary search the "to_be_deleted" node and "before deletion node"!
	{
		if (s < current->number)
		{
			if (current->is_threadl)
			{
				cout << "Not found, no deletion" << endl;
			}

			before_delete = current;
			to_be_deleted = current->left;
			current = current->left;
		}
		else if (s > current->number)
		{
			if (current->is_threadr)
			{
				cout << "Not found, no deletion" << endl;
			}

			before_delete = current;
			to_be_deleted = current->right;
			current = current->right;
		}
		else
		{
			break;//found the to_be_delete
		}
	}
	//deal with 2 child circumstance
	if (!to_be_deleted->is_threadl&&!to_be_deleted->is_threadr)
	{
		/*find l sub max and replace the to_be_delete node than binary search where the l sub max is,assign its number's value
		to "s", than delete it as leaf/1 child type*/
		node* keep_data = to_be_deleted;
		current = to_be_deleted->left;
		while (!current->is_threadr)
		{
			before_delete = current;
			to_be_deleted = current->right;
			current = current->right;
		}
		keep_data->number = current->number;
		s = current->number;
	}
	//deal with 3 types
	if (to_be_deleted->is_threadl&&to_be_deleted->is_threadr) //to be deleted is a leaf
	{

	}
	else if (to_be_deleted->is_threadr) //to_be_deleted has lsub but no rsub
	{
		//tree consistency ,connect the before_delete to to_be_deleted->left
		if (before_delete->left == to_be_deleted)
		{
			before_delete->left = to_be_deleted->left;
		}
		else if (before_delete->right == to_be_deleted)
		{
			before_delete->right = to_be_deleted->left;
		}
		//find the lsubmax and connect its rthread to the to_be_delete->rthread
		current = to_be_deleted->left;
		while (!current->is_threadr)
		{
			current = current->right;
		}
		//after find the lsubmax connect ths lsubmax->rthread to to_be_deleted->rthread
		current->right = to_be_deleted->right;
		//then free the memory space
		delete to_be_deleted;
	}
	else//to_be_deleted has rsub but no lsub
	{
		//tree consistency ,connect the before_delete to to_be_deleted->right
		if (before_delete->left == to_be_deleted)
		{
			before_delete->left = to_be_deleted->right;
		}
		else if (before_delete->right == to_be_deleted)
		{
			before_delete->right = to_be_deleted->right;
		}
		//find the rsubmin and connect its lthread to the to_be_delete->lthread
		current = to_be_deleted->right;
		while (!current->is_threadl)
		{
			current = current->left;
		}
		//after find the rsubmin connect ths rsubmin->lthread to to_be_deleted->lthread
		current->left = to_be_deleted->left;
		//then free the memory space
		delete to_be_deleted;
	}

	num--;
	/*if (s == root->number)//delete root
	{ 
		if (root->is_threadl&&root->is_threadr)//root itself is a leaf
		{
			num = 0;
		}
		else if (root->is_threadr) //root has left child but no right one
		{
			//binary search the max in the left subtree at root->left and connect the max node to end;
			node* current = root->left;
			while (!current->is_threadr)
			{
				current = current->right;
			}
			cout << "Find the lsubmax of root :" << current->number << endl;
			//and connect its right ptr to the tail node and also tail node
			current->right = tail;
			tail->right = current;
			//end of connection and delete the to_be_deleted node to free the memory spaace
			delete to_be_deleted;
		}
		else //root has right child but no left one
		{
			to_be_deleted = root;
			root = root->right;
			//binary search the max in the left subtree at root->left and connect the max node to end;
			node* current = root;
			while (!current->is_threadl)
			{
				current = current->left;
			}
			cout << "Find the rsubmin of root :" << current->number << endl;
			//and connect its right ptr to the tail node and also tail node
			current->left = head;
			head->left = current;
			//end of connection and delete the to_be_deleted node to free the memory spaace
			delete to_be_deleted;
		}
	}
	else//not delete root
	{
		if (to_be_deleted->is_threadl&&to_be_deleted->is_threadr)
		{

		}
		else if (to_be_deleted->is_threadr)
		{

		}
		else
		{

		}
	}*/

}

void op_tree_totum::inorder_run(){
	//TODO: travel the tree from the head node to the tail node and output the values
	//You should NOT use stack or recurtion 
	node* current = head;
	if (!num)
	{
		cout << "Empty tree!" << endl;
	}
	else
	{
		while (current != tail)
		{
			if (current->is_threadr)
			{
				current = current->right;
			}
			else //search the min in the r sub tree if the right ptr is not a thread type
			{
				current = current->right;
				while (!current->is_threadl) //if it is not the thread type, keep searching for the right sub min
				{
					current = current->left;
				}
			}
			cout << current->number << " ";
		}

	}

}

void op_tree_totum::reverseorder_run(){
	//TODO: travel the tree from the tail node to the head node and output the values
	//You should NOT use stack or recurtion 
	node* current = tail;
	if (!num)
	{
		cout << "Empty tree!" << endl;
	}
	else
	{
		while (current != head)
		{
			if (current->is_threadl)
			{
				current = current->left;
			}
			else//search the max in the l sub tree if the left ptr is not a thread type
			{
				current = current->left;
				while (!current->is_threadr) //if it is not the thread type, keep searching for the left sub max
				{
					current = current->right;
				}
			}
			cout << current->number << " ";
		}
	}

}

int op_tree_totum::size(){
	return num;
}
