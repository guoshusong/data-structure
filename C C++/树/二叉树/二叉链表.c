typedef int Status;
typedef int TElemType;

typedef struct BiTNode {//结点结构
	TElemType data;
	struct BiTNode* lchild, * rchild;
};