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
//对顺序表l作归并排序
void MergeSort(SqList* l) {
	MSort(l->r, l->r, 1, l->length);
}

//将SR[s..t]归并排序为TR1[s..t]
void MSort(int SR[], int TR1[], int s, int t) {
	int m;
	int TR2[MAXSIZE];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;//将SR[s..t]平均分为SR[s..m]和SR[m+1..t]
		MSort(SR,TR2,s,m);//将SR[s..m]归并为有序的TR2[s..m]
		MSort(SR,TR2,m+1,t);
		Merge(TR2, TR1, s, m, t);//将TR2[s..m]和TR2[M+1..T]归并到TR1[s..t]
	}
}

//将有序的SR[I..m]和SR[m+1..n]归并为有序的TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n) {
	int j, k, l;
	for ( j = m+1,k=i; i <= m&&j<=n; k++)//将SR中记录由小到大归并入TR
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i<=m)
	{
		for (l = 0; l <= m - i; i++)
			TR[k + l] = SR[i + l];//将剩余的SR[i..m]复制到TR
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];//将剩余的SR[j..n]复制到TR
	}
}

//对顺序表l作归并非递归排序
void MergeSort2(SqList* l) {
	int* TR = (int* )malloc(l->length * sizeof(int));
	int k = 1;
	while (k<l->length)
	{
		MergePass(l->r, TR, l->length);
		k = 2 * k;
		MergePass( TR,l->r, l->length);
		k = 2 * k;
	}
}

//将SR[]相邻长度为s的子序列两两归并到TR[]中
void MergePass(int SR[], int TR[], int s, int n) {
	int i = 1;
	int j;
	while (i <= n-2*s+1)
	{
		Merge(SR, TR, i + s - 1,i+2*s-1);//两两归并
		i = i + 2 * s;
	}
	if (i<n-s+1)//归并最后两个序列
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else//若只剩下单个子序列
	{
		for (j=i;j<=n;j++)
		{
			TR[j] = SR[j];
		}
	}
}