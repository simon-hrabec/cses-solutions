#include <bits/stdc++.h>
 
using namespace std;
 
uint64_t fnums[1'000'001];
constexpr int64_t MOD = 1'000'000'007;

pair<int64_t, int64_t> egcd(const int64_t a, const int64_t b) {
  if (a == 0) {
    return {0, 1};
  }
 
  const auto[x, y] = egcd(b%a, a);
  return {y - (b/a) * x, x};
}
 
uint64_t inverse(const int64_t a) {
  const auto[x, y] = egcd(a, MOD);
  return (x%MOD + MOD) % MOD;
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
    uint64_t bot1 = inverse(fnums[b]);
    uint64_t bot2 = inverse(fnums[a-b]);

    cout << ((((top * bot1) % MOD) * bot2) % MOD) << endl;
  }
}
 
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  solve();  
  return 0;
}