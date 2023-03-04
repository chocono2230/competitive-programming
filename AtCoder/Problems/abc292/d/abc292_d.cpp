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
  vector<int> ed(n, 0);
  dsu uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ed.at(a)++;
    uf.merge(a, b);
  }
  bool ans = false;
  auto vv = uf.groups();
  for (auto &v : vv) {
    int co = 0;
    for (auto now : v) {
      co += ed.at(now);
    }
    if (co != v.size()) ans = true;
  }
  if (!ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}