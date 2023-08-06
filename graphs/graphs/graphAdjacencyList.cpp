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
//// node,���� ���� �Ұ� , ó������ ���� 
//// mode = ���⼺ �� ���⼺ ���� 
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
//// �����Ҵ��� �޸� ���� 
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
// // edge �߰� ,from�� ���� , to �� ������� 
//void insertEdge(Graph* g, int from, int to)
//{
//	Node* n = newNode(to); // ������ ��� ��ȣ�� �������ִ� ��� ���� 
//
//	// ���ο� ��尡 ����Ʈ�� head �κ� , ���Ḯ��Ʈ�� ���� �պκп� �߰��� 
//	n->next = g->list[from].head;
//	g->list[from].head = n;
//
//	// �� ���⼺�� ��� �ݴ���⿡�� �߰����� 
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
//Node* newNode(int dest)//�׷����� ������ �߰��ϴ� ��� ���Ḯ��Ʈ�� ��� ���� 
//{
//	Node* n = (Node*)malloc(sizeof(Node)); // �����Ҵ����ְ� 
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
//		while (n) // n->next�� null�� ��� �ڵ����� ����Ǵ� while�� 
//		{
//			printf("-> %d", n->dest);
//			n = n->next;
//		}
//
//		printf("\n");
//	}
//}
