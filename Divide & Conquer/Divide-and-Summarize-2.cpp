#include <bits/stdc++.h>
using namespace std;
#define pv(v) for(int i = 0; i < v.size(); ++i)cout<<#v<<"="<<v[i]<<endl;
#define all(c) c.begin(),c.end()
vector<int> presum;
vector<int> v;
set<int> d;


void cal(int s, int e) {

	d.insert(presum[e + 1] - presum[s]);

	if (v[s] == v[e]) {
		return;
	}

	int l = s, h = e + 1, val = (v[s] + v[e]) / 2;

	while (l < h) {
		int mid = (l + h) / 2;
		if (v[mid] <= val) {
			l = mid + 1;
		}
		else {
			h = mid;
		}
	}
	// cout << min << "-" << max << "-" << endl;


	int pivot = h - 1;
	cal(s, pivot);
	cal(pivot + 1, e);


}

void solve() {

	v.clear();
	d.clear();
	presum.clear();
	int n, q;
	cin >> n >> q;
	for (int i = 0, j; i < n; ++i)
	{
		cin >> j;
		v.push_back(j);
	}
	sort(all(v));
	presum.push_back(0);
	for (int i = 0, sum = 0; i < v.size(); ++i)
	{
		sum += v[i];
		presum.push_back(sum);
	}
	// pv(presum);
	cal(0, n - 1);

	while (q--) {
		int k;
		cin >> k;
		if (d.find(k) != d.end()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
int main(int argc, char const * argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		solve();
	}
	return 0;
}