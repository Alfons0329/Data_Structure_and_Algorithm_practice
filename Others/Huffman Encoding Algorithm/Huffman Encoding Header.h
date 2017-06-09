#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
struct Huffman_node
{
	int freq;
	char word;
	Huffman_node *left_ch, *right_ch;
};
class Huffman_encoding_main
{
public:

	vector<vector<int> > asciitable_frequency;
	string Huffman_string;

	void start();
	void input_data();
	static bool compare_node_freq(const Huffman_node* ,const Huffman_node* ); //No static will make sort compare inaccessible
	void build_Huffman_tree();
	void print_encoded_code(const Huffman_node*,string);
};
void Huffman_encoding_main:: start()
{
	input_data();
	build_Huffman_tree();
	system("pause");
}
void Huffman_encoding_main::input_data()
{
	cout << "Enter an English sentence for huffman encoding: \n";
	getline(cin, Huffman_string); //cin is not suitable for white space
	asciitable_frequency.resize(96); //2D array 96 row for the ASCII table space to del
	for (int i = 0; i < Huffman_string.size(); i++)
	{
		if (asciitable_frequency[Huffman_string[i] - ' '].empty())
		{
			asciitable_frequency[Huffman_string[i] - ' '].push_back(count(Huffman_string.begin(), Huffman_string.end(), Huffman_string[i]));
		}

	}
}

bool Huffman_encoding_main::compare_node_freq(const Huffman_node* node1,const Huffman_node* node2)
{
	return node1->freq > node2->freq;
}
void Huffman_encoding_main::build_Huffman_tree()
{
	int nodes_cnt = 0;
	for (int i = 0; i < 96; i++)
	{
		if (!asciitable_frequency[i].empty())
			nodes_cnt++;
	}
	vector<Huffman_node*> insert_nodes_ptr_container;
	insert_nodes_ptr_container.resize(nodes_cnt);
	for (int i = 0; i < nodes_cnt; i++) //put the initialized pointer to the vector for better manipulation
	{
		insert_nodes_ptr_container[i] = new Huffman_node;//Dont forget this ,or will cause "SEG FAULT"
	}
	//take the data and frequency into each "insert node"'s data container
	for (int i = 0, j = 0; i < 96; i++)
	{
		if (!asciitable_frequency[i].empty())
		{
			insert_nodes_ptr_container[j]->freq = asciitable_frequency[i][0];
			insert_nodes_ptr_container[j]->word = i + 32;
			j++;
		}
	}
	/*cout << "Nodes to be inserted: " << nodes_cnt << endl;
	sort(insert_nodes_ptr_container.begin(), insert_nodes_ptr_container.end(), compare_node_freq);
	//test debug
	cout << "Ready to insert node and the frequency "<<endl;
	for (int i = 0; i < insert_nodes_ptr_container.size(); i++)
	{
		cout << insert_nodes_ptr_container[i]->word << "  :   " << insert_nodes_ptr_container[i]->freq << endl;
	}*/

	//Build the Huffman tree
	//the initialized is a forest with each is a leaf!
	Huffman_node *left_ch, *right_ch, *parent;
	left_ch = new Huffman_node;
	right_ch = new Huffman_node;

	left_ch->left_ch = NULL;     //Leaf type nodes at the beginning phase
	left_ch->right_ch = NULL;	 //Leaf type nodes at the beginning phase
								 //Leaf type nodes at the beginning phase
	right_ch->left_ch = NULL;	 //Leaf type nodes at the beginning phase
	right_ch->right_ch = NULL;	 //Leaf type nodes at the beginning phase

	while (insert_nodes_ptr_container.size()!=1) //Last element will be the root
	{
		sort(insert_nodes_ptr_container.begin(), insert_nodes_ptr_container.end(), compare_node_freq);
		//sort again since we add parent node to the input list!

		//take the less freq  char to be the deeper node to save time complexity
		left_ch = insert_nodes_ptr_container.back();
		insert_nodes_ptr_container.pop_back();

		//take the less freq  char to be the deeper node to save time complexity
		right_ch = insert_nodes_ptr_container.back();
		insert_nodes_ptr_container.pop_back();


		parent = new Huffman_node;
		parent->freq = left_ch->freq + right_ch->freq; //Merge 2 nodes each with some frequency
		parent->word = '|'; //Just let it be the internal node of Huffman tree
		parent->left_ch = left_ch; //from upper lines
		parent->right_ch = right_ch; //from upper lines
		insert_nodes_ptr_container.insert(insert_nodes_ptr_container.begin(),parent); //Insert at front since it is with higher combined frequency , the sorting is sorted
		//with "Higher frequency"at the front thus we whould put at the front after merging 2 subndes


	}
	print_encoded_code(insert_nodes_ptr_container.back()," ");
}

void Huffman_encoding_main::print_encoded_code(const Huffman_node* current,string encoded_string) //direction 0 for leftptr and 1 for right ptr
{

	if (current == NULL)
	{
		return;
	}
	else if (current->word!='|') //not an internal node but leaf
	{
		cout << current->word << "  freq: " << current->freq << "  Huffman code:  " << encoded_string << endl;
		return;
	}
	/*if (current == NULL)
	{
		return;
	}
	else if (current->left_ch == NULL && current->right_ch == NULL)
	{
		cout << current->word << "  freq: " << current->freq << "  Huffman code:  " << encoded_string << endl;
		return;
	}*/
	//recursivelt traverse all the leafs just like preorder traversal
	print_encoded_code(current->left_ch,encoded_string+"0");
	print_encoded_code(current->right_ch,encoded_string+"1");
}
