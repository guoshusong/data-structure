#define LH +1 //���
#define EH 0 //�Ǹ�
#define RH -1 //�Ҹ�

typedef struct BiTNode {
	int data;
	int bf; //����ƽ������
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/*��������
����pΪ���Ķ�������������������
����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����
*/
void R_Rotate(BiTree* p) {
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;//L���������ҽ�Ϊp��������
	L->rchild = (*p);
	*p = L;//pָ���µĸ����
}
//��������
void l_Rotate(BiTree* p) {
	BiTree r;
	r = (*p)->rchild;
	(*p)->rchild = r->lchild;
	r->lchild = (*p);
	*p = r;//pָ���µĸ����
}

//��ƽ����ת��������ʱ��ָ��Tָ���µĸ����
void LeftBalance(BiTree* t) {
	BiTree l, lr;
	l = (*t)->lchild;//lָ��t�����������
	switch (l.bf)
	{
	case LH://�½�������T�����ӵ��������ϣ�Ҫ����������
		(*t)->bf = l->bf = EH;
		R_Rotate(t);
		break;
	case RH://�½����T���ӵ�������,Ҫ��˫������
		lr = l->rchild;//lrָ��T�����ӵ���������
		switch (lr->bf)//�޸�T�������ӵ�ƽ������
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
		l_Rotate(&(*t)->lchild);//��t��������������ƽ�⴦��
		R_Rotate(t);//��t������ƽ�⴦��
	}
}

/*
����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ��
����Ԫ��Ϊe���½�㲢����1�����򷵻�0.��������ʹ����������
ʧȥƽ�⣬����ƽ����ת����taller��ӳT�������
*/
int InsertAVL(BiTree* t, int e, int* taller) {
	if (!*T)
	{//�����½�㣬�����ߣ���tallerΪ1
		*t = (BiTree)malloc(sizeof(BiTNode));
		(*t)->data = e;
		(*t)->lchild = (*t)->rchild = NULL;
		(*t)->bf = EH;
		*taller = 1;
	}
	else
	{
		if (e == (*t)->data)
		{//�����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ���
			*taller = 0;
			return 0;
		}
		if (e < (*t)->data)
		{//Ӧ������T���������н�������
			if (!InsertAVL(&(*t)->lchild,e,taller))
			{//δ����
				return 0;
			}
			if (taller)
			{//�Ѳ��뵽T����������������������
				switch ((*t)->bf)
				{
				case LH://ԭ�����������������ߣ���Ҫ��ƽ�⴦��
						LeftBalance(t);
						*taller = 0;
						break;
				case EH: //ԭ�����������ȸߣ��������������߶�������
					(*t)->bf = LH;
					*taller = 0;
					break;
				case RH://ԭ������������������,�����������ȸ�
					(*t)->bf = EH;
					*taller = 0;
					break;
				}

			}
		}
		else
		{//Ӧ������T������������Ѱ

			if (!InsertAVL(&(*t)->rchild, e, taller))
			{//δ����
				return 0;
			}
			if (taller)
			{//�Ѳ��뵽T����������������������
				switch ((*t)->bf)
				{
				case LH://ԭ�����������������ߣ������������ȸ�
					(*t)->bf = EH;
					*taller = 0;
					break;
				case EH: //ԭ�����������ȸߣ��������������߶�������
					(*t)->bf = RH;
					*taller = 0;
					break;
				case RH://ԭ������������������,
					RightBalance(t);
					*taller = 0;
					break;
				}

			}
		}
	}
	return 1;
}
