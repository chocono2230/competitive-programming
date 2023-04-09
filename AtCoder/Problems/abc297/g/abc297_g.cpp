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
  int n, l, r;
  cin >> n >> l >> r;
  int s = l + r;
  ll now = 0;
  rep(i, n) {
    ll in;
    cin >> in;
    in %= s;
    if (in < l) continue;
    ll add = in - l + 1;
    add = (add + l - 1) / l;
    now ^= add;
  }
  if (now != 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}