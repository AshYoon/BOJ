#pragma once
#ifndef _KRUSKAL_MST_H
#include "graphAdjecencyMatrix.h"

#define MAX_EDGE (100)

/*********MST ������ ���ؼ� ������ ������ �����ϴ� �ڷ��� *****************/
typedef struct Edge {
	int src, dest, weight;
	// source ? , destination , weight�� ����ġ 
	//source�� �� edge�� ����ϴ� ���� , dest�� �� edge�� �������� 
	// weight�� ����ġ	
};

typedef struct EdgeList {
	Edge data[MAX_EDGE];
	int size;
}EdgeList;

/******************find Union �Լ� ���� **************/

#define ROOT(x) (parent[x] == -1)  // find �� ���� define 
void setInit(int parent[]); // �ʱ�ȭ 


int setFind(int parent[], int i);
void setUnion(int parent[], int x,int y);


/*************kruskal MST ���� ������ ���� *************/

int cmpfunc(const void* a, const void* b); // edge �񱳸����� ? , sort�� ���� 
void sortEdgeList(Graph* g, EdgeList* elist);  // edge sort

Graph* kruskalMST(Graph* g);
// MST == minimmum spanning tree , �ּ� ���� Ʈ�� 
#endif // !_KRUSKAL_MST_H
