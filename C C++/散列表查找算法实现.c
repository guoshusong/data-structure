//HsahTable��ɢ�б�ṹ���ṹ��elemΪһ����̬����
#define SUCCESS 1
#define fault 0
#define HashSize 12
#define NULIIKEY -32768
typedef struct {
	int* elem;//����Ԫ�ش洢��ַ����̬��������
	int count;//����Ԫ�ظ���
}HashTable;
int m = 0;//ɢ�б����ȫ�ֱ���

//��ʼ��ɢ�б�
int InitHashTable(HashTable* h) {
	int i;
	m = HashSize;
	h->count = m;
	h->elem = (int*)malloc(m * sizeof(int));
	for ( i = 0; i < m; i++)
		h->elem[i] = NULIIKEY;
	return SUCCESS;
}

//ɢ�к���
int Hash(int key) {
	return key % m;//����������
}

//����ؼ���
void InsertHash(HashTable* h, int key) {
	int addr = Hash(key);//ɢ�е�ַ
	while (h->elem[addr]!= NULIIKEY)//������ǿգ����ͻ
		addr = (addr + 1) % m;//���ŵ�ַ��������̽��
	h->elem[addr] = key;//�п�λ����ؼ���
}

//����
int SearchHash(HashTable* h,int key, int* addr) {
	*addr = Hash(key);
	while (h->elem[*addr]!=key)
	{
		*addr = (*addr + 1) % m;
		if (h->elem[*addr] ==NULIIKEY || *addr == Hash(key))
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}