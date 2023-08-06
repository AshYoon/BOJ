#pragma once
#ifndef _GRAPH_ADJECENCY_lIST_H
#define _GRAPH_ADJECENCY_lIST_H
// ���⼺ ����⼺ 
typedef enum { UNDIRECTED = 0, DIRECTED = 1 } GraphType;

// ���Ḯ��Ʈ �����Ǵ� ���� ��带 ���� ����ü , 

typedef struct Node {
	int dest; // destination 
	Node* next; // ����Ǵ³�� or NULL 
	bool visited ;
};

// ��� ��带 ���� ����ü 
typedef struct HeadNodes {
	Node* head;

};

// �׷��� ��ü �Ѱ� ����ü 
typedef struct Graph {
	int nodeSize;
	GraphType mode; // directed ���� undirected ���� 
	HeadNodes* list;
} Graph;

//graph viz 
void graphvizDirver(Graph* g);
void graphvizPrint(Graph* g);

// �׷��� ������ ���� 
Graph* create(int nodeNo, GraphType mode);
void destroy(Graph* g);

// Edge �߰��� ���� 
void insertEdge(Graph* g, int from, int to);
void deleteEdge(Graph* g, int from, int to);

// ���ο� ��� ���� ���� �Լ� 
Node* newNode(int dest);

//�׷��� �ֿܼ� ����Լ� 
void print(Graph* g);


#endif // !_GRAPH_ADJECENCY_lIST_H
