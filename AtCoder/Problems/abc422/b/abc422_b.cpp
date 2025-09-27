#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '.') continue;
    int co = 0;
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '#') co++;
    }
    if (co != 2 && co != 4) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}