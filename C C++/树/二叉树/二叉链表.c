typedef int Status;
typedef int TElemType;

typedef struct BiTNode {//���ṹ
	TElemType data;
	struct BiTNode* lchild, * rchild;
};