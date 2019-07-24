
#define OK 1
#define ERROR 0
typedef int QElemType;

typedef int Status;

typedef struct QNode {//结点结构
	QElemType data;
	struct  QNode* next;
}QNode,*QueuePtr;

typedef struct {//队列的链表结构
	QueuePtr front, rear;//队头、队尾指针
}LinkQueue;

Status EnQueue(LinkQueue* q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)//存储分配失败
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;

	q->rear->next = s;//把拥有元素e新结点s赋值给原队尾结点的后继

	q->rear = s;//把当前s设置为队尾结点

	return OK;
}

Status DeQueue(LinkQueue* q, QElemType *e) {
	QueuePtr p;
	if (q->front == q->rear)
	{
		return ERROR;//队列为空
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;//将原队头结点后继p->next赋值给头结点后继

	if (q->rear == p)//若队头是队尾，则删除后将rear指向头结点
	{
		q->rear = q->front;
	}
	free(p);
	return OK;
}