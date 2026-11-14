#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  ll l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> sums(n + 1, 0);
  rep(i, n) sums.at(i + 1) = sums.at(i) + a.at(i);
  map<ll, int> mp;
  rep(i, n + 1) {
    mp[sums.at(i)] = -1;
    mp[sums.at(i) - r] = -1;
    mp[sums.at(i) - l] = -1;
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  fenwick_tree<ll> fw(sz);
  ll ans = 0;
  rep(i, n + 1) {
    int p = mp[sums.at(i) - l];
    int q = mp[sums.at(i) - r];
    ans += fw.sum(q, p + 1);
    fw.add(mp[sums.at(i)], 1);
  }
  cout << ans << endl;
  return 0;
}