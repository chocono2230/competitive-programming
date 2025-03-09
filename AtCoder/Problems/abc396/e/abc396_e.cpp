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
  vector<int> x, y, z;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    x.push_back(a);
    y.push_back(b);
    z.push_back(c);
  }

  vector<int> ans(n, 0);
  rep(bit, 30) {
    vector<bool> chk(n, false);
    vector<bool> flg(n, false);
    dsu uf(n);
    rep(i, m) {
      int xx = x.at(i);
      int yy = y.at(i);
      bool zz = ((z.at(i) & (1 << bit)) != 0);
      if (chk.at(xx) && chk.at(yy)) {
        if ((flg.at(xx) ^ flg.at(yy)) != zz) {
          cout << -1 << endl;
          return 0;
        }
        continue;
      }
      if (!chk.at(xx) && !chk.at(yy)) {
        flg.at(xx) = zz;
      } else {
        if (chk.at(xx)) {
          flg.at(yy) = (zz ^ flg.at(xx));
        } else {
          flg.at(xx) = (zz ^ flg.at(yy));
        }
      }
      chk.at(xx) = true;
      chk.at(yy) = true;
      uf.merge(xx, yy);
    }
    auto grp = uf.groups();
    for (auto &v : grp) {
      int ss = 0;
      for (auto now : v) {
        if (!chk.at(now)) break;
        if (flg.at(now)) ss++;
      }
      int add = min(ss, (int)v.size() - ss);
      for (auto now : v) {
        if (!chk.at(now)) break;
        if (flg.at(now) ^ (add != ss)) {
          ans.at(now) |= (1 << bit);
        }
      }
    }
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}