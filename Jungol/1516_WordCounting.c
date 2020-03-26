#include <stdio.h>
int ind = 0;
typedef struct _node {
	char word[51];
	int cnt;
}Node;

Node list[51];

int mstrlen(const char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int mstrcmp(const char* str1, const char* str2) {
	int i = 0;
	while (1) {
		if (str1[i] - str2[i]) return (str1[i] - str2[i]);
		if (str1[i] == '\0' && str2[i] == '\0') return 0;
		i++;
	}
}

char* mstrcpy(char* des, const char* sour) {
	int i = 0;
	for (i = 0; sour[i] != '\0'; i++) {
		des[i] = sour[i];
	}
	des[i] = '\0';
	return des;
}
int listcmp(char* _word) {
	for (int i = 0; i < ind; i++) {
		if (!mstrcmp(list[i].word, _word)) {
			list[i].cnt++;
			return 1;
		}
	}
	mstrcpy(list[ind].word, _word);
	list[ind].cnt = 1;
	ind++;
	return 0;
}

void run(char* sentence) {
	int len = mstrlen(sentence);
	char _word[51];
	for (int i = 0; i < len; i++) {
		int j = 0;
		for (j = 0; sentence[i + j] != ' '; j++) {
			_word[j] = sentence[i + j];
			if ((i + j) > len) break;
		}
		_word[j] = '\0';
		i = i + j;
		if (listcmp(_word)) continue;
	}
	return;
}

void init() {
	for (int i = 0; i < ind; i++) {
		list[i].cnt = 0;
	}
	ind = 0;
}

void Sorting() {
	char temp[51];
	int tcnt;
	for (int i = 0; i < ind; i++) {
		for (int j = i; j < ind; j++) {
			if (mstrcmp(list[i].word, list[j].word) > 0) {
				mstrcpy(temp, list[i].word);
				mstrcpy(list[i].word, list[j].word);
				mstrcpy(list[j].word, temp);
				tcnt = list[i].cnt;
				list[i].cnt = list[j].cnt;
				list[j].cnt = tcnt;
			}
		}
	}
}

int main() {
	int n = 0;
	char END[] = "END";
	char sentence[201];

	while (1) {
		gets(sentence);
		if (!mstrcmp(sentence, END)) break;
		run(sentence);
		Sorting();
		for (int i = 0; i < ind; i++) {
			printf("%s : %d\n", list[i].word, list[i].cnt);
		}
		init();
	}


	return 0;
}
