// heap is complite binary tree.

#include <iostream>
#include "tree.h"

using namespace std;

#define MAX_HEAP_SIZE 100
#define START_INDEX 1
#define TRUE 1
#define FALSE 0


class MaxHeap: public Tree{

private:

	TreeNode *heap[MAX_HEAP_SIZE];
	int heapsize;

	int isEmpty(){
		return this -> heapsize == 0;
	}

	int isFull(){
		return this -> heapsize == MAX_HEAP_SIZE;
	}

	int upheap(void){
		printf("upheap\n");
		int currentIndex = this -> heapsize;
		int value = this -> heap[currentIndex] -> getData();
		int parent_value = this -> heap[currentIndex/2] -> getData();

		while(parent_value <= value){
			SWAP(currentIndex / 2, currentIndex);
			currentIndex /= 2;
			parent_value = this -> heap[currentIndex/2] -> getData();
		}

		return 0;
	}
	void SWAP(int pIndex, int cIndex){
      TreeNode *tmp;
      tmp = this->heap[pIndex];
      this->heap[pIndex] = this->heap[cIndex];
      this->heap[cIndex] = tmp;
   }
	void printTreeNode(int index){
		TreeNode *node = this -> heap[index];
		if(node != NULL){
			printf("%d ", node -> getData());
		}
		else{
			printf("0 ");
		}
	}

	TreeNode* deleteNode(void){
		if(this -> isEmpty()){
			return NULL;
		}

		TreeNode* targetNode = this -> heap[START_INDEX];
		this -> heap[START_INDEX] = this -> heap[heapsize];
		this -> heapsize--;
		this -> downheap();
		return targetNode;
	}

	void downheap(void){
		int pIndex = START_INDEX;
		int cIndex = START_INDEX * 2;
		// 자식 인덱스

		while(cIndex <= this -> heapsize){
			if(this -> heap[cIndex] -> getData() < this -> heap[cIndex+1] -> getData()){
				cIndex++;
			}
			if(this -> heap[cIndex] -> getData() <= this -> heap[pIndex] -> getData()){
				break;
			}
			this -> SWAP(pIndex, cIndex);
	        pIndex = cIndex;
	        cIndex = pIndex * 2;

		}

	}
public:

	MaxHeap(void){
		this -> heapsize = 0;
		memset(this -> heap, 0, sizeof(TreeNode)*MAX_HEAP_SIZE);
		TreeNode *dummyNode = new TreeNode(999999);
		this -> heap[0] = dummyNode;
	}

	virtual void pushTreeNode(TreeNode *newNode){
		printf("Push new node data : ");
		if(this -> isFull()){
			printf("Heap is Full\n");
			return;
		}

		printf("%d\n", newNode -> getData());
		this -> heapsize++;
		this -> heap[heapsize] = newNode;
		this -> upheap();


	}
	virtual TreeNode* popTreeNode(void){
		printf("Pop node\n");
		TreeNode *targetNode = this -> deleteNode();
		if(targetNode == NULL){
			printf("Heap is empty\n");
		}
		printf("%d\n", targetNode -> getData());
		return NULL;
	}
	virtual void printAllNode(void){
		printf("Print All Node : \n");
		if(this -> isEmpty()){
			printf("HEAP is empty!\n");
			return;
		}
		for(int i = START_INDEX; i < heapsize + 1; i++){
			printTreeNode(i);
		}
		printf("\n");

	}

	void sortData(void){
		printf("Sorting Node : \n");
		if(this -> isEmpty()){
			printf("Heap is empty\n");
			return;
		}

		TreeNode *targetNode;
		while(!(this -> isEmpty())){
			targetNode = this -> deleteNode();
			printf("%d ", targetNode -> getData());
		}
		printf("\n");
	}
};

int main(){

	MaxHeap *heap = new MaxHeap();
	heap -> printAllNode();

   TreeNode *new1 = new TreeNode(41);
   heap->pushTreeNode(new1);
   new1 = new TreeNode(32);
   heap->pushTreeNode(new1);
   new1 = new TreeNode(14);
   heap->pushTreeNode(new1);
   new1 = new TreeNode(23);
   heap->pushTreeNode(new1);

   heap->printAllNode();
   
   
   heap->popTreeNode();

   heap->printAllNode();

   heap->sortData();
   heap->printAllNode();


	return 0;
}