#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;
typedef enum {Link,Thread} PointerTag;//Link == 0 ��ʾ���Һ���ָ��,Thread ==1 ��ʾָ��ǰ�����̵�������

typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

//��������������ĵݹ麯��
BiThrTree pre;//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��

void InThreading(BiThrTree p) {
	if (p)
	{
		InThreading(p->lchild);//�ݹ�������������
			if (!p->lchild)//û������
			{
				p->LTag = Thread;//ǰ������
				p->lchild = pre;//����ָ��ǰ��
			}
			if (!pre->rchild)//ǰ��û���Һ���
			{
				pre->RTag = Thread;
				pre->rchild = p;
			}
			pre = p;
		InThreading(p->rchild);//�ݹ�������������
	}
}