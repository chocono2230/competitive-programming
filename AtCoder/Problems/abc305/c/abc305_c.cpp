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
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  rep(i, h) s.at(i) = "." + s.at(i) + ".";
  s.insert(s.begin(), string(w + 2, '.'));
  s.push_back(string(w + 2, '.'));
  h += 2;
  w += 2;
  int ddi[] = {1, 0, -1, 0}, ddj[] = {0, 1, 0, -1};
  rep2(i, 1, h - 1) rep2(j, 1, w - 1) {
    if (s.at(i).at(j) == '#') continue;
    int f2 = 0;
    rep(k, 4) {
      int ni = i + ddi[k], nj = j + ddj[k];
      if (s.at(ni).at(nj) == '#') f2++;
    }
    if (f2 > 1) {
      cout << i << " " << j << endl;
      return 0;
    }
  }
  return 0;
}