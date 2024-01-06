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
  vector ans(n, vector<int>(n, -1));
  int i = 0, j = 0;
  int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
  int idx = 0;
  rep(p, n * n - 1) {
    ans.at(i).at(j) = p;
    auto fc = [&]() -> pair<int, int> {
      int ni = i + di[idx % 4];
      int nj = j + dj[idx % 4];
      if (nj < 0 || n <= nj || ni < 0 || n <= ni) return {-1, -1};
      if (ans.at(ni).at(nj) != -1) return {-1, -1};
      return {ni, nj};
    };
    auto [ni, nj] = fc();
    if (ni == -1) {
      idx++;
      auto [r1, r2] = fc();
      ni = r1, nj = r2;
    }
    i = ni, j = nj;
  }
  rep(i, n) {
    rep(j, n) {
      if (ans.at(i).at(j) == -1)
        cout << "T";
      else
        cout << ans.at(i).at(j) + 1;
      cout << (j == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}