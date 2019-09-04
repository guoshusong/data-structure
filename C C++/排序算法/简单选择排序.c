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

//��ѡ������
void SelectSort(SqList* l) {
	int i, j, min;
	for ( i = 1; i < l->length; i++)
	{
		min = i;//����ǰС�궨��Ϊ��Сֵ
		for ( j = i+1; j <= l->length; j++)
		{
			if (l->r[min]>l->r[j])
			{
				min = j;
			}
			if (i!= min) {
				swap(l,i,min);
			}

		}
	}
}