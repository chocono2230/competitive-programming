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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector dp(n + 1, vector<bool>(m, false));
  dp.at(0).at(m - 1) = true;
  rep(i, n - m + 1) {
    rep(j, m) {
      if (!dp.at(i).at(j)) continue;
      rep(d, j) {
        int co = d;
        rep2(k, d, m) {
          if (s.at(i + k) != t.at(k)) break;
          co++;
        }
        if (co == d) continue;
        co--;
        rep2(k, d, m) {
          // cerr << i << " " << j << " " << d << " " << k << endl;
          if (s.at(i + k) != t.at(k)) break;
          // cerr << i << " " << j << " " << d << " " << k << " " << co << endl;
          dp.at(i + k + 1).at(co) = true;
        }
      }
    }
  }
  cerr << endl;
  rep(i, n + 1) {
    cerr << i << " ";
    rep(j, m) cerr << dp.at(i).at(j) << " ";
    cerr << endl;
  }
  bool ans = dp.back().back();
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}