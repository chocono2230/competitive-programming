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

vector<string> s;
int memo[51][51][51][51];

int fc(int il, int ir, int jl, int jr) {
  if (ir <= il) return 0;
  if (jr <= jl) return 0;
  if (memo[il][ir][jl][jr] != -1) return memo[il][ir][jl][jr];
  int res = max(ir - il, jr - jl);
  rep2(z, jl, jr) {
    bool f = false;
    rep2(k, il, ir) {
      if (s.at(k).at(z) == '#') {
        f = true;
        break;
      }
    }
    if (!f) res = min(res, fc(il, ir, jl, z) + fc(il, ir, z + 1, jr));
  }
  rep2(z, il, ir) {
    bool f = false;
    rep2(k, jl, jr) {
      if (s.at(z).at(k) == '#') {
        f = true;
        break;
      }
    }
    if (!f) res = min(res, fc(il, z, jl, jr) + fc(z + 1, ir, jl, jr));
  }
  memo[il][ir][jl][jr] = res;
  return res;
}

int main() {
  int n;
  cin >> n;
  s.resize(n);
  rep(i, n) cin >> s.at(i);
  rep(i, 51) rep(i2, 51) rep(i3, 51) rep(i4, 51) memo[i][i2][i3][i4] = -1;
  int ans = fc(0, n, 0, n);
  cout << ans << endl;
  return 0;
}