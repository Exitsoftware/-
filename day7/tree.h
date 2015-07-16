#ifndef __TREE__
#define __TREE__ 

// if not define TREE, Define TREE header file.

#include <iostream>
using namespace std;

class TreeNode{
private:
	int data;

public:
	
	TreeNode(int data){
		this -> data = data;
	}

	int getData(void){
		return this -> data;
	}

	void setData(int data){
		this -> data = data;
	}
};


class Tree{
public:
	virtual void pushTreeNode(TreeNode *newNode) = 0;
	virtual TreeNode* popTreeNode(void) = 0;
	virtual void printAllNode(void) = 0;
};
#endif



