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

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  ll now = 0;
  set<pair<int, int>> l, r;
  vector<int> vv(n, 0);
  rep(i, n) {
    if (i < k)
      l.insert({0, i});
    else
      r.insert({0, i});
  }
  rep(_i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    if (k == n) {
      now -= vv.at(x);
      vv.at(x) = y;
      now += vv.at(x);
      cout << now << endl;
      continue;
    }
    auto itr = l.lower_bound({vv.at(x), x});
    if (itr != l.end() && *itr == make_pair(vv.at(x), x)) {
      now -= itr->first;
      l.erase(itr);
      auto ritr = r.end();
      ritr--;
      l.insert({ritr->first, ritr->second});
      now += ritr->first;
      r.erase(ritr);
    } else {
      r.erase({vv.at(x), x});
    }
    vv.at(x) = y;
    r.insert({vv.at(x), x});
    auto rend = r.end();
    rend--;
    if (l.begin()->first >= rend->first) {
      cout << now << endl;
      continue;
    }
    auto s = *rend;
    auto t = *l.begin();
    now -= t.first;
    now += s.first;
    l.erase(t);
    r.erase(s);
    l.insert(s);
    r.insert(t);
    cout << now << endl;
  }
  return 0;
}