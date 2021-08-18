#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, i = 0, z = 0, counter = 0;
	vector<int> v;
	cin >> n;
	for (int j = 1 ; j <= n; j++) {
		v.push_back(j);
	}
	do {
		i = 0;
		for (int j = 1; j < n && counter != 10001 ; counter++, ++j)
		{
			string answer;
			cout << 1 << " " << v[i] << " " << v[j] << endl;
			cin >> answer;
			if (answer == "NO") {
				counter++;
				break;
			}
			else {
				i++;
				if (i == n - 1) {
					z = 1;
				}
			}
		}
		if (z == 1) {
			break;

		}

	} while (counter != 10001 && next_permutation(v.begin(), v.end()));
	cout << 0 << " ";
	if (i == n - 1) {
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