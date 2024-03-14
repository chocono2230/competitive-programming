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
  int k;
  cin >> k;
  queue<ll> q;
  rep(i, 9) q.push(i + 1);
  while (!q.empty()) {
    ll now = q.front();
    q.pop();
    k--;
    if (k == 0) {
      cout << now << endl;
      return 0;
    }
    ll nx = now * 10;
    int sz = now % 10;
    rep(i, sz) { q.push(nx + i); }
  }
  return 0;
}