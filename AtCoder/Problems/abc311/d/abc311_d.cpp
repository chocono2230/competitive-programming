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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector tc(n, vector<bool>(m, false));
  vector tb(n, vector<bool>(m, false));
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  queue<pair<int, int>> q;
  q.push({1, 1});
  tc.at(1).at(1) = tb.at(1).at(1) = true;
  while (!q.empty()) {
    auto [i, j] = q.front();
    // cerr << i << " " << j << endl;
    q.pop();
    rep(k, 4) {
      int pi = i, pj = j;
      while (1) {
        int ni = pi + di[k], nj = pj + dj[k];
        if (s.at(ni).at(nj) == '#') {
          if (!tb.at(pi).at(pj)) {
            tb.at(pi).at(pj) = true;
            q.push({pi, pj});
          }
          break;
        }
        tc.at(ni).at(nj) = true;
        pi = ni;
        pj = nj;
      }
    }
  }
  int ans = 0;
  rep(i, n) rep(j, m) if (tc.at(i).at(j)) ans++;
  cout << ans << endl;
  return 0;
}