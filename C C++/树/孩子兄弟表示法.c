#define MAX_TREE_SIZE 100

typedef int TElemType;
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * rightchild;
}CSNode,*CSTree;