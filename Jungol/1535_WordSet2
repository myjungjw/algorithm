#include <stdio.h>
int ind = 0;
typedef struct _node {
	char word[51];
}Node;

Node list[500];

int mstrlen(const char* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int mstrcmp(const char* str1, const char* str2) {
	if (mstrlen(str1) != mstrlen(str2)) return 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
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
		if (mstrcmp(list[i].word, _word)) return 1;
	}
	mstrcpy(list[ind++].word, _word);
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

int main() {
	int n = 0;
	char END[] = "END";
	char sentence[51];

	while (1) {
		gets(sentence);
		if (mstrcmp(sentence, END)) break;
		run(sentence);
		for (int i = 0; i < ind; i++) {
			printf("%s ", list[i].word);
		}
		printf("\n");
	}


	return 0;
}
