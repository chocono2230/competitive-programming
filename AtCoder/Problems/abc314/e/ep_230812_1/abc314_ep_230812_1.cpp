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

int n, m;
vector<int> c;
vector<int> zs;
vector s(0, vector<int>());

double rc(int lv) {
  static vector<double> memo(105, 0);
  static vector<bool> flg(105, false);
  if (lv <= 0) return 0;
  if (flg.at(lv)) return memo.at(lv);
  double mn = 4e18;
  rep(i, n) {
    double add = c.at(i);
    int co = zs.at(i);
    int sz = s.at(i).size();
    double nzsum = 0;
    rep2(j, co, sz) { nzsum += rc(lv - s.at(i).at(j)); }
    if (co == 0) {
      add += nzsum / sz;
    } else {
      add *= (double)sz / (sz - co);
      add += nzsum / (sz - co);
    }
    mn = min(mn, add);
  }
  flg.at(lv) = true;
  return memo.at(lv) = mn;
}

int main() {
  cin >> n >> m;
  c.resize(n);
  s.resize(n);
  zs.resize(n);
  rep(i, n) {
    cin >> c.at(i);
    int p;
    cin >> p;
    rep(j, p) {
      int in;
      cin >> in;
      s.at(i).push_back(in);
    }
    sort(ALL(s.at(i)));
    int z = 0;
    rep(j, p) {
      if (s.at(i).at(j) != 0) break;
      z++;
    }
    zs.at(i) = z;
  }
  double ans = rc(m);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}