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
//��L����������
void QuickSort(SqList* L) {
	QSort(L, 1, L->length);
}
//��˳���L�е�������L->[low..high]����������
void QSort(SqList* L, int low, int high) {
	int  pivot;
	if (low < high)
	{
		while (low<high)
		{
			pivot = Partition(L, low, high);//��L->[low..high]һ��Ϊ��,�������ֵ
			QSort(L, low, pivot - 1);//�Ե��ӱ���п�������
			low = pivot + 1;
		}
		
	}
}

//����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ��
//��ʱ��֮ǰ(��)�ļ�¼������(С)����
int Partition(SqList* L, int low, int high) {
	int pivotkey;

	//�Ż������ѡȡ
	int mid = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		swap(L, low, high);//��֤���С
	if (L->r[mid] > L->r[high])
		swap(L, high, mid);//��֤�м�С���Ҷ�
	if (L->r[mid] > L->r[low])
		swap(L,mid, low);//��֤���С
	//��ʱL-r[low]�Ѿ��������ؼ����е��м�ֵ

	pivotkey = L->r[low];//���ӱ�ĵ�һ��¼��Ϊ����ֵ

	//�Ż�����Ҫ�Ľ���
	L->r[0] = pivotkey;
	
	while (low<high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		L->r[low] = L->r[high];//�����滻�����ǽ���
		while (low < high && L->r[low] >= pivotkey)
			low++;
		L->r[high] = L->r[low];
		
	}
	L->r[low] = L->r[0];
	return low;//������������λ��
}