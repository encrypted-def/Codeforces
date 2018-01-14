#include <stdio.h>
#include <string.h>
char a[30];
char b[30];
int numA[10];
int numB[10];
int main(void) {
	scanf("%s", a);
	scanf("%s", b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for (int i = 0; i < lenA; i++)
		numA[a[i] - '0']++;
	for (int i = 0; i < lenB; i++)
		numB[b[i] - '0']++;
	if (lenB > lenA) { // 어떻게 해도 무조건 A가 작을 때
		for (int i = 9; i >= 0; i--)
			while (numA[i]--)
				printf("%c", i + '0');
		return 0;
	}
	// lenA = lenB임이 보장됨
	for (int i = 0; i < lenA; i++) {
		// i번째 자리의 값을 b[i]로 둘 때
		if (numA[b[i] - '0'] > 0) { // 존재할 경우
			numA[b[i] - '0']--; // 일단 i번째 자리의 값을 b[i]로 뒀다고 가정
			long long A_chunk = 0;
			long long B_chunk = 0;
			for (int j = i + 1; j < lenA; j++)
				B_chunk = 10 * B_chunk + (b[j] - '0');
			for (int i = 0; i <= 9; i++) {
				for (int t = 0; t < numA[i]; t++)
					A_chunk = 10 * A_chunk + i;
			}
			if (A_chunk <= B_chunk) { // b[i]로 두는 것에 문제가 없음을 확인
				printf("%c", b[i]);
				continue;
			}
			else
				numA[b[i] - '0']++; // b[i]로 둔 것을 다시 되돌림
		}
		// 최상위 값만 정해주면 됨
		for (int j = b[i] - 1; j >= '0'; j--) {
			if (numA[j - '0'] > 0) {
				numA[j - '0']--;
				printf("%c", j);
				break;
			}
		}
		for (int i = 9; i >= 0; i--) {
			while (numA[i]--)
				printf("%c", i + '0');
		}
		return 0;
	}
}
