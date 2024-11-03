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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, n) a.at(i) %= m;
  vector<ll> as(n + 1, 0);
  rep(i, n) {
    as.at(i + 1) = as.at(i) + a.at(i);
    as.at(i + 1) %= m;
  }
  ll ans = 0, sum = 0;
  fenwick_tree<int> fw(m);
  rep2(r, 1, n + 1) {
    ll add = as.at(r) * r;
    add -= sum;
    add += (ll)fw.sum(as.at(r) + 1, m) * m;
    fw.add(as.at(r), 1);
    sum += as.at(r);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}