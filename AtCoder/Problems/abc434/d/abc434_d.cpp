#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> udlr(n);
  rep(i, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    c--;
    udlr.at(i) = {a, b, c, d};
  }

  int sz = 2001;
  vector imos(sz, vector<int>(sz, 0));
  for (auto [u, d, l, r] : udlr) {
    imos.at(u).at(l)++;
    imos.at(u).at(r)--;
    imos.at(d).at(l)--;
    imos.at(d).at(r)++;
  }
  vector table(sz, vector<int>(sz, 0));
  rep(i, sz) rep(j, sz) {
    if (i != 0 && j != 0) table.at(i).at(j) -= table.at(i - 1).at(j - 1);
    table.at(i).at(j) += imos.at(i).at(j);
    if (i != sz - 1) table.at(i + 1).at(j) += table.at(i).at(j);
    if (j != sz - 1) table.at(i).at(j + 1) += table.at(i).at(j);
  }

  int bz = 0;
  rep(i, sz - 1) rep(j, sz - 1) if (table.at(i).at(j) == 0) bz++;

  vector bb(sz, vector<int>(sz, 0));
  rep(i, sz - 1) rep(j, sz - 1) {
    if (table.at(i).at(j) == 1) bb.at(i + 1).at(j + 1)++;
  }
  // rep(i, 10) {
  //   rep(j, 10) cerr << bb.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  rep(i, sz) rep(j, sz) {
    if (i != 0 && j != 0) bb.at(i).at(j) -= bb.at(i - 1).at(j - 1);
    if (i != sz - 1) bb.at(i + 1).at(j) += bb.at(i).at(j);
    if (j != sz - 1) bb.at(i).at(j + 1) += bb.at(i).at(j);
  }
  // cerr << "T" << bz << endl;
  // rep(i, 10) {
  //   rep(j, 10) cerr << bb.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  for (auto [u, d, l, r] : udlr) {
    // cerr << bb.at(d).at(r) << endl;
    int add = bb.at(d).at(r) - bb.at(d).at(l) - bb.at(u).at(r) + bb.at(u).at(l);
    // cerr << "X" << add << endl;
    cout << bz + add << endl;
  }
  return 0;
}