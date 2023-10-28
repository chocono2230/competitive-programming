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
  int n;
  cin >> n;
  string r, c;
  cin >> r >> c;

  vector<int> v(n, 0), v2(n, 0);
  vector<string> ans(n, string(n, '.'));
  auto rc = [&](const auto &self, int lv) -> bool {
    if (lv == n) {
      rep(i, n) {
        bool chk = false;
        rep(j, n) {
          if (ans.at(i).at(j) != '.') {
            chk = (ans.at(i).at(j) == r.at(i));
            break;
          }
        }
        if (!chk) return false;
      }
      rep(j, n) {
        bool chk = false;
        rep(i, n) {
          if (ans.at(i).at(j) != '.') {
            chk = (ans.at(i).at(j) == c.at(j));
            break;
          }
        }
        if (!chk) return false;
      }
      vector h(n, vector<int>(3, 0));
      vector w(n, vector<int>(3, 0));
      rep(i, n) rep(j, n) {
        if (ans.at(i).at(j) == '.') continue;
        h.at(i).at(ans.at(i).at(j) - 'A') = 1;
        w.at(j).at(ans.at(i).at(j) - 'A') = 1;
      }
      rep(i, n) {
        if (reduce(ALL(h.at(i))) != 3) return false;
        if (reduce(ALL(w.at(i))) != 3) return false;
      }
      return true;
    }
    rep(i, n) rep2(j, i + 1, n) rep2(k, j + 1, n) {
      vector<int> p(3);
      rep(z, 3) p.at(z) = z;
      do {
        if (p.at(0) + 'A' != r.at(lv)) continue;
        ans.at(lv).at(i) = 'A' + p.at(0);
        ans.at(lv).at(j) = 'A' + p.at(1);
        ans.at(lv).at(k) = 'A' + p.at(2);
        auto r = self(self, lv + 1);
        if (r) return true;
        ans.at(lv).at(i) = '.';
        ans.at(lv).at(j) = '.';
        ans.at(lv).at(k) = '.';
      } while (next_permutation(ALL(p)));
    }
    return false;
  };
  auto p = rc(rc, 0);
  if (p) {
    cout << "Yes" << endl;
    rep(i, n) cout << ans.at(i) << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}