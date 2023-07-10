#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> arr;
vector<int> res;
 
int dfs(int idx) {
  int count = 0;
  for(const int child : arr[idx]) {
    count += dfs(child) + 1;
  }
  res[idx] = count;
  return count;
}
 
void solve() {
  int n;
  cin >> n;
  
  arr.resize(n);
  res.resize(n);
 
  for(int i = 1; i < n; i++) {
    int num;
    cin >> num;
    arr[num-1].push_back(i);
  } 
 
  dfs(0);
 
  for(const auto num : res) {
    cout << num << ' ';
  }
  cout << endl;
}
 
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  solve();  
  return 0;
}
