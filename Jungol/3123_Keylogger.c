#include <stdio.h>
#include <malloc.h>
char str[1000000];
int T;
typedef struct _node Node;
typedef struct _list List;
struct _node{
	char data;
	Node* prev;
	Node* next;
};
struct _list{
	Node* head;
	Node* tail;
	Node* cur;
	int cnt;
};
void init(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));
	list->head->data = list->tail->data = 0;
	list->head->prev = list->tail->next = NULL;
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->cur = list->tail;
	list->cnt = 0;
}
void insert(List* list, char nd) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nd;
	newNode->prev = list->cur->prev;
	newNode->next = list->cur;
	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
	list->cnt++;
}
void erase(List* list) {
	if (list->cur == list->head->next) return;
	Node* delNode = list->cur->prev;
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;
	free(delNode);
	list->cnt--;
	return;
}
void Left(List* list) {
	if (list->cur == list->head->next) return;
	list->cur = list->cur->prev;
	return;
}
void Right(List* list) {
	if (list->cur == list->tail) return;
	list->cur = list->cur->next;
	return;
}

int main() {
	List* list = (List*)malloc(sizeof(List));
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%s", str);
		init(list);
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '-') erase(list);
			else if (str[i] == '<') Left(list);
			else if (str[i] == '>') Right(list);
			else insert(list, str[i]);
		}
		list->cur = list->head->next;
		while (1) {
			printf("%c", list->cur->data);
			list->cur = list->cur->next;
			if (list->cur == list->tail) break;
		}
		printf("\n");
	}
}
