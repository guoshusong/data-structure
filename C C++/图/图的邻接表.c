#define MAXVEX 100 //最大顶点数

typedef char VertexType; //顶点类型由用户定义
typedef int EdgeType; //边上的权值类型由用户定义

typedef int Boolean;

Boolean visited[MAXVEX];//访问数组的标志

typedef struct EdgeNode {//边表结点
	int adjvex;
	EdgeType weight;//权值，对于非网图可以不需要
	struct EdgeNode* next;//指向下一邻接点
}EdgeNode;

typedef struct VertexNode { //顶点表结点
	VertexType data;//顶点信息
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	int i, j, k;
	EdgeNode* e;
	printf("请输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for ( i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);//输入顶点信息
		G->adjList[i].firstedge = NULL;
	}
	for ( k = 0; k < G->numEdges; k++)
	{
		printf("请输入边(Vi,Vj)上的顶点序号:\n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));//向内存申请空间，生成边表结点
		e->adjvex = j;//邻接序号
		e->next = G->adjList[i].firstedge;//将e指针指向当前顶点指向的结点

		G->adjList[i].firstedge = e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}

//邻接表的深度优先递归算法
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

//邻接表的深度遍历
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

//邻接表的广度遍历算法
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
				p = GL.adjList[i].firstedge;//找到当前顶点边链表头指针
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