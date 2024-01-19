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
    int n, m, x;
    cin >> n >> m >> x;

    char ch[n][m];
    map<char, set<pair<int, int>>> location;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch[i][j];
            location[ch[i][j]].insert({i, j});
        }
    }

    map<char, double> shortestDistatnce;
    for (const auto &item: location) {
        double distance = INF;
        if (!location.count('S')) break;
        if (item.first == 'S')continue;

        for (const auto &letterLocation: item.second) {
            for (const auto &shiftLocation: location['S']) {
                double currentDistance = sqrt(
                        (shiftLocation.first - letterLocation.first) * (shiftLocation.first - letterLocation.first) + (shiftLocation.second - letterLocation.second) * (shiftLocation.second - letterLocation.second));
                distance = min(distance, currentDistance);
            }
        }

        shortestDistatnce[item.first] = distance;
    }

    int Q; cin >> Q;
    string s;
    cin >>s;
    int ANS = 0;
    for(int i=0;i<s.length();i++) {
        if(!location.count(tolower(s[i]))) {
            cout<< "-1" << endl;
            return;
        }
        if (isupper(s[i])) {
            if (!location.count('S')) {
                cout << -1 << endl;
                return;
            }
            ANS += shortestDistatnce[tolower(s[i])] > x;
        }
    }
    cout << ANS << endl;

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