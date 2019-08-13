typedef char VertexType; //�����������û��Զ���

typedef int Boolean;



typedef int EdgeType; //���ϵ�Ȩֵ�������û�����
#define MAXVEX 100 //��󶥵���
#define INFINITY 65535 //��65535�������

Boolean visited[MAXVEX];//��������ı�־

typedef struct {
	VertexType vexs[MAXVEX];//�����
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ��󣬿ɿ����߱�
	int numVertexes, numEdges;//ͼ�е�ǰ�Ķ������ͱ���
}MGraph;

//ͼ�Ĺ���
void CreateGraph(MGraph *G) {
	int i, j, k, w;
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//���붥�����ͱ���
	for ( i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->vexs[i]);
	}
	for ( i = 0; i < G->numVertexes; i++)
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;//�ڽӾ����ʼ��
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("�����(Vi,Vj)�ϵ��±�i���±�j��Ȩw��\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//ͼΪ����ͼ
	}
}


//�ڽӾ����������ȵݹ��㷨
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;
	printf("%c", G.vexs[i]);//��ӡ���
	for ( j = 0; j <G.numVertexes; j++)
	{
		if (G.arc[i][j] == i && !visited[j])
		{
			DFS(G, j);//�Է��ʵ��ڽӶ�����еݹ����
		}
	}
}

//�ڽӾ����������ȱ���
void DFSTraverse(MGraph G){
	int i;
	for ( i = 0; i < G.numVertexes; i++)
	{
		visited[i] = false;//��ʼ���ж���״̬����δ���ʹ���״̬
	}
	for ( i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])//��δ���ʹ��Ľ�㣬����DFS��������ͨͼ����ֻ��ִ��һ��
		{
			DFS(G, i);
		}
	}
}

//�ڽӾ���Ĺ�ȱ����㷨
void BFSTraverse(MGraph G) {
	int i, j;
	Queue Q;
	for ( i = 0; i < G.numVertexes; i++)
	{
		visited[i] = false;
	}
	InitQueue(&Q);//��ʼ���Ը����õĶ���
	for ( i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i]) {
			visited[i] = true;
			printf("%c", G.vexs[i]);
			EnQueue(&Q, i);//���˶�������
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);//������Ԫ�س��У���ֵ��i
				for ( j = 0; j < G.numVertexes; j++)
				{
					if (G.arc[i][j] == 1 && !visited[i])//�ж����������뵱ǰ������ڱߣ���δ���ʹ�
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