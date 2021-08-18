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

set<ll> poss;
vector<ll> a;
vector<ll> pre_sum;

void solve(ll s, ll e)
{
    poss.insert(pre_sum[e + 1] - pre_sum[s]);

    if (a[s] == a[e])
    {
        return;
    }

    ll l = s, h = e + 1;
    ll val = (a[s] + a[e]) / 2;
    while (l < h)
    {
        ll mid = (l + h) / 2;
        if (a[mid] <= val)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }

    ll pivot = h - 1;
    solve(s, pivot);
    solve(pivot + 1, e);
}

int main()
{

    // Use ctrl+shift+b ( second option )
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        poss.clear();

        a.resize(n, 0);
        pre_sum.resize(n + 1, 0);
        // pv(pre_sum);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(all(a));
        for (ll i = 1; i <= n; i++)
        {
            pre_sum[i] = pre_sum[i - 1] + a[i - 1];
        }
        pv(pre_sum);
        solve(0, n - 1);

        while (m--)
        {
            ll el;
            cin >> el;

            if (poss.find(el) != poss.end())
                cout << "Yes" << nl;
            else
                cout << "No" << nl;
        }
    }

    return 0;
}
