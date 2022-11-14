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
	if (n == 1)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
	}
	else if (n == 2)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "1 0" << '\n';
	}
	else if (n == 3)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "0 3" << '\n';
		cout << "4 0" << '\n';
	}
	else if (n == 4)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "0 1" << '\n';
		cout << "1 1" << '\n';
		cout << "1 0" << '\n';
	}
	else if (n == 5)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "0 6" << '\n';
		cout << "3 6" << '\n';
		cout << "7 3" << '\n';
		cout << "3 0" << '\n';
	}
	else if (n == 6)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "-4 3" << '\n';
		cout << "0 6" << '\n';
		cout << "3 6" << '\n';
		cout << "7 3" << '\n';
		cout << "3 0" << '\n';
	}
	else if (n == 7)
	{
		cout << "YES" << '\n';
		cout << "12 9" << '\n';
		cout << "12 13" << '\n';
		cout << "8 16" << '\n';
		cout << "-8 16" << '\n';
		cout << "-12 13" << '\n';
		cout << "-12 9" << '\n';
	}
	else if (n == 8)
	{
		cout << "YES" << '\n';
		cout << "0 0" << '\n';
		cout << "5 0" << '\n';
		cout << "8 4" << '\n';
		cout << "8 9" << '\n';
		cout << "5 13" << '\n';
		cout << "0 13" << '\n';
		cout << "-3 9" << '\n';
		cout << "-3 4" << '\n';
	}
	else cout << "NO" << '\n';
}
main(){
    // Toggle()
            Process();
}
