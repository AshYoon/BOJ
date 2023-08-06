#pragma once
#ifndef _GRAPH_ADJACENCY_MATRIX_H
#define _GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>

#define MAX_NODE (100)
typedef enum { DIRECTED = 0, UNDIRECTED = 1 } GraphType;

// 그래프에 필요한 구조체 정의 
typedef struct {
    GraphType mode;
    bool nodeList[MAX_NODE]; // Array for presence/absence of nodes (true present, false absent)
    int adjMatrix[MAX_NODE][MAX_NODE]; // Double array for adjacency matrix with weights
    int nodeSize; // actual number of nodes used
} Graph;

// 그래프 화면 출력함수 
void graphvizPrint(Graph* g);
void graphvizDriver(Graph* g);

void create(Graph* g, GraphType mode);
void destroy(Graph* g);

void insertNode(Graph* g, int node);
void deleteNode(Graph* g, int node);

void insertEdge(Graph* g, int from, int to ,int weight	);
void insertEdge(Graph* g, int from, int to);
void deleteEdge(Graph* g, int from, int to);

void print(const Graph* g);

// utility functions

int getNodeSize(Graph* g);
int getEdgeSize(Graph* g);


// 신장(골격) 트리 , 해당그래프를 모두 방문하는 최소한의 edge를 사용한 트리 
// 신장(골격) 이라는 뜻으로 이해해도된다 기초가되는 골격 
// 해당 그래프의 신장트리를 구해서 반환하는 함수 
Graph* spanningTreeDriver(const Graph* g);

// 깊이 우선 탐색으로 신장트리를 생성하는 함수 , 기존의 DFS 와 비슷하다 
void spanningTreeDFS(const Graph* g, int start, 
	bool visited[], int adjMatrix[][MAX_NODE]);


#endif