#include <stdio.h>
int f[30];
bool isFibo(int a) {
	for (int i = 1; i <= 29; i++) {
		if (f[i] == a)
			return true;
	}
	return false;
}
int main(void) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 29; i++)
		f[i] = f[i - 1] + f[i - 2];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (isFibo(i))
			printf("O");
		else
			printf("o");
	}
}
