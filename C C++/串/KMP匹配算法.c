//���ڼ����ַ���t��next����
void get_next(String t, int* next) {
	int i, j;
	i = 1;
	j = 0 ;
	next[1] = 0;
	while (i < t[0])//�˴�t[0]��ʾt�ĳ���
	{
		if(j == 0 || t[i] == t[j])//t[i]��ʾ��׺�ĵ����ַ���,t[j]��ʾǰ׺�ĵ����ַ���
		{
			++i;
			++j;
			if (t[i] != t[j])//����ǰ�ַ�����ǰ׺�ַ�����ͬ
			{
				next[i] = j;//��ǰ��jΪnext��i��λ��
			}
			else {
				next[i] = next[j];//�����ǰ׺�ַ�����ͬ����ǰ׺�ַ�����nextֵ��ֵ��next��i��λ��

		}
		else
		{
			j = next[j];//���ַ�������ͬ����j����
		}

	}
}

//�����Ӵ�t������s�е�pos���ַ�֮���λ�á�
//�˴�t[0]��ʾt�ĳ���,s[0]��ʾs�ĳ���
int index_KMP(String s,String t,int pos) {
	int i = pos;//i��������s��ǰλ�õ��±꣬��pos��Ϊ1�����posλ����ʱƥ��
	int j = 1;//�����Ӵ�t�е�ǰλ���±�
	int next[255];
	get_next(t, next);//�õ��ַ���t��next����
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i]==t[j])//����ĸ�����������������㷨������j=0�ж�
		{
			++i;
			++j;
		}
		else // ָ��������¿�ʼƥ��
		{
			j = next[j];//j���غ���λ�ã�iֵ����
		}
	}
	if (j > t[0])
	{
		return i - t[0];
	}
	else
	{
		return[0];
	}
}