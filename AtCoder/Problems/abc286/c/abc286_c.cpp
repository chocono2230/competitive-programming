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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  const ll INF = 1e18;
  ll ans = INF;
  rep(i, n) {
    ll add = (ll)a * i;
    string t = s.substr(i) + s.substr(0, i);
    rep(i, t.size() / 2) {
      if (t.at(i) != t.at(n - i - 1)) add += b;
    }
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}