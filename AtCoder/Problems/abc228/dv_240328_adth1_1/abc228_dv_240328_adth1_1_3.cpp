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
  int q;
  cin >> q;
  int n = 1 << 20;
  vector<int> edge(n, -1);
  rep(i, n) { edge.at(i) = (i + 1) % n; }
  vector<ll> now(n, -1);
  while (q--) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 1) {
      int ps = x % n;
      int pos = ps;
      while (now.at(pos) != -1) {
        pos = edge.at(pos);
      }
      now.at(pos) = x;
      if (ps != pos) edge.at(ps) = pos;
    } else {
      x %= n;
      cout << now.at(x) << endl;
    }
  }
  return 0;
}