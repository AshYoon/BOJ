#pragma once
#ifndef _GRAPH_ADJACENCY_MATRIX_H
#define _GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>

#define MAX_NODE (100)
typedef enum { DIRECTED = 0, UNDIRECTED = 1 } GraphType;

// �׷����� �ʿ��� ����ü ���� 
typedef struct {
    GraphType mode;
    bool nodeList[MAX_NODE]; // Array for presence/absence of nodes (true present, false absent)
    int adjMatrix[MAX_NODE][MAX_NODE]; // Double array for adjacency matrix with weights
    int nodeSize; // actual number of nodes used
} Graph;

// �׷��� ȭ�� ����Լ� 
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


// ����(���) Ʈ�� , �ش�׷����� ��� �湮�ϴ� �ּ����� edge�� ����� Ʈ�� 
// ����(���) �̶�� ������ �����ص��ȴ� ���ʰ��Ǵ� ��� 
// �ش� �׷����� ����Ʈ���� ���ؼ� ��ȯ�ϴ� �Լ� 
Graph* spanningTreeDriver(const Graph* g);

// ���� �켱 Ž������ ����Ʈ���� �����ϴ� �Լ� , ������ DFS �� ����ϴ� 
void spanningTreeDFS(const Graph* g, int start, 
	bool visited[], int adjMatrix[][MAX_NODE]);


#endif