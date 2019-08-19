#define MAXVEX 100 //��󶥵���

typedef char VertexType; //�����������û�����
typedef int EdgeType; //���ϵ�Ȩֵ�������û�����

typedef struct EdgeNode {//�߱���
	int adjvex;
	EdgeType weight;//Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	struct EdgeNode* next;//ָ����һ�ڽӵ�
}EdgeNode;

typedef struct VertexNode { //�������
	VertexType data;//������Ϣ
	EdgeNode* firstedge;
	int in;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;

int* etv, * ltv;
int* stack2;//���ڴ洢�������е�ջ
int top2;

//�����������ڹؼ�·���ļ���
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
	etv = (int*)malloc(GL.numVertexes * sizeof(int));//�¼����緢��ʱ��
	for ( i = 0; i < GL.numVertexes; i++)
	{
		etv[i] = 0;
	}
	stack2= (int*)malloc(GL.numVertexes * sizeof(int));
	while (top != 0)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;//�������Ķ������ѹ���������е�ջ��
		for (e = GL.adjList[gettop].firstedge; e; e = e->next)
		{//�Դ˶��㻡����б���
			k = e->adjvex;
			if (!(--GL.adjList[k].in))//��k�Ŷ������ȼ�һ
				stack[++top] = k;//��Ϊ0����ջ��
			if ((etv[gettop] + e->weight) > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}
	if (count < GL.numVertexes)//���С�ڶ���˵�����ڻ�
	{
		return 0;//����
	}
	else
	{
		return 1;//�ɹ�
	}
}


//�ؼ�·�����㷨����
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
		{//�������ʱ�����ٷ���ʱ��ltvֵ
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	for ( j = 0; j < GL.numVertexes; j++)
	{//��ete��lte�͹ؼ��
		for (e = GL.adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				printf("<v%d,<v%d> length��%d,", GL.adjList[j].data, GL.adjList[k].data, e->weight);
		}
	}
}