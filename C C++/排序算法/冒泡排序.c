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

//��򵥵�ð������
void BubbleSort0(SqList* l) {
	int i, j;
	for ( i = 1; i < l->length; i++)
	{
		for ( j = l->length-1; j >= i; j--)
		{
			if (l->r[j]>l->r[j+1])
			{
				swap(l, j, j+1);
			}
		}
	}
}

//ð�������Ż�
void BubbleSort2(SqList *l) {
	int i, j;
	int flag = 1;
	for ( i = 1; i < l->length && flag; i++)
	{
		flag = 0;
		for (j = l->length - 1; j >= i; j--)
		{
			if (l->r[j] > l->r[j + 1])
			{
				swap(l, j, j+1);
				flag = 1;//�������ݽ�������flagΪ1
			}
		}
	}
}