#include<iostream>
using namespace std;
char a;
int N, n;
int stack[100];
int t=-1;

void in() {
	cin >> stack[++t];
	return;
};
void out() {
	if (t == -1) cout << "empty" << endl;
	else cout << stack[t--] << endl;
	return;
}
void cprint() {
	cout << t+1 << endl;
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 'i') in();
		else if (a == 'o') out();
		else if (a == 'c') cprint();
	}

	return 0;
}
