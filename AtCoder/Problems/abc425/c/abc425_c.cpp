#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  auto b = a;
  rep(i, n) b.push_back(a.at(i));
  vector<ll> sums(n * 2 + 1, 0);
  rep(i, n * 2) sums.at(i + 1) = sums.at(i) + b.at(i);
  int idx = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int in;
      cin >> in;
      idx += in;
      idx %= n;
    }
    if (mode == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      l += idx;
      r += idx;
      cout << sums.at(r) - sums.at(l) << endl;
    }
  }
  return 0;
}