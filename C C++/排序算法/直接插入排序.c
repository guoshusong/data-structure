#define MAXSIZE 10
typedef struct {
	int r[MAXSIZE + 1];//r[0]用作哨兵或临时变量
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
			l->r[0] = l->r[i];//设置哨兵
			for (j = i - 1; l->r[j] > l->r[0]; j--)
				l->r[j + 1] = l->r[j];//记录后移
			l->r[j + 1] = l->r[0];//插入到正确的位置
		}
	}
}