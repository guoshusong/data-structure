//����ƥ���㷨
//����s��t�ĳ��ȴ���s[0]��t[0]��
int index(String s, String t, int pos) {
	int i = pos;//i��������s�е�ǰλ���±꣬��pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int j = 1;//j�����Ӵ�t�е�ǰλ���±�

	while (i <= s[0] && j <= t[0]) {
		if (s[i] == t[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;//i���ص��ϴ�ƥ����λ����һλ
			j = 1;

		}
	}
	if (j > t[0]) {
		return i - t[0];
	}
	else
		return 0;
}