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
  ll n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  vector<int> co(n, 0);
  if (m != 1) co = vector<int>(n * 2, 0);
  rep(i, co.size()) {
    if (i != 0) co.at(i) = co.at(i - 1);
    if (s.at(i % n) == 'x') co.at(i)++;
  }
  int xco = co.at(n - 1);
  // for (auto i : co) cerr << i << " ";
  // cerr << endl;
  // cerr << xco << endl;

  ll ans = 0;
  rep(i, n) {
    int ok = i - 1, ng = co.size();
    ll p = xco * m - (i == 0 ? 0 : co.at(i - 1));
    if (p <= k) {
      ll add = n * m - i;
      ans = max(ans, add);
      continue;
    }
    ll z = k % xco;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      if (co.at(mid) - (i == 0 ? 0 : co.at(i - 1)) <= z)
        ok = mid;
      else
        ng = mid;
    }
    ll add = k / xco * n;
    add += ng - i;
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}