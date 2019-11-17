#include <stdio.h>

int map[10][10];
int N;

int bishop[100][3];
int max = 0;
int cnt = 0;

void input() {
	freopen("bishop.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void define() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
				bishop[cnt][0] = i;
				bishop[cnt][1] = j;
				bishop[cnt][2] = 0;
				cnt++;
		}
	}
}

int check(int dep) {
	for (int t = 0; t < dep; t++) {
		if (bishop[dep][0] + bishop[dep][1] == bishop[t][0] + bishop[t][1] || bishop[dep][0] - bishop[dep][1] == bishop[t][0] - bishop[t][1]) {
			if (bishop[t][2] == 1) return 1;  // 못 놓는 자리.
		}
	}
	return 0;   // 놓을 수 있는 자리
}

int dfs(int index, int dep) {
	if (dep == cnt) { max = cnt; return max; }
	if (cnt - index < max - dep) return max;
	if (dep > 2 * N - 1) return max;


	if (bishop[index][2] == 0 && check(index) == 0)
	{
		bishop[index][2] = 1;
		if (max < dep + 1) max = dep + 1;
		if (index == cnt - 1) return max;
		dfs(index + 1, dep + 1);
		bishop[index][2] = 0;
	}

	if (index == cnt - 1) return max;
	else dfs(index + 1, dep);
}

int main()
{
	input();
	define();
	dfs(0, 0);
	//output();
	if (cnt == 0) {
		printf("%d", cnt);
	}
	else {
		printf("%d", max);
	}
	return 0;
}


