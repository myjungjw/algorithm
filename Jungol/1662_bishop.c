#include <stdio.h>

int map[10][10];
int N;
int odd[100][3];
int even[100][3];
int odd_max = 0;
int even_max = 0;
int odd_cnt = 0;
int even_cnt = 0;


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

			if ((i + j) % 2 == 1) {
				odd[odd_cnt][0] = i;
				odd[odd_cnt][1] = j;
				odd[odd_cnt][2] = 0;
				odd_cnt++;
			}
			if ((i + j) % 2 == 0) {
				even[even_cnt][0] = i;
				even[even_cnt][1] = j;
				even[even_cnt][2] = 0;
				even_cnt++;
			}
		}
	}
}

int even_check(int even_dep) {
	for (int t = 0; t < even_dep; t++) {
		if (even[even_dep][0] + even[even_dep][1] == even[t][0] + even[t][1] || even[even_dep][0] - even[even_dep][1] == even[t][0] - even[t][1]) {
			if (even[t][2] == 1) return 1;  // 못 놓는 자리.
		}
	}
	return 0;   // 놓을 수 있는 자리
}

int odd_check(int odd_dep) {
	for (int t = 0; t < odd_dep; t++) {
		if (odd[odd_dep][0] + odd[odd_dep][1] == odd[t][0] + odd[t][1] || odd[odd_dep][0] - odd[odd_dep][1] == odd[t][0] - odd[t][1]) {
			if (odd[t][2] == 1) return 1;  // 못 놓는 자리.
		}
	}
	return 0;   // 놓을 수 있는 자리
}

int odd_dfs(int odd_index, int odd_dep) {
	if (odd_dep == odd_cnt) { odd_max = odd_cnt; return odd_max; }
	if (odd_cnt - odd_index < odd_max - odd_dep) return odd_max;

	if (odd[odd_index][2] == 0 && odd_check(odd_index) == 0) {
		odd[odd_index][2] = 1;
		if (odd_max < odd_dep + 1) odd_max = odd_dep + 1;
		if (odd_index == odd_cnt - 1) return odd_max;
		odd_dfs(odd_index + 1, odd_dep + 1);
		odd[odd_index][2] = 0;
	}

	if (odd_index == odd_cnt) return odd_max;
	else odd_dfs(odd_index + 1, odd_dep);
}

int even_dfs(int even_index, int even_dep) {
	if (even_dep == even_cnt) { even_max = even_cnt; return even_max; }
	if (even_cnt - even_index < even_max - even_dep) return even_max;

	if (even[even_index][2] == 0 && even_check(even_index) == 0) {
		even[even_index][2] = 1;
		if (even_max < even_dep + 1) even_max = even_dep + 1;
		if (even_index == even_cnt - 1) return even_max;
		even_dfs(even_index + 1, even_dep + 1);
		even[even_index][2] = 0;
	}

	if (even_index == even_cnt) return even_max;
	else even_dfs(even_index + 1, even_dep);
}

int main()
{
	input();
	define();
    odd_dfs(0,0);
	even_dfs(0, 0);
	printf("%d %d", odd_max,even_max);

	return 0;
}