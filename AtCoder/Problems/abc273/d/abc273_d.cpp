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
  int h, w;
  cin >> h >> w;
  int r, c;
  cin >> r >> c;
  r--;
  c--;
  set<pair<int, int>> ise, jse;
  ise.insert({h, 0});
  jse.insert({w, 0});
  ise.insert({-1, 0});
  jse.insert({-1, 0});
  int n;
  cin >> n;
  rep(_i, n) {
    int i, j;
    cin >> i >> j;
    i--;
    j--;
    ise.insert({i, j});
    jse.insert({j, i});
  }
  int q;
  cin >> q;
  while (q--) {
    char d;
    int l;
    cin >> d >> l;
    int di = 0, dj = 0;
    if (d == 'L') dj--;
    if (d == 'R') dj++;
    if (d == 'U') di--;
    if (d == 'D') di++;
    int nxr = r, nxc = c;
    auto fc = [](set<pair<int, int>> &jse, int di, int &nxr, int nxc, int l,
                 int h, int c, int r) -> void {
      auto itr = jse.lower_bound({c, r});
      if (di == 1) {
        nxr += l;
        if (itr->first == nxc) nxr = min(nxr, itr->second - 1);
        nxr = min(nxr, h - 1);
      } else {
        nxr -= l;
        // cerr << "SS" << nxr << " " << itr->first << " " << itr->second <<
        // endl;
        itr--;
        // cerr << "SS" << nxr << " " << itr->first << " " << itr->second <<
        // endl;
        if (itr->first == nxc) nxr = max(nxr, itr->second + 1);
        nxr = max(nxr, 0);
        // cerr << "SS" << nxr << endl;
      }
    };
    if (dj == 0) {
      fc(jse, di, nxr, nxc, l, h, c, r);
    } else {
      fc(ise, dj, nxc, nxr, l, w, r, c);
    }
    r = nxr;
    c = nxc;
    cout << r + 1 << " " << c + 1 << endl;
  }
  return 0;
}