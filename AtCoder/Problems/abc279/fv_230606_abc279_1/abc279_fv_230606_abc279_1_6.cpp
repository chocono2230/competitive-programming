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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  dsu uf(n + q + 5);
  vector<int> box(n, -1);
  vector<int> ibx(n + q + 5, -1);
  rep(i, n) {
    box.at(i) = i;
    ibx.at(i) = i;
  }
  int co = n;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      int bx = box.at(x), by = box.at(y);
      if (by == -1) continue;
      if (bx == -1) {
        box.at(x) = box.at(y);
        ibx.at(box.at(x)) = x;
        box.at(y) = -1;
        continue;
      }
      auto l = uf.merge(bx, by);
      box.at(x) = l;
      ibx.at(l) = x;
      box.at(y) = -1;
    }
    if (mode == 2) {
      int z;
      cin >> z;
      z--;
      if (box.at(z) == -1) {
        box.at(z) = co;
        ibx.at(co) = z;
      } else {
        auto l = uf.merge(box.at(z), co);
        box.at(z) = l;
        ibx.at(l) = z;
      }
      co++;
    }
    if (mode == 3) {
      int x;
      cin >> x;
      x--;
      int l = uf.leader(x);
      int ans = ibx.at(l);
      cout << ans + 1 << endl;
    }
  }
  return 0;
}