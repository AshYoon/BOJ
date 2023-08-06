#include <stdio.h>
#include "binaryTree.h"

void init(BinaryTree* bt)
{
	bt->size = 0;
	bt->data[0] = { true , '0' };
}

int leftChild(const BinaryTree* bt, const int pos)
{
	if (pos * 2 <= bt->size) return pos * 2;
	else return 0;
}

int rightChild(const BinaryTree* bt, const int pos)
{
	if (pos * 2 + 1 <= bt->size) return pos * 2 + 1;
	else return 0;
}

int parent(const BinaryTree* bt, const int pos)
{
	if (pos == 1) return 0; // pos �� ���� root �� 0 �� ��ȯ 
	else return pos / 2; // �ƴ϶�� pos /2 �� ��ȯ 
	
}

Element value(const BinaryTree* bt, const int pos)
{
	if (pos >= 0 && pos <= bt->size) // pos �� 0���� ũ�� Ʈ���� �������������
		return bt->data[pos]; //bt ���� pos ���� value �� return 
	// pos �� 0 �̸� error ���� ���⼭�� pos �� 0 �̸� 0 �� ��ȯ�ϴ°����� ���� 
}

void insert(BinaryTree* bt, const Element e)
{
	if (bt->size >= MAX_SIZE - 1) return;
	else {
		bt->size++;  // bt ������ ���������ְ� 
		bt->data[bt->size] = e;  // bt�Ǹ����� idx�� �ش� data �ֱ� 
		// ���ο� �׸� �߰� ��� 
	}



}
