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

int TopologicalSort(GraphAdjList GL) {
	EdgeNode* e;
	int i, k, gettop;
	int top=0;//用栈指针下标
	int count = 0;//用于统计输出顶点的个数
	int* stack;
	stack = (int*)malloc(GL.numVertexes * sizeof(int));
	for ( i = 0; i < GL.numVertexes; i++)
	{
		if (GL.adjList[i].in == 0)
		{
			stack[++top] = i;
		}
	}
	while (top!=0)
	{
		gettop = stack[top--];
		printf("%d ->", GL.adjList[gettop].data);
		count++;
		for ( e = GL.adjList[gettop].firstedge; e ; e=e->next)
		{//对此顶点弧表进行遍历
			k = e->adjvex;
			if (!(-- GL.adjList[k].in))//将k号顶点的入度减一
			{
				stack[++top]=k;//若为0则入栈。
			}
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