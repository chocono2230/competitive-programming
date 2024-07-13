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
  vector<tuple<int, int, int>> a, b, c;
  ll amx = 0, amn = 0, bmx = 0, bmn = 0, camx = 0, cbmx = 0;
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    if (0 <= l) {
      a.push_back({l, r, i});
      amx += r;
      amn += l;
    } else if (r <= 0) {
      b.push_back({r, l, i});
      bmx += -l;
      bmn += -r;
    } else {
      c.push_back({l, r, i});
      camx += r;
      cbmx += -l;
    }
  }
  if (amn > bmx + cbmx || bmn > amx + camx) {
    cout << "No" << endl;
    return 0;
  }
  bool f = (amn < bmn);
  vector<int> ans(n);
  ll now = 0;
  auto &v = a;
  if (f) v = b;
  for (auto [mn, mx, i] : v) {
    now += mn;
    ans.at(i) = mn;
  }
  v = b;
  if (f) v = a;
  for (auto [mn, mx, i] : v) {
    ll d = abs(now) - abs(mx);
    if (d > 0) {
      ans.at(i) = mx;
      now += mx;
    } else {
      ans.at(i) = -now;
      now = 0;
    }
  }
  for (auto [mn, mx, i] : c) {
    if (now < 0) {
      ll nxnow = now + mx;
      if (nxnow > 0) {
        mx = -now;
      }
      ans.at(i) = mx;
      now += mx;
    } else {
      ll nxnow = now + mn;
      if (nxnow < 0) {
        mn = -now;
      }
      ans.at(i) = mn;
      now += mn;
    }
  }
  cout << "Yes" << endl;
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}