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
  ll k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  fenwick_tree<int> fw(n);
  ll ans = 0;
  ll now = 0;
  const int INF = 1001001001;
  int r = 0, l = INF;
  rep(i, n) {
    r = i;
    ll nxnow = fw.sum(p.at(i), n) + now;
    if (nxnow > k) {
      break;
    }
    if (nxnow == k && l == INF) {
      l = r;
    }
    now = nxnow;
    fw.add(p.at(i), 1);
  }
  ans += max(0, r - l);
  rep2(i, 1, n) {
    int z = fw.sum(0, p.at(i - 1));
    now -= z;
    fw.add(p.at(i - 1), -1);
    if (z == 0) {
      l = max(l, i);
      ans += max(0, r - l);
      continue;
    }
  }
  return 0;
}