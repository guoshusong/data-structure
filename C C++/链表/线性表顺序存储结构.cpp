#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
#define MAXSIZE 20 /*�洢�ռ��ʼ������*/

typedef int ElemType; //ElemType���͸���ʵ������������������Ϊint

typedef struct {
	ElemType data[MAXSIZE];
	int length;  //���Ա�Ȼ����
}SqList;
/*
Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��ok��
��ʼ���� ˳�����Ա�L�Ѿ����ڣ�1��i��ListLength(L)
�����������e����L�е�i������Ԫ�ص�ֵ
*/

Status GetElem(SqList L, int i, ElemType* e) {
	if (L.length == 0 || i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList* L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i < 1 || i > L->length+1)//ע������Ϊlength+1
	{
		return ERROR;
	}
	if (i <= L->length)
	{
		for ( k = L->length; k>= i-1; k--)//��Ԫ������ƶ�
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int i, ElemType* e) {
	int k;
	if (L->length == 0) //���Ա�Ϊ��
	{
		return ERROR;
	}

	if (i < 1 || i > L->length)//ɾ��λ�ò���ȷ
	{
		return ERROR;
	}

	*e = L->data[i - 1];
	if (i < L->length)
	{
		for ( k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;

}

