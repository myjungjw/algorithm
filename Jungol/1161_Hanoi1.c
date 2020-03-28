#include <stdio.h>
short N;

void dfs(short n, short s, short e) {
	short k = 0;
	if (s + e == 3) k = 3;
	if (s + e == 4) k = 2;
	if (s + e == 5) k = 1;
	if (n == 1) {
		printf("%d : %d -> %d\n", n, s, e);
		return;
	}
	if (n == 2) {
		printf("%d : %d -> %d\n", n - 1, s, k);
		printf("%d : %d -> %d\n", n, s, e);
		printf("%d : %d -> %d\n", n - 1, k, e);
		return;
	}
	else {
		dfs(n - 1, s, k);
		printf("%d : %d -> %d\n", n, s, e);
		dfs(n - 1, k, e);
		return;
	}
}

int main() {
	scanf("%d", &N);
	dfs(N, 1, 3);
	return 0;
}
