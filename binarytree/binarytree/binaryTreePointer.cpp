#include "binaryTreePointer.h"
#include <stdio.h>
#include <malloc.h> // �����Ҵ��� ���� ��� 
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
		inOrder(root->left); //inorder����� ����Ʈ������ ���, �״��� root 
		printf("%d ", root->data);
		inOrder(root->right); //left - root - right ������ 

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

	init(&q); // queue �ʱ�ȭ 
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
	// ��ü ��� ������ ��ȯ , ����Լ��� ���� 
	// ��ü ��� ���� = ���� ���� Ʈ�� ��� ���� + R S T node ����  + 1 

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
	// leaf ����� ���� ��ȯ , ��ͷ� ���� 
	// ��ü leaf ��� ���� = ���� ���� Ʈ�� leaf ��� + ������ ����Ʈ�� leaf ��� 
	if (!root)
	{
		return 0;
	}
	else {
		if (root->left == NULL && root->right == NULL)
		{
			return 1; // root �� �޾ƿ� ��ü�� leaf ���� 1 ��ȯ 
		}
		else
			return noOfLeafNodes(root->left) + noOfLeafNodes(root->right); // LST L + RST L 
	}
}

int noOfInternalNodes(const Node* root)
{
	//internal ����� ���� ��ȯ 
	// ��ü Internal ��� ���� = ���� Internal ��� ���� + ������ Internal ��尳�� + 1 
	if (!root)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) // leaf ����ϰ�� return 0 
	{
		return 0;
	}
	else if (root->left != NULL && root->right != NULL) //Iternal node�� return 
	{
		return noOfInternalNodes(root->left) + noOfInternalNodes(root->right) + 1;
	}
}

int height(const Node* root)
{
	//height �� ��ȯ 
	// height  = 1 + max( ���� ST + R S T ) 

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
	// ����� ���� , ����Ž��Ʈ�� �˻� 
	// �׸��� ã���� �� ����� �����͸� ��ȯ
	// �׸��� ������ null ��ȯ

	if (root == NULL) return NULL; // root �� null�� ,�� leaf ��忡�� ������尡 ���°�� null return
	if (e == root->data) return root; // �˻������ ã����� root return ,ã�µ����� e �� root�� data �� ��ġ�Ұ�� 
	else if (e < root->data) return BST_recursiveSearch(root->left, e); // Left SubTree ��������ΰ˻� ���� e < root->data �� �������̴ϱ� �������� ���°�  
	else return BST_recursiveSearch(root->right, e); //else right sub tree ����� �˻� 
}

Node* BST_iterativeSearch(Node* root, Element e)
{
	// �ݺ��� ���� , �׸��� ã���� �ش� ����� ������ ��ȯ , ������ null ��ȯ 
	while (root)
	{
		if (e == root->data) return root; // �ش� �����Ͱ� ������ ��� ��ȯ 
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
	else if (e < root->data) // ���� ��庸�� ������� search left sub tree
	{
		root->left = BST_recursiveInsert(root->left, e);
	}
	else
		root->right = BST_recursiveInsert(root->right, e);

	// ��ȯ ���� �߿��ϴ� 
	// �ش� ����� root���� ��� ��ȯ���ָ鼭 Ž���������� ���� ������ �����ʰ� 
	// ��������� right node �� ���� Ž���Ҽ��ִ°� 
	return root;

}

Node* BST_recursiveDelete(Node* root, Element e)
{
	if (root == NULL) return root; // root �� null�̸� root ��ȯ 
	else if (e == root->data)
	{
		Node* temp; // ������ ��� 
		if (root->left && root->right)
		{
			//�ڽ� ��尡 2 �� �ΰ�� 
			temp = BST_findMin(root->right); // temp�� RST���� ���� ������ ���ʿ� root->right�� �־��� 
			root->data = temp->data; // root �� data �� temp�� data�� ������Ŵ temp���� root�� �Ǿ���ϴϱ� 
			root->right = BST_recursiveDelete(root->right, temp->data); // root .right�� 
		}
		else {
			// �ڽĳ�尡 1 �� �ų� 0 ����� 
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;

			free(temp); //���� �Ҵ����༭ free ? 
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
	//������ ����Ʈ���� ���� ���� ���� ��带 ã�� �Լ� 
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

	// root ��尡 �ڽ� ��带 �ϳ��� ������ �ִ� ��츦 Ȯ��
	if ((root->left == NULL && root->right != NULL) ||
		(root->left != NULL && root->right == NULL))
		numbers = 1;

	// ���� ����Ʈ���� ������ ����Ʈ�� ��� Ȯ��
	numbers += DegreeIsOne(root->left);
	numbers += DegreeIsOne(root->right);

	return numbers;
}



/// graphviz ���� �ڵ� 
// graphviz����� ���� �ڵ� 
// �� ����� �湮 ������ ǥ���ϱ����� �ڵ带 �Ϻ� ���� 
// �� ����� ������ �湮�ϴ� ������ ���� ��忡 ��ȣ�� ǥ��
// DOT�� ������ �� �����ؾ��Ѵ� 


void printGraphVizPreOrder(const Node* root)
{
	static int no = 0; // �������� no ���� �� �ʱ�ȭ 
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