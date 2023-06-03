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
  dsu uf(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    uf.merge(u, v);
  }
  auto grp = uf.groups();
  vector<int> uid(n, -1);
  rep(i, grp.size()) {
    for (auto now : grp.at(i)) {
      uid.at(now) = i;
    }
  }
  set<pair<int, int>> ban;
  int k;
  cin >> k;
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    a = uid.at(a);
    b = uid.at(b);
    if (a > b) swap(a, b);
    ban.insert({a, b});
  }

  int q;
  cin >> q;
  while (q--) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    p = uid.at(p);
    q = uid.at(q);
    if (p > q) swap(p, q);
    if (ban.find({p, q}) != ban.end()) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}