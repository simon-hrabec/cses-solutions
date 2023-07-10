#include <bits/stdc++.h>

using namespace std;

struct trienode {
  trienode* children[2];
};

trienode tarr[6400000];
int tidx = 1;

void insert(int num) {
  trienode* curr = &tarr[0];
  for(int i = 29; i >= 0; i--) {
    bool bit = num & (1<<i);
    if (curr->children[bit] == nullptr) {
      curr->children[bit] = &tarr[tidx++];
    }
    curr = curr->children[bit];
  }
}

int query(int num) {
  trienode* curr = &tarr[0];
  int res = 0;
  for(int i = 29; i >= 0; i--) {
    bool bit = num & (1<<i);
      if (curr->children[0] && curr->children[1]) {
          res |= 1<<i;
          curr = curr->children[!bit];
      } else if (curr->children[0]) {
          res |= num & (1<<i);
          curr = curr->children[0];
      } else {
          res |= (~num & (1<<i));
          curr = curr->children[1];
      }
  }

  return res;
}

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  insert(0);
  int best = 0;
  int num = 0;
  for(int i = 0; i < n; i++) {
    num ^= arr[i];
    best = max(query(num), best);
    insert(num);
  }

  cout << best << endl;
}

int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
