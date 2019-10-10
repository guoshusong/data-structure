/*
 * leetcode394 ��https://leetcode-cn.com/problems/decode-string/
 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 10000

 //ע�����Ƕ�׵����
 //ע�����ֶ�λ�����
void decode(char* s, int beginIndex, int endIndex, int tempIndex);
char* decodeString(char* s) {
	char* str;
	str = (char*)malloc(sizeof(char) * MAXSIZE);
	memset(str, 0, sizeof(char) * MAXSIZE);
	strncpy(str, s, strlen(s) + 1);

	int beginIndex = 0;
	int endIndex = 0;
	int tempIndex = 0;
	int flag = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ']') {
			continue;
		}
		else {
			flag = 0;
			endIndex = i;
			tempIndex = i;
			while (--tempIndex >= 0) {
				if (isalpha(str[tempIndex]) && flag == 0) {
					continue;
				}
				else if (str[tempIndex] == '[' && flag == 0) {  // ����Ҫע��flag��־�������������⣬���������Ҫ�ж�flag���������Ƕ��ʱ�����쳣��
					beginIndex = tempIndex;
					flag = 1;
					continue;
				}
				else if (isdigit(str[tempIndex])) {
					continue;
				}
				else {
					break;
				}
			}
			decode(str, beginIndex, endIndex, tempIndex + 1);
			i = -1;
		}
	}
	return str;
}

void decode(char* s, int beginIndex, int endIndex, int tempIndex)
{
	char* temp;
	int total = 0;
	int tempLen = 0;
	int temp1Len = 0;
	temp = (char*)malloc(sizeof(char) * MAXSIZE);
	memset(temp, 0, sizeof(char) * MAXSIZE);

	//ȡ������
	for (int i = tempIndex; i < beginIndex; i++) {
		int num1 = s[i] - '0';  //����֮ǰ��С�İ�s[i]д����[temoIndex],�����˺þá�
		total = total * 10 + num1;
	}

	//ȡ���ַ���
	for (int i = 0; i < total; i++) {
		for (int j = beginIndex + 1; j < endIndex; j++) {
			temp[(j - beginIndex - 1) + i * (endIndex - beginIndex - 1)] = s[j];
			tempLen++;
		}
	}

	//��temp�滻S�ַ���
	//��������ַ���
	char* temp1;
	temp1 = (char*)malloc(sizeof(char) * MAXSIZE);
	memset(temp1, 0, sizeof(char) * MAXSIZE);

	for (int i = endIndex + 1; s[i] != '\0'; i++) {
		temp1[i - endIndex - 1] = s[i];
		temp1Len++;
	}

	for (int i = tempIndex; i < tempIndex + tempLen; i++) {
		s[i] = temp[i - tempIndex];
	}
	for (int i = tempIndex + tempLen; i < tempIndex + tempLen + temp1Len; i++) {
		s[i] = temp1[i - tempIndex - tempLen];
	}
	s[tempIndex + tempLen + temp1Len] = '\0';
}