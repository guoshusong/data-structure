#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
typedef int TElemType;

void CreateBiTree(BiTree *T) {
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#'  )
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree((*T)->lchild);//创造左子树
		CreateBiTree((*T)->rchild);//创造右子树
	}
}