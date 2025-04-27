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
  int n, d;
  cin >> n >> d;
  vector<int> co(1000005, 0);
  rep(i, n) {
    int in;
    cin >> in;
    co.at(in)++;
  }
  int ans = 0;
  if (d == 0) {
    rep(i, co.size()) {
      if (co.at(i) != 0) ans += co.at(i) - 1;
    }
    cout << ans << endl;
    return 0;
  }
  rep(m, d) {
    vector<int> p;
    rep2(i, m, co.size()) {
      p.push_back(co.at(i));
      i += d - 1;
    }
    const int INF = 1001001001;
    vector dp(p.size() + 1, vector<int>(2, INF));
    dp.at(0).at(0) = 0;
    rep2(i, 1, dp.size()) {
      int pn = p.at(i - 1);
      if (pn == 0) {
        dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i - 1).at(0));
        dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i - 1).at(1));
      } else {
        dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i - 1).at(1) + pn);
        dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i - 1).at(0) + pn);
        dp.at(i).at(1) = min(dp.at(i).at(1), dp.at(i - 1).at(0));
      }
    }
    // rep(i, 5) { cerr << dp.at(i).front() << " " << dp.at(i).back() << endl; }
    // cerr << "------" << endl;
    ans += min(dp.back().front(), dp.back().back());
  }
  cout << ans << endl;
  return 0;
}