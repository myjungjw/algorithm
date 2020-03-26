#include <stdio.h>
int N, M;
int a[10];

int dfs1(int n) {
	for (int i = 1; i <= 6; i++) {
		a[n] = i;
		if (n != (N-1)) dfs1(n + 1);
		else if (n == (N-1)) {
			for (int j = 0; j < N ; j++ ) {
				printf("%d ", a[j]);
			}
			printf("\n");
		}
	}
	return n + 1;
}
int dfs2(int n) {
	for (int i = 1; i <= 6; i++) {
		if (n > 0 && a[n - 1] > i) continue;
		a[n] = i;
		if (n != (N - 1)) dfs2(n + 1);
		else if (n == (N - 1)) {
			for (int j = 0; j < N; j++) {
				printf("%d ", a[j]);
			}
			printf("\n");
		}
	}
	return n + 1;
}
int dfs3(int n) {
	for (int i = 1; i <= 6; i++) {
		int flag = 0;
		for (int k = 0; k < n; k++) {
			if (a[k] == i) flag = 1;
		}
		if (flag == 1) continue;

		a[n] = i;
		if (n != (N - 1)) dfs3(n + 1);
		else if (n == (N - 1)) {
			for (int j = 0; j < N; j++) {
				printf("%d ", a[j]);
			}
			printf("\n");
		}
	}
	return n + 1;
}
int main() {
	scanf("%d %d", &N, &M);
	if ( M == 1 ) dfs1(0);
	if ( M == 2 ) dfs2(0);
	if ( M == 3 ) dfs3(0);
	return 0;
}
