#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int sz = 1;
  rep(i, n) sz *= 2;
  vector<int> ans(sz, k / sz);
  int md = k % sz;
  bool f = false;
  auto rc = [&](const auto &self, int l, int r, int m) -> void {
    if (l + 1 == r) {
      if (m == 1) ans.at(l)++;
      return;
    }
    if (m % 2 != 0) f = true;
    int mid = (r + l) / 2;
    self(self, l, mid, m / 2);
    self(self, mid, r, (m + 1) / 2);
  };
  rc(rc, 0, sz, md);
  if (f)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  rep(i, sz) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}