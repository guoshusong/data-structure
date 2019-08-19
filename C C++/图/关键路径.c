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
	int in;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;

int* etv, * ltv;
int* stack2;//用于存储拓扑序列的栈
int top2;

//拓扑排序，用于关键路径的计算
int TopologicalSort(GraphAdjList GL) {
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;
	int count = 0;
	int* stack;
	stack = (int*)malloc(GL.numVertexes * sizeof(int));
	for (i = 0; i < GL.numVertexes; i++)
	{
		if (GL.adjList[i].in == 0)
		{
			stack[++top] = i;
		}
	}
	top2 = 0;
	etv = (int*)malloc(GL.numVertexes * sizeof(int));//事件最早发生时间
	for ( i = 0; i < GL.numVertexes; i++)
	{
		etv[i] = 0;
	}
	stack2= (int*)malloc(GL.numVertexes * sizeof(int));
	while (top != 0)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;//将弹出的顶点序号压入拓扑序列的栈。
		for (e = GL.adjList[gettop].firstedge; e; e = e->next)
		{//对此顶点弧表进行遍历
			k = e->adjvex;
			if (!(--GL.adjList[k].in))//将k号顶点的入度减一
				stack[++top] = k;//若为0则入栈。
			if ((etv[gettop] + e->weight) > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}
	if (count < GL.numVertexes)//如果小于顶点说明存在环
	{
		return 0;//错误
	}
	else
	{
		return 1;//成功
	}
}


//关键路径的算法代码
void CriticalPath(GraphAdjList GL) {
	EdgeNode* e;
	int i, gettop, k, j;
	int ete, lte;
	TopologicalSort(GL);
	ltv= (int*)malloc(GL.numVertexes * sizeof(int));
	for (i = 0; i < GL.numVertexes; i++)
		ltv[i] = etv[GL.numVertexes - 1];
	while (top2 !=0)
	{
		gettop = stack2[top2--];
		for (e = GL.adjList[gettop].firstedge; e; e = e->next)
		{//求各顶点时间的最迟发生时间ltv值
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	for ( j = 0; j < GL.numVertexes; j++)
	{//求ete，lte和关键活动
		for (e = GL.adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				printf("<v%d,<v%d> length：%d,", GL.adjList[j].data, GL.adjList[k].data, e->weight);
		}
	}
}