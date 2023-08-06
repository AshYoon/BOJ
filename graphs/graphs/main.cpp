//#include "graphAdjecencyMatrix.h"
#include "global.h"
#include <iostream>
#include <cstring>
//#include "graphAdjacencyList.h"
#include "graphAdjecencyMatrix.h"
#include "circularQueue.h"

extern Graph* kruskalMST(Graph* g);


void dijkstra(Graph* g, int src, int dist[], int previous[]);
int minDistance(int dist[], bool visited[], int nodeSize);

void dijkstra(Graph* g, int src, int dist[], int previous[])
{
	bool visited[MAX_NODE]; // 방문 완료 노드 저장 배열 
	int nodeSize = g->nodeSize;

	for (int i = 0; i < nodeSize; i++) // 모든 노드 최단 거리값 초기화 
	{
		dist[i] = INT_MAX; // 무한대값으로 조기화 
		visited[i] = false; // 모든 노드 방문 여부 false 
		previous[i] = -1; //최단거리 값 초기화 
	}

	dist[src] = 0; // 시작 노드의 최단 경로값은 0 으로 초기화 

	//모든 노드에 대해서 
	for (int count = 0; count < nodeSize - 1; count++)
	{
		// 방문 완료 하지 않는 노드들 중에서 최소 경로값을 가진 노드 선택
		int u = minDistance(dist, visited, nodeSize);
		if (u == INT_MAX) return; // 모든 노드를 방문 완료 했다면 종료 ,아마 방문할수없는 노드를 만난다면 종료인듯 ?

		visited[u] = true; // 선택된 현재 노드 방문 완료로 check 

		// 선택된 노드의 인접 노드들의 최소 경로 값수정 

		for (int v = 0; v < nodeSize; v++)
		{
			if (!visited[v]  // 방문 하지않은노드  
				&& g->adjMatrix[u][v]  // 에지가 존재하고 
				&& dist[u] + g->adjMatrix[u][v] < dist[v]) // 최단거리[u] + weight( u ,v) 가 기존의 최단거리[v]보다작다면 
			{
				dist[v] = dist[u] + g->adjMatrix[u][v]; // 최단거리수정 
				previous[v] = u; // 저장 
			}
		}
	
	
	
	
	
	}
}

int minDistance(int dist[], bool visited[], int nodeSize)
{
	int min = INT_MAX;
	int min_index = -1; // min_index를 -1로 초기화

	for (int v = 0; v < nodeSize; v++)
	{
		if (visited[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}

	return min_index;
}




//
//#define MAX (5) // 노드는 최대 5개를 대상 
//#define ROOT(x) (parent[x] == -1)
// 해당 조건문을 ROOT(x) 로 대신함 

// parent 배열을 통해서 , 노드 i 의 set 번호를 반환한다 
// 루트 노드에 도달할때까지 재귀함수를 호출한다 . 

//int setFind(int parent[], int i)
//{
//	if (ROOT(i)) // 조건문이 참이라면( 해당노드가 부모노드라면 ) 
//	{
//		return i; // 해당노드 반환 , 즉 return i 
//	}
//	else
//		return setFind(parent, parent[i]); // 아니라면 재귀로 setFind 
//}
//
//// 노드 x 와 노드 y 가 속한 집합을 합집합 
//// 노드 x 의 부모노드를 노드 y의 부모노드로 설정한다 
//
//void setUnion(int parent[], int x, int y)
//{
//	int xparent = setFind(parent, x); // setFind로 각각 부모 찾아주기 
//	int yparent = setFind(parent, y);	
//
//	parent[xparent] = yparent; // xparent의 부모는 y parent 
//}
//
//// 집합을 출력
//void setPrint(int parent[])
//{
//	printf("Parent Array: ");
//	for (int i = 0; i < MAX; i++)
//	{
//		printf("%d ", parent[i]);
//	}
//	printf("\n");
//
//	for (int i = 0; i < MAX; i++)
//	{
//		printf("set %d : ", i);
//		for (int j = 0; j < MAX; j++)
//		{
//			if (setFind(parent, j) == i) printf("%d ", j);
//		}
//
//		printf("\n");
//	}
//}



//
//void DepthFirstSearch(Graph* g , int node )
//{
//	g->list[node].head->next->visited = true;
//	//printf(" is visited &d", node);
//	cout << node << " is visited " << endl;
//	//printf("\n");
//	
//	for (int n = 0; n < g->nodeSize; ++n)
//	{
//		// head가 null인지 , head -> next가 null인지도 확인해야함 
//		if (g->list[n].head != NULL && g->list[n].head->next != NULL && g->list[n].head->next->visited == false)
//		{
//			DepthFirstSearch(g, n);
//			// visited를 확인하기전에 next가 nullptr인지 아닌지 확인해야한다 그 이후 조건 검사해야함 
//		}
//	}
//
//}

//// 인접 행렬에서 재귀함수를 이용한 깊이 우선 담색 
//void recursiveDFSforList(const Graph* g, bool visitied[], int start)
//{
//	// bool visited 는 방문한 노드를 저장 
//	//int 는 검색 시작 노드 번호 
//
//	visitied[start] = true;
//	printf("%d ->", start);
//	//printf("\n");
//	for (Node* n = g->list[start].head; n != NULL; n = n->next)
//	{
//		// node * n 은 g->list[start]의 head , head가 null이 아니라면 , n은 다음노드 
//		
//		if (!visitied[n->dest]) recursiveDFSforList(g, visitied, n->dest);
//	}
//
//}
//
//
//// 인접리스트넓이 우선 탐색 Binary First Search
//// 
//void BFSforList(Graph* g, bool visited[], int start)
//{
//	Queue q;
//	Element from;
//
//	init(&q);
//	visited[start] = true;
//	printf("%d->", start);
//	enQueue(&q, start);
//
//	while (!isEmpty(&q))
//	{
//		from = deQueue(&q);
//
//		for (Node* n = g->list[from].head; n != NULL; n = n->next)
//		{
//			if (!visited[n->dest])
//			{
//				visited[n->dest] = true;
//				printf("%d ->", n->dest);
//				enQueue(&q, n->dest);
//			}
//		}
//	}
//}



// 인접 행렬에서 recursive DFS 수행 , 
// 스택과 재귀 함수를 이용해서 구현 
// 
void recursiveDFSforMatrix(const Graph* g, bool visited[], int start)
{
	visited[start] = true;
	printf(" %d -> ", start);

	for (int v = 0; v < g->nodeSize; v++)
	{
		//노드 v 로의 edge가 존재하고 노드 v 를 방문하지않았다면 
		if (g->adjMatrix[start][v] && !visited[v]) recursiveDFSforMatrix(g, visited, v);
	}
}

void BFSforMatrix(const Graph* g, bool visited[], int start)
{
	Queue q;
	init(&q); // 큐 초기화 
	enQueue(&q, start);  // 큐에 start 추가 
	visited[start] = true;  // 방문한 노드번호를 visited 노드에서  true 로 바꿔줌 

	printf("%d -> ", start); //start 노드 print

	while (!isEmpty(&q)) // 비워지기 전까지 
	{
		int from = deQueue(&q); //큐에서 dequeue 한걸 from에 넣어주고 
		for (int to = 0; to < g->nodeSize; to++)
		{
			if (g->adjMatrix[from][to] && !visited[to]) // from에서 to로가는 edge가있다면 ,visited도 false라면 
			{
				enQueue(&q, to); // 큐에 to 넣어주고 , visited[to]는 true로 
				visited[to] = true;
				printf("%d ", to);

			}
		}
	}

	printf("\n");

}




//연결 성분을 구하는 재귀함수 
//int component[] : 각 노드마다 할당된 컴포넌트 번호 저장 
// int start : 연결 성분을 설정할 시작번호 
// int componentNo :연결 성분 번호 

void connectedComponent(const Graph* g, int component[], int start, int componentNo)
{
	component[start] = componentNo; // 첫노드에 컴포넌트 번호 할당 

	for (int v = 0; v < g->nodeSize; v++) // 모든노드에 대해서 
	{
		if (g->adjMatrix[start][v] && !component[v]) // [start][v]의 에지가 있으면 
		{
			connectedComponent(g, component, v, componentNo); // 재귀적으로 호출 
		}
	}
}


/// 연결성분을 구하는 드라이브함수 , 컴포넌트 번호는 1 부터 시작 

// int component[] : 각 노드마다 할당된 컴포넌트 번호 저장 

void connectedComponentDriver(const Graph* g, int component[])
{
	int componentNo = 0;
	for(int i = 0; i < g->nodeSize; i++) // 모든 노드에 대해 
		if (component[i] == 0) // 아직 방문하지않은 노드라면 
		{
			componentNo++; // 새로운 노드번호 할당하고 

			// 재귀함수로 연결된 노드에 같은 컴포넌트 번호 할당 
			connectedComponent(g, component, i, componentNo); 
		}
}

//연결성분 출력함수 
//
void connectedComponentPrint(const Graph* g, const int component[])
{
	printf("\n Connected Component Print \n");
	for (int i = 0; i < g->nodeSize; i++)
	{
		printf("%3d ", component[i]);
	}

	printf("\n");
}

int main()
{
	//Graph g;
	//create(&g, DIRECTED);

	//insertNode(&g, 0);
	//insertNode(&g, 1);
	//insertNode(&g, 2);
	//insertNode(&g, 3);
	//insertNode(&g, 4);

	//insertEdge(&g, 0, 1, 4);
	//insertEdge(&g, 0, 2, 2);
	//insertEdge(&g, 0, 3, 11);
	//insertEdge(&g, 0, 4, 10);
	//insertEdge(&g, 1, 3, 5);
	//insertEdge(&g, 2, 3, 8);
	//insertEdge(&g, 2, 4, 3);
	//insertEdge(&g, 3, 4, 1);

	//print(&g);
	//graphvizDriver(&g);
	//int dist[MAX_NODE];
	//int previous[MAX_NODE];

	////0번노드를 시작지점으로 
	//int start = 0;
	//dijkstra(&g, start, dist, previous);

	//printf("distance from node %d \n", start);
	//for (int i = 0; i < g.nodeSize; i++)
	//{
	//	printf("%d :  %d\n", i, dist[i]);
	//}


	//printf("Previous Node\n");
	//for (int i = 0; i < g.nodeSize; i++)
	//{
	//	printf("%d : %d\n", i, previous[i]);
	//}

	//// start 노드에서 모든 노드로의 최단 경로 출력 
	//for (int i = 0; i < g.nodeSize; i++)
	//{
	//	int end = i;
	//	printf("Endgind to node %d", end);
	//	while (previous[end] != -1)
	//	{
	//		printf("<--%d", previous[end]);
	//		end = previous[end];
	//	}
	//	printf("\n");
	//}





	/*************************************88kruskalMST 알고리즘 테스트***************************/ 
	//Graph g;
	////test for directed Graph

	//create(&g, DIRECTED);
	//insertNode(&g, 0);
	//insertNode(&g, 1);
	//insertNode(&g, 2);
	//insertNode(&g, 3);
	//insertNode(&g, 4);
	//
	//insertEdge(&g, 0, 1, 16);
	//insertEdge(&g, 0, 2, 2);
	//insertEdge(&g, 0, 3, 11);
	//insertEdge(&g, 0, 4, 9);
	//insertEdge(&g, 1, 3, 5);
	//insertEdge(&g, 2, 3, 16);
	//insertEdge(&g, 2, 4, 3);
	//insertEdge(&g, 3, 4, 1);

	//print(&g);
	//graphvizDriver(&g);

	//Graph* mst = kruskalMST(&g);
	//print(mst);
	//graphvizDriver(mst);

	////test for undirected graph
	//destroy(&g);

	//create(&g, UNDIRECTED);

	//insertNode(&g, 0);
	//insertNode(&g, 1);
	//insertNode(&g, 2);
	//insertNode(&g, 3);
	//insertNode(&g, 4);

	//insertEdge(&g, 0, 1, 16);
	//insertEdge(&g, 0, 2, 2);
	//insertEdge(&g, 0, 3, 11);
	//insertEdge(&g, 0, 4, 9);
	//insertEdge(&g, 1, 3, 5);
	//insertEdge(&g, 2, 3, 16);
	//insertEdge(&g, 2, 4, 3);
	//insertEdge(&g, 3, 4, 1);


	//print(&g);
	//graphvizDriver(&g);

	//Graph* mst2 = kruskalMST(&g);
	//print(mst2);
	//graphvizDriver(mst2);

	////////////////////////set union 연습 


	//int set[MAX];

	//// 시작시에모든 노드는 부모노드가 없음 , 자기 자신이 root node

	//for (int i = 0; i < MAX; i++) set[i] = -1;

	//setPrint(set);

	//setUnion(set, 1, 3); // 1 과 3 을 합집합 
	//setUnion(set, 2, 4); // 2 , 4 합집합 
	//setPrint(set); // 출력 

	//setUnion(set, 1, 2); // 1 집합과 2 집합을 합집합하고 1의 부모는 2 의 부모 
	//setPrint(set);




	// spanning Tree Test code 


	//printf("Connected Component Testing \n");
	//Graph g;


	//create(&g, DIRECTED);

	//insertNode(&g, 0);
	//insertNode(&g, 1);
	//insertNode(&g, 2);
	//insertNode(&g, 3);
	//insertNode(&g, 4);

	//insertEdge(&g, 0, 1 , 1);
	//insertEdge(&g, 0, 2 , 1);
	//insertEdge(&g, 0, 3 , 1);
	//insertEdge(&g, 0, 4 , 1);
	//insertEdge(&g, 1, 3 , 1);
	//insertEdge(&g, 2, 3 , 1);
	//insertEdge(&g, 2, 4 , 1);
	//insertEdge(&g, 3, 4 , 1);

	//print(&g);
	//graphvizDriver(&g);

	//Graph* st = spanningTreeDriver(&g);
	//printf("spanning tree Print\n");
	//graphvizDriver(st);



	//// 연결 성분 test code
	//printf("Connected Component Testing\n");

	//Graph g;
	//create(&g, DIRECTED);



	//insertNode(&g, 0);
	//insertNode(&g, 1);
	//insertNode(&g, 2);
	//insertNode(&g, 3);
	//insertNode(&g, 4);
	//insertNode(&g, 5);
	//insertNode(&g, 6);
	//insertNode(&g, 7);
	//insertNode(&g, 8);  // 노드 8개 삽입

	//insertEdge(&g, 0, 1); //ctrl + d , 현재 줄 아래줄로 복사 
	//insertEdge(&g, 0, 3);
	//insertEdge(&g, 1, 2);
	//insertEdge(&g, 3, 3);
	//insertEdge(&g, 4, 5);
	//insertEdge(&g, 4, 6);
	//insertEdge(&g, 5, 6);
	//insertEdge(&g, 7, 8); //edge 추가 

	//print(&g);
	//graphvizDriver(&g);
	//int component[MAX_NODE];
	//for (int v = 0; v < MAX_NODE; v++)
	//{
	//	component[v] = 0;
	//}
	//connectedComponentDriver(&g, component);
	//connectedComponentPrint(&g, component);

	//destroy(&g);






	//////////////////////////////////////////////////////
	////////////////////////인접 행렬로 구현한 DFS 와 BFS
	Graph g;

	create(&g, DIRECTED);

	insertNode(&g, 0);
	insertNode(&g, 1);
	insertNode(&g, 2);
	insertNode(&g, 3);
	insertNode(&g, 4);
	insertNode(&g, 5);

	
	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 1, 3);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);
	insertEdge(&g, 3, 4);

	print(&g);
	graphvizDriver(&g);

	bool visited[MAX_NODE];
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited[v] = false;
	}

	printf("\nrecursive DFS search for Matrix");
	recursiveDFSforMatrix(&g, visited, 0);
	for (int v = 0; v < MAX_NODE; v++)
	{
		visited[v] = false;
	}

	printf("\n BFS search for Matrix");
	BFSforMatrix(&g, visited, 0);
	destroy(&g);





	////////////////////////////////////////////////////
	//////////////////////////인접리스트로 구현한 DFS 와 BFS 
	//Graph* g;

	//g = create(5, UNDIRECTED); // 생성할때 5개로 node 수 고정 

	//insertEdge(g, 0, 1);
	//insertEdge(g, 0, 2);
	//insertEdge(g, 0, 3);
	//insertEdge(g, 0, 4);
	//insertEdge(g, 1, 3);
	//insertEdge(g, 2, 3);
	//insertEdge(g, 2, 4);
	//insertEdge(g, 3, 4);


	//print(g);


	//graphvizDirver(g);
	////graph search
	//bool Visited[5];
	//for (int v = 0; v < 5; v++) Visited[v] = false;
	//printf("\nrecursive DFS search : ");
	//recursiveDFSforList(g, Visited, 1);
	//printf("\n");






	//print(g);

	//graphvizDirver(g);
	//bool visited2[5];
	//for (int v = 0; v < 5; v++) visited2[v] = false;
	//printf("\nBFS search");
	//BFSforList(g, visited2, 1); // 방향성 그래프에서는 잘못된 결과값이 도출됨 


	//destroy(g);


}