typedef int Status;
typedef int TElemType;

typedef struct BiTNode {//½áµã½á¹¹
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//前序遍历算法
void PreOrderTraverse(BiTree T) {
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);//显示结点数据
	PreOrderTraverse(T->lchild);//先序遍历左子树
	PreOrderTraverse(T ->rchild);//最后先序遍历右子树
}

//中序遍历算法
void InOrderTraverse(BiTree T) {
	if (T == NULL)
	{
		return;
	}
	InOrderTraverse(T->lchild);//中序遍历左子树
	printf("%c", T->data);//显示结点数据
	InOrderTraverse(T ->rchild);//中序遍历右子树
}

//后序遍历算法
void PostOrderTraverse(BiTree T) {
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);//后遍历左子树
	PostOrderTraverse(T ->rchild);//后序遍历右子树
	printf("%c", T->data);//显示结点数据
}