#define MAXVEX 100 //��󶥵���

typedef char VertexType; //�����������û�����
typedef int EdgeType; //���ϵ�Ȩֵ�������û�����

typedef int Boolean;

Boolean visited[MAXVEX];//��������ı�־

typedef struct EdgeNode {//�߱���
	int adjvex;
	EdgeType weight;//Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	struct EdgeNode* next;//ָ����һ�ڽӵ�
}EdgeNode;

typedef struct VertexNode { //�������
	VertexType data;//������Ϣ
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	int i, j, k;
	EdgeNode* e;
	printf("�����붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for ( i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);//���붥����Ϣ
		G->adjList[i].firstedge = NULL;
	}
	for ( k = 0; k < G->numEdges; k++)
	{
		printf("�������(Vi,Vj)�ϵĶ������:\n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));//���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = j;//�ڽ����
		e->next = G->adjList[i].firstedge;//��eָ��ָ��ǰ����ָ��Ľ��

		G->adjList[i].firstedge = e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}

//�ڽӱ��������ȵݹ��㷨
void DFS(GraphAdjList GL, int i) {
	EdgeNode* p;
	visited[i] = true;
	printf("%c", GL.adjList[i].data);
	p = GL.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(GL, p->adjvex);
		}
		p = p->next;
	}
}

//�ڽӱ����ȱ���
void DFSTraverse(GraphAdjList GL) {
	int i;
	for ( i = 0; i < GL.numVertexes; i++)
	{
		visited[i] = false;
	}
	for ( i = 0; i < GL.numVertexes; i++)
	{
		if (!visited[i])
		{
			DFS(GL, i);
		}
	}
}

//�ڽӱ�Ĺ�ȱ����㷨
void BFSTraverse(GraphAdjList GL) {
	int i;
	EdgeNode* p;
	Queue Q;
	for (i = 0; i < GL.numVertexes; i++)
	{
		visited[i] = false;
	}
	InitQueue(&Q);
	for ( i = 0; i < GL.numVertexes; i++)
	{
		if (!visited[i]) {
			visited[i] = true;
			printf("%c", GL.adjList[i].data);
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL.adjList[i].firstedge;//�ҵ���ǰ���������ͷָ��
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						printf("%c", GL.adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);
					}
					p = p->next;
				}
			}
		}

	}
}