#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemType;

typedef int Status;

typedef struct 
{
	QElemType data[MAXSIZE];
	int front; //头指针
	int rear; //尾指针，若队列不为空，指向队尾元素的下一个位置
}SqQueue;

Status InitQueue(SqQueue* q) {
	q->front = 0;
	q->rear = 0;
	return OK;
}

//队列长度
int QueueLength(SqQueue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue* q, QElemType e) {
	if ((q->rear+1)%MAXSIZE == q->front)//队列满的判断
	{
		return ERROR;
	}
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;//rear指针向后移动一位

	return OK;
}

Status DeQueue(SqQueue* q, QElemType* e) {
	if (q->front == q->rear)//队列空
	{
		return ERROR;
	}
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;//将front指针向后移动一位

	return OK;
}