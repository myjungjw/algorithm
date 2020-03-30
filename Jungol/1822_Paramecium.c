#include <stdio.h>
int a, b, d, N, birth;
int bug[10001];

int sum(int s, int e){
	int sum = 0 ;
	for ( int i = s ;i < e ; i++) sum += bug[i];
	return sum%1000;
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &a, &b, &d, &N);
	bug[0] = 1;
	for (int i = 1; i <= N; i++) {
		birth = sum(a-1, b-1);
		for ( int j = (d - 1) ; j > 0 ; j--) bug[j] = bug[j - 1];
		bug[0] = birth;
	}
	printf("%d", sum(0, d));
	return 0;
}
