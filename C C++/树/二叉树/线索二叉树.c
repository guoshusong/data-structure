#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;
typedef enum {Link,Thread} PointerTag;//Link == 0 表示左右孩子指针,Thread ==1 表示指向前驱或后继的线索。

typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

//中序遍历线索化的递归函数
BiThrTree pre;//全局变量，始终指向刚刚访问过的结点

void InThreading(BiThrTree p) {
	if (p)
	{
		InThreading(p->lchild);//递归左子树线索化
			if (!p->lchild)//没有左孩子
			{
				p->LTag = Thread;//前驱线索
				p->lchild = pre;//左孩子指向前驱
			}
			if (!pre->rchild)//前驱没有右孩子
			{
				pre->RTag = Thread;
				pre->rchild = p;
			}
			pre = p;
		InThreading(p->rchild);//递归右子树线索化
	}
}