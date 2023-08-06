#pragma once
#ifndef _GRAPH_ADJECENCY_lIST_H
#define _GRAPH_ADJECENCY_lIST_H
// 방향성 비방향성 
typedef enum { UNDIRECTED = 0, DIRECTED = 1 } GraphType;

// 연결리스트 관리되는 인접 노드를 위한 구조체 , 

typedef struct Node {
	int dest; // destination 
	Node* next; // 연결되는노드 or NULL 
	bool visited ;
};

// 헤드 노드를 위한 구조체 
typedef struct HeadNodes {
	Node* head;

};

// 그래프 전체 총괄 구조체 
typedef struct Graph {
	int nodeSize;
	GraphType mode; // directed 인지 undirected 인지 
	HeadNodes* list;
} Graph;

//graph viz 
void graphvizDirver(Graph* g);
void graphvizPrint(Graph* g);

// 그래프 생성및 삭제 
Graph* create(int nodeNo, GraphType mode);
void destroy(Graph* g);

// Edge 추가및 삭제 
void insertEdge(Graph* g, int from, int to);
void deleteEdge(Graph* g, int from, int to);

// 새로운 노드 동적 생성 함수 
Node* newNode(int dest);

//그래프 콘솔에 출력함수 
void print(Graph* g);


#endif // !_GRAPH_ADJECENCY_lIST_H
