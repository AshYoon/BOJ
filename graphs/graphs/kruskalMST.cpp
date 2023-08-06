#include "kruskalMST.h"
#include <stdio.h>
#include <stdlib.h>

/// kruskal MST 

// kruskal �� �ּҽ���Ʈ��(MST) �˰��� 

// ���ϰ� - ������ MST �׷����� Graph * 
// �Ű����� - Graph * ,
// Greedy �˰��� 




// set  , union �Լ� 
void setInit(int parent[])
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		parent[i] = -1; 
	}
	// parent �Լ� ��Ʈ��� �ڱ��ڽ����� ��� �ʱ�ȭ 
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


// qsort() �Լ��� �Ķ���ͷ� �������� 
//�Լ������Ϳ� ���ؼ� qsort() �� �׸� ������ �񱳸� �����ϴ� �Լ� 

int cmpfunc(const void* a, const void* b)
{
	return(((Edge*)a)->weight > ((Edge*)b)->weight);
	// ���� ����ġ�� ���ؼ� ū ����ġ�� ��ȯ 
}




//  �� ���⼺ �׷����� �������� ������ edgelist ������ ������������ ���� 

void sortEdgeList(Graph* g, EdgeList* elist)
{
	//�׷������� �������������ؼ� ������ edgelist ���� 
	elist->size = 0;
	if (g->mode == UNDIRECTED)
	{
		for (int i = 0; i < g->nodeSize; i++)
		{
			for (int j = 0; j < i; j++) // �� �κ��̴ٸ� ?? �� ? ���⼺���� �ߺ��Ǵ� ������ �����ȵǴϱ� 
			{// �ߺ��Ǵ� edge�� �����ϱ����� j <  i 
				if (g->adjMatrix[i][j])
				{
					elist->data[elist->size].src = i; //�� edge�� ��� ��� 
					elist->data[elist->size].dest = j; // �� edge�� ��������
					elist->data[elist->size].weight = g->adjMatrix[i][j];


					elist->size++;// edge�� �߰��ɶ����� elist�� size ++ 
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


	//edge list ������ 
	for (int i = 0; i < elist->size; i++)
	{
		printf("%d ", elist->data[i].weight);
	}

	printf("\n");
	//edge list ���� 
	qsort(elist->data, elist->size, sizeof(Edge), cmpfunc);
	// �� ��Ʈ , cmpfunc���������� elist->data�� elist size��ŭ ����
	// sizeof(Edge) �� ����ü�� ũ�⸦ �������� cmpfunc�� ����ؿ� ���� 
	//qsort���� sizeof(Edge)�� �Լ����� ������ ����� ũ�⸦ �˷��� 
	// ���� �������� �޸� ������ �Ҵ��ϰ� ������ ���డ���ϰ��� 


	// edge list ������ 
	for (int i = 0; i < elist->size; i++)
	{
		printf("%d ", elist->data[i].weight);
	}

	printf("\n");



}



/// kruskal MST 

// kruskal �� �ּҽ���Ʈ��(MST) �˰��� 

// ���ϰ� - ������ MST �׷����� Graph * 
// �Ű����� - Graph * ,
// Greedy �˰��� 

Graph* kruskalMST(Graph* g)
{
	// MST �׷����� ���� ��� �ʱ�ȭ , ( �� �׷����� ��带 ������ ) 
	Graph* mst = (Graph*)malloc(sizeof(Graph));
	create(mst, g->mode);
	for (int node = 0; node < g->nodeSize; node++)
	{
		insertNode(mst, node);
	}

	//find Union ������ ���� set �ʱ�ȭ 
	int set[MAX_EDGE];
	setInit(set);

	// �� �׷����� ������ ����
	EdgeList elist;
	// ?? ��常�����Ѱ��� edge�� elist�� �ϳ��� �ȵ��ִµ��� sortedgelist���� ? 


	sortEdgeList(g, &elist);

	//������ �ϳ����߰��ϸ鼭 cycle ������ �˻� 
	for (int e = 0; e < elist.size; e++)
	{
		Edge next_edge = elist.data[e];
		int x = setFind(set, elist.data[e].src); // ?? �Ƹ� src�� ��߳�� , dest�µ������ 
		int y = setFind(set, elist.data[e].dest); // ������� 
		if (x != y) // �ߺ� edge�� �ƴ϶�� 
		{
			insertEdge(mst, elist.data[e].src, elist.data[e].dest, elist.data[e].weight);
			setUnion(set, x, y);
		}
	}

	return mst;

}
