#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
vector<pair<int, int>> v;
list<int> gr[100001] ;
int dp[100001][2];


void dfs(int child, int parent) {
	for (auto i : gr[child])
	{
		if (i != parent) {
			dfs(i, child);
			dp[child][0] += max(abs(v[child - 1].first - v[i - 1].first) + dp[i][0], abs(v[child - 1].first - v[i - 1].second) + dp[i][1]);
			dp[child][1] += max(abs(v[child - 1].second - v[i - 1].first) + dp[i][0], abs(v[child - 1].second - v[i - 1].second) + dp[i][1]);
		}
	}

}
void work() {
	int n;
	cin >> n;
	v.clear();
	for (int i = 1; i <= n; ++i)
	{
		gr[i].clear();
		dp[i][0] = dp[i][1] = 0;
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		work();
		cout << endl;
	}
	return 0;
}