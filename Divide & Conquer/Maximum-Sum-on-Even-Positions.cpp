#include <iostream>
#include <vector>
#include <algorithm>
#define all(a) a.begin(),a.end()
#define print(a) for (auto x : a)cout << x<<" ";
using namespace std;

int check(vector<int> *v) {

	int sum = 0, x = 0;
	if (v.size() % 2 == 0) {
		x = 0;
	}
	else {
		x = 1;
	}
	vector<int> left = {v.begin(), v.begin() + v.size() - x / 2};
	vector<int> right = {v.begin() + v.size() - x / 2, v.end()};


	if (x == 1) {
		sum += v[v.size() - 1];
	}

	return sum;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	int sum = 0;
	for (int i = 0, j; i < n; ++i)
	{
		cin >> j;
		v.push_back(j);
	}
	// cout << v.size() << endl;
	// print(v);
	cout << check(&v);

}

int main(int argc, char const * argv[])
{
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}