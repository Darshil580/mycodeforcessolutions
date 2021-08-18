#include <bits/stdc++.h>
using namespace std;

#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_upto(a, n)        \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";    \
    cout << endl
#define take(x, n)              \
    for (int i = 0; i < n; i++) \
        cin >> x[i];
#define pv(v) for(int i = 0; i < v.size(); ++i)cout<<#v<<"="<<v[i]<<endl;
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"
#define watch3(x, y, z) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << " and " << (#z) << " is " << (z) << "\n"

#define ll long long
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(), (c).end()
#define nl "\n"

#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mod 1000000007

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;



void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void local() {
#ifndef ONLINE_JUDGE
	// for getting input from input.in
	freopen("input.in", "r", stdin);
	// for writing output to output.in
	freopen("output.in", "w", stdout);
#endif
}


int operation() {

	//Your Logic Code...............


}


void testcase() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ":" << operation() << endl;
	}
}

int main()
{
	//fast IO by disabling c functionality on c++ active.
	fastIO();
	//Comment it during submission.
	local();
	//testcases run.........
	testcase();
	return 0;
}