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
  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> w(m);
  rep(i, m) cin >> w.at(i);
  sort(ALL(b));
  sort(ALL(w));
  ll ans = 0;
  while (!w.empty()) {
    if (b.empty()) break;
    if (w.back() <= 0) break;
    int add = w.back() + b.back();
    if (add <= 0) break;
    ans += add;
    w.pop_back();
    b.pop_back();
  }
  rrep(i, b.size()) {
    if (b.at(i) <= 0) break;
    ans += b.at(i);
  }
  cout << ans << endl;
  return 0;
}