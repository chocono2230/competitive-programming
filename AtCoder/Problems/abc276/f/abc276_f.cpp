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
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  rep(i, n) {
    cin >> a.at(i).first;
    a.at(i).second = i;
  }
  auto b = a;
  sort(ALL(b));
  vector<int> idx(n);
  rep(i, n) { idx.at(b.at(i).second) = i; }

  fenwick_tree<mint> co(n), sum(n);
  mint tot = 0, ss = 0;
  rep(i, n) {
    auto now = a.at(i);
    int tidx = idx.at(now.second);
    tot += (i + 1) * 2 - 1;
    ss += sum.sum(tidx, n) * 2;
    ss += co.sum(0, tidx) * now.first * 2 + now.first;
    mint out = ss / tot;
    cout << out.val() << endl;
    sum.add(tidx, now.first);
    co.add(tidx, 1);
  }
  return 0;
}