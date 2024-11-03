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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  fenwick_tree<int> fw(m);
  ll sum = 0, psum = 0;
  rep(i, n) {
    a.at(i) %= m;
    fw.add(a.at(i), 1);
    psum += a.at(i);
    sum += psum;
  }
  int ans = 0, base = 0;
  rep(i, n) {
    cerr << sum << endl;
    ans += sum;
    sum -= a.at(i);
    fw.add(a.at(i), -1);
    int pb = base;
    base += a.at(i);
    base %= m;
    if (pb == base) continue;
    int toc = n - i - 1;
    int d = abs(base - pb);
    if (pb < base) {
      int rc = fw.sum(base, m);
      int mc = fw.sum(pb, base);
      int lc = toc - rc - mc;
      int z = m - base;
      int z2 = z + pb;
      sum -= (ll)rc * d;
      sum += (ll)lc * z;
      sum += (ll)mc * z2;
    } else {
      int rc = fw.sum(pb, m);
      int mc = fw.sum(base, pb);
      int lc = toc - rc - mc;
      sum += (ll)rc * d;
      sum += (ll)lc * d;
      sum -= (ll)mc * (m - d);
    }
  }
  cout << ans << endl;
  return 0;
}