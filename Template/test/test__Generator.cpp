#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

void run_case(){
    int n = uid(1, 10);
    cout << n << "\n";
}

signed main(){
    cin.tie(0) ->sync_with_stdio(0);

    #ifdef JASPER
        freopen("INP.inp", "r", stdin);
    #endif

    int Test = 1; 
    // cin >> Test;
    for (int i = 1; i <= Test; i++){

        run_case();
    }
}


