#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
#define all(a)  a.begin(),a.end()

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

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
const int N = 1e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;


int n,m,a,b,ANS = 0;
map<int,set<int> > g;
void solve(int test_case) {
    ANS = 0;g.clear();
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
 
    bool done = false;
    while(!done) {
        set<int> del;
        for (const auto& it : g) {
            if (it.second.size() == 1)
                del.insert(it.first);
        }
        for (const auto& it : del) {
            g.erase(it);
            for (const auto& it2 : g) {
                g[it2.first].erase(it);
            }
        }

//        for (auto it: g)
//            for (auto it2 : it.second)
//                cout << it.first << ' ' << it2 << endl;
//
//        cout << "------------" << endl;

        if (del.empty()) break;
        ANS++;
    }

    cout << ANS << endl;

}

int main() {
    _Depressed();
    ll tc;
    tc = 1;
//    cin >> tc;
    for (int test_case = 1; test_case <= tc; test_case++) {
        solve(test_case);
    }
}