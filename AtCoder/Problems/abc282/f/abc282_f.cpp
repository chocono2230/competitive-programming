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
  // ll ans = 0;
  // int n = 4000;
  // rep(i, n) {
  //   int now = i;
  //   int add = 1;
  //   while (1) {
  //     if (now >= n) break;
  //     now = i + add;
  //     add <<= 1;
  //     ans++;
  //   }
  // }
  // cout << ans << endl;
  int n;
  cin >> n;
  vector gr(n, vector<bool>(n, false));
  vector numgr(n, vector<int>(n, -1));
  vector<pair<int, int>> oo;
  rep(i, n) {
    int add = 0;
    while (1) {
      int now = i + add;
      if (now >= n) break;
      gr.at(i).at(now) = true;
      numgr.at(i).at(now) = oo.size();
      if (add == 0)
        add = 1;
      else
        add = (add << 1);
      oo.push_back({i, now});
    }
  }
  cout << oo.size() << endl;
  for (auto [a, b] : oo) {
    cout << a + 1 << " " << b + 1 << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int add = 0;
    int st = -1;
    while (1) {
      int now = l + add;
      if (now > r) break;
      st = now;
      if (add == 0)
        add = 1;
      else
        add <<= 1;
    }
    assert(st != -1);
    int rr = -1;
    rrep(i, st + 1) {
      if (gr.at(i).at(r)) {
        rr = i;
        break;
      }
    }
    // cerr << l + 1 << " " << st + 1 << " " << rr + 1 << " " << r + 1 << endl;
    assert(l <= rr);
    int p = numgr.at(l).at(st) + 1, q = numgr.at(rr).at(r) + 1;
    cout << p << " " << q << endl;
  }
  return 0;
}