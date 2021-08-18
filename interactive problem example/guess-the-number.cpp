#include <iostream>
#include <string>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(int argc, char const *argv[])
{
	// fastIO();
	int  left = 1, right = 1000000;
	string response;

	while (left != right) {
		int mid = (left + right + 1) / 2;
		cout << mid << endl;
		cin >> response;
		if (response == "<") {
			right = mid - 1;
		}
		else {
			left = mid;
		}
	}
	cout << "! " << left << endl;
	return 0;
}