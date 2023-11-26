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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<int> h(n, 0), w(n, 0);
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == 'o') {
      h.at(i)++;
      w.at(j)++;
    }
  }
  ll ans = 0;
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == 'o') {
      ll hc = h.at(i) - 1, wc = w.at(j) - 1;
      ans += hc * wc;
    }
  }
  cout << ans << endl;
  return 0;
}