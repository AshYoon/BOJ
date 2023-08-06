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
//	// ����Լ��� �̿��ؼ� ����Ʈ�� ����Լ� 
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
	//	insert(&bt, trainData[i]); // data ���� 
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
	//ADT ���� dispose �� �����ϴ� �Լ��� ������ ���⼭�� dispose(root) ó�� ��� �Ұ��� 
	// ����带 �������� �Ҵ����� �ʱ⶧���� 


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

	// �Ʒ��� �Լ�ȣ�⿡�� ù��° ��带 �߰��� ���� �Լ��� ��ȯ���� ����ϰ�
	//�� �������ʹ� �Լ�ȣ���� ��������ʰ��ִ� 
	// �ֱ׷��� �� ���� + �����͸� �Ķ���ͷ� �Ѱ��ٶ��� �ǹ̸� �������ؾ��Ѵ�
	//

	bst = BST_recursiveInsert(bst, 31);// 31 �� bst �� ���� ��ȯ���� bst �����Ϳ� ����


	BST_recursiveInsert(bst, 16);
	BST_recursiveInsert(bst, 45);
	//BST_recursiveInsert(bst, 0);

	//printGraphVizDriver(bst, 0); // mode 0 �� ���� preorder������� 

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

	//Ʈ������ �׸� ���� 

	bst = BST_recursiveDelete(bst, 7);

	printGraphVizDriver(bst, 0);
	bst = BST_recursiveDelete(bst, 16);

	bst = BST_recursiveDelete(bst, 24);

	bst = BST_recursiveDelete(bst, 31);
	printGraphVizDriver(bst, 0);
	dispose(bst);

	bst = NULL;
	// �޸𸮸� ���free ���� ��������� null�� �־�� �����ϴ� 








}

