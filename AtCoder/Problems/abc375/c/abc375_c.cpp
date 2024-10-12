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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<string> ans(n, string(n, '.'));
  vector chk(n, vector<bool>(n, false));
  int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};
  int pdi[] = {0, 1, 0, -1}, pdj[] = {1, 0, -1, 0};
  rep(i, n / 2) {
    int idx = i % 4;
    int pidx = 0;
    int mx = n - i - 1;
    int si = 0, sj = 0;
    if (idx == 0) si = mx, sj = i;
    if (idx == 1) si = mx, sj = mx;
    if (idx == 2) si = i, sj = mx;
    if (idx == 3) si = i, sj = i;
    int pi = i, pj = i;
    int co = 0;
    while (1) {
      // cerr << i << " " << si << " " << sj << "|"
      //      << " " << pi << " " << pj << endl;

      // for (auto s : ans) cout << s << endl;
      ans.at(pi).at(pj) = s.at(si).at(sj);
      chk.at(si).at(sj) = true;
      int nxi = si + di[idx], nxj = sj + dj[idx];
      if (nxi < 0 || n <= nxi || nxj < 0 || n <= nxj || chk.at(nxi).at(nxj)) {
        idx = (idx + 3) % 4;
        pidx = (pidx + 1) % 4;
        co++;
        if (co == 4) break;
        nxi = si + di[idx], nxj = sj + dj[idx];
        if (nxi < 0 || n <= nxi || nxj < 0 || n <= nxj || chk.at(nxi).at(nxj))
          break;
      }
      pi = pi + pdi[pidx], pj = pj + pdj[pidx];
      si = nxi, sj = nxj;
    }
  }
  for (auto s : ans) cout << s << endl;
  return 0;
}