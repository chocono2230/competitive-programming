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
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> cab(m);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    cab.at(i) = {a - b, a, b};
  }
  sort(ALL(cab));
  ll ans = 0;
  for (auto [c, a, b] : cab) {
    if (n < a) continue;
    ll d = (n - a) / c + 1;
    ans += d;
    n -= d * c;
  }
  cout << ans << endl;
  return 0;
}