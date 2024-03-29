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
  dsu uf(200005);
  rep(i, n) {
    int j = n - i - 1;
    if (j <= i) break;
    if (a.at(i) == a.at(j)) continue;
    uf.merge(a.at(i), a.at(j));
  }
  int ans = 0;
  auto grp = uf.groups();
  for (auto &v : grp) {
    ans += v.size() - 1;
  }
  cout << ans << endl;
  return 0;
}