#include <stdio.h>
int W;
int max;
int maxcnt[6];
int cnt[6];
int money[6] = { 500, 100, 50, 10, 5, 1 };
\
int run(int w) {
	int ccnt=0;
	int temp;
	for (int i500 = 0; i500 <= maxcnt[0]; i500++) {
		for (int i100 = 0; i100 <= maxcnt[1]; i100++) {
			for (int i50 = 0; i50 <= maxcnt[2]; i50++) {
				for (int i10 = 0; i10 <= maxcnt[3]; i10++) {
					for (int i5 = 0; i5 <= maxcnt[4]; i5++) {
						for (int i1 = 0; i1 <= maxcnt[5]; i1++) {
							ccnt = i500 + i100 + i50 + i10 + i5 + i1;
							temp = 500 * i500 + 100 * i100 + 50 * i50 + 10 * i10 + 5 * i5 + i1;
							if (temp == w && ccnt > max) {
								cnt[0] = i500;
								cnt[1] = i100;
								cnt[2] = i50;
								cnt[3] = i10;
								cnt[4] = i5;
								cnt[5] = i1;
								max = ccnt;
							}
						}
					}
				}
			}
		}
	}
	return max;
}

int main() {
	int result;
	scanf("%d", &W);
	scanf("%d %d %d %d %d %d", &maxcnt[0], &maxcnt[1], &maxcnt[2], &maxcnt[3], &maxcnt[4], &maxcnt[5]);
	result = run(W);
	printf("%d\n%d %d %d %d %d %d", result, cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
	return 0;
}
