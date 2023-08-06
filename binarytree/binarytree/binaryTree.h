#pragma once


#ifndef _BINARY_TREE_ARRAY_
#define _BINARY_TREE_ARRAY_

#define MAX_SIZE (100)

typedef struct {
	bool isQuestion; // true : 비 단말 노드 , ( 내부 노드 ) 
	char msg[100]; // 내부노드이면 질문 , 단말노드이면 결론 // 스무고개 제작 
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