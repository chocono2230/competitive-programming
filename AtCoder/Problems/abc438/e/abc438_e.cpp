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
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  vector table(40, vector<ll>(n, 0));
  vector edge(40, vector<int>(n, 0));
  rep(i, n) table.at(0).at(i) = i + 1;
  edge.at(0) = a;
  rep(i, 39) {
    rep(j, n) { edge.at(i + 1).at(j) = edge.at(i).at(edge.at(i).at(j)); }
    rep(j, n) {
      table.at(i + 1).at(j) =
          table.at(i).at(j) + table.at(i).at(edge.at(i).at(j));
    }
  }
  while (q--) {
    int t, b;
    cin >> t >> b;
    b--;
    ll ans = 0;
    rep(i, 40) {
      if ((t & (1LL << i)) == 0) continue;
      ans += table.at(i).at(b);
      // cerr << i << " " << ans << endl;
      b = edge.at(i).at(b);
    }
    cout << ans << endl;
  }
  return 0;
}