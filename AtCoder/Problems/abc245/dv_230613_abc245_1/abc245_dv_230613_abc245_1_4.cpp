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
  vector<ll> a(n + 1);
  rep(i, n + 1) cin >> a.at(i);
  vector<ll> c(n + m + 1);
  rep(i, n + m + 1) cin >> c.at(i);
  vector<ll> b(m + 1, 0);
  rrep(i, m + 1) {
    b.at(i) = c.at(i + n) / a.at(n);
    rep(j, n + 1) {
      int k = i + j;
      c.at(k) -= b.at(i) * a.at(j);
    }
  }
  rep(i, m + 1) {
    if (i != 0) cout << " ";
    cout << b.at(i);
  }
  cout << endl;
  return 0;
}