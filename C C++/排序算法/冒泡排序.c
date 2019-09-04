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

//最简单的冒泡排序
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

//冒泡排序优化
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
				flag = 1;//若有数据交换，则flag为1
			}
		}
	}
}