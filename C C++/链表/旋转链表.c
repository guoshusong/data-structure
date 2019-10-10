/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k) {
	struct ListNode* p;
	struct ListNode* q;

	int count = 1;
	int j, i;
	p = head;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else {
		while (p->next)
		{
			p = p->next;
			count++;
		}

		k = k % count;
		if (k == 0) {
			return head;
		}
		p->next = head;
		q = p;
		for (i = 0; i < count - k; i++) {
			head = head->next;
			q = q->next;
		}
		q->next = NULL;
		return head;
	}
}

