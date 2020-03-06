#include <stdio.h>
int N, k;
int map[50][50];
int cx = -1;
int cy = 0;
int flag = 0;
int sflag = 0;
int second = 0;
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
Dir ssolv(Dir in);


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
	else if ( k == 0 ){
		flag = 1;
		printf("-1");
		return out;
	}else{
		second = 1;
		k--;
		return out;
	}
	return out;
}

void roof(Dir in) {

	Dir out;
	while (1) {
		out = solv(in);
		if (flag == 1) break;
		if (second == 1 && k==0 ) {
			sroof(in);
			break;
		}
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt);
			break;
		};
		in = out;
	}
	return;
}

void sroof(Dir in) {
	//save point
	sx = cx;
	sy = cy;
	int temp;

// 무슨 타일로 바꿨는지는 중요하지 않음. 3방향이란게 중요
	//방향 유지
	while(1) {
		in = ssolv(in);
		if (sflag == 1) break;
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt + scnt);
			return;
		}
	}

	cx = sx;
	cy = sy;
	sflag = 0;
	scnt =0 ;
	temp = in.x;
	in.x = in.y;
	in.y = temp;

	while(1) {
		in = ssolv(in);
		if (sflag == 1) break;
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt + scnt);
			return;
		}
	}

	cx = sx;
	cy = sy;
	sflag = 0;
	scnt = 0;
	in.x = -in.x;
	in.y = -in.y;
	while(1) {
		in = ssolv(in);
		if (sflag == 1) break;
		if ((cx + in.x == endx) && (cy + in.y == endy)) {	// 도착
			printf("%d", cnt + scnt);
			return;
		}
	}
	printf("-1");
	return;
}

Dir ssolv(Dir in){
	cx = cx + in.x;
	cy = cy + in.y;
	int tile = map[cx][cy];
	Dir out;

	if (((cx < N) || (cy < N)) && (tile == 0) && (((in.x == 0) && (in.y == -1)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = -in.y;
		out.y = -in.x;
		scnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 1) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == -1)))) {
		out.x = in.y;
		out.y = in.x;
		scnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 2) && (((in.x == -1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.y;
		out.y = in.x;
		scnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 3) && (((in.x == 1) && (in.y == 0)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = -in.y;
		out.y = -in.x;
		scnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 4) && (((in.x == 0) && (in.y == -1)) || ((in.x == 0) && (in.y == 1)))) {
		out.x = in.x;
		out.y = in.y;
		scnt++;
		return out;
	}
	else if (((cx < N) || (cy < N)) && (tile == 5) && (((in.x == 1) && (in.y == 0)) || ((in.x == -1) && (in.y == 0)))) {
		out.x = in.x;
		out.y = in.y;
		scnt++;
		return out;
	}
	else if ( k == 0 ){
		// 얘는 하면 안됨. 3번 반복할 놈이라.
		sflag = 1;
		return out;
	}else{
		second = 1;
		k--;
		return out;
	}
	return out;
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
