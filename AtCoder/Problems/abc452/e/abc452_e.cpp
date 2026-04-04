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
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;
  vector<mint> a(n);
  rep(i, n) {
    int in;
    cin >> in;
    a.at(i) = in;
  }
  vector<mint> b(m);
  rep(i, m) {
    int in;
    cin >> in;
    b.at(i) = in;
  }
  // rep(i, n) cerr << a.at(i).val() << " ";
  // cerr << endl;

  mint ans = 0, sum = 0;
  if (n + 1 < m) {
    rrep2(j, n + 1, m) sum += b.at(j);
  }
  rrep(i, n) {
    if (i + 1 >= m) continue;
    sum += b.at(i + 1);
    ans += sum * (i + 1) * a.at(i);
  }
  // cerr << sum.val() << endl;
  // cerr << ans.val() << endl;
  sum = 0;
  mint add = 0;
  vector flgs(n, vector<int>());
  rep(i, n) {
    sum += add;
    for (auto idx : flgs.at(i)) {
      sum -= b.at(idx) * (idx + 1);
    }
    ans += sum * a.at(i);
    if (i < m) {
      add += b.at(i);
      rep2(p, i, n) {
        flgs.at(p).push_back(i);
        p += (i + 1) - 1;
      }
    }
  }
  cout << ans.val() << endl;
  return 0;
}