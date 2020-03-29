#include <stdio.h>
int a, b, d, N;
int head, tail;
char bug[1000001];
int main() {
  int h, t;
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &a, &b, &d, &N);
	for (int i = 0; i <= N; i++) {
		h = head;
		t = tail;
		for (int k = h; k <= t; k++) {
			if (bug[k] >= d) head = (head + 1) % 1000;
			if (bug[k] >= a && bug[k] < b) tail = (tail + 1) % 1000;
		}
		for (int j = head; j <= tail; j++) bug[j]++;
	}
	int result;
	if (tail >= head) result = tail - head + 1;
	else result = tail - head + 1001;
	printf("%d", result);
	return 0;
}
