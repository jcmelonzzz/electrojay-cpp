#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{	
	string s;
	cin >> s;

	vector<int> a[10];
	for(int i = 0;i < s.size();i ++){
		a[s[i] - '0'].push_back(i);
	}

	int ans = 0x3f3f3f3f;
	int len = s.size();
	for(int i = 0;i < 10;i ++){
		// cout << "i = " << i << "\n";
		for(int j = 0;j < 10;j ++){
			if(i == j){
				int l = a[i].size();
				ans = min(ans,len - l);

				// cout << "ans = " << ans << "\n";
			}else{
				int cnt = 0;
				int to = 0;
				for(int k = 0;k < a[i].size();k ++){
					while(to < a[j].size() && a[j][to] < a[i][k]){
						to ++;
					}
					if(to >= a[j].size())break;
					cnt ++;
					while(k < a[i].size() && a[j][to] > a[i][k]){
						k ++;
					}
					if(k >= a[i].size())break;
					k --;
				}
				ans = min(ans,len - 2 * cnt);
				// cout << "cnt = " << cnt << "\n";

				// cout << "ans = " << ans << "\n";

				cnt = to = 0;
				for(int k = 0;k < a[j].size();k ++){
					while(to < a[i].size() && a[i][to] < a[j][k]){
						to ++;
					}
					if(to >= a[i].size())break;
					cnt ++;
					while(k < a[j].size() && a[i][to] > a[j][k]){
						k ++;
					}
					if(k >= a[j].size())break;
					k --;
				}
				ans = min(ans,len - 2 * cnt);

				// cout << "ans = " << ans << "\n";

				// cout << "cnt = " << cnt << "\n";
			}
		}
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}