#pragma once
#ifndef _KRUSKAL_MST_H
#include "graphAdjecencyMatrix.h"

#define MAX_EDGE (100)

/*********MST 생성을 위해서 에지를 별도로 보관하는 자료형 *****************/
typedef struct Edge {
	int src, dest, weight;
	// source ? , destination , weight는 가중치 
	//source는 이 edge가 출발하는 지점 , dest는 이 edge의 도착지점 
	// weight는 가중치	
};

typedef struct EdgeList {
	Edge data[MAX_EDGE];
	int size;
}EdgeList;

/******************find Union 함수 선언 **************/

#define ROOT(x) (parent[x] == -1)  // find 를 위한 define 
void setInit(int parent[]); // 초기화 


int setFind(int parent[], int i);
void setUnion(int parent[], int x,int y);


/*************kruskal MST 관련 ㅎ마수 선언 *************/

int cmpfunc(const void* a, const void* b); // edge 비교를위한 ? , sort를 위한 
void sortEdgeList(Graph* g, EdgeList* elist);  // edge sort

Graph* kruskalMST(Graph* g);
// MST == minimmum spanning tree , 최소 신장 트리 
#endif // !_KRUSKAL_MST_H
