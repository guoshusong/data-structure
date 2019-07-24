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
	int front; //ͷָ��
	int rear; //βָ�룬�����в�Ϊ�գ�ָ���βԪ�ص���һ��λ��
}SqQueue;

Status InitQueue(SqQueue* q) {
	q->front = 0;
	q->rear = 0;
	return OK;
}

//���г���
int QueueLength(SqQueue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue* q, QElemType e) {
	if ((q->rear+1)%MAXSIZE == q->front)//���������ж�
	{
		return ERROR;
	}
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;//rearָ������ƶ�һλ

	return OK;
}

Status DeQueue(SqQueue* q, QElemType* e) {
	if (q->front == q->rear)//���п�
	{
		return ERROR;
	}
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;//��frontָ������ƶ�һλ

	return OK;
}