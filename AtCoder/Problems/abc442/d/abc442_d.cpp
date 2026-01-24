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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  fenwick_tree<ll> fw(n);
  rep(i, n) fw.add(i, a.at(i));
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int in;
      cin >> in;
      in--;
      int p = a.at(in), q = a.at(in + 1);
      fw.add(in, -p);
      fw.add(in + 1, -q);
      fw.add(in, q);
      fw.add(in + 1, p);
      swap(a.at(in), a.at(in + 1));
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      cout << fw.sum(l, r) << endl;
    }
  }
  return 0;
}