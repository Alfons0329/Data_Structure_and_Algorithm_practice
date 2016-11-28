#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include <stdexcept>
using namespace std;
class main_cir_queue
{
public:
	main_cir_queue();
	int *cir_que, *new_cir_que;
	int front, rear, size, datas;
	void push(int &);
	void execute();
	bool isfull();
	void extend();
	void pop();
	void print();
	void queue_sort();
	void clean_all();
};
main_cir_queue::main_cir_queue()
{
	size = 0, front = -1, rear = -1, datas = 0;
	execute();
}
void main_cir_queue::execute()
{
	int command;
	cout << "Command: 1 Build a circular queue,2 Print,3 Pop,4 Sort,6 Build after the predecessor(strcat) ,7 Clean all, EOF quit: ";
	while (cin >> command)
	{
		switch (command)
		{
		case 1:
			cout << "Size of circular queue and how many data(#data should<=size-1): ";
			cin >> size >> datas;
			cir_que = new int[size];  //construct an circular queue of size
			rear = 0; //rear first at 0 and front at the end
			front = (rear + size - 1) % size;
			cout << "Enter data: ";
			for (int i = 0; i < datas; i++)
			{
				int tmp;
				cin >> tmp;
				push(tmp);
			}

			break;
		case 2:
			print();
			break;
		case 3:
			pop();
			break;
		case 4:
			queue_sort();
			break;
		case 6:
			cout << "How many data after the predecessor (#data should<=size-1): ?";
			cin >> datas;
			cout << "Enter the data: ";
			for (int i = 0; i < datas; i++)
			{
				int tmp;
				cin >> tmp;
				push(tmp);
			}
			break;
		case 7:
			clean_all();
			break;
		default:
			cout << "Command should be 1~7 and EOF! \n";
		}
		cout << "Enter a command: ";
	}
}
void main_cir_queue::push(int &in)
{
	if (!isfull())
	{
		cout << "Front and rear at " << front << " , " << rear << endl;
		cir_que[rear] = in;
		rear = (rear + 1) % size;
	}
	else
	{
		cout << "Front and rear at " << front << " , " << rear << endl;
		cout << "It's full , need extneded!" << endl;
		cir_que[rear] = in;
		extend();
		
	}
}
bool main_cir_queue::isfull()
{
	if (front == (rear + 1) % size)
	{
		return true;
	}
	else return false;
}
void main_cir_queue::extend()
{
	new_cir_que = new int[2 * size];
	for (int i = 0; i < size; i++)   //paste from old to new new queue serves as the temproary queue for storage the old purpose
	{
		new_cir_que[i] = cir_que[i];
	}
	delete[] cir_que;
	cir_que = new int[2 * size]; //reconstruct paste again to the old
	for (int i = 0; i < size; i++)
	{
		cir_que[i] = new_cir_que[i];
	}
	rear = size - 1;
	size *= 2;
	front = size - 1;
}
void main_cir_queue::pop()
{
	if (!size)
	{
		cout << "Size is 0 cannot pop!";
		out_of_range orr("Size is 0 cannot pop!");  // std exception for the size 0 queue unable to pop
		
		throw orr.what();
	}
	cir_que[front] = NULL;
	front++;
}
void main_cir_queue::print()
{
	
	if (!size)
	{
		cout << "Size is 0 , nothing to print !";
		out_of_range orr("Size is 0 , nothing to print !");
		
		throw orr.what();
	}
	else
	{
		cout << "Circular queue size :"<<size<<" and contains: ";
		for (int i = (front + 1) % size; i < rear; i++)
		{
			//cout << "I is now" << i << endl;
			cout << cir_que[i] << " ";
		}
		cout << endl;
	}

}
void main_cir_queue::clean_all()
{
	delete[] cir_que;
	size = 0;
}
void main_cir_queue::queue_sort()
{
	for (int i = (front + 1) % size; i < rear-1; i++)  //I have no idea why it should be done 2 times to get all right.....
	{
		if (cir_que[i] > cir_que[i + 1])
			swap(cir_que[i], cir_que[i + 1]);
	}
	for (int i = (front + 1) % size; i < rear - 1; i++)
	{
		if (cir_que[i] > cir_que[i + 1])
			swap(cir_que[i], cir_que[i + 1]);
	}
}