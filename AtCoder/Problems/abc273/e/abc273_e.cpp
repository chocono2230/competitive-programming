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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<pair<int, int>> qe;
  map<int, int> mp;
  rep(i, q) {
    string s;
    cin >> s;
    if (s == "DELETE") {
      qe.push_back({1, 0});
      continue;
    }
    int x;
    cin >> x;
    if (s == "ADD") qe.push_back({0, x});
    if (s == "SAVE") qe.push_back({2, x});
    if (s == "LOAD") qe.push_back({3, x});
    mp[x] = -1;
  }
  int sz = 0;
  for (auto &p : mp) {
    p.second = sz++;
  }
  for (auto &p : qe) {
    if (p.first >= 2) p.second = mp[p.second];
  }

  vector<pair<int, int>> lg(q + 1);
  vector<int> lz(q + 1, 0);
  lg.front() = {-1, 0};
  vector<int> pg(sz, 0);
  int now = -1, pr = 0, z = 0;
  rep(i, q) {
    auto [a, b] = qe.at(i);
    if (a == 0) {
      now = b;
      lg.at(i + 1) = {now, pr};
      pr = i + 1;
      z = i + 1;
      lz.at(i + 1) = z;
    } else if (a == 1) {
      auto pp = lg.at(pr);
      // cerr << now << " " << pr << endl;
      lg.at(i + 1) = pp;
      now = pp.first;
      pr = pp.second;
      z = i + 1;
      lz.at(i + 1) = z;
      // cerr << now << " " << pr << endl;
    } else {
      if (a == 2) {
        // cerr << b << " " << z << endl;
        pg.at(b) = z;
        lz.at(i + 1) = lz.at(z);
        // cerr << b << " " << z << endl;
        // cerr << i << " " << b << " " << pr << endl;
      } else {
        int p = pg.at(b);
        // cerr << i << " " << p << endl;
        now = lg.at(p).first;
        pr = lg.at(p).second;
        z = lz.at(p);
        lz.at(i + 1) = z;
        // cerr << i << " " << b << " " << p << " " << pr << " " << now << endl;
      }
    }
    if (i != 0) cout << " ";
    cout << now;
  }
  cout << endl;
  return 0;
}