#define _CRT_SECURE_NO_WARNINGS
//#include "binaryTree.h"
#include "binaryTreePointer.h"
#include <stdio.h>
#include <string.h>
#include "circularQueue.h"


void printGraphVizDriver(const Node* root, int mode);





//void graphvizPrint(BinaryTree* bt, in	t node)
//{ 
//
//	// 재귀함수를 이용해서 이진트리 출력함수 
//	if (node > bt->size)return;
//	if (node != 1) printf("\"%s\" -> \"%s\";\n", bt->data[node / 2].msg, bt->data[node].msg);
//
//	graphvizPrint(bt, 2 * node);
//	graphvizPrint(bt, 2 * node+1);
//}
//
//
//void graphvizDriver(BinaryTree* bt)
//{
//	printf("digraph G {\n");
//	graphvizPrint(bt, 1);
//	printf("}\n");
//}


//void printgraphViz(const Node* root)
//{
//	if (root != NULL) {
//		if (root->left != NULL) printf("\t%d->%d\n", root->data, root->left->data);
//		printgraphViz(root->left);
//		if (root->right != NULL) printf("\t%d->%d\n", root->data, root->right->data);
//		printgraphViz(root->right);
//	}
//}

//void printGraphVizDriver(const Node* root) {
//	printf("\ndigraph g{ \n");
//	printgraphViz(root);
//	printf("}\n");
//}




//
//void test()
//{
//	Node* root = NULL;
//	root = create(1);
//	root->left = create(2);
//	root->right = create(3);
//	Node* t = root->left;
//	t->left = create(4);
//	t->right = create(5);
//
//	t = root->right;
//	t->left = create(6);
//	t->right = create(7);
//
//	print(root);
//	printgraphViz(root);
//	dispose(root);
//
//}


int main()
{
	//BinaryTree bt;
	//init(&bt);

	////for (int i = 1; i <= 8; i++)
	////{
	////	insert(&bt, i);
	////	
	////}

	//Element trainData[] = {
	//	{true , "is animal?  "},
	//	{true , "has 2 legs"},
	//	{true , " is tall?"},
	//	{true , "can fly?" },
	//	{true , "is  lagrger than human? "},
	//	{true , "has needle leaf ? " },
	//	{true , "is flower ? " },
	//	{false , " it is a bird."},
	//	{false , " it is a chicken " },
	//	{false , "it is an elephant "},
	//	{false , " it is a dog"},
	//	{false , " it is a pine tree " },
	//	{false , " it is a bamboo"},
	//	{false , " it is an orchid."},
	//	{false , " it is grass ."}
	//};

	//for (int i = 1; i < 15; i++)
	//{
	//	insert(&bt, trainData[i]); // data 삽입 
	//}

	//graphvizDriver(&bt);

	//int question = 1;
	//char answer;

	//do {
	//	printf("%s", bt.data[question].msg);
	//	printf(" if Yes , enter 'y' or 'n ' :");
	//	scanf("%c", &answer);

	//	if (answer == 'y')
	//	{
	//		question = rightChild(&bt, question);
	//	}
	//	else
	//	{
	//		question = leftChild(&bt, question);
	//	}

	//	scanf("%c", &answer);

	//} while (bt.data[question].msg);


	//Node n1 = { 2 , NULL , NULL };
	//Node n2 = { 3 , NULL , NULL };
	//Node n3 = { 1 , &n1 , &n2 };

	//Node* root = &n3;

	//printf("%d", root->data);
	//printf("%d", root->left->data);
	//printf("%d \n ", root->right->data);
	//printGraphVizDriver(root);
	//ADT 에는 dispose 로 해제하는 함수가 있지만 여기서는 dispose(root) 처럼 사용 불가능 
	// 모든노드를 동적으로 할당하지 않기때문에 


	//test();

////////////////////////////////////////////////////////////////////////////////////
	//Node n1 = { 20 , NULL , NULL };
	//Node n2 = { 30 , NULL , NULL };
	//Node n3 = { 10 , &n1 , &n2 };

	//Node* root = &n3;

	//Node n4 = { 40 , NULL , NULL };
	//Node n5 = { 50 , NULL , NULL };

	//n1.left = &n4;
	//n1.right = &n5;

	//inOrder(root); printf("\n");
	//preOrder(root); printf("\n");
	//postorder(root); printf("\n");
	//levelOrder(root); printf("\n");



	//printGraphVizDriver(root, 0);
	//printGraphVizDriver(root, 1);
	//printGraphVizDriver(root, 2);
	//printGraphVizDriver(root, 3);
//////////////////////////////////////////////////////////////////////

	//printf("No of Nodes %d \n ", noOfNodes(root));
	//printf("no of leafnodes %d \n", noOfLeafNodes(root));
	//printf(" no of Iternal Nodes %d \n", noOfInternalNodes(root));
	//printf(" height of trees %d \n ", height(root));
////////////////////////////////////////////////////////////////////////




    Node* bst = NULL;

	// 아래의 함수호출에서 첫번째 노드를 추가할 때는 함수의 반환값을 사용하고
	//그 다음부터는 함수호출을 사용하지않고있다 
	// 왜그런지 꼭 이해 + 포인터를 파라미터로 넘겨줄때의 의미를 잘이해해야한다
	//

	bst = BST_recursiveInsert(bst, 31);// 31 을 bst 에 삽입 반환값을 bst 포인터에 삽입


	BST_recursiveInsert(bst, 16);
	BST_recursiveInsert(bst, 45);
	//BST_recursiveInsert(bst, 0);

	//printGraphVizDriver(bst, 0); // mode 0 로 실행 preorder방식으로 

	BST_recursiveInsert(bst, 24);
	BST_recursiveInsert(bst, 7);
	
	//printGraphVizDriver(bst, 0);

	BST_recursiveInsert(bst, 19);
	BST_recursiveInsert(bst, 29);
	BST_recursiveInsert(bst, 6);
	BST_recursiveInsert(bst, 15);
	BST_recursiveInsert(bst, 2);
	BST_recursiveInsert(bst, 3);
	BST_recursiveInsert(bst, 76);
	BST_recursiveInsert(bst, 28);

	printf(" number of one degree %d ", DegreeIsOne(bst));
	printGraphVizDriver(bst, 0);

	//트리에서 항목 삭제 

	bst = BST_recursiveDelete(bst, 7);

	printGraphVizDriver(bst, 0);
	bst = BST_recursiveDelete(bst, 16);

	bst = BST_recursiveDelete(bst, 24);

	bst = BST_recursiveDelete(bst, 31);
	printGraphVizDriver(bst, 0);
	dispose(bst);

	bst = NULL;
	// 메모리를 모두free 한후 명시적으로 null을 넣어야 안전하다 








}

