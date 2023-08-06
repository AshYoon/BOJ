#pragma once


#ifndef _BINARY_TREE_ARRAY_
#define _BINARY_TREE_ARRAY_

#define MAX_SIZE (100)

typedef struct {
	bool isQuestion; // true : �� �ܸ� ��� , ( ���� ��� ) 
	char msg[100]; // ���γ���̸� ���� , �ܸ�����̸� ��� // ������ ���� 
}Element;

typedef struct {
	Element data[MAX_SIZE];
	int size;
}BinaryTree;

void init(BinaryTree* bt);
int leftChild(const BinaryTree* bt, const int pos);
int rightChild(const BinaryTree* bt, const int pos);
int parent(const BinaryTree* bt, const int pos);
Element value(const BinaryTree* bt, const int pos);
void insert(BinaryTree* bt, const Element e);

#endif