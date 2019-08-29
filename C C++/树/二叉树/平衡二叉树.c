#define LH +1 //左高
#define EH 0 //登高
#define RH -1 //右高

typedef struct BiTNode {
	int data;
	int bf; //结点的平衡因子
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/*右旋代码
对以p为根的二叉排序树作右旋处理
处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
*/
void R_Rotate(BiTree* p) {
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;//L的右子树挂接为p的左子树
	L->rchild = (*p);
	*p = L;//p指向新的根结点
}
//左旋操作
void l_Rotate(BiTree* p) {
	BiTree r;
	r = (*p)->rchild;
	(*p)->rchild = r->lchild;
	r->lchild = (*p);
	*p = r;//p指向新的根结点
}

//左平衡旋转处理，结束时，指针T指向新的根结点
void LeftBalance(BiTree* t) {
	BiTree l, lr;
	l = (*t)->lchild;//l指向t的左子树结点
	switch (l.bf)
	{
	case LH://新结点插入在T的左孩子的左子树上，要作右旋处理
		(*t)->bf = l->bf = EH;
		R_Rotate(t);
		break;
	case RH://新结点在T左孩子的右树上,要做双旋处理
		lr = l->rchild;//lr指向T的左孩子的右子树根
		switch (lr->bf)//修改T及其左孩子的平衡因子
		{
		case LH: (*t)->bf = RH;
			l->bf = EH;
			break;
		case EH: (*t)->bf = l->bf = EH;
			break;
		case RH: (*t)->bf = l->bf = EH;
			l->bf = LH;
			break;
		}
		lr->bf = EH;
		l_Rotate(&(*t)->lchild);//对t的左子树作左旋平衡处理
		R_Rotate(t);//对t作右旋平衡处理
	}
}

/*
若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
数据元素为e的新结点并返回1，否则返回0.若因插入而使二叉排序树
失去平衡，则做平衡旋转处理，taller反映T长高与否
*/
int InsertAVL(BiTree* t, int e, int* taller) {
	if (!*T)
	{//插入新结点，树长高，则taller为1
		*t = (BiTree)malloc(sizeof(BiTNode));
		(*t)->data = e;
		(*t)->lchild = (*t)->rchild = NULL;
		(*t)->bf = EH;
		*taller = 1;
	}
	else
	{
		if (e == (*t)->data)
		{//树中已存在和e有相同关键字的结点则不再插入
			*taller = 0;
			return 0;
		}
		if (e < (*t)->data)
		{//应继续在T的左子树中进行搜索
			if (!InsertAVL(&(*t)->lchild,e,taller))
			{//未插入
				return 0;
			}
			if (taller)
			{//已插入到T的左子树中且左子树长高
				switch ((*t)->bf)
				{
				case LH://原来左子树比右子树高，需要做平衡处理
						LeftBalance(t);
						*taller = 0;
						break;
				case EH: //原本左右子树等高，现因左子树增高而树增高
					(*t)->bf = LH;
					*taller = 0;
					break;
				case RH://原本右子树比左子树高,现左右子树等高
					(*t)->bf = EH;
					*taller = 0;
					break;
				}

			}
		}
		else
		{//应继续在T的右子树中搜寻

			if (!InsertAVL(&(*t)->rchild, e, taller))
			{//未插入
				return 0;
			}
			if (taller)
			{//已插入到T的右子树中且右子树长高
				switch ((*t)->bf)
				{
				case LH://原来左子树比右子树高，现左右子树等高
					(*t)->bf = EH;
					*taller = 0;
					break;
				case EH: //原本左右子树等高，现因右子树增高而树增高
					(*t)->bf = RH;
					*taller = 0;
					break;
				case RH://原本右子树比左子树高,
					RightBalance(t);
					*taller = 0;
					break;
				}

			}
		}
	}
	return 1;
}
