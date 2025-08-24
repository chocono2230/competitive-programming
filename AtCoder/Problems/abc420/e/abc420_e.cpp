#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> co(n, 0);
  vector<int> sum(n, 0);
  dsu uf(n);
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (uf.same(u, v)) continue;
      int lu = uf.leader(u), lv = uf.leader(v);
      int su = sum.at(lu), sv = sum.at(lv);
      sum.at(lu) -= su, sum.at(lv) -= sv;
      uf.merge(u, v);
      int nl = uf.leader(u);
      sum.at(nl) = su + sv;
    }
    if (mode == 2) {
      int in;
      cin >> in;
      in--;
      int add = 1;
      if (co.at(in) % 2 == 1) {
        add = -1;
      }
      co.at(in)++;
      int ld = uf.leader(in);
      sum.at(ld) += add;
    }
    if (mode == 3) {
      int in;
      cin >> in;
      in--;
      int ans = sum.at(uf.leader(in));
      if (ans == 0)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  }
  return 0;
}