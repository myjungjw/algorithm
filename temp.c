#include <stdio.h>
int N, k;
int map[50][50];
int cx = -1;
int cy = 0;
int flag = 0;
int cnt, scnt;
int endx, endy;
int sx, sy, dx, dy;

typedef struct _point {
	int x;
	int y;
}Dir;
void input();
void output();
void roof(Dir in);
void sroof(Dir in);
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
	int tile = map[cx][cy];
	Dir out;

	if (((cx < N) || (cy < N)) && (tile == 0) && (((in.x == 0) && (in.y == -1)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = -in.y;
		out.y = -in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 1) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == -1)))) {
		out.x = in.y;
		out.y = in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 2) && (((in.x == -1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.y;
		out.y = in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 3) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = -in.y;
		out.y = -in.x;
		cnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 4) && (((in.x == 0) && (in.y == -1)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.x;
		out.y = in.y;
		cnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 5) && (((in.x == 1) && (in.y == 0)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = in.x;
		out.y = in.y;
		cnt++;
		return out;
	}
	else {
		// in이 같은 방향이어야 함.즉 4방위 중 하나이므로 in 방향당 3가지 케이스가 나옴
		// 그런데 그중에 하나는 실패했으므로 나머지 2개를 테스트 해봐야함
		// 2개중에 더 빠른놈이 답임.
		// 아니네 하나밖에 나올 수가 없음.
		if (k == 0) {
			flag = 1;
			printf("-1");
			return out;
		}
		cx = cx - in.x;
		cy = cy - in.y;
		cnt--;
		k--;
		// save point map[sx][sy] 에서 dx, dy 방향
		sx = cx;
		sy = cy;
		dx = in.x;
		dy = in.y;

		for (int i = 0; i < 6; i++) {
			// save point로.. 
			cx = sx;
			cy = sy;
			in.x = dx;
			in.y = dy;
			// 문제의 그 지점 회복됨.
			// 여기서 타일을 바꾸고 out지점도 타일에 따라 바뀌어야됨.
			map[sx][sy] = i;
			
			roof(in);
		}
		return out;
	}

	return out;
}

void roof(Dir in) {
	while (1) {
		in = solv(in);
		if (flag == 1) break;
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt);
			break;
		};
	}
	return;
}

void sroof(Dir in) {
	while(1) {
		in = solv(in);
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
