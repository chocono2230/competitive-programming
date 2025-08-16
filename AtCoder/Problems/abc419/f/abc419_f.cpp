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
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector dp(l + 1, vector(1 << n, map<string, mint>()));
  dp.at(0).at(0)[""] = 1;
  rep(i, l) rep(bit, 1 << n) {
    for (auto &[p, q] : dp.at(i).at(bit)) {
      rep(idx, 26) {
        auto nxp = p;
        nxp.push_back('a' + idx);
        int nxbit = bit;
        bool nxf = false;
        rep(j, n) {
          if ((bit & (1 << j)) != 0) continue;
          bool chk = false;
          rep(k, s.at(j).size()) {
            if (k == nxp.size()) break;
            if (s.at(j).at(k) != nxp.at(k)) {
              chk = true;
              break;
            }
          }
          if (!chk) {
            if (s.at(j).size() == nxp.size())
              nxbit |= (1 << j);
            else
              nxf = true;
          }
        }
        if (!nxf) nxp = "";
        dp.at(i + 1).at(nxbit)[nxp] += q;
      }
    }
  }
  mint ans = 0;
  for (auto &p : dp.back().back()) {
    ans += p.second;
  }
  cout << ans.val() << endl;
  return 0;
}