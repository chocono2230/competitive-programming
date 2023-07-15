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
  vector f(n, vector<bool>(m, false));
  vector<int> p(n);
  rep(i, n) {
    int ip, c;
    cin >> ip >> c;
    p.at(i) = ip;
    rep(j, c) {
      int in;
      cin >> in;
      in--;
      f.at(i).at(in) = true;
    }
  }
  rep(i, n) rep(j, n) {
    if (i == j) continue;
    if (p.at(i) < p.at(j)) continue;
    bool flg = false, flg2 = false;
    flg2 |= (p.at(i) > p.at(j));
    rep(k, m) {
      if (f.at(i).at(k)) {
        flg |= !f.at(j).at(k);
      } else {
        flg2 |= f.at(j).at(k);
      }
    }
    if (!flg && flg2) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}