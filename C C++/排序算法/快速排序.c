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
//对L作快速排序
void QuickSort(SqList* L) {
	QSort(L, 1, L->length);
}
//对顺序表L中的子序列L->[low..high]作快速排序
void QSort(SqList* L, int low, int high) {
	int  pivot;
	if (low < high)
	{
		while (low<high)
		{
			pivot = Partition(L, low, high);//将L->[low..high]一分为二,算出枢轴值
			QSort(L, low, pivot - 1);//对低子表进行快速排序
			low = pivot + 1;
		}
		
	}
}

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时它之前(后)的记录均不大(小)于它
int Partition(SqList* L, int low, int high) {
	int pivotkey;

	//优化枢轴的选取
	int mid = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		swap(L, low, high);//保证左端小
	if (L->r[mid] > L->r[high])
		swap(L, high, mid);//保证中间小于右端
	if (L->r[mid] > L->r[low])
		swap(L,mid, low);//保证左端小
	//此时L-r[low]已经是三个关键字中的中间值

	pivotkey = L->r[low];//用子表的第一记录作为枢轴值

	//优化不必要的交换
	L->r[0] = pivotkey;
	
	while (low<high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		L->r[low] = L->r[high];//采用替换而不是交换
		while (low < high && L->r[low] >= pivotkey)
			low++;
		L->r[high] = L->r[low];
		
	}
	L->r[low] = L->r[0];
	return low;//返回枢轴所在位置
}