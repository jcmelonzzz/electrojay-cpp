#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int l = 0,r = n - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			l ++;
			r --;
		} else { 
			break;
		}
	}

	cout << r - l + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}