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

int TopologicalSort(GraphAdjList GL) {
	EdgeNode* e;
	int i, k, gettop;
	int top=0;//��ջָ���±�
	int count = 0;//����ͳ���������ĸ���
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
		{//�Դ˶��㻡����б���
			k = e->adjvex;
			if (!(-- GL.adjList[k].in))//��k�Ŷ������ȼ�һ
			{
				stack[++top]=k;//��Ϊ0����ջ��
			}
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