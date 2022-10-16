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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  rep(i, n) {
    int in;
    cin >> in;
    in--;
    uf.merge(i, in);
  }
  auto gp = uf.groups();
  mint ans = mint(m).pow(n) - mint(m).pow(gp.size());
  ans /= 2;
  cout << ans.val() << endl;
  return 0;
}