typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/*
递归查找二叉排序树T中是否存在key
指针f指向T的双亲，其初始调用值为Null
若查找成功，则指针p指向该数据元素结点，并返回1
否则指针p指向查找路径上访问的最后一个结点并返回0
*/
int SearchBST(BiTree T, int key, BiTree f, BiTree* p) {
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if(key == T->data)
	{
		*p = T;
		return 1;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
	}
}

//插入操作
int InsertBST(BiTree* T, int key) {
	BiTree p, s;
	if (!SearchBST(*T,key,NULL,&p))//查找不成功
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			* T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	else
	{
		return 0;
	}
}

//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据结点
int DeleteBST(BiTree* T, int key) {
	if (!T)
	{
		return 0;
	}
	else
	{
		if (key == (*T)->data)
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

int Delete(BiTree* p) {
	BiTree q, s;
	if ((*p)->rchild ==NULL)//若右子树为空，只需要重接左子树
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*q)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else {
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)//转左，然后向右走到尽头(找到待删除结点的前驱)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;//s指向被删除结点的前驱
		if (q!=*p)
		{
			q->rchild = s->lchild;//重接q的右子树
		}
		else
			q->lchild = s->rchild;//重接q的左子树
		free(s);
	}
	return 1;
	
}