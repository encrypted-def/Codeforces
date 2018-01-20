#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100004];
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool isAllEven = true;
	sort(a, a + n);
	int cnt = 0;
	int current = a[0];
	for (int i = 0; i < n; i++) {
		if (current == a[i])
			cnt++;
		else {
			current = a[i];
			if (cnt % 2 != 0) {
				isAllEven = false;
				break;
			}
			cnt = 1;
		}
	}
	if (cnt % 2 != 0)
		isAllEven = false;
	if (isAllEven)
		printf("Agasa");
	else
		printf("Conan");
	return 0;
}
