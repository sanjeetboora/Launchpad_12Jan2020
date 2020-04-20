#include <bits/stdc++.h>
using namespace std;
//max heap
void upheapify(vector<int> &heap, int index){
	if(index == 0){
		return;
	}

	int parentIndex = (index-1)/2;
	if(heap[index] > heap[parentIndex]){
		//swap
		int temp = heap[index];
		heap[index] = heap[parentIndex];
		heap[parentIndex] = temp;

		upheapify(heap, parentIndex);
	}
	else{
		return;
	}


// 0

// lc => 1  rc => 2

// 1=> (0*2) + 1
// 2=> (0*2) + 2 

// left child
// index = 1
// parentIndex = (index-1)/2 => (1-1)/2 = 0/2 = 0

// right child
// index = 2
// parentIndex = (index-1)/2 => (2-1)/2 = 1/2 = 0

}


void insert(vector<int> &heap, int num){

	heap.push_back(num);
	upheapify(heap, heap.size()-1);	

}
void displayHeap(vector<int> &heap){
	for (int i = 0; i < heap.size(); ++i)
	{
		cout<<heap[i]<<", ";
	}
	cout<<endl;
}

void downheapify(vector<int> &heap, int index){
	int leftChildIndex = (2*index)+1;
	int rightChildIndex = (2*index)+2;

	//index is leaf node
	if(leftChildIndex >= heap.size() and rightChildIndex >=heap.size()){
		return;
	}

	int largeChildIndex = index;
	if(leftChildIndex < heap.size() and heap[leftChildIndex] > heap[index]){
		largeChildIndex = leftChildIndex;
	}
	if(rightChildIndex < heap.size() and heap[rightChildIndex] > heap[largeChildIndex]){
		largeChildIndex = rightChildIndex;
	}

	if(largeChildIndex == index){
		return;
	}
	swap(heap[index], heap[largeChildIndex]);
	downheapify(heap, largeChildIndex);

}


void deleteRoot(vector<int> &heap){
	swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap, 0);
}

void deleteNode(vector<int> &heap, int index){
		heap[index] = INT_MAX;
		upheapify(heap,index);
		deleteRoot(heap);
}
void buildHeap(vector<int> &heap){
	for (int i = 0; i < heap.size(); ++i)
	{
		upheapify(heap, i);
	}
}

void buildHeapOptimized(vector<int> &heap){
	for (int i = heap.size()-1; i >=0; --i)
	{
		downheapify(heap, i);
	}
}




int main(int argc, char const *argv[])
{	//max heap
	vector<int> heap;
	
	// insert(heap, 10);
	// insert(heap, 5);
	// insert(heap, 1);
	// insert(heap, 12);
	// insert(heap, 190);
	// insert(heap, 18);
	// displayHeap(heap);
	// deleteRoot(heap);
	// displayHeap(heap);
	// deleteNode(heap,2);
	// displayHeap(heap);
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int ele;
		cin>>ele;
		heap.push_back(ele);
	}
	displayHeap(heap);
	//buildHeap(heap);
	buildHeapOptimized(heap);
	displayHeap(heap);


	


	return 0;
}