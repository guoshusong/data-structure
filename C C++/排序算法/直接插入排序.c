#define MAXSIZE 10
typedef struct {
	int r[MAXSIZE + 1];//r[0]�����ڱ�����ʱ����
	int length;
}SqList;

void swap(SqList* l, int i, int j) {
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}

void InsertSort(SqList* l) {
	int i, j;
	for ( i = 2; i <= l->length; i++)
	{
		if (l->r[i] < l->r[i-1])
		{
			l->r[0] = l->r[i];//�����ڱ�
			for (j = i - 1; l->r[j] > l->r[0]; j--)
				l->r[j + 1] = l->r[j];//��¼����
			l->r[j + 1] = l->r[0];//���뵽��ȷ��λ��
		}
	}
}