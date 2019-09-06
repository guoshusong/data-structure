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
//��˳���l���鲢����
void MergeSort(SqList* l) {
	MSort(l->r, l->r, 1, l->length);
}

//��SR[s..t]�鲢����ΪTR1[s..t]
void MSort(int SR[], int TR1[], int s, int t) {
	int m;
	int TR2[MAXSIZE];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;//��SR[s..t]ƽ����ΪSR[s..m]��SR[m+1..t]
		MSort(SR,TR2,s,m);//��SR[s..m]�鲢Ϊ�����TR2[s..m]
		MSort(SR,TR2,m+1,t);
		Merge(TR2, TR1, s, m, t);//��TR2[s..m]��TR2[M+1..T]�鲢��TR1[s..t]
	}
}

//�������SR[I..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]
void Merge(int SR[], int TR[], int i, int m, int n) {
	int j, k, l;
	for ( j = m+1,k=i; i <= m&&j<=n; k++)//��SR�м�¼��С����鲢��TR
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i<=m)
	{
		for (l = 0; l <= m - i; i++)
			TR[k + l] = SR[i + l];//��ʣ���SR[i..m]���Ƶ�TR
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];//��ʣ���SR[j..n]���Ƶ�TR
	}
}

//��˳���l���鲢�ǵݹ�����
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

//��SR[]���ڳ���Ϊs�������������鲢��TR[]��
void MergePass(int SR[], int TR[], int s, int n) {
	int i = 1;
	int j;
	while (i <= n-2*s+1)
	{
		Merge(SR, TR, i + s - 1,i+2*s-1);//�����鲢
		i = i + 2 * s;
	}
	if (i<n-s+1)//�鲢�����������
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else//��ֻʣ�µ���������
	{
		for (j=i;j<=n;j++)
		{
			TR[j] = SR[j];
		}
	}
}