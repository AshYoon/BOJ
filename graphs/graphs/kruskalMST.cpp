#include "kruskalMST.h"
#include <stdio.h>
#include <stdlib.h>

/// kruskal MST 

// kruskal 의 최소신장트리(MST) 알고리즘 

// 리턴값 - 생성된 MST 그래프의 Graph * 
// 매개변수 - Graph * ,
// Greedy 알고리즘 




// set  , union 함수 
void setInit(int parent[])
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		parent[i] = -1; 
	}
	// parent 함수 루트노드 자기자신으로 모두 초기화 
}

int setFind(int parent[], int i)
{
	if (ROOT(i))
	{
		return i;
	}
	else
	{
		return setFind(parent, parent[i]);
	}
}

void setUnion(int parent[], int x, int y)
{
	 int xparent = setFind(parent, x);
	 int yparent = setFind(parent, y);

	 parent[xparent] = yparent;


}


// qsort() 함수에 파라미터로 전해지는 
//함수포인터에 의해서 qsort() 의 항목 사이의 비교를 수행하는 함수 

int cmpfunc(const void* a, const void* b)
{
	return(((Edge*)a)->weight > ((Edge*)b)->weight);
	// 둘의 가중치를 비교해서 큰 가중치를 반환 
}




//  비 방향성 그래프의 에지들을 별도의 edgelist 변수에 오름차순으로 정렬 

void sortEdgeList(Graph* g, EdgeList* elist)
{
	//그래프에서 에지들을보갓해서 별도의 edgelist 생성 
	elist->size = 0;
	if (g->mode == UNDIRECTED)
	{
		for (int i = 0; i < g->nodeSize; i++)
		{
			for (int j = 0; j < i; j++) // 이 부분이다름 ?? 왜 ? 방향성노드는 중복되는 에지가 생기면안되니깐 
			{// 중복되는 edge를 방지하기위해 j <  i 
				if (g->adjMatrix[i][j])
				{
					elist->data[elist->size].src = i; //이 edge의 출발 노드 
					elist->data[elist->size].dest = j; // 이 edge의 도착도느
					elist->data[elist->size].weight = g->adjMatrix[i][j];


					elist->size++;// edge가 추가될때마다 elist의 size ++ 
				}
			}
		}
	}
	else if (g->mode == DIRECTED)
	{
		for (int i = 0; i < g->nodeSize; i++)
		{
			for (int j = 0; j < g->nodeSize; j++)
			{
				if (g->adjMatrix[i][j])
				{
					elist->data[elist->size].src = i;
					elist->data[elist->size].dest = j;
					elist->data[elist->size].weight = g->adjMatrix[i][j];
					elist->size++;
				}
			}
		}
	}


	//edge list 정렬전 
	for (int i = 0; i < elist->size; i++)
	{
		printf("%d ", elist->data[i].weight);
	}

	printf("\n");
	//edge list 정렬 
	qsort(elist->data, elist->size, sizeof(Edge), cmpfunc);
	// 퀵 소트 , cmpfunc를기준으로 elist->data를 elist size만큼 정렬
	// sizeof(Edge) 는 구조체의 크기를 기준으로 cmpfunc을 사용해여 정렬 
	//qsort에게 sizeof(Edge)는 함수에게 정렬할 요소의 크기를 알려줌 
	// 따라서 직접적인 메모리 공간을 할당하고 정렬을 수행가능하게함 


	// edge list 정렬후 
	for (int i = 0; i < elist->size; i++)
	{
		printf("%d ", elist->data[i].weight);
	}

	printf("\n");



}



/// kruskal MST 

// kruskal 의 최소신장트리(MST) 알고리즘 

// 리턴값 - 생성된 MST 그래프의 Graph * 
// 매개변수 - Graph * ,
// Greedy 알고리즘 

Graph* kruskalMST(Graph* g)
{
	// MST 그래프를 위한 노드 초기화 , ( 원 그래프의 노드를 복사함 ) 
	Graph* mst = (Graph*)malloc(sizeof(Graph));
	create(mst, g->mode);
	for (int node = 0; node < g->nodeSize; node++)
	{
		insertNode(mst, node);
	}

	//find Union 연산을 위한 set 초기화 
	int set[MAX_EDGE];
	setInit(set);

	// 원 그래프의 에지를 정렬
	EdgeList elist;
	// ?? 노드만복사한거지 edge는 elist에 하나도 안들어가있는데왜 sortedgelist를함 ? 


	sortEdgeList(g, &elist);

	//에지를 하나씩추가하면서 cycle 유무의 검사 
	for (int e = 0; e < elist.size; e++)
	{
		Edge next_edge = elist.data[e];
		int x = setFind(set, elist.data[e].src); // ?? 아마 src는 출발노드 , dest는도착노드 
		int y = setFind(set, elist.data[e].dest); // 다음노드 
		if (x != y) // 중복 edge가 아니라면 
		{
			insertEdge(mst, elist.data[e].src, elist.data[e].dest, elist.data[e].weight);
			setUnion(set, x, y);
		}
	}

	return mst;

}
