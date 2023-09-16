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
  int m;
  cin >> m;
  vector<string> s(3);
  rep(i, 3) cin >> s.at(i);
  const int INF = 1001001001;
  auto fc = [&](char x) -> int {
    rep(i, 3) {
      bool chk = false;
      rep(j, m) {
        if (s.at(i).at(j) == x) {
          chk = true;
          break;
        }
      }
      if (!chk) return INF;
    }
    vector<int> p(3);
    rep(i, 3) p.at(i) = i;
    int res = 1001001001;
    do {
      int idx = 0;
      int i = 0;
      while (1) {
        if (s.at(p.at(idx)).at(i % m) == x) {
          idx++;
        }
        if (idx == 3) {
          res = min(res, i);
          break;
        }
        i++;
      }
    } while (next_permutation(ALL(p)));
    return res;
  };
  int ans = INF;
  rep(i, 10) ans = min(ans, fc(i + '0'));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}