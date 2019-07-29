typedef int Status;
typedef int TElemType;

typedef struct BiTNode {//½áµã½á¹¹
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
