#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;

typedef int Status;

typedef struct {
	SElemType data[MAXSIZE];
	int top;//用于栈顶指针
}SqStack;

Status Push(SqStack* S, SElemType e) {
	if (S->top == MAXSIZE -1) //栈满
	{
		return ERROR;
	}

	S->top++;
	S->data[S->top] =e; //将新元素赋值给栈顶空间
	return OK;
}

Status Pop(SqStack *S, SElemType *e) {
	if (S->top == -1)
	{
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;
	return OK;
}