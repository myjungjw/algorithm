#include <stdio.h>
int N, k;
int map[50][50];
int cx = -1;
int cy = 0;
int flag = 0;
int sflag = 0;
int cnt, scnt;
int endx, endy;
int sx = -2 , sy=-2;
int t;

typedef struct _point {
	int x;
	int y;
}Dir;
void input();
void output();
void roof(Dir in);
Dir solv(Dir in);


int main() {
	freopen("in.txt", "r", stdin);
	input();
	Dir in;
	in.x = 1;
	in.y = 0;

	roof(in);
	output();
	return 0;
}

void input() {
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[j][i]);
		}
	}
	endx = N;
	endy = N - 1;
};

void output() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
}



Dir solv(Dir in) {
	cx = cx + in.x;
	cy = cy + in.y;
`	int tile = map[cx][cy];
	Dir out;

	if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 0) && (((in.x == 0) && (in.y == -1)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = -in.y;
		out.y = -in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 1) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == -1)))) {
		out.x = in.y;
		out.y = in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 2) && (((in.x == -1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.y;
		out.y = in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 3) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = -in.y;
		out.y = -in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 4) && (((in.x == 0) && (in.y == -1)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.x;
		out.y = in.y;
		cnt++;
		return out;
	}
	else if (((cx < N) && (cx >= 0) && (cy >= 0) && (cy < N)) && (tile == 5) && (((in.x == 1) && (in.y == 0)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = in.x;
		out.y = in.y;
		cnt++;
		return out;
	}
	else if (k <= 0 && cx!= sx && cy!=sy ) {
		flag = 1;
		printf("-1");
		return in;
	}
	else {
		if (sx != (cx - in.x) || sy != (cy - in.y)) k--;
		cx = cx - in.x;
		cy = cy - in.y;
		sx = cx;
		sy = cy;
		map[cx][cy] = t;
        // 안된다
        // 아무거나 넣으면 안됨. 입구가 맞는 놈으로 넣어야됨.. ㅅㅂ
        // in.x가 아니라 그 전의 방향을 기억하고 있어야함.. 후
		t++;
		cx = -1;
		cy = 0;
		cnt = 0;
		in.x = 1;
		in.y = 0;
		return in;
	}
	return out;
}

void roof(Dir in) {

	Dir out;
	while (1) {
		out = solv(in);
		if (flag == 1) break;
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt);
			break;
		};
		in = out;
	}
	return;
}



/*
(x, y)

0번
(0, -1) -> (1, 0)
(-1, 0) -> (0, 1)

1번
(1, 0) -> (0, 1)
(0, -1) -> (-1, 0)

2번
(0, 1) -> (1, 0)
(-1, 0) -> (0, -1)

3번
(1, 0) -> (0, -1)
(0, 1) -> (-1, 0)

4번
(0, -1) -> (0, -1)
(0, 1) -> (0, 1)

5번
(1, 0) -> (1, 0)
(-1, 0) -> (-1, 0)

4->5 or 5->4 는 절대 안됨

start는 [-1,0]에서 (1, 0)을 먹으면서 시작
*/
