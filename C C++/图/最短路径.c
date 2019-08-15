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

typedef int Pathmatirx[MAXVEX];//用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];//用于存储到各点最短路径的权值之和

//(Dijkstra)算法,求有向图G的顶点V0到其余顶点V的最短路径P[v]及带权长度D[v]
//P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径的长度
void ShorttestPath_Dijkstra(MGraph G, int v0, Pathmatirx* p, ShortPathTable* d) {
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1表示求得顶点Vo至Vw的最短路径
	for (  v = 0; v <G.numVertexes; v++)
	{
		final[v] = 0;
		(*d)[v] = G.arc[v0][v];//将与v0点有连线的顶点加上权值
		(*p)[v] = 0;//初始化路径数组
	}
	(*d)[v0] = 0;
	final[v0] = 1;
	//开始主循环
	for ( v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for ( w = 0; w < G.numVertexes; w++)
		{
			if (!final[w]&&(*d)[w]<min)
			{
				k = w;
				min = (*d)[w];//w顶点离v0更近
			}
		}
	}
	final[k] = 1;
	for ( w = 0; w < G.numVertexes; w++)//修正当前最短路径及距离
	{
		//如果经过v顶点的路径比现在这条路径的长度短的话
		if (!final[w] && (min+G.arc[k][w]) <  (*d)[w])
		{
			(*d)[w] = min + G.arc[k][w];
			(*p)[w] = k;
		}
	}
}