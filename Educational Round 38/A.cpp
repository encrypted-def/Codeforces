#include <stdio.h>
#include <string.h>
char s[105];
bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main(void) {
	int t;
	scanf("%d", &t);
	scanf("%s", s);
	printf("%c", s[0]);
	for (int i = 1; i < t; i++) {
		if (isVowel(s[i - 1]) && isVowel(s[i]))
			continue;
		printf("%c", s[i]);
	}
}
