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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n, 0);
  rep(i, n) {
    if (s.at(i) == 'A') v.at(i) = 1;
    if (s.at(i) == 'B') v.at(i) = -1;
  }
  vector<ll> sums(n + 1, 0);
  rep(i, n) sums.at(i + 1) = sums.at(i) + v.at(i);

  int sz = 2000000;
  int c = sz / 2;
  fenwick_tree<int> fw(sz);
  ll ans = 0;
  rep(i, n + 1) {
    int now = sums.at(i);
    ans += fw.sum(0, c + now);
    fw.add(c + now, 1);
  }
  cout << ans << endl;
  return 0;
}