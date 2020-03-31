#include <iostream>
using namespace std;
int N;
int head, tail;
int q[101];
char c;
void in() {
	cin >> q[tail++];
	return;
}
void out() {
	if (head == tail) cout << "empty" << endl;
	else cout << q[head++] << endl;
	return;
}
void cprint() {
	cout << (tail - head) << endl;
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'i') in();
		else if (c == 'o') out();
		else if (c == 'c') cprint();
	}
	return 0;
}
