#include <bits/stdc++.h>
 
using namespace std;

std::array<int, 200'000> arr;

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	std::sort(arr.begin(), arr.begin()+n);

	int res = 1;
	for(int i = 1; i < n; i++) {
		if (arr[i-1] != arr[i]) {
			res++;
		}
	}

	cout << res << endl;
}
 
int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	solve();	
	return 0;
}
