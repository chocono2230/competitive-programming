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
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  fenwick_tree<mint> sum(n + 1);
  mint count = 1;
  rep2(i, 1, n + 1) {
    mint ss = sum.sum(0, i);
    sum.add(i, ss + count * a.at(i - 1));
    count += (count - i);
  }
  rep(i, n + 1) cerr << sum.sum(i, i + 1).val() << " ";
  cerr << endl;
  mint ans = sum.sum(n, n + 1) / count;
  cout << ans.val() << endl;
  return 0;
}