#include <stdio.h>

int n, a, b, m, x, y, N;
int fam[100][100];
int dfs(int X, int Y) {
	N++;
	if (fam[X][Y] == 1) return N;
	if (fam[X][Y] == 2) return 0;
	for (int i = 1; i <= n; i++) {
		if (fam[X][i] == 1) {
			fam[X][i] = fam[i][X] = 2;
			if (dfs(i, Y) != -1 ) return N;;
		}
	}
	N--;
	return -1;
}
int main() {
	scanf("%d %d %d %d", &n, &a, &b, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		fam[x][y] = 1;
		fam[y][x] = 1;
	}
	
	printf("%d", dfs(a,b));


	return 0;
}
