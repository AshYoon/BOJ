#include <stdio.h>
#include "graphAdjecencyMatrix.h"
#include "circularQueue.h"
#include <cstring>


// �ڷᱸ���� �׷��� . ���� ����� �̿��ؼ� ���� 
// ������ �߰� / ���� , ����� �߰� /���� ��� 


//graph viz ����Լ� 




void graphvizPrint(Graph* g)
{
	char mode[3];


	if (g->mode == DIRECTED) strcpy(mode, "->");
	else strcpy(mode, "--");


	for (int r = 0; r < g->nodeSize; r++)
	{
		if (g->nodeList[r]) printf("\t\"%d\";\n", r);
	}


	if(g->mode == DIRECTED)
	for (int r = 0; r < MAX_SIZE; r++)
	{
		for (int c = 0; c < MAX_SIZE; c++)
		{
			if(g->adjMatrix[r][c]) printf("\t\"%d\" %s\"%d\" [label =\"%d\"];\n",r,mode ,c
			, g->adjMatrix[r][c]);
		}
	}

	if (g->mode == UNDIRECTED)
	{
		for (int r = 0; r < MAX_SIZE; r++)
		{
			for (int c = 0; c < r; c++)
			{
				if (g->adjMatrix[r][c]) printf("\t\"%d\" %s\"%d\" [label =\"%d\"];\n", r, mode, c
					, g->adjMatrix[r][c]);
			}
		}
	}
}

void graphvizDriver(Graph* g)
{
	if (g->mode == DIRECTED) printf("digraph G { \n ");
	else printf("graph G { \n");

	graphvizPrint(g);
	printf("}\n");

}

// �׷��� �ʱ�ȭ�Ѵ� 
// ���� ����� ���Ҹ� ��� false �� ǥ�� 
/// mode directed �Ǵ� undriected 
// ���ϰ� void 
// �Ű����� graph *g , GraphType mode 


void create(Graph* g, GraphType mode)
{

	int r, c;

	g->nodeSize = 0; // ���� ����ϴ� ����� ���� ���� 
	g->mode = mode; // ���� �츮�� ������ mode�� �޾ƿͼ� undirected���� directed ���� 
	for (r = 0; r < MAX_NODE; r++) // max node ���� 
	{ 
		g->nodeList[r] = false;  // �� ���� false �� 
		for (c = 0; c < MAX_NODE; c++)
		{
			g->adjMatrix[r][c] = false;  // �� ���� false 

		}
	}
}

// �׷��� ���� 
// ��������� �̿��� �׷��� ���� ����� �������� �޸𸮸� �Ҵ����� �ʱ� ������ 
// ���������δ� create ( Graph * g ) �Լ��� ȣ���ؼ� �׷��� �� �ʱ�ȭ���ش�
// ���� void , �Ű����� Graph *G

void destroy(Graph* g)
{
	create(g, g->mode); // �׳��ʱ�ȭ�ε� �̰� 
}

// �ش��ϴ� ��ȣ�� ��� �߰� 
// void return , �Ű����� graph*g , int mode 


void insertNode(Graph* g, int node)
{
	if (node >= MAX_NODE) // ��尡 max ��� ���� ũ�ų� ���ٸ� 
	{
		printf("Error : node no out of range . \n ");
			return;
	}

	g->nodeList[node] = true; // �ش� ��� true �� �ٲ��ֱ� 
	(g->nodeSize)++; // ��� size ++ 

}

void deleteNode(Graph* g, int node)
{
	if (node >= MAX_NODE)
	{
		printf(" Error : node no out of range . \n");
		return;
	}

	for (int i = 0; i < g->nodeSize; i++)
	{
		deleteEdge(g, i, node); // �ش� ���� ������ edge ���� 
		deleteEdge(g, node, i); // �ش��忡�� ������ edge ���� 

	}
	g->nodeList[node] = false;
	if (node == (g->nodeSize) - 1) (g->nodeSize)--;  



}




// node ��ȣ from ���� to �� edge �߰� 
// return : void , parameter , Graph *  g , int from , int to 
void insertEdge(Graph* g, int from, int to , int weight)
{
	if (from < 0 || from >= g->nodeSize || to < 0 || to >= g->nodeSize)
	{
		printf("error : node number out of range .\n");
		return; // ������ ��� ��尡 �ԷµǸ� �ٷ� return 
	}

	g->adjMatrix[from][to] = weight; // �ش� edge true 
	if (g->mode == UNDIRECTED) g->adjMatrix[to][from] = weight; // ���� �� ���⼺�̸� �ݴ뵵 true 
}


void insertEdge(Graph* g, int from, int to)
{
	if (from < 0 || from >= g->nodeSize || to < 0 || to >= g->nodeSize)
	{
		printf("Error : node no out of range. \n  ");
		return;
	}

	g->adjMatrix[from][to] = true;
	if (g->mode == UNDIRECTED) g->adjMatrix[to][from] = true;
}




// node ��ȣ from ���� to �� edge �� ���� 
// return : void , �Ķ���� , graph*g , int from , int to 

void deleteEdge(Graph* g, int from, int to)
{
	if (from < 0 || from >= g->nodeSize || to < 0 || to >= g->nodeSize)
	{
		printf("error : node number out of range .\n");
		return; // ������ ��� ��尡 �ԷµǸ� �ٷ� return 
	}

	g->adjMatrix[from][to] = false;
	if (g->mode == UNDIRECTED) g->adjMatrix[to][from] = false;


}


//graph ȭ�鿡 ���  

void print(const Graph* g)
{
	printf("graph Print \n");
	for (int r = 0; r < g->nodeSize; r++)
	{
		for (int c = 0; c < g->nodeSize; c++)
		{
			printf("%3d ", g->adjMatrix[r][c]);
		}
		printf("\n");
	}
}

int getNodeSize(Graph* g)
{

	// ��ü node ���� ���� ��	 ��ȯ 
	int n;
	int count = 0;
	for (n = 0; n < g->nodeSize; n++)
	{
		if (g->nodeList[n]) count++;
	}


	return count;
}

int getEdgeSize(Graph* g)
{
	// ��ü edge ���� ���� �� ��ȯ 
	int count = 0;

	for (int r = 0; r < g->nodeSize; r++)
	{
		for (int c = 0; c < g->nodeSize; c++)
		{
			if (g->adjMatrix[r][c]) count++;
		}
	}

	return count;

}

// �������� 2���� �迭�� �Ҵ��ؼ� �����Ѵٸ� ��带 �߰��Ҷ� ��������������ִ� 


//
Graph* spanningTreeDriver(const Graph* g)
{
	//DFS�� ���� Ž���ϴ� �������� , �̹� �湮�� ��带 �����ϴ� �迭 
	bool visited[MAX_NODE];

	//�ʱ�ȭ�� ��� ��带 �湮�����ʴ°����� üũ 
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited[v] = false;
	}

	// ������ ���� Ʈ���� ������ ������ �����Ҵ� �޴´� 
	Graph* st = (Graph*)malloc(sizeof(Graph));
	create(st, DIRECTED);

	spanningTreeDFS(g, 0, visited, st->adjMatrix);

	return st;

}



// ����Ʈ�� ���ϴ� ����Խ� 
void spanningTreeDFS(const Graph* g, int start, bool visited[], int adjMatrix[][MAX_NODE])
{

	visited[start] = true;
	for (int v = 0; v < g->nodeSize; v++)
	{
		if (g->adjMatrix[start][v] && !visited[v]) // edge�� �ְ� �湮�����ʾҴٸ� 
		{
			adjMatrix[start][v] = true; // true 
			spanningTreeDFS(g, v, visited, adjMatrix); // ��� 
		}
	}
}



