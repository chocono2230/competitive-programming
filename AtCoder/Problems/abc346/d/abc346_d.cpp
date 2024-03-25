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
  string s;
  cin >> s;
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  vector sum(2, vector<ll>(n + 1, 0));
  rep(i, n) {
    char now = (i % 2) + '0';
    rep(j, 2) sum.at(j).at(i + 1) = sum.at(j).at(i);
    int idx = (s.at(i) != now ? 0 : 1);
    sum.at(idx).at(i + 1) += c.at(i);
  }
  const ll INF = 1e18;
  ll ans = INF;
  rep(i, n - 1) {
    auto fc = [&](int ta) {
      ll res = 0;
      char tc = ta + '0';
      if (s.at(i) != tc) res += c.at(i);
      if (s.at(i + 1) != tc) res += c.at(i + 1);
      int lidx = ((ta == 0) ^ (i % 2 == 1) ? 0 : 1);
      res += sum.at(lidx).at(i);
      int ridx = ((ta == 0) ^ (i % 2 == 0) ? 0 : 1);
      res += sum.at(ridx).back() - sum.at(ridx).at(i + 2);
      return res;
    };
    // cerr << i << " " << fc(0) << " " << fc(1) << endl;
    ll add = min(fc(0), fc(1));
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}