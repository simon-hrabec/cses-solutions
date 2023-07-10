#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  unordered_set<int> nums;
  nums.rehash(200000);
  int n;
  cin >> n;
  while(n--) {
    int num;
    cin >> num;
    nums.insert(num);
  }
  
  cout << nums.size() << endl;
}
 
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  solve2(); 
  return 0;
}
