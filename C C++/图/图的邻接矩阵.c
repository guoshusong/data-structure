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

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

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

//����ķ�㷨Prim
void MiniSpanTree_Prim(MGraph G) {
	int min, i, j, k;
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//������ض����ߵ�Ȩֵ
	lowcost[0] = 0;//��ʼ����һ��ȨֵΪ0����V0������������lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ�����������
	adjvex[0] = 0;
	for ( i = 0; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];//��V0������֮�бߵ�Ȩֵ��������
		adjvex[i] = 0;//��ʼ����ΪV0���±�
	}
	for (i = 0; i < G.numVertexes; i++) {
		min = INFINITY;//��ʼ����СȨֵΪ��
		k = 0;
		j = 1;
		while (j<G.numVertexes)//ѭ��ȫ������
		{
			if (lowcost[j]!=0 && lowcost[j]<min)
			{//���Ȩֵ��Ϊ0����ȨֵС��min
				min = lowcost[j];//�õ�ǰȨֵ��Ϊ��Сֵ
				k = j;//����ǰ��Сֵ���±����k
			}
			j++;
		}
	}
	printf("(%d,%d)", adjvex[k], k);//��ӡ��ǰ�������Ȩֵ��С��
	lowcost[k] = 0;//����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
	for ( j = 1; j < G.numVertexes; j++)
	{
		if (lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
		{//���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
			lowcost[j] = G.arc[k][j];
			adjvex[j] = k;
		}
	}

}

//��³˹�����㷨
void MiniSpanTree_Kruskal(MGraph G) {
	int i, n, m;
	Edge edges[10];
	int parent[MAXVEX];//����һ���������жϱ�����Ƿ��γɻ�·
	/*
	�˴�ʡ�Խ��ڽӾ���Gת��Ϊ�߼�����edges����Ȩ��С��������Ĵ���
	*/
	for ( i = 0; i < G.numVertexes; i++)
	{
		parent[i] = 0;
	}
	for ( i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n!=m)//˵���˱�û���������������γɻ�·
		{
			parent[n] = m;//��ʾ�˶����Ѿ���������������
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

//�������߶����β���±�
int Find(int* parent, int f) {
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}