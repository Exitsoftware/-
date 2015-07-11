#include <stdio.h>
#include <stdlib.h>



//     15
//    /|
//   4 20
//  /  /| 
// 1 16 25




//중위 순회
// 1 4 15 16 20 25

//전위 순회
// 15 4 1 20 16 25

// 후위 순회
// 1 4 16 25 20 15



typedef struct Node{
	char data;
	struct Node *left, *right;
	/* data */
}Node;

Node* CreateNode(char newData){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node -> left = NULL;
	new_node -> right = NULL;
	new_node -> data = newData;
	return new_node;
}

void Preorder(Node* node){
	if(node == NULL){
		return;
	}
	printf("%d\n", node -> data);
	Preorder(node -> left);
	Preorder(node -> right);
}

int main(){

	Node* A = CreateNode('A');
	Node* B = CreateNode('B');
	Node* C = CreateNode('C');
	Node* D = CreateNode('D');
	Node* E = CreateNode('E');


	return 0;
}