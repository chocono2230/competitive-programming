#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  fenwick_tree<int> fw(m);
  vector events(m + 1, vector<int>());
  ll now = 0;
  rep(i, n) {
    events.at(m - a.at(i)).push_back(i);
    now += fw.sum(a.at(i) + 1, m);
    fw.add(a.at(i), 1);
  }
  rep(i, m) {
    cout << now << endl;
    for (auto p : events.at(i + 1)) {
      int pl = p;
      int ml = n - pl - 1;
      now += (pl - ml);
    }
  }
  return 0;
}