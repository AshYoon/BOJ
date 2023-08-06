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
	bool visited[MAX_NODE]; // �湮 �Ϸ� ��� ���� �迭 
	int nodeSize = g->nodeSize;

	for (int i = 0; i < nodeSize; i++) // ��� ��� �ִ� �Ÿ��� �ʱ�ȭ 
	{
		dist[i] = INT_MAX; // ���Ѵ밪���� ����ȭ 
		visited[i] = false; // ��� ��� �湮 ���� false 
		previous[i] = -1; //�ִܰŸ� �� �ʱ�ȭ 
	}

	dist[src] = 0; // ���� ����� �ִ� ��ΰ��� 0 ���� �ʱ�ȭ 

	//��� ��忡 ���ؼ� 
	for (int count = 0; count < nodeSize - 1; count++)
	{
		// �湮 �Ϸ� ���� �ʴ� ���� �߿��� �ּ� ��ΰ��� ���� ��� ����
		int u = minDistance(dist, visited, nodeSize);
		if (u == INT_MAX) return; // ��� ��带 �湮 �Ϸ� �ߴٸ� ���� ,�Ƹ� �湮�Ҽ����� ��带 �����ٸ� �����ε� ?

		visited[u] = true; // ���õ� ���� ��� �湮 �Ϸ�� check 

		// ���õ� ����� ���� ������ �ּ� ��� ������ 

		for (int v = 0; v < nodeSize; v++)
		{
			if (!visited[v]  // �湮 �����������  
				&& g->adjMatrix[u][v]  // ������ �����ϰ� 
				&& dist[u] + g->adjMatrix[u][v] < dist[v]) // �ִܰŸ�[u] + weight( u ,v) �� ������ �ִܰŸ�[v]�����۴ٸ� 
			{
				dist[v] = dist[u] + g->adjMatrix[u][v]; // �ִܰŸ����� 
				previous[v] = u; // ���� 
			}
		}
	
	
	
	
	
	}
}

int minDistance(int dist[], bool visited[], int nodeSize)
{
	int min = INT_MAX;
	int min_index = -1; // min_index�� -1�� �ʱ�ȭ

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
//#define MAX (5) // ���� �ִ� 5���� ��� 
//#define ROOT(x) (parent[x] == -1)
// �ش� ���ǹ��� ROOT(x) �� ����� 

// parent �迭�� ���ؼ� , ��� i �� set ��ȣ�� ��ȯ�Ѵ� 
// ��Ʈ ��忡 �����Ҷ����� ����Լ��� ȣ���Ѵ� . 

//int setFind(int parent[], int i)
//{
//	if (ROOT(i)) // ���ǹ��� ���̶��( �ش��尡 �θ����� ) 
//	{
//		return i; // �ش��� ��ȯ , �� return i 
//	}
//	else
//		return setFind(parent, parent[i]); // �ƴ϶�� ��ͷ� setFind 
//}
//
//// ��� x �� ��� y �� ���� ������ ������ 
//// ��� x �� �θ��带 ��� y�� �θ���� �����Ѵ� 
//
//void setUnion(int parent[], int x, int y)
//{
//	int xparent = setFind(parent, x); // setFind�� ���� �θ� ã���ֱ� 
//	int yparent = setFind(parent, y);	
//
//	parent[xparent] = yparent; // xparent�� �θ�� y parent 
//}
//
//// ������ ���
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
//		// head�� null���� , head -> next�� null������ Ȯ���ؾ��� 
//		if (g->list[n].head != NULL && g->list[n].head->next != NULL && g->list[n].head->next->visited == false)
//		{
//			DepthFirstSearch(g, n);
//			// visited�� Ȯ���ϱ����� next�� nullptr���� �ƴ��� Ȯ���ؾ��Ѵ� �� ���� ���� �˻��ؾ��� 
//		}
//	}
//
//}

//// ���� ��Ŀ��� ����Լ��� �̿��� ���� �켱 ��� 
//void recursiveDFSforList(const Graph* g, bool visitied[], int start)
//{
//	// bool visited �� �湮�� ��带 ���� 
//	//int �� �˻� ���� ��� ��ȣ 
//
//	visitied[start] = true;
//	printf("%d ->", start);
//	//printf("\n");
//	for (Node* n = g->list[start].head; n != NULL; n = n->next)
//	{
//		// node * n �� g->list[start]�� head , head�� null�� �ƴ϶�� , n�� ������� 
//		
//		if (!visitied[n->dest]) recursiveDFSforList(g, visitied, n->dest);
//	}
//
//}
//
//
//// ��������Ʈ���� �켱 Ž�� Binary First Search
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



// ���� ��Ŀ��� recursive DFS ���� , 
// ���ð� ��� �Լ��� �̿��ؼ� ���� 
// 
void recursiveDFSforMatrix(const Graph* g, bool visited[], int start)
{
	visited[start] = true;
	printf(" %d -> ", start);

	for (int v = 0; v < g->nodeSize; v++)
	{
		//��� v ���� edge�� �����ϰ� ��� v �� �湮�����ʾҴٸ� 
		if (g->adjMatrix[start][v] && !visited[v]) recursiveDFSforMatrix(g, visited, v);
	}
}

void BFSforMatrix(const Graph* g, bool visited[], int start)
{
	Queue q;
	init(&q); // ť �ʱ�ȭ 
	enQueue(&q, start);  // ť�� start �߰� 
	visited[start] = true;  // �湮�� ����ȣ�� visited ��忡��  true �� �ٲ��� 

	printf("%d -> ", start); //start ��� print

	while (!isEmpty(&q)) // ������� ������ 
	{
		int from = deQueue(&q); //ť���� dequeue �Ѱ� from�� �־��ְ� 
		for (int to = 0; to < g->nodeSize; to++)
		{
			if (g->adjMatrix[from][to] && !visited[to]) // from���� to�ΰ��� edge���ִٸ� ,visited�� false��� 
			{
				enQueue(&q, to); // ť�� to �־��ְ� , visited[to]�� true�� 
				visited[to] = true;
				printf("%d ", to);

			}
		}
	}

	printf("\n");

}




//���� ������ ���ϴ� ����Լ� 
//int component[] : �� ��帶�� �Ҵ�� ������Ʈ ��ȣ ���� 
// int start : ���� ������ ������ ���۹�ȣ 
// int componentNo :���� ���� ��ȣ 

void connectedComponent(const Graph* g, int component[], int start, int componentNo)
{
	component[start] = componentNo; // ù��忡 ������Ʈ ��ȣ �Ҵ� 

	for (int v = 0; v < g->nodeSize; v++) // ����忡 ���ؼ� 
	{
		if (g->adjMatrix[start][v] && !component[v]) // [start][v]�� ������ ������ 
		{
			connectedComponent(g, component, v, componentNo); // ��������� ȣ�� 
		}
	}
}


/// ���Ἲ���� ���ϴ� ����̺��Լ� , ������Ʈ ��ȣ�� 1 ���� ���� 

// int component[] : �� ��帶�� �Ҵ�� ������Ʈ ��ȣ ���� 

void connectedComponentDriver(const Graph* g, int component[])
{
	int componentNo = 0;
	for(int i = 0; i < g->nodeSize; i++) // ��� ��忡 ���� 
		if (component[i] == 0) // ���� �湮�������� ����� 
		{
			componentNo++; // ���ο� ����ȣ �Ҵ��ϰ� 

			// ����Լ��� ����� ��忡 ���� ������Ʈ ��ȣ �Ҵ� 
			connectedComponent(g, component, i, componentNo); 
		}
}

//���Ἲ�� ����Լ� 
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

	////0����带 ������������ 
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

	//// start ��忡�� ��� ������ �ִ� ��� ��� 
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





	/*************************************88kruskalMST �˰��� �׽�Ʈ***************************/ 
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

	////////////////////////set union ���� 


	//int set[MAX];

	//// ���۽ÿ���� ���� �θ��尡 ���� , �ڱ� �ڽ��� root node

	//for (int i = 0; i < MAX; i++) set[i] = -1;

	//setPrint(set);

	//setUnion(set, 1, 3); // 1 �� 3 �� ������ 
	//setUnion(set, 2, 4); // 2 , 4 ������ 
	//setPrint(set); // ��� 

	//setUnion(set, 1, 2); // 1 ���հ� 2 ������ �������ϰ� 1�� �θ�� 2 �� �θ� 
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



	//// ���� ���� test code
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
	//insertNode(&g, 8);  // ��� 8�� ����

	//insertEdge(&g, 0, 1); //ctrl + d , ���� �� �Ʒ��ٷ� ���� 
	//insertEdge(&g, 0, 3);
	//insertEdge(&g, 1, 2);
	//insertEdge(&g, 3, 3);
	//insertEdge(&g, 4, 5);
	//insertEdge(&g, 4, 6);
	//insertEdge(&g, 5, 6);
	//insertEdge(&g, 7, 8); //edge �߰� 

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
	////////////////////////���� ��ķ� ������ DFS �� BFS
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
	//////////////////////////��������Ʈ�� ������ DFS �� BFS 
	//Graph* g;

	//g = create(5, UNDIRECTED); // �����Ҷ� 5���� node �� ���� 

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
	//BFSforList(g, visited2, 1); // ���⼺ �׷��������� �߸��� ������� ����� 


	//destroy(g);


}