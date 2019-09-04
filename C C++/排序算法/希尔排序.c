#define MAXSIZE 10
typedef struct {
	int r[MAXSIZE + 1];//r[0]�����ڱ�����ʱ����
	int length;
}SqList;

void ShellSort(SqList* l) {
	int i, j;
	int increment = l->length;
	do
	{
		increment = increment / 3 + 1;//����
		for (i = increment + 1; i <= l->length; i++)
		{
			if (l->r[i] < l->r[i-increment])
			{//��Ҫ��l->r[i]��������������
				l->r[0] = l->r[i];
				for (j = i - increment;j >0 &&l->r[j] > l->r[0]; j-=increment)
					l->r[j+increment] = l->r[j];//��¼����
				l->r[j + increment] = l->r[0];//���뵽��ȷ��λ��
			}
		}
	} while (increment > 1);
}