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
  char p, q;
  cin >> p >> q;
  p -= 'A';
  q -= 'A';
  if (p > q) swap(p, q);
  vector<int> v = {3, 1, 4, 1, 5, 9};
  int ans = 0;
  rep2(i, p, q) { ans += v.at(i); }
  cout << ans << endl;
  return 0;
}