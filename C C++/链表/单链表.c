

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}node;

typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e) {
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i)//p不为空，j还没有等于i时,循环继续
	{
		p = p->next;
		++j;
	}
	if (!p || j > i )
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status ListInsert(LinkList* L, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i ) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node) );//生成新结点(C标准函数)

	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListInsert(LinkList* L, int i, ElemType* e) {
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}