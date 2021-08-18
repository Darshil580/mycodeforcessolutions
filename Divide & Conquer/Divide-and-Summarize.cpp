#include <bits/stdc++.h>
using namespace std;
#define pv(v) for(int i = 0; i < v.size(); ++i)cout<<#v<<"="<<v[i]<<endl;



void cal(vector<int> v, vector<int>* data) {
	// pv(v);
	// if (v.size() == 2) {
	// 	da
	// }
	data->push_back(accumulate(v.begin(), v.end(), 0));

	int min = v[0], max = v[0];
	for (int i = 1; i < v.size() ; ++i)
	{
		if (min > v[i]) {
			min = v[i];
		}
		if (max < v[i]) {
			max = v[i];
		}
	}
	// cout << min << "-" << max << "-" << endl;

	if (min == max) {
		return;
	}

	int mid = (min + max) / 2;

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] <= mid) {
			left.push_back(v[i]);
		}
		else {
			right.push_back(v[i]);
		}
	}

	cal(left, data);
	cal(right, data);


}

void solve() {
	// data.clear();
	vector<int> v;
	vector<int> data;
	int n, q;
	cin >> n >> q;
	for (int i = 0, j; i < n; ++i)
	{
		cin >> j;
		v.push_back(j);
	}
	cal(v, &data);
	// pv(data);
	for (int i = 0, j; i < q; ++i)
	{
		int x = 0;
		cin >> j;
		// cout << j;
		for (auto k : data) {
			if (j == k) {
				cout << "Yes" << endl;
				x = 1;
				break;
			}
		}
		if (x == 0) {
			cout << "No" << endl;
		}

	}
}

int main(int argc, char const *argv[])
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