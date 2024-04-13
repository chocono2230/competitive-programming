#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ull = unsigned long long;
using namespace std;

int main() {
  ull l, r;
  cin >> l >> r;
  ull now = l;
  vector<pair<ull, ull>> ans;
  ull pnow = 0;
  // int dbg = 0;
  rrep(i, 62) {
    if ((r & (1ULL << i)) == 0) continue;
    ull base_nx = (pnow | (1ULL << i));
    while (now != base_nx) {
      // assert(dbg++ < 10);
      // cerr << now << " " << base_nx << endl;
      int p = 0;
      rep(j, i) {
        if ((now & (1ULL << j)) != 0) break;
        p++;
      }
      ull nx = now;
      nx += (1ULL << p);
      ans.push_back({now, nx});
      now = nx;
    }
    pnow = base_nx;
  }
  cout << ans.size() << endl;
  for (auto p : ans) cout << p.first << " " << p.second << endl;
  return 0;
}