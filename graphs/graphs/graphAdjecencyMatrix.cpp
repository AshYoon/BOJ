#include <stdio.h>
#include "graphAdjecencyMatrix.h"
#include "circularQueue.h"
#include <cstring>


// 자료구조의 그래프 . 인접 행렬을 이용해서 구현 
// 에지의 추가 / 삭제 , 노드의 추가 /삭제 기능 


//graph viz 출력함수 




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

// 그래프 초기화한다 
// 인접 행렬의 원소를 모두 false 로 표시 
/// mode directed 또는 undriected 
// 리턴값 void 
// 매개변수 graph *g , GraphType mode 


void create(Graph* g, GraphType mode)
{

	int r, c;

	g->nodeSize = 0; // 실제 사용하는 노드의 개수 관리 
	g->mode = mode; // 모드는 우리가 설정한 mode를 받아와서 undirected인지 directed 인지 
	for (r = 0; r < MAX_NODE; r++) // max node 까지 
	{ 
		g->nodeList[r] = false;  // 행 전부 false 로 
		for (c = 0; c < MAX_NODE; c++)
		{
			g->adjMatrix[r][c] = false;  // 열 전부 false 

		}
	}
}

// 그래프 삭제 
// 인접행렬을 이용한 그래프 구현 방법은 동적으로 메모리를 할당하지 않기 떄문에 
// 내부적으로는 create ( Graph * g ) 함수를 호출해서 그래프 를 초기화해준다
// 리턴 void , 매개변수 Graph *G

void destroy(Graph* g)
{
	create(g, g->mode); // 그냥초기화인데 이건 
}

// 해당하는 번호의 노드 추가 
// void return , 매개변수 graph*g , int mode 


void insertNode(Graph* g, int node)
{
	if (node >= MAX_NODE) // 노드가 max 노드 보다 크거나 같다면 
	{
		printf("Error : node no out of range . \n ");
			return;
	}

	g->nodeList[node] = true; // 해당 노드 true 로 바꾸주기 
	(g->nodeSize)++; // 노드 size ++ 

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
		deleteEdge(g, i, node); // 해당 노드로 들어오는 edge 삭제 
		deleteEdge(g, node, i); // 해당노드에서 나가는 edge 삭제 

	}
	g->nodeList[node] = false;
	if (node == (g->nodeSize) - 1) (g->nodeSize)--;  



}




// node 번호 from 에서 to 의 edge 추가 
// return : void , parameter , Graph *  g , int from , int to 
void insertEdge(Graph* g, int from, int to , int weight)
{
	if (from < 0 || from >= g->nodeSize || to < 0 || to >= g->nodeSize)
	{
		printf("error : node number out of range .\n");
		return; // 범위를 벗어난 노드가 입력되면 바로 return 
	}

	g->adjMatrix[from][to] = weight; // 해당 edge true 
	if (g->mode == UNDIRECTED) g->adjMatrix[to][from] = weight; // 만약 비 방향성이면 반대도 true 
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




// node 번호 from 에서 to 의 edge 를 삭제 
// return : void , 파라미터 , graph*g , int from , int to 

void deleteEdge(Graph* g, int from, int to)
{
	if (from < 0 || from >= g->nodeSize || to < 0 || to >= g->nodeSize)
	{
		printf("error : node number out of range .\n");
		return; // 범위를 벗어난 노드가 입력되면 바로 return 
	}

	g->adjMatrix[from][to] = false;
	if (g->mode == UNDIRECTED) g->adjMatrix[to][from] = false;


}


//graph 화면에 출력  

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

	// 전체 node 개수 측정 및	 반환 
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
	// 전체 edge 갯수 측정 및 반환 
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

// 동적으로 2차원 배열을 할당해서 구현한다면 노드를 추가할때 문제가생길수도있다 


//
Graph* spanningTreeDriver(const Graph* g)
{
	//DFS를 위해 탐색하는 과정에서 , 이미 방문한 노드를 저장하는 배열 
	bool visited[MAX_NODE];

	//초기화로 모든 노드를 방문하지않는것으로 체크 
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited[v] = false;
	}

	// 생성된 신장 트리를 저장할 변수를 동적할당 받는다 
	Graph* st = (Graph*)malloc(sizeof(Graph));
	create(st, DIRECTED);

	spanningTreeDFS(g, 0, visited, st->adjMatrix);

	return st;

}



// 신장트리 구하는 재귀함슈 
void spanningTreeDFS(const Graph* g, int start, bool visited[], int adjMatrix[][MAX_NODE])
{

	visited[start] = true;
	for (int v = 0; v < g->nodeSize; v++)
	{
		if (g->adjMatrix[start][v] && !visited[v]) // edge가 있고 방문하지않았다면 
		{
			adjMatrix[start][v] = true; // true 
			spanningTreeDFS(g, v, visited, adjMatrix); // 재귀 
		}
	}
}



