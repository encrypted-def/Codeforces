#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int op[1001]; // op[i] : i를 몇 번 해야 1로 만들 수 있는지.
const int MOD = 1000000007;
char n[1005];
int combi[1005][1005];
int k;
vector<int> cand;
int operation(int k) {
	int ans = 0;
	while (k) {
		ans += k & 1;
		k >>= 1;
	}
	return ans;
}
int calc(int n) {
	int ans = 0;
	while (n > 1) {
		n = operation(n);
		ans++;
	}
	return ans;
}
void setcombi() {
	combi[0][0] = 1;
	for (int i = 1; i <= 1003; i++) {
		combi[i][0] = 1;
		combi[i][i] = 1;
	}
	for (int n = 1; n <= 1003; n++)
		for (int r = 1; r <= n - 1; r++)
			combi[n][r] = (combi[n - 1][r] + combi[n - 1][r - 1]) % MOD;
}
int main(void) {
	setcombi();
	scanf("%s", n);
	scanf("%d", &k);
	for (int i = 1; i <= 1000; i++) {
		if (calc(i) == k - 1) {
			cand.push_back(i); // 1이 i개 있는 수여야 special함
		}
	}
	if (k == 0) {
		printf("1");
		return 0;
	}
	int len = strlen(n);
	int cnt0 = 0;
	int cnt1 = 0;
	int idx = 0;
	int ans = 0;
	while (idx < len) {
		if (n[idx] == '1') {
			// len-1-idx개를 마음대로 굴릴 수 있음. (cnt1)개는 1로 이미 고정됨 
			for (auto near : cand) {
				if (near - cnt1 < 0)
					continue;
				ans = (ans + combi[len - 1 - idx][near - cnt1]) % MOD;
			}
			cnt1++;
		}
		idx++;
	}
	for (auto near : cand) {
		if (cnt1 == near)
			ans = (ans + 1) % MOD;
	}
	if (k == 1)
		ans--;
	printf("%d", ans);
}
