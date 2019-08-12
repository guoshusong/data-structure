#define MAXVEX 100 //最大顶点数

typedef char VertexType; //顶点类型由用户定义
typedef int EdgeType; //边上的权值类型由用户定义

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