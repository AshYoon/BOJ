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
	if (pos == 1) return 0; // pos 가 만약 root 면 0 을 반환 
	else return pos / 2; // 아니라면 pos /2 를 반환 
	
}

Element value(const BinaryTree* bt, const int pos)
{
	if (pos >= 0 && pos <= bt->size) // pos 가 0보다 크고 트리의 사이즈보다작을때
		return bt->data[pos]; //bt 안의 pos 번의 value 를 return 
	// pos 가 0 이면 error 지면 여기서는 pos 가 0 이면 0 을 반환하는것으로 가정 
}

void insert(BinaryTree* bt, const Element e)
{
	if (bt->size >= MAX_SIZE - 1) return;
	else {
		bt->size++;  // bt 사이즈 증가시켜주고 
		bt->data[bt->size] = e;  // bt의마지막 idx에 해당 data 넣기 
		// 새로운 항목 추가 방법 
	}



}
