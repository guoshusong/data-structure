//暴力匹配算法
//假设s和t的长度存在s[0]和t[0]中
int index(String s, String t, int pos) {
	int i = pos;//i用于主串s中当前位置下标，若pos不为1，则从pos位置开始匹配
	int j = 1;//j用于子串t中当前位置下标

	while (i <= s[0] && j <= t[0]) {
		if (s[i] == t[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;//i返回到上次匹配首位的下一位
			j = 1;

		}
	}
	if (j > t[0]) {
		return i - t[0];
	}
	else
		return 0;
}