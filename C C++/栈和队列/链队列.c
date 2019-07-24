
#define OK 1
#define ERROR 0
typedef int QElemType;

typedef int Status;

typedef struct QNode {//���ṹ
	QElemType data;
	struct  QNode* next;
}QNode,*QueuePtr;

typedef struct {//���е�����ṹ
	QueuePtr front, rear;//��ͷ����βָ��
}LinkQueue;

Status EnQueue(LinkQueue* q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)//�洢����ʧ��
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;

	q->rear->next = s;//��ӵ��Ԫ��e�½��s��ֵ��ԭ��β���ĺ��

	q->rear = s;//�ѵ�ǰs����Ϊ��β���

	return OK;
}

Status DeQueue(LinkQueue* q, QElemType *e) {
	QueuePtr p;
	if (q->front == q->rear)
	{
		return ERROR;//����Ϊ��
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;//��ԭ��ͷ�����p->next��ֵ��ͷ�����

	if (q->rear == p)//����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
	{
		q->rear = q->front;
	}
	free(p);
	return OK;
}