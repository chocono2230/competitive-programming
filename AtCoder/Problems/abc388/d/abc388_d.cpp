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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> imos(n, 0);
  ll now = 0;
  rep(i, n) {
    now += imos.at(i);
    a.at(i) += now;
    if (i == n - 1) break;
    ll d = min(a.at(i), (ll)n - i - 1);
    a.at(i) -= d;
    if (d > 0) {
      imos.at(i + 1)++;
      if (d != n - i - 1 && i + d + 1 < n) {
        imos.at(i + d + 1)--;
      }
    }
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
  return 0;
}