#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode {//结点结构
	TElemType data;
	int parent;
}PTNode;

typedef struct {//树结构
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//根的位置和结点数
}PTree;
