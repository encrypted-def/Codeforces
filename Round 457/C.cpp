#include <stdio.h>
bool isPrime(int p) {
	if (p == 1)
		return false;
	for (int i = 2; i*i <= p; i++)
		if (p % i == 0)
			return false;
	return true;
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	// N보다 크면서 소수인 것을 찾아야함
	int P = N + 1;
	while (!isPrime(P))
		P++;
	printf("%d %d\n", P, P);
	for (int i = 1; i <= N - 2; i++)
		printf("%d %d %d\n", i, i + 1, 1);
	printf("%d %d %d\n", N - 1, N, P - (N - 2));
	int cnt = N - 1;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 2; j <= N; j++) {
			if (cnt == M)
				break;
			printf("%d %d %d\n", i, j, 10000000);
			cnt++;
		}
		if (cnt == M)
			break;
	}
}
