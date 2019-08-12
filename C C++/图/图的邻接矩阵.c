typedef char VertexType; //顶点类型由用户自定义

typedef int Boolean;



typedef int EdgeType; //边上的权值类型由用户定义
#define MAXVEX 100 //最大顶点数
#define INFINITY 65535 //用65535来代替∞

Boolean visited[MAXVEX];//访问数组的标志

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


//邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;
	printf("%c", G.vexs[i]);//打印结点
	for ( j = 0; j <G.numVertexes; j++)
	{
		if (G.arc[i][j] == i && !visited[j])
		{
			DFS(G, j);//对访问的邻接顶点进行递归调用
		}
	}
}