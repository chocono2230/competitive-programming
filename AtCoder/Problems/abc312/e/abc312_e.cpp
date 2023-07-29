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
  vector xv(105, vector(105, vector<int>(105, -1)));
  vector yv(105, vector(105, vector<int>(105, -1)));
  vector zv(105, vector(105, vector<int>(105, -1)));
  vector xv1(105, vector(105, vector<int>(105, -1)));
  vector yv1(105, vector(105, vector<int>(105, -1)));
  vector zv1(105, vector(105, vector<int>(105, -1)));
  vector<set<int>> ans(n);
  vector<tuple<int, int, int, int, int, int>> aa(n);
  rep(i, n) {
    int x, y, z;
    cin >> x >> y >> z;
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    aa.at(i) = {x, y, z, x1, y1, z1};
    rep2(q, y, y1) rep2(r, z, z1) { xv.at(x).at(q).at(r) = i; }
    rep2(p, x, x1) rep2(r, z, z1) { yv.at(y).at(p).at(r) = i; }
    rep2(p, x, x1) rep2(q, y, y1) { zv.at(z).at(p).at(q) = i; }
  }
  rep(i, n) {
    auto [x, y, z, x1, y1, z1] = aa.at(i);
    rep2(q, y, y1) rep2(r, z, z1) {
      if (xv.at(x1).at(q).at(r) != -1) {
        ans.at(i).insert(xv.at(x1).at(q).at(r));
        ans.at(xv.at(x1).at(q).at(r)).insert(i);
      }
    }
    rep2(p, x, x1) rep2(r, z, z1) {
      if (yv.at(y1).at(p).at(r) != -1) {
        ans.at(i).insert(yv.at(y1).at(p).at(r));
        ans.at(yv.at(y1).at(p).at(r)).insert(i);
      }
    }
    rep2(p, x, x1) rep2(q, y, y1) {
      if (zv.at(z1).at(p).at(q) != -1) {
        ans.at(i).insert(zv.at(z1).at(p).at(q));
        ans.at(zv.at(z1).at(p).at(q)).insert(i);
      }
    }
  }
  for (auto &ss : ans) cout << ss.size() << endl;
  return 0;
}