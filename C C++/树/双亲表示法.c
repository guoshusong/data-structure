#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode {//���ṹ
	TElemType data;
	int parent;
}PTNode;

typedef struct {//���ṹ
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//����λ�úͽ����
}PTree;
