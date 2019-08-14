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

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

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

//邻接矩阵的深度优先遍历
void DFSTraverse(MGraph G){
	int i;
	for ( i = 0; i < G.numVertexes; i++)
	{
		visited[i] = false;//初始所有顶点状态都是未访问过的状态
	}
	for ( i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])//对未访问过的结点，调用DFS。若是连通图，则只会执行一次
		{
			DFS(G, i);
		}
	}
}

//邻接矩阵的广度遍历算法
void BFSTraverse(MGraph G) {
	int i, j;
	Queue Q;
	for ( i = 0; i < G.numVertexes; i++)
	{
		visited[i] = false;
	}
	InitQueue(&Q);//初始化以辅助用的队列
	for ( i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i]) {
			visited[i] = true;
			printf("%c", G.vexs[i]);
			EnQueue(&Q, i);//将此顶点入列
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);//将队中元素出列，赋值给i
				for ( j = 0; j < G.numVertexes; j++)
				{
					if (G.arc[i][j] == 1 && !visited[i])//判断其他顶点与当前顶点存在边，且未访问过
					{
						visited[i] = true;
						printf("%c", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

//普利姆算法Prim
void MiniSpanTree_Prim(MGraph G) {
	int min, i, j, k;
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	lowcost[0] = 0;//初始化第一个权值为0，即V0加入生成树，lowcost的值为0，在这里就是此下标的顶点已经加入生成树
	adjvex[0] = 0;
	for ( i = 0; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];//将V0顶点与之有边的权值存入数组
		adjvex[i] = 0;//初始化都为V0的下标
	}
	for (i = 0; i < G.numVertexes; i++) {
		min = INFINITY;//初始化最小权值为∞
		k = 0;
		j = 1;
		while (j<G.numVertexes)//循环全部顶点
		{
			if (lowcost[j]!=0 && lowcost[j]<min)
			{//如果权值不为0，且权值小于min
				min = lowcost[j];//让当前权值称为最小值
				k = j;//将当前最小值的下标存入k
			}
			j++;
		}
	}
	printf("(%d,%d)", adjvex[k], k);//打印当前顶点边中权值最小边
	lowcost[k] = 0;//将当前顶点的权值设置为0，表示此顶点已经完成任务
	for ( j = 1; j < G.numVertexes; j++)
	{
		if (lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
		{//若下标为k顶点各边权值小于此前这些顶点未被接入生成树权值
			lowcost[j] = G.arc[k][j];
			adjvex[j] = k;
		}
	}

}

//卡鲁斯卡尔算法
void MiniSpanTree_Kruskal(MGraph G) {
	int i, n, m;
	Edge edges[10];
	int parent[MAXVEX];//定义一数组用来判断边与边是否形成环路
	/*
	此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码
	*/
	for ( i = 0; i < G.numVertexes; i++)
	{
		parent[i] = 0;
	}
	for ( i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n!=m)//说明此边没有与现有生成树形成环路
		{
			parent[n] = m;//表示此顶点已经在生成树集合中
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

//查找连线顶点的尾部下标
int Find(int* parent, int f) {
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}