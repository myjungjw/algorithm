#include <stdio.h>

int N, k;
int map[50][50][2];
int endx, endy;
int maxcnt;
int kt;

typedef struct _node {
	int inx;
	int iny;
	int x;
	int y;
}Node;

void input();
void output();
int dfs(Node current, int cnt, int kt);
int NBlocked(Node current);
int CBlocked(Node current, int tile);
Node CalcOut(Node current);


int main() {
	freopen("in.txt", "r", stdin);
	input();
	Node current;
	int cnt = 0;
	current.x = 0;
	current.y = 0;
	current.inx = 1;
	current.iny = 0;

	if (dfs(current, cnt, k) != 0) maxcnt = -1;
	output();
	return 0;
}

void input() {
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[j][i][0]);
		}
	}
	endx = N;
	endy = N - 1;
};

void output() {
	printf("%d", maxcnt);
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[j][i][0]);
		}
		printf("\n");
	}
}

int dfs(Node current, int cnt, int kt) {
	cnt++;
	Node next;
	next = CalcOut(current);

	//0. 탈출조건
	if ((next.x == endx && next.y == endy) && CBlocked(current, map[current.x][current.y][0]) == 0) {
		maxcnt = cnt;
		return 0;
	}
	// 1.막히면
	if (NBlocked(next) == -1 || CBlocked(current, map[current.x][current.y][0]) == -1) {
		if (map[current.x][current.y][1] != 0) return -1;
		if (kt == 0) return -1;
		kt--;
		for (int tile = 0; tile < 6; tile++) {
			if (CBlocked(current, tile) == -1) continue;

			map[current.x][current.y][0] = tile;
			map[current.x][current.y][1] = tile+1;

			if (dfs(current, cnt - 1, kt) == 0) {
				return 0;
			}
			else {
				continue;
			}
		}
	}else {  // 2. 안막히면
		map[current.x][current.y][1] = 1; // visited
		if (dfs(next, cnt, kt) == 0) return 0;
	}
	if (kt == 0) return -1;
	// 이전거로 돌아가서 타일 바꾸기!!
	for (int tile = 0; tile < 6; tile++) {
		if (CBlocked(current, tile) == -1) continue;

		map[current.x][current.y][0] = tile;
		map[current.x][current.y][1] = tile + 1;

		if (dfs(current, cnt - 1, kt) == 0) {
			return 0;
		}
		else {
			continue;
		}
	}
}


Node CalcOut(Node current) {
	Node next;
	next = current;
	int tile = map[current.x][current.y][0];
	if (tile == 0 || tile == 3) {
		next.inx = -current.iny;
		next.iny = -current.inx;
	}
	else if (tile == 1 || tile == 2) {
		next.inx = current.iny;
		next.iny = current.inx;
	}
	else if (tile == 4 || tile == 5) {
		next.inx = current.inx;
		next.iny = current.iny;
	}
	next.x += next.inx;
	next.y += next.iny;
	return next;
}

int NBlocked(Node next) {
	int tile = map[next.x][next.y][0];
	// 가지도 말아야 하는 경우 1. map 초과 2. 갔던길 . 
	// 즉 change(next) 하면안됨
	// change(current) 하거나 그 이전 dfs 타일로 돌아가야댐
	if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= N) return -1;
	if (map[next.x][next.y][1] == 1) return -1;
	return 0;
}
int CBlocked(Node current, int tile) {
	// in과 tile이 안맞는 경우 판단
	if (tile == 0 && (current.inx == 1 || current.iny == 1)) return -1;
	if (tile == 1 && (current.inx == -1 || current.iny == 1)) return -1;
	if (tile == 2 && (current.inx == 1 || current.iny == -1)) return -1;
	if (tile == 3 && (current.inx == -1 || current.iny == -1)) return -1;
	if (tile == 4 && (current.inx == 1 || current.inx == -1)) return -1;
	if (tile == 5 && (current.iny == 1 || current.iny == -1)) return -1;
	return 0;
}

