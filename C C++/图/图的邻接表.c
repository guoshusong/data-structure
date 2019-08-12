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
}VertexNode,AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	int i, j, k;
	EdgeNode* e;
	printf("�����붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for ( i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);//���붥����Ϣ
		G->adjList[i].firstedge = NULL;
	}
	for ( k = 0; k < G->numEdges; k++)
	{
		printf("�������(Vi,Vj)�ϵĶ������:\n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));//���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = j;//�ڽ����
		e->next = G->adjList[i].firstedge;//��eָ��ָ��ǰ����ָ��Ľ��

		G->adjList[i].firstedge = e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}