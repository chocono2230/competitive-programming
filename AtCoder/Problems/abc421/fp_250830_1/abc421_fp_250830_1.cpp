#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int q;
  cin >> q;
  vector<pair<int, int>> node(q + 1, {-2, -2});
  node.at(0) = {0, -1};
  rep2(idx, 1, q + 1) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      cin >> x;
      int pr = node.at(x).second;
      if (pr != -1) node.at(pr).first = idx;
      node.at(idx) = {x, pr};
      node.at(x).second = idx;
    }
    if (mode == 2) {
      int a, b;
      cin >> a >> b;
      int ai = a, bi = b;
      ll asum = 0, bsum = 0;
      // int dbg = 0;
      while (1) {
        // if (dbg++ < 10) cerr << ai << " " << bi << endl;
        asum += ai;
        bsum += bi;
        ai = node.at(ai).first;
        bi = node.at(bi).first;
        if (ai == b) {
          asum += b;
          bsum = -1;
          break;
        }
        if (bi == a) {
          bsum += a;
          asum = -1;
          break;
        }
      }
      ll ans = asum - a - b;
      if (asum == -1) ans = bsum - a - b;
      cout << ans << endl;
      if (bsum == -1) {
        node.at(b).second = a;
        node.at(a).first = b;
        // cerr << "DBG" << a << " " << b << endl;
      }
      if (asum == -1) {
        node.at(a).second = b;
        node.at(b).first = a;
      }
    }
  }
  return 0;
}