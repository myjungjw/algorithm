#include <stdio.h>
#include <malloc.h>
int n, k, cnt;
typedef struct _node Node;
typedef struct _cirque Cirque;
struct _node{
	int data;
	Node* next;
	Node* prev;
};
struct _cirque{
	Node* head;
	Node* cur;
	int cnt;
};
void init(Cirque* que) {
	que -> head = (Node*)malloc(sizeof(Node));
	que->head->data = n;
	que->cur = que->head;
	que->cur->next = que->cur;
	que->cur->prev = que->cur;
	for (int i = n - 1; i >= 1; i--) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = i;
		newNode->next = que->cur;
		newNode->prev = que->head;
		newNode->next->prev = newNode;
		newNode->prev->next = newNode;
		que->cur = newNode;
	}
	que->cur = que->head;
	return;
}

void erase(Cirque* que) {
	for (int i = 0; i < k; i++) {
		que->cur = que->cur->next;
	}
	Node* delNode = que->cur;
	delNode->next->prev = delNode->prev;
	delNode->prev->next = delNode->next;
	que->cur = delNode->prev;
	printf("%d ", delNode->data);
	free(delNode);
	cnt--;
	return;
}

int main() {
	Cirque* que = (Cirque*)malloc(sizeof(Cirque));
	scanf("%d %d", &n, &k);
	cnt = n;
	init(que);
	while (cnt) {
		erase(que);
	}
	return 0;
}
