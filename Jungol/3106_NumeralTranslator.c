#include <stdio.h>
char result[80];
unsigned long long squre(int X, int N) {
	unsigned long long result = 1;
	if (X == 0) return 0;
	for (int i = 0; i < N; i++) {
		if (N != 0) result = result * X;
		if (N == 0) result = 1;
	}
	return result;
}
int mstrlen(char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}
unsigned long long asc(char a) {
	if (a >= 'A') {
		return a - 55;
	}
	return a - 48;
}
char ascr(int a) {
	if (a >= 10) {
		return a + 55;
	}
	return a + 48;
}
unsigned long long Ten(const char* num, int len, int X) {
	unsigned long long n = 0;
	unsigned long long temp;
	for (int i = len; i > 0; i--) {
		temp = squre(X, i - 1);
		n = n + asc(num[len - i]) * temp;
	}
	return n;
}
void Two(int b, unsigned long long n) {
	int i = 0;
	int count = 0;
	int t[80];
	while (n != 0) {
		t[i++] = n % b;
		count++;
		n /= b;
	}
	for (int j = 0; j < count; j++) {
		result[j] = ascr(t[count - j - 1]);
	}

	result[count] = '\0';
	return;
}

int main() {
	int a, b;
	unsigned long long n;
	char num[80];

	while (1) {
		int len;
		scanf("%d", &a);
		if (a == 0) break;
		scanf("%s", num);
		scanf("%d", &b);

		n = Ten(num, mstrlen(num), a);
		Two(b, n);
		if (n == 0) {
			printf("0\n");
		}
		else {
			printf("%s\n", result);
		}
	}
	return 0;
}

