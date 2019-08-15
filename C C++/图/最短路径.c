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

typedef int Pathmatirx[MAXVEX];//���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX];//���ڴ洢���������·����Ȩֵ֮��

//(Dijkstra)�㷨,������ͼG�Ķ���V0�����ඥ��V�����·��P[v]����Ȩ����D[v]
//P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·���ĳ���
void ShorttestPath_Dijkstra(MGraph G, int v0, Pathmatirx* p, ShortPathTable* d) {
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1��ʾ��ö���Vo��Vw�����·��
	for (  v = 0; v <G.numVertexes; v++)
	{
		final[v] = 0;
		(*d)[v] = G.arc[v0][v];//����v0�������ߵĶ������Ȩֵ
		(*p)[v] = 0;//��ʼ��·������
	}
	(*d)[v0] = 0;
	final[v0] = 1;
	//��ʼ��ѭ��
	for ( v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for ( w = 0; w < G.numVertexes; w++)
		{
			if (!final[w]&&(*d)[w]<min)
			{
				k = w;
				min = (*d)[w];//w������v0����
			}
		}
	}
	final[k] = 1;
	for ( w = 0; w < G.numVertexes; w++)//������ǰ���·��������
	{
		//�������v�����·������������·���ĳ��ȶ̵Ļ�
		if (!final[w] && (min+G.arc[k][w]) <  (*d)[w])
		{
			(*d)[w] = min + G.arc[k][w];
			(*p)[w] = k;
		}
	}
}