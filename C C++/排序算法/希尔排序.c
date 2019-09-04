#define MAXSIZE 10
typedef struct {
	int r[MAXSIZE + 1];//r[0]用作哨兵或临时变量
	int length;
}SqList;

void ShellSort(SqList* l) {
	int i, j;
	int increment = l->length;
	do
	{
		increment = increment / 3 + 1;//增量
		for (i = increment + 1; i <= l->length; i++)
		{
			if (l->r[i] < l->r[i-increment])
			{//需要将l->r[i]插入有序增量表
				l->r[0] = l->r[i];
				for (j = i - increment;j >0 &&l->r[j] > l->r[0]; j-=increment)
					l->r[j+increment] = l->r[j];//记录后移
				l->r[j + increment] = l->r[0];//插入到正确的位置
			}
		}
	} while (increment > 1);
}