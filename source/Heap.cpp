#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

class Heap{
	vector<int> _heap;
public:
	void insert(int);
	void deleteMin();
	int peekMin();
	void climbUp(int);
	void climbDown(int);
	void display();
};

void Heap::insert(int el){
	int length = _heap.size();
	if(length==0){
		_heap.push_back(el);
	}else{
		_heap.push_back(el);
		climbUp(length-1);
	}
}

void Heap::climbUp(int index){
	if(index == 0){
		return;
	}
	
	int parent = ceil((double)index/2)-1;
	if(_heap[index] < _heap[parent]){
		int temp = _heap[parent];
		_heap[parent] = _heap[index];
		_heap[index] = temp;
		climbUp(parent);
	}
		
}

void Heap::climbDown(int index){
	int length = _heap.size();
	int left = 2*index;
	int right = 2*index+1;
	if(left>length-1){
		return;
	}
	int min = index;
	if(right<=length-1 ){
		min = _heap[left]<_heap[right]?left:right;
	}else{
		min = left;
	}
	
	if(_heap[min] < _heap[index]){
		int temp = _heap[index];
		_heap[index] = _heap[min];
		_heap[min] = temp;
		climbDown(min);
	}
	
}

void Heap::display(){
	cout<<"Contents of the Heap are : \n";
	for(vector<int>::iterator itr = _heap.begin(); itr!=_heap.end(); ++itr){
		cout<<*itr<<" , ";
	}
	cout<<'\n';
}

void Heap::deleteMin(){
	int length = _heap.size();
	if(length==0){
		cout<<"Heap Empty\n";
		return;
	}
		
	_heap[0] = _heap[length-1];
	_heap.pop_back();
	climbDown(0);
}

int Heap::peekMin(){
	if(_heap.size()==0){
		cout<<"Empty Heap\n";
		return INT_MIN;
	}
	return _heap[0];
}

int main(){
	Heap minHeap;
	minHeap.insert(4);
	
	minHeap.insert(10);
	
	minHeap.insert(1);
	
	minHeap.insert(3);
	
	minHeap.insert(5);
	cout<<"**************************************\n\n";
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	cout<<"**************************************\n\n";
	cout<<"Delete Min....\n";
	cout<<"Min = "<<minHeap.peekMin()<<'\n';
	minHeap.deleteMin();
	minHeap.display();
	return 0;
}