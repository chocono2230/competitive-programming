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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  auto fc = [&](int i, int j, int di, int dj) {
    int co = 0;
    rep(_i, 6) {
      if (i < 0 || n <= i || j < 0 || n <= j) return false;
      if (s.at(i).at(j) == '#') co++;
      i += di;
      j += dj;
    }
    return co >= 4;
  };
  bool ans = false;
  int di[] = {1, 0, 1, -1}, dj[] = {0, 1, 1, 1};
  rep(i, n) rep(j, n) rep(k, 4) { ans |= fc(i, j, di[k], dj[k]); }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}