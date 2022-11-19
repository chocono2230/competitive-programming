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
  int h, w, n;
  cin >> h >> w >> n;
  int hd, wd;
  cin >> hd >> wd;
  vector table(n, vector<int>(4, -1));
  rep(i, h) rep(j, w) {
    int in;
    cin >> in;
    in--;
    if (table.at(in).front() == -1) {
      table.at(in).at(0) = table.at(in).at(1) = i;
      table.at(in).at(2) = table.at(in).at(3) = j;
    } else {
      if (table.at(in).at(0) > i) table.at(in).at(0) = i;
      if (table.at(in).at(1) < i) table.at(in).at(1) = i;
      if (table.at(in).at(2) > j) table.at(in).at(2) = j;
      if (table.at(in).at(3) < j) table.at(in).at(3) = j;
    }
  }
  vector ans(h - hd + 1, vector<int>(w - wd + 1, 0));
  for (auto &tt : table) {
    int l = tt.at(0), r = tt.at(1), b = tt.at(2), t = tt.at(3);
    // cerr << "PP " << l << " " << r << " " << b << " " << t << endl;
    if (l == -1) continue;
    rep(i, h - hd + 1) rep(j, w - wd + 1) {
      int ld = i, rd = i + hd, bd = j, td = j + wd;
      // cerr << ld << " " << rd << " " << bd << " " << td << " "
      //      << (l < ld || rd <= r || b < bd || td <= t) << endl;
      if (l < ld || rd <= r || b < bd || td <= t) ans.at(i).at(j)++;
    }
  }
  rep(i, ans.size()) {
    rep(j, ans.at(i).size()) {
      if (j != 0) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}