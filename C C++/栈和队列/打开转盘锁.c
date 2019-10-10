#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000

static char gFlag[MAX_N] = { 0 };

struct Node {
	char num[5];
	int level;
};

static struct Node gQueue[MAX_N] = { 0 };

int openLock(char** deadends, int deadendsSize, char* target)
{
	int i, num;
	int front, rear;
	int lev;
	char cur[5] = { 0 };
	char add[5] = { 0 };
	char sub[5] = { 0 };

	if (deadendsSize == 0 || target == NULL) {
		return -1;
	}

	memset(gFlag, 0, sizeof(gFlag));//��������г�ʼ���Ĳ���
	memset(gQueue, 0, sizeof(gQueue));

	/* ��������ϼ�¼��deadEnds��Ϊ���٣�ʹ�ø���ֵ��Ϊ�����±꣬������ʹ��ˣ���1�����δ���ʹ�����0 */
	for (i = 0; i < deadendsSize; i++) {
		num = atoi(deadends[i]);//
		gFlag[num] = 1;
	}

	if (gFlag[atoi(target)] == 1) {
		return -1;
	}

	if (gFlag[0] == 1) {
		return -1;
	}

	/* ������ȱ����������������ϣ���������������Ѿ������������Ҳ���뵽������ϣ���ֹ�����ظ����� */
	front = 0;
	rear = 0;

	/* ��0000����ʼ״̬��� */
	gQueue[front].level = 0;
	strcpy(gQueue[front++].num, "0000");
	gFlag[num] = 1;

	while (front != rear) {
		lev = gQueue[rear].level;
		strcpy(cur, gQueue[rear++].num);

		if (strcmp(cur, target) == 0) {
			return lev;
		}

		for (i = 0; i < 4; i++) {
			strcpy(add, cur);
			if (cur[i] == '9') {
				add[i] = '0';
			}
			else {
				add[i] = cur[i] + 1;
			}

			num = atoi(add);
			if (gFlag[num] == 0) {
				gQueue[front].level = lev + 1;
				strcpy(gQueue[front++].num, add);
				gFlag[num] = 1;
			}

			strcpy(sub, cur);
			if (cur[i] == '0') {
				sub[i] = '9';
			}
			else {
				sub[i] = cur[i] - 1;
			}

			num = atoi(sub);
			if (gFlag[num] == 0) {
				gQueue[front].level = lev + 1;
				strcpy(gQueue[front++].num, sub);
				gFlag[num] = 1;
			}

			//printf("%d %d \n", front, rear);
		}
	}

	return -1;
}

