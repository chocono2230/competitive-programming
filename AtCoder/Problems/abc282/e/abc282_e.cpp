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
using mint = modint;

int main() {
  int n, m;
  cin >> n >> m;
  modint::set_mod(m);
  vector<mint> a(n);
  rep(i, n) {
    int in;
    cin >> in;
    a.at(i) = in;
  }
  dsu uf(n);
  vector v(n, vector<mint>(n, 0));
  priority_queue<tuple<int, int, int>> q;
  rep(i, n) rep2(j, i + 1, n) {
    mint x = a.at(i).pow(a.at(j).val()) + a.at(j).pow(a.at(i).val());
    q.push({x.val(), i, j});
  }
  ll ans = 0;
  while (!q.empty()) {
    auto [a, b, c] = q.top();
    q.pop();
    if (uf.same(b, c)) continue;
    ans += a;
    uf.merge(b, c);
  }
  cout << ans << endl;
  return 0;
}