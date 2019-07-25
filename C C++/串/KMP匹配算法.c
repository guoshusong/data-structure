//用于计算字符串t的next数组
void get_next(String t, int* next) {
	int i, j;
	i = 1;
	j = 0 ;
	next[1] = 0;
	while (i < t[0])//此处t[0]表示t的长度
	{
		if(j == 0 || t[i] == t[j])//t[i]表示后缀的单个字符串,t[j]表示前缀的单个字符串
		{
			++i;
			++j;
			if (t[i] != t[j])//若当前字符串与前缀字符不相同
			{
				next[i] = j;//则当前的j为next在i的位置
			}
			else {
				next[i] = next[j];//如果与前缀字符串相同，则将前缀字符串的next值赋值给next在i的位置

		}
		else
		{
			j = next[j];//若字符串不相同，则j回溯
		}

	}
}

//返回子串t在主串s中第pos个字符之后的位置。
//此处t[0]表示t的长度,s[0]表示s的长度
int index_KMP(String s,String t,int pos) {
	int i = pos;//i用于主串s当前位置的下标，若pos不为1，则从pos位置来时匹配
	int j = 1;//用于子串t中当前位置下标
	int next[255];
	get_next(t, next);//得到字符串t的next数组
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i]==t[j])//两字母相等则继续，与朴素算法增加了j=0判断
		{
			++i;
			++j;
		}
		else // 指针后退重新开始匹配
		{
			j = next[j];//j返回合适位置，i值不变
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