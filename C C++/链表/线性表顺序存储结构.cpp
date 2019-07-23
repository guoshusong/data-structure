#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
#define MAXSIZE 20 /*存储空间初始分配量*/

typedef int ElemType; //ElemType类型根据实际情况而定，这里假设为int

typedef struct {
	ElemType data[MAXSIZE];
	int length;  //线性表当然长度
}SqList;
/*
Status是函数的类型，其值是函数结果状态代码，如ok等
初始条件 顺序线性表L已经存在，1≤i≤ListLength(L)
操作结果：用e返回L中第i个数据元素的值
*/

Status GetElem(SqList L, int i, ElemType* e) {
	if (L.length == 0 || i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList* L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i < 1 || i > L->length+1)//注意这里为length+1
	{
		return ERROR;
	}
	if (i <= L->length)
	{
		for ( k = L->length; k>= i-1; k--)//将元素向后移动
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int i, ElemType* e) {
	int k;
	if (L->length == 0) //线性表为空
	{
		return ERROR;
	}

	if (i < 1 || i > L->length)//删除位置不正确
	{
		return ERROR;
	}

	*e = L->data[i - 1];
	if (i < L->length)
	{
		for ( k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;

}

