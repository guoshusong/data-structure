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
	//�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
	s->next = L ->top;
	//���µĽ��s��ֵ��ջ��ָ��.
	L->top = s;
	L->count++;
	return OK;
}

Status Pop(LinkStack* L, SElemType* e) {
	LinkStackPtr p;
	if ��StackEmpty(*L))
	{
	return ERROR;
	}
	*e = L->top->data;
	p = L->top;
	//��ջ��ָ������
	L->top = L->top->next;
	free(p);
	L->count--;
	return OK;
}