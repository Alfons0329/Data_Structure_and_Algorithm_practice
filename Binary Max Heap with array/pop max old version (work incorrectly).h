template <typename T>
T max_heap_arr<T>::pop_max()
{
	if (max_heap.size() == 1)
	{
		cout << "Nothing to remove! ";
		return NULL;
	}
	
	int swap_index = 1, take_small_place = max_heap.size() - 1;
	T max_value = max_heap[1];
	vector<int> swap_path; /*record the minium (or the element which was taken out for deletion max)'s path for identify swapping
	/path correctly*/
	swap_path.clear();
	 //take_small_place is to determine whether the replacing node is at r side or l side
	//the previos version always top-down swapping l side and cause wrong answer.
	while (take_small_place)
	{
		swap_path.push_back(take_small_place);
		cout << "Take small place " << take_small_place << endl;
		take_small_place /= 2;
	}
	max_heap[1] = max_heap.back();
	max_heap.pop_back();
	step = 0;
	if (is_powoftwo(max_heap.size() - 1))
		level--;
	for (int i = swap_path.size()-1; i >=2; i--) //watch out the reverse order and the first elemt cant access since that element is taken to the top of heap for re-swapping
		//and it's now an undefined mamory space ,thus it is out beyond comparison
	{
		if (max_heap[swap_path[i]] < max_heap[swap_path[i - 1]])
		{
			cout << "Swap no. " << swap_path[i] << "  " << max_heap[swap_path[i]] 
			<< " And Swap no." << swap_path[i - 1] << " " << max_heap[swap_path[i - 1]]<<endl;
			swap(max_heap[swap_path[i]], max_heap[swap_path[i - 1]]);
			step++;
		}
	}
	/*while (swap_index < max_heap.size())
	{
	if (max_heap[swap_index] < max_heap[swap_index * 2]&&max_heap[swap_index*2]>max_heap[swap_index*2+1])
	{
	cout << "This " << max_heap[swap_index] << "  and   " << max_heap[swap_index * 2] << endl;
	swap(max_heap[swap_index], max_heap[swap_index * 2]);
	step++;
	swap_index *= 2;
	cout << "Swap index is " << swap_index << endl;
	if (swap_index * 2 >max_heap.size() - 1) //out of range prevention ! dont forget -1 since vector[0] is NULL! and start from 1 while implementing max heap
	{
	break;
	}
	}
	else if (max_heap[swap_index] < max_heap[swap_index * 2 + 1])
	{
	cout << "This " << max_heap[swap_index] << "  and   " << max_heap[swap_index * 2 + 1] << endl;
	swap(max_heap[swap_index], max_heap[swap_index * 2 + 1]);
	step++;
	swap_index = swap_index * 2 + 1;
	cout << "Swap index is " << swap_index << endl;
	if (swap_index * 2 + 1 >= max_heap.size() - 1) //out of range prevention ! dont forget -1 since vector[0] is NULL! and start from 1 while implementing max heap
	{
	break;
	}
	}
	}*/

	return max_value;
}