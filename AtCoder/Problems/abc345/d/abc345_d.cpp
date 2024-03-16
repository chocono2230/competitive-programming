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
  int n, h, w;
  cin >> n >> h >> w;
  vector<pair<int, int>> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
  int mx = 1;
  rep(i, n) mx *= 3;
  vector<pair<int, int>> rk;
  vector chk(h, vector<bool>(w, false));
  rep2(bit, 1, mx) {
    vector<pair<int, int>> v;
    int p = bit;
    rep(i, n) {
      if (p % 3 == 2) v.push_back(ab.at(i));
      if (p % 3 == 1) v.push_back({ab.at(i).second, ab.at(i).first});
      p /= 3;
    }
    // for (auto [a, b] : v) cerr << a << ":" << b << " ";
    // cerr << endl;
    vector<int> pv(v.size());
    rep(i, pv.size()) pv.at(i) = i;
    do {
      bool ng = false;
      int idx = 0;
      rk.clear();
      int co = 0;
      rep(i, h) rep(j, w) {
        if (chk.at(i).at(j)) continue;
        if (idx == pv.size()) {
          ng = true;
          goto SKIP;
        }
        auto [a, b] = v.at(pv.at(idx++));
        if (i + a > h || j + b > w) {
          ng = true;
          goto SKIP;
        }
        rep2(ii, i, i + a) rep2(jj, j, j + b) {
          rk.push_back({ii, jj});
          chk.at(ii).at(jj) = true;
          co++;
        }
      }
      if (co != h * w) ng = true;
    SKIP:
      if (!ng) {
        cout << "Yes" << endl;
        return 0;
      }
      for (auto [i, j] : rk) {
        chk.at(i).at(j) = false;
      }
    } while (next_permutation(ALL(pv)));
  }
  cout << "No" << endl;
  return 0;
}