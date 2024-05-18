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
  vector<pair<int, int>> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
  vector chk(n, vector<bool>(n, false));
  rep(i, n) rep(j, n) {
    if (i == j) continue;
    if (ab.at(i).first == ab.at(j).first ||
        ab.at(i).second == ab.at(j).second) {
      chk.at(i).at(j) = true;
    }
  }
  vector<int> memo(1 << 19, -1);
  auto rc = [&](const auto &self, int now) -> bool {
    if (memo.at(now) != -1) {
      if (memo.at(now) == 0) return false;
      return true;
    }
    bool res = false;
    rep(i, n) rep2(j, i + 1, n) {
      if (((now & (1 << i)) != 0) && ((now & (1 << j)) != 0) &&
          chk.at(i).at(j)) {
        int nxbit = now;
        nxbit ^= (1 << i);
        nxbit ^= (1 << j);
        auto r = self(self, nxbit);
        if (!r) {
          res = true;
          goto L;
        }
      }
    }
  L:
    if (res)
      memo.at(now) = 1;
    else
      memo.at(now) = 0;
    return res;
  };
  int st = (1 << n) - 1;
  auto r = rc(rc, st);
  if (r)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}