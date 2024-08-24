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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  fenwick_tree<ll> fw(n);
  rep(i, n) fw.add(i, a.at(i));
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  set<int> se;
  rep(i, n) {
    if (b.at(i) == 1) continue;
    se.insert(i);
  }
  se.insert(n);
  int q;
  cin >> q;

  while (q--) {
    int m, p, q;
    cin >> m >> p >> q;
    if (m == 1) {
      p--;
      fw.add(p, -a.at(p));
      a.at(p) = q;
      fw.add(p, a.at(p));
      continue;
    }
    if (m == 2) {
      p--;
      if (b.at(p) != 1) {
        se.erase(p);
      }
      b.at(p) = q;
      if (b.at(p) != 1) {
        se.insert(p);
      }
      continue;
    }
    p--;
    int pos = p;
    int end = q;
    ll now = a.at(pos);
    while (1) {
      auto itr = se.upper_bound(pos);
      int r = end;
      if (itr != se.end() && *itr < end) r = *itr;
      now += fw.sum(pos + 1, r);
      if (r == end) break;
      now = max(now + a.at(r), now * b.at(r));
      pos = r;
    }
    cout << now << endl;
  }
  return 0;
}