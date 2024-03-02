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
  vector<int> deg(n, 0);
  dsu uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    deg.at(a)++;
    deg.at(b)++;
    uf.merge(a, b);
    if (deg.at(a) == 3 || deg.at(b) == 3) {
      cout << "No" << endl;
      return 0;
    }
  }
  auto grp = uf.groups();
  for (auto &v : grp) {
    if (v.size() == 1) continue;
    bool f = false;
    for (auto now : v) {
      if (deg.at(now) == 1) f = true;
    }
    if (!f) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}