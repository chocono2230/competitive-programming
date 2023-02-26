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
  vector tb(n, vector<int>(m, -1));
  vector gr(n, vector<int>());
  vector rgr(n, vector<int>());
  rep(i, n) {
    rep(j, m) {
      if (s.at(i).at(j) == '1') {
        gr.at(i).push_back(i + j + 1);
        rgr.at(i + j + 1).push_back(i);
      }
    }
  }
  const int INF = 1001001001;
  vector dd(n, INF);
  vector ff(n, false);
  ff.back() = true;
  dd.front() = 0;
  rep(i, n - 1) {
    rep(j, m) {
      if (s.at(i).at(j) == '0') continue;
      int ni = i + (j + 1);
      dd.at(ni) = min(dd.at(ni), dd.at(i) + 1);
    }
  }
  int mn = dd.back();
  vector<int> ans(n, -1);
  rrep2(i, 1, n - 1) {
    bool f = false;
    bool f2 = false;
    for (auto nx : gr.at(i)) {
      if (ff.at(nx) && dd.at(i) + 1 == dd.at(nx)) f2 = true;
      for (auto nxbk : rgr.at(nx)) {
        if (nxbk == i) continue;
        if (dd.at(nxbk) + 1 == dd.at(nx) && ff.at(nx)) f = true;
      }
    }
    if (f) {
      ans.at(i) = mn;
      if (f2) ff.at(i) = true;
    } else {
      bool z = false;
      bool k = false;
      for (auto nx : gr.at(i)) {
        if (!ff.at(nx)) continue;
        k = true;
        for (auto nxbk : rgr.at(nx)) {
          if (nxbk == i) continue;
          if (dd.at(nxbk) == dd.at(nx)) z = true;
        }
      }
      if (!k) {
        ans.at(i) = mn;
      } else {
        ff.at(i) = true;
        if (!z) {
          ans.at(i) = -1;
        } else {
          ans.at(i) = mn + 1;
        }
      }
    }
  }
  rep2(i, 1, n - 1) {
    if (i != 1) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  rep(i, n) { cerr << ff.at(i) << " "; }
  cerr << endl;

  return 0;
}