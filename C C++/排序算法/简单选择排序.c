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

//简单选择排序
void SelectSort(SqList* l) {
	int i, j, min;
	for ( i = 1; i < l->length; i++)
	{
		min = i;//将当前小标定义为最小值
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