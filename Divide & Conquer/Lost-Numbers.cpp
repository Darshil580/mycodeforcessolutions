#include <iostream>
#include <vector>
#include <algorithm>


#define pv(v) for (int i = 0; i < v.size(); ++i) cout<<v[i]<<endl;

using namespace std;

int main() {
	vector<int> a = {4, 8, 15, 16, 23, 42}, ans(4);
	int i = 0;
	while (i < 4) {
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cout.flush();
		cin >> ans[i];
		i++;
	}
	do {
		bool check = true;
		for (int i = 0; i < 4; i++)
			check &= (a[i] * a[i + 1] == ans[i]);
		if (check) break;
	} while (next_permutation(a.begin(), a.end()));

	cout << "! ";
	for (auto k : a) cout << k << " ";
	cout.flush();

	return 0;
}
