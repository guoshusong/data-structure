#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
  
typedef int Position;
#define NotFound -1
  
void BuildMatch( char *pattern, int *match )
{
    Position i, j;
    int m = strlen(pattern);
    match[0] = -1;
      
    for ( j=1; j<m; j++ ) {
        i = match[j-1];
        while ( (i>=0) && (pattern[i+1]!=pattern[j]) )
            i = match[i];
        if ( pattern[i+1]==pattern[j] )
             match[j] = i+1;
        else match[j] = -1;
    }
}
  
Position KMP( char *string, char *pattern )
{
    int n = strlen(string);
    int m = strlen(pattern);
    Position s, p, *match;
      
    if ( n < m ) return NotFound;
    match = (Position *)malloc(sizeof(Position) * m);
    BuildMatch(pattern, match);
    s = p = 0;
    while ( s<n && p<m ) {
        if ( string[s]==pattern[p] ) {
            s++; p++;
        }
        else if (p>0) p = match[p-1]+1;
        else s++;
    }
    return ( p==m )? (s-m) : NotFound;
}
int main() {
  char string[1000001] = {0};
  char pattern[1000001] = {0};
  scanf("%s\n", (char *)&string);
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s\n", (char *)&pattern);
    Position p = KMP(string, pattern);
    if(p != NotFound) {
      if(i == n - 1) {
        printf("%s", (char *)string+p);
      } else {
        printf("%s\n", (char *)string+p);
      }
    } else {
      if(i == n - 1) {
        printf("Not Found");
      } else {
        printf("Not Found\n");
      }
    }
  }
  return 0;
}
 
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <string.h>
//void Next(char* T, int* next) {
//	int i = 1;
//	next[1] = 0;
//	int j = 0;
//	while (i < strlen(T)) {
//		if (j == 0 || T[i - 1] == T[j - 1]) {
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else {
//			j = next[j];
//		}
//	}
//}
//int KMP(char* S, char* T) {
//	int next[1000];
//	Next(T, next);//根据模式串T,初始化next数组
//	int i = 1;
//	int j = 1;
//	while (i <= strlen(S) && j <= strlen(T)) {
//		//j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
//		if (j == 0 || S[i - 1] == T[j - 1]) {
//			i++;
//			j++;
//		}
//		else {
//			j = next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
//		}
//	}
//	if (j > strlen(T)) {//如果条件为真，说明匹配成功
//		return i - (int)strlen(T);
//	}
//	return -1;
//}
//int main() {
//
//	char a[100];
//	char b[100];
//	int n, i, j;
//	scanf("%s", a);
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%s", b);
//		j = KMP(a, b);
//		if (j == -1) {
//			printf("Not Found\n");
//			continue;
//		}
//		else {
//			for (; j <= strlen(a); j++) {
//				printf("%c", a[j - 1]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//
//}
