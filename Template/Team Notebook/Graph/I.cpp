#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define Toggle()  \
    int N;        \
    cin >> N;     \
    cin.ignore(); \
    while (N--)
#define pb push_back
#define SORT(a) sort(a.begin(), a.end())

template <typename T>
using treap = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using multitreap = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using reverse_pq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using matrix = vector<vector<T>>;
template <typename T>
using rubik = vector<vector<vector<T>>>;

void Process(){
	ll n;
	cin >> n;
	ll DP[n + 5][n + 5];
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cin >> DP[i][j];
		}
	}
	ll in = DP[1][1];
	matrix<ll> a(n + 5);
	ll deg[n + 5]{};
	FOR(i, 1, n)
	{
		FOR(j, i + 1, n)
		{
			if (DP[i][j] > in)
			{
				a[i].pb(j);
				deg[j] = -1;
			}
			else
			{
				a[j].pb(i);
				deg[i] = -1;
			}
		}
	}
	
	vector<ll> x;
	ll VST[n + 5]{};
	
	function<void(ll, ll)> dfs = [&](ll y, ll par)
	{
		if (VST[y]) return;
		VST[y] = 1;
		for (auto &o : a[y])
		{
			dfs(o, y);
		}
		x.pb(y);
	};
	
	FOR(i, 1, n)
	{
		if (deg[i] == 0)
		{
			dfs(i, i);
//			cout << i << '\n';
		}
	}
	
	reverse(x.begin(), x.end());
	
	ll ansx[n + 5];
	FOR(i, 0, n - 1)
	{
		ansx[x[i]] = i + 1;
	}
	
    FOR(i, 1, n)
    {
    	cout << ansx[i] << ' ';
	}
	cout << '\n';
    
}
main(){
    // Toggle()
            Process();
}
