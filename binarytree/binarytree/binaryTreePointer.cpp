#include "binaryTreePointer.h"
#include <stdio.h>
#include <malloc.h> // 동적할당을 위한 헤더 
//#include <algorithm>
#include <stdlib.h>
#include "circularQueue.h"


#define max(a, b) ((a) > (b) ? (a) : (b))


Node* create(Element e)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = e;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void dispose(Node* root)
{
	if (root != NULL)
	{
		dispose(root->left);
		dispose(root->right);
		free(root);
	}
}

void print(const Node* root)
{
	if (root != NULL)
	{
		print(root->left);
		printf("%d \n", root->data);
		print(root->right);
	}
}

Node* insertLeft(Node* root, int value)
{
	root->left = create(value);
	return root->left;

}

Node* insertRight(Node* root, int value)
{
	root->right = create(value);
	return root->right;
}

void inOrder(const Node* root)
{
	if (root)
	{
		inOrder(root->left); //inorder방식의 왼쪽트리부터 출력, 그다음 root 
		printf("%d ", root->data);
		inOrder(root->right); //left - root - right 순으로 

	}
}

void preOrder(const Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);

	}
}

void postorder(const Node* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);

	}
}

void levelOrder(const Node* root)
{
	Queue q;
	Node n;

	init(&q); // queue 초기화 
	enQueue(&q, *root);
	while (!isEmpty(&q))
	{
		n = deQueue(&q);
		printf("%d ", n.data);
		if (n.left) enQueue(&q, *(n.left));
		if (n.right) enQueue(&q, *(n.right));
	}



}

int noOfNodes(const Node* root)
{
	// 전체 노드 개수를 반환 , 재귀함수로 구현 
	// 전체 노드 개수 = 왼쪽 서브 트리 노드 개수 + R S T node 개수  + 1 

	if (!root)
	{
		return 0;
	}
	else {
		return noOfNodes(root->left) + noOfNodes(root->right) + 1;
	}
}

int noOfLeafNodes(const Node* root)
{
	// leaf 노드의 개수 반환 , 재귀로 구현 
	// 전체 leaf 노드 개수 = 왼쪽 서브 트리 leaf 노드 + 오른쪽 서브트리 leaf 노드 
	if (!root)
	{
		return 0;
	}
	else {
		if (root->left == NULL && root->right == NULL)
		{
			return 1; // root 로 받아온 객체가 leaf 노드면 1 반환 
		}
		else
			return noOfLeafNodes(root->left) + noOfLeafNodes(root->right); // LST L + RST L 
	}
}

int noOfInternalNodes(const Node* root)
{
	//internal 노드의 개수 반환 
	// 전체 Internal 노드 개수 = 왼쪽 Internal 노드 개수 + 오른쪽 Internal 노드개수 + 1 
	if (!root)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) // leaf 노드일경우 return 0 
	{
		return 0;
	}
	else if (root->left != NULL && root->right != NULL) //Iternal node면 return 
	{
		return noOfInternalNodes(root->left) + noOfInternalNodes(root->right) + 1;
	}
}

int height(const Node* root)
{
	//height 를 반환 
	// height  = 1 + max( 왼쪽 ST + R S T ) 

	if (!root)
	{
		return 0;
	}
	else
	{
		return 1 + max(height(root->left), height(root->right));
		
	}
}

Node* BST_recursiveSearch(Node* root, Element e)
{
	// 재귀적 구현 , 이진탐색트리 검색 
	// 항목을 찾으면 그 노드의 포인터를 반환
	// 항목을 없으면 null 반환

	if (root == NULL) return NULL; // root 에 null값 ,즉 leaf 노드에서 하위노드가 없는경우 null return
	if (e == root->data) return root; // 검색대상을 찾은경우 root return ,찾는데이터 e 가 root의 data 와 일치할경우 
	else if (e < root->data) return BST_recursiveSearch(root->left, e); // Left SubTree 재귀적으로검색 값이 e < root->data 면 작은값이니깐 왼쪽으로 가는것  
	else return BST_recursiveSearch(root->right, e); //else right sub tree 재귀적 검색 
}

Node* BST_iterativeSearch(Node* root, Element e)
{
	// 반복적 구현 , 항목을 찾으면 해당 노드의 포인터 반환 , 없으면 null 반환 
	while (root)
	{
		if (e == root->data) return root; // 해당 데이터가 맞으면 노드 반환 
		else if (e < root->data) root = root->left; // left sub tree search 
		else root = root->right; // search right sub tree 
	}
	return NULL;

}

Node* BST_recursiveInsert(Node* root, Element e)
{
	if (root == NULL)
	{
		root = create(e);
	}
	else if (e < root->data) // 현재 노드보다 작은경우 search left sub tree
	{
		root->left = BST_recursiveInsert(root->left, e);
	}
	else
		root->right = BST_recursiveInsert(root->right, e);

	// 반환 값이 중요하다 
	// 해당 노드의 root값을 계속 반환해주면서 탐색은하지만 원본 변경을 하지않고 
	// 재귀적으로 right node 의 값을 탐색할수있는것 
	return root;

}

Node* BST_recursiveDelete(Node* root, Element e)
{
	if (root == NULL) return root; // root 가 null이면 root 반환 
	else if (e == root->data)
	{
		Node* temp; // 복제할 노드 
		if (root->left && root->right)
		{
			//자식 노드가 2 개 인경우 
			temp = BST_findMin(root->right); // temp는 RST에서 가장 작은값 애초에 root->right를 넣어줌 
			root->data = temp->data; // root 에 data 에 temp의 data를 복제시킴 temp값이 root가 되어야하니깐 
			root->right = BST_recursiveDelete(root->right, temp->data); // root .right는 
		}
		else {
			// 자식노드가 1 개 거나 0 개라면 
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;

			free(temp); //동적 할당해줘서 free ? 
		}

	}
	else if (e < root->data)
		root->left = BST_recursiveDelete(root->left, e);
	else if (e > root->data)
		root->right = BST_recursiveDelete(root->right, e);

	return root;
}

Node* BST_findMin(Node* node)
{
	//오른쪽 서브트리의 가장 작은 값의 노드를 찾는 함수 
	if (node == NULL)
	{
		return NULL;
	}

	if (node->left)
		BST_findMin(node->left);
	else
		return node;
}

Node* BST_findMax(Node* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->right)
		BST_findMax(node->right);
	else
		return node;
}

int DegreeIsOne(Node* root)
{
	if (root == NULL)
		return 0;

	int numbers = 0;

	// root 노드가 자식 노드를 하나만 가지고 있는 경우를 확인
	if ((root->left == NULL && root->right != NULL) ||
		(root->left != NULL && root->right == NULL))
		numbers = 1;

	// 왼쪽 서브트리와 오른쪽 서브트리 모두 확인
	numbers += DegreeIsOne(root->left);
	numbers += DegreeIsOne(root->right);

	return numbers;
}



/// graphviz 관련 코드 
// graphviz출력을 위한 코드 
// 각 노드의 방문 순서를 표기하기위해 코드를 일부 수정 
// 각 노드의 색상을 방문하는 순서에 따라 노드에 번호를 표시
// DOT의 문법을 잘 이해해야한다 


void printGraphVizPreOrder(const Node* root)
{
	static int no = 0; // 전역변수 no 선언 및 초기화 
	if (root != NULL)
	{
		printf("\t\"%d\"[label = \" %d\"];\n", root->data, no++);
		if (root->left != NULL)  printf("\t%d->%d\n", root->data, root->left->data);
		printGraphVizPreOrder(root->left);
		
		


		
		if (root->right != NULL) printf("\t%d->%d\n", root->data, root->right->data);
		printGraphVizPreOrder(root->right);
	}
}

void printGraphVizInOrder(const Node* root)
{
	static int no = 0;
	if (root != NULL)
	{
		
		if (root->left != NULL)  printf("\t%d->%d\n", root->data, root->left->data);
		printGraphVizInOrder(root->left);
		
		printf("\t\"%d\"[label = \" %d\"];\n", root->data, no++);


		if (root->right != NULL) printf("\t%d->%d\n", root->data, root->right->data);
		printGraphVizInOrder(root->right);



	}
}

void printGraphVizPostOrder(const Node* root)
{
	static int no = 0;
	if (root != NULL)
	{
		
		if (root->left != NULL)  printf("\t%d->%d\n", root->data, root->left->data);
		printGraphVizPostOrder(root->left);



		if (root->right != NULL) printf("\t%d->%d\n", root->data, root->right->data);
		printGraphVizPostOrder(root->right);

		printf("\t\"%d\"[label = \" %d\"];\n", root->data, no++);

	}
}


void printGraphVizLevelOrder(const Node* root)
{
	Queue q;
	Node n;
	init(&q);
	enQueue(&q, *root);

	int no = 0;

	while (!isEmpty(&q))
	{
		n = deQueue(&q);
		printf("\t\"%d\" [label = \" %d\"];\n", n.data, no++);

		if (n.left)
		{
			enQueue(&q, *(n.left));
			printf("\t%d->%d\n", n.data, (n.left)->data);
		}

		if (n.right)
		{
			enQueue(&q, *(n.right));
			printf("\t%d->%d\n", n.data, (n.right)->data);
		}
	}
}


void printGraphVizDriver(const Node* root, int mode)
{
	printf("\n digraph g { \n ");

	if (mode == 0) printGraphVizPreOrder(root);
	else if (mode == 1) printGraphVizInOrder(root);
	else if (mode == 2) printGraphVizPostOrder(root);
	else if (mode == 3) printGraphVizLevelOrder(root);

	printf("} \n ");
}