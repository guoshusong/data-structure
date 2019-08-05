typedef char VertexType; //顶点类型由用户自定义
typedef int EdgeType; //边上的权值类型由用户定义
#define MAXVEX 100 //最大顶点数
#define INFINITY 65535 //用65535来代替∞

typedef struct {
	VertexType vexs[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵，可看作边表
	int numVertexes, numEdges;//图中当前的顶点数和边数
}MGraph;

//图的构造
void CreateGraph(MGraph *G) {
	int i, j, k, w;
	printf("输入顶点数和边数:\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//输入顶点数和边数
	for ( i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->vexs[i]);
	}
	for ( i = 0; i < G->numVertexes; i++)
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;//邻接矩阵初始化
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边(Vi,Vj)上的下标i，下标j和权w：\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//图为无向图
	}
}