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
  set<int> se;
  se.insert(n + 1);
  rep(i, m) {
    int in;
    cin >> in;
    se.insert(in);
  }
  int bf = 0, dd = n;
  for (auto now : se) {
    int d = now - bf;
    d--;
    bf = now;
    if (d != 0) dd = min(dd, d);
  }
  int ans = 0;
  bf = 0;
  for (auto now : se) {
    int d = now - bf;
    d--;
    bf = now;
    if (d != 0) ans += (d + dd - 1) / dd;
  }
  cout << ans << endl;
  return 0;
}