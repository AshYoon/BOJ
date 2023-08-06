//#include <stdio.h>
//#include <stdlib.h>
//#include <cstring>
//#include "graphAdjacencyList.h"
//
//void graphvizDirver(Graph* g)
//{
//	if (g->mode == DIRECTED) printf("digraph G {\n");
//	else printf("graph G {\n");
//
//	graphvizPrint(g);
//
//	printf("}\n");
//}
//
//void graphvizPrint(Graph* g)
//{
//	const char* mode;
//
//	if (g->mode == DIRECTED)
//		mode = "->";
//	else
//		mode = "--";
//
//	for (int v = 0; v < g->nodeSize; v++)
//	{
//		printf("\t\"%d\";\n",v);
//	}
//
//
//	for (int i = 0; i < g->nodeSize; i++)
//	{
//		Node* n = g->list[i].head;
//		while (n != NULL)
//		{
//			printf("\t\"%d\" -> \"%d\";\n", i, n->dest);
//			n = n->next;
//		}
//	}
//}
//
//// node,개수 변경 불가 , 처음부터 고정 
//// mode = 방향성 비 방향성 여부 
//Graph* create(int nodeNo, GraphType mode)
//{
//	Graph* g = (Graph*)malloc(sizeof(Graph));
//	g->nodeSize = nodeNo;
//	g->mode = mode;
//	g->list = (HeadNodes*)malloc(nodeNo * sizeof(HeadNodes));
//
//	for (int i = 0; i < nodeNo; ++i)
//	{
//		g->list[i].head = NULL;
//		
//	}
//
//	return g;
//
//}
//
//// 동적할당한 메모리 해제 
//
//void destroy(Graph* g)
//{
//
//	for (int v = 0; v < g->nodeSize; ++v)
//		free(g->list[v].head);
//	g->nodeSize = 0;
//	free(g->list);
//
//	return;
//
//	
//
//}
//
// // edge 추가 ,from은 시작 , to 는 도착노드 
//void insertEdge(Graph* g, int from, int to)
//{
//	Node* n = newNode(to); // 목적지 노드 번호를 가지고있는 노드 생성 
//
//	// 새로운 노드가 리스트의 head 부분 , 연결리스트의 제일 앞부분에 추가됨 
//	n->next = g->list[from].head;
//	g->list[from].head = n;
//
//	// 비 방향성일 경우 반대방향에도 추가해줌 
//	if (g->mode == UNDIRECTED)
//	{
//		n = newNode(from);
//		n->next = g->list[to].head;
//		g->list[to].head = n;
//	}
//}
//
//
//// 
//void deleteEdge(Graph* g, int from, int to)
//{
//	// not implemented , 
//}
//
//
//Node* newNode(int dest)//그래프에 에지를 추가하는 경우 연결리스트의 노드 생성 
//{
//	Node* n = (Node*)malloc(sizeof(Node)); // 동적할당해주고 
//	n->dest = dest; // 
//	n->next = NULL;
//	n->visited = false;
//	return n;
//}
//
//void print(Graph* g)
//{
//	for (int v = 0; v < g->nodeSize; v++)
//	{
//		Node* n = g->list[v].head;
//		printf("vertex  %d : ", v);
//		while (n) // n->next가 null일 경우 자동으로 종료되는 while문 
//		{
//			printf("-> %d", n->dest);
//			n = n->next;
//		}
//
//		printf("\n");
//	}
//}
