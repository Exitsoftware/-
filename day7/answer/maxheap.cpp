#include <iostream>
#include "tree.h"

using namespace std;

#define MAX_HEAP_SIZE 100
#define START_INDEX 1
#define TRUE 1
#define FALSE 0

class MaxHeap: public Tree {
private:
	TreeNode *heap[MAX_HEAP_SIZE];
	int heapSize;

	int isEmpty(void) {
		return this->heapSize == 0 ? TRUE : FALSE;
	}

	int isFull(void) {
		return this->heapSize == MAX_HEAP_SIZE ? TRUE : FALSE;
	}

	void upheap(void) {
		int currentIndex = this->heapSize;
		int value = this->heap[currentIndex]->getData();
		while( this->heap[currentIndex/2]->getData() <= value) {
			this->swap(currentIndex/2, currentIndex);
			currentIndex = currentIndex/2;
		}
	}

	void swap(int pIndex, int cIndex) {
		TreeNode *tmp;
		tmp = this->heap[pIndex];
		this->heap[pIndex] = this->heap[cIndex];
		this->heap[cIndex] = tmp;
	}

	void printTreeNode(int index) {
		TreeNode *node = this->heap[index];
		if (node != NULL) {
			cout << node->getData() << " ";
		} else {
			cout << "0 ";
		}
	}

	TreeNode* deleteNode(void) {
		if (this->isEmpty()) {
			return NULL;
		}
		TreeNode* targetNode = this->heap[START_INDEX];
		this->heap[START_INDEX] = this->heap[this->heapSize];
		this->heapSize--;
		this->downheap();
		return targetNode;
	}

	void downheap(void) {
		int pIndex = START_INDEX;
		int cIndex = START_INDEX *2;

		while (cIndex <= this->heapSize) {
			if (this->heap[cIndex]->getData() < this->heap[cIndex+1]->getData()) {
				cIndex++;
			}
			if (this->heap[cIndex]->getData() <= this->heap[pIndex]->getData()) {
				break;
			}
			swap(pIndex, cIndex);
			pIndex = cIndex;
			cIndex = pIndex * 2;
		}
	}

public:
	MaxHeap(void) {
		this->heapSize = 0;
		memset(this->heap, 0, sizeof(TreeNode)*MAX_HEAP_SIZE);
		TreeNode *dummyNode = new TreeNode(999999);
		this->heap[0] = dummyNode;
	}

	virtual void pushTreeNode(TreeNode *newNode){
		cout << "PUSH NEW NODE DATA : ";
		if (this->isFull()) {
			cout << "HEAP IS FULL" << endl;
			return;
		}
		cout << newNode->getData() << endl;
		this->heapSize++;
		this->heap[heapSize] = newNode;
		this->upheap();
	}
	
	virtual TreeNode* popTreeNode(void) {
		cout << "POP NODE : ";
		TreeNode *targetNode = this->deleteNode();
		if (targetNode == NULL) {
			cout << "HEAP IS EMPTY" << endl;
		}
		cout << targetNode->getData() << endl;
		return targetNode;
	}
	
	virtual void printAllNode(void) {
		cout << "Print All Node : ";
		if (this->isEmpty()) {
			cout << "HEAP IS EMPTY" << endl;
			return;
		}
		for (int i=START_INDEX; i<heapSize+1; i++) {
			this->printTreeNode(i);
		}
		cout << endl;
	}

	void sortData(void) {
		cout << "Sorting Node : ";
		if (this->isEmpty()) {
			cout << "HEAP IS EMPTY" << endl;
			return;
		}

		TreeNode *targetNode;
		while(!(this->isEmpty())) {
			targetNode = this->deleteNode();
			cout << targetNode->getData() << " ";
		}
		cout << endl;
	}
};

int main(void) {
	MaxHeap *heap = new MaxHeap();
	
	int data;
	int listLen;
	TreeNode *nodeList[10];

	cin >> listLen;
	for (int i=0; i<listLen; i++) {
		cin >> data;
		nodeList[i] = new TreeNode(data);
		heap->pushTreeNode(nodeList[i]);
	}

	heap->printAllNode();
	heap->popTreeNode();
	heap->printAllNode();

	heap->popTreeNode();
	heap->printAllNode();

	heap->sortData();
	return 0;
}