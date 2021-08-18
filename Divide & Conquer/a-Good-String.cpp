#include <iostream>
#include<string>
using namespace std;

int  min(int l , int r) {
	return l < r ? l : r;
}

int getcost(string s, char ch) {
	int  val1 = 0, val2 = 0;
	if (s.size() == 1) {
		if (s[0] == ch) {
			return 0;
		} else {
			return 1;
		}
	}

	string s1 = s.substr(0, s.size() / 2);
	string s2 = s.substr(s.size() / 2, s.size());

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] == ch) {
			continue;
		}
		else {
			val1++;
		}
	}

	for (int i = s.size() / 2; i < s.size(); i++) {
		if (s[i] == ch) {
			continue;
		}
		else {
			val2++;
		}
	}
	return min(val1 + getcost(s2, ch + 1), val2 + getcost(s1, ch + 1));

}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void testcase() {
	int T;
	char ch = 'a';
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int n;
		string s;
		cin >> n;
		cin >> s;
		cout << getcost(s, ch) << endl;
	}
}

int main(int argc, char const *argv[])
{
	fastIO();
	testcase();
	return 0;
}