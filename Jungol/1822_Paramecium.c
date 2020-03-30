#include <stdio.h>
int a, b, d, N, temp;
int bug[10001];
int birth() {
	int sum=0;
	for (int i = (a-1); i < (b-1); i++) {
		sum += bug[i];
	}
	return sum%1000;
}

int result() {
	int sum=0;
	for (int i = 0; i < d; i++) {
		sum += bug[i];
	}
	return sum%1000;
}
int main() {
	scanf("%d %d %d %d", &a, &b, &d, &N);
	for (int i = 0; i <= N; i++) {
		if (i == 0) {	
			bug[0] = 1;
			continue;
		}
		else {
			temp = birth();
			for (int j = (d - 1) ; j > 0 ; j--) {
				bug[j] = bug[j - 1];
			}
			bug[0] = temp;
		}
	}
	printf("%d", result());
	return 0;
}
