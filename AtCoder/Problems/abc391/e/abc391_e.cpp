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
  int sz = 1;
  rep(i, n) sz *= 3;
  vector vv(n + 1, vector<int>());
  string s;
  cin >> s;
  rep(i, sz) { vv.at(0).push_back(s.at(i) - '0'); }
  rep2(i, 1, n + 1) {
    rep(j, vv.at(i - 1).size() / 3) {
      int ss = 0;
      rep2(k, j * 3, (j + 1) * 3) ss += vv.at(i - 1).at(k);
      vv.at(i).push_back(ss / 2);
    }
  }

  auto dp = vv;
  const int INF = 1001001001;
  rep(i, sz) dp.at(0).at(i) = 1;
  rep2(i, 1, n + 1) {
    rep(j, vv.at(i - 1).size() / 3) {
      dp.at(i).at(j) = INF;
      rep(bit, 1 << 3) {
        int cost = 0;
        int p = popcount((unsigned int)bit) / 2;
        if (p == vv.at(i).at(j)) continue;
        rep(k, 3) {
          if ((bit & (1 << k)) == 0) {
            if (vv.at(i - 1).at(j * 3 + k) != 0)
              cost += dp.at(i - 1).at(j * 3 + k);
          } else {
            if (vv.at(i - 1).at(j * 3 + k) == 0)
              cost += dp.at(i - 1).at(j * 3 + k);
          }
        }
        dp.at(i).at(j) = min(dp.at(i).at(j), cost);
      }
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}