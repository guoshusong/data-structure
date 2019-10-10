typedef struct {
	int* data;
	int size, len, head, tail;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->data = (int*)malloc(sizeof(int) * k);
	q->len = 0;
	q->head = 0;
	q->tail = -1;
	q->size = k;
	return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->len)return false;
	obj->tail = (obj->tail + 1) % obj->size;
	obj->data[obj->tail] = value;
	++obj->len;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->len == 0)return false;
	obj->head = (obj->head + 1) % obj->size;
	--(obj->len);
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->len == 0)return -1;
	return obj->data[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->len == 0)return -1;
	return obj->data[obj->tail];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->len == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->len == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/