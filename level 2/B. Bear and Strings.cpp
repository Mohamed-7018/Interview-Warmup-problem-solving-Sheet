#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
#define all(a)  a.begin(),a.end()

double START_TIME;
ll dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
ll dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

void _Depressed(bool isEnd = false) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    START_TIME = clock();
#endif
}

const ll OO = 0X3F3F3F3F3F3F3F3F;
const ll N = 5 * 1e5 + 9, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;

void solve(ll test_case) {
  string s;int ANS =0;
  cin >> s;

  for(int i=0;i<s.length();i++) {
      int found = s.find("bear",i);
      if (found != -1) { ANS += (s.length() - (found + 3)); }
  }
  cout<<ANS <<endl;

}

int main() {
    _Depressed();
    ll testCases = 1;
//    cin >> testCases;
    while (testCases--) {
        solve(testCases);
    }

#ifndef ONLINE_JUDGE
    double END_TIME = clock();
    double TIME_TAKEN = double(END_TIME - START_TIME) / double(CLOCKS_PER_SEC);
    cout << "\n// Time taken = " << fixed << setprecision(5) << TIME_TAKEN << " ms\n";
#endif

}