#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
#define all(a)  a.begin(),a.end()

ll dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
ll dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

void _Depressed() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const ll OO = 0X3F3F3F3F3F3F3F3F;
const ll N = 5 * 1e5 + 9, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;


void solve(ll test_case) {
    ll n,x;
    cin >> n >> x;

    vector<ll> a(n);
    for(auto &i : a) cin >> i;

    sort(all(a));
//    reverse(all(a));

    ll ANS = 0;
    for(auto i: a) {
        ANS+= i*x;
        x= max(x-1,1LL);
    }

    cout << ANS <<"\n";
}

int main() {
    _Depressed();
    ll testCases;
    testCases = 1;
//    cin >> testCases;
    while (testCases--) {
        solve(testCases);
    }
}