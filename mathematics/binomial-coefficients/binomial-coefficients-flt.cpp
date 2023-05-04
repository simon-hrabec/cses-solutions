#include <bits/stdc++.h>
 
using namespace std;
 
uint64_t fnums[1'000'001];
constexpr int64_t MOD = 1'000'000'007;

int64_t exponentiate_mod_minus_2(int64_t num) {
    int64_t res = 1;
    int64_t exponent = MOD-2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = (res * num) % MOD;
        }
        exponent = exponent >> 1;
        num = (num * num) % MOD;
    }
    return res;
}

void solve() {
	fnums[0] = 1;
	fnums[1] = 1;
	for(int i = 2; i < 1'000'001; i++) {
		fnums[i] = (i*fnums[i-1]) % MOD;
	}
 
	int n;
	cin >> n;
	
	while(n--) {
		int64_t a, b;
		cin >> a >> b;
 
		uint64_t top = fnums[a];
		uint64_t bot1 = exponentiate_mod_minus_2(fnums[b]);
		uint64_t bot2 = exponentiate_mod_minus_2(fnums[a-b]);

		cout << ((((top * bot1) % MOD) * bot2) % MOD) << endl;
	}
}
 
int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	solve();	
	return 0;
}