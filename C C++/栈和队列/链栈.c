#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;

typedef int Status;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status Push(LinkStack  *L, SElemType e) {
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	//把当前的栈顶元素赋值给新结点的直接后继
	s->next = L ->top;
	//将新的结点s赋值给栈顶指针.
	L->top = s;
	L->count++;
	return OK;
}

Status Pop(LinkStack* L, SElemType* e) {
	LinkStackPtr p;
	if （StackEmpty(*L))
	{
	return ERROR;
	}
	*e = L->top->data;
	p = L->top;
	//将栈顶指定下移
	L->top = L->top->next;
	free(p);
	L->count--;
	return OK;
}