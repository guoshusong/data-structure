#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;

typedef int Status;


typedef struct {
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

/**
stackNumber表示要进第一个栈还是第二个栈
*/
Status Push(SqDoubleStack* S, SElemType e, int stackNumber) {
	if (S->top1+1==S->top2)
	{
		return ERROR;//栈满
	}
	if (stackNumber==1)
	{
		S->data[++S->top1] = e;
	}
	else if (stackNumber == 2)
	{
		S->data[--S->top2] = e;
	}
	
	return OK;
}

Status Pop(SqDoubleStack* s, SElemType* e, int stackNumber) {
	if (stackNumber == 1)
	{
		if (s->top1 == -1)
		{
			return ERROR;
		}
		*e = s->data[s->top1--];
	}
	else if (stackNumber == 2)
	{
		if (s->top2 == MAXSIZE)
		{
			return ERROR;
		}
		*e = s->data[s->top2++];
	}
	return OK;
}