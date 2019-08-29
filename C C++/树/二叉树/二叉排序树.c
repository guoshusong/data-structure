typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/*
�ݹ���Ҷ���������T���Ƿ����key
ָ��fָ��T��˫�ף����ʼ����ֵΪNull
�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������1
����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����0
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

//�������
int InsertBST(BiTree* T, int key) {
	BiTree p, s;
	if (!SearchBST(*T,key,NULL,&p))//���Ҳ��ɹ�
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

//������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ�������ݽ��
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
	if ((*p)->rchild ==NULL)//��������Ϊ�գ�ֻ��Ҫ�ؽ�������
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
		while (s->rchild)//ת��Ȼ�������ߵ���ͷ(�ҵ���ɾ������ǰ��)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;//sָ��ɾ������ǰ��
		if (q!=*p)
		{
			q->rchild = s->lchild;//�ؽ�q��������
		}
		else
			q->lchild = s->rchild;//�ؽ�q��������
		free(s);
	}
	return 1;
	
}