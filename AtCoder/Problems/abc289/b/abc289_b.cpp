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
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  rep(i, m) {
    int in;
    cin >> in;
    in--;
    uf.merge(in, in + 1);
  }
  bool f = false;
  rep(i, n) {
    int sz = uf.size(i);
    int r = i + sz;
    rrep2(j, i, r) {
      if (f) cout << " ";
      f = true;
      cout << j + 1;
    }
    i = r - 1;
  }
  cout << endl;
  return 0;
}