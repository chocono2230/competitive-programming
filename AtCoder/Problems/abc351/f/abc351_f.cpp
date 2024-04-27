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
  int n;
  cin >> n;
  vector<pair<int, int>> ai(n);
  rep(i, n) {
    int in;
    cin >> in;
    ai.at(i) = {in, i};
  }
  sort(ALL(ai));
  fenwick_tree<ll> fw(n), co(n);
  ll ans = 0;
  for (auto [a, i] : ai) {
    ll c = co.sum(0, i);
    ans += a * c - fw.sum(0, i);
    fw.add(i, a);
    co.add(i, 1);
  }
  cout << ans << endl;
  return 0;
}