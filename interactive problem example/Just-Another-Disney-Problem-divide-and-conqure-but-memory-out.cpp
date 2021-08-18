#include <iostream>
#include<vector>
#include<algorithm>
#define pv(v)for (int i = 0; i < v.size(); ++i)cout<<#v<<"="<<v[i]<<endl;

using namespace std;

vector<int> work(vector<int> v, int *counter) {
	int x;
	string answer;
	if (v.size() == 2) {
		cout << 1 << " " << v[0] << " " << v[1] << endl;
		(*counter)++;
		cin >> answer;
		if (answer == "NO") {
			int temp;
			temp = v[0];
			v[0] = v[1];
			v[1] = temp;
			// cout << "check=" << v[0] << " " << v[1] << endl;
			return v;
		}
	}
	if (v.size() == 1) {
		// cout << "as" << v[0];
		return v;
	}
	if (v.size() % 2 == 1) {
		x = 1;
	}
	else {
		x = 0;
	}
	vector<int> v1 = {v.begin(), v.begin() + v.size() / 2};
	vector<int> v2 = {v.begin() + (v.size() / 2 - 1) + x, v.end() };

	v1 = work(v1, counter);
	v2 = work(v2, counter);

	vector<int> ans;
	// pv(newbie);

	for (int i = 0; i < v.size(); i++) {
		cout << 1 << " " << v1[0] << " " << v2[0] << endl;
		(*counter)++;
		cin >> answer;
		if (answer == "YES") {
			ans.push_back(v1[0]);
			v1.erase(v1.begin(), v1.begin() + 1);
			// pv(v1);

			if (v1.empty()) {
				ans.insert(ans.end(), v2.begin(), v2.end());
				return ans;
			}
		} else {
			ans.push_back(v2[0]);
			// pv(ans);
			v2.erase(v2.begin(), v2.begin() + 1);
			// pv(v2);

			if (v2.empty()) {
				ans.insert(ans.end(), v1.begin(), v1.end());
				return ans;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n, i = 0, z = 0, counter = 0;
	vector<int> v;
	cin >> n;
	for (int j = 1 ; j <= n; j++) {
		v.push_back(j);
	}
	v = work(v, &counter);


	cout << 0 << " ";
	if (counter != 10001) {
		for (auto k : v)cout << k << " ";
	}
	else {
		for (int k = 0; k < n; ++k)
		{
			cout << 0 << " ";
		}
	}
	return 0;
}