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

vector<pair<int, int>> lr;

int rc(int l, int r, bool rs = false) {
  static vector memo(105, vector<int>(105, -1));
  if (rs) {
    rep(i, memo.size()) rep(j, memo.at(i).size()) memo.at(i).at(j) = -1;
    return 0;
  }
  if (memo.at(l).at(r) != -1) return memo.at(l).at(r);
  if (l == r) return memo.at(l).at(r) = 0;
  set<int> se;
  for (auto [l1, r1] : lr) {
    if (l1 < l) continue;
    if (r < r1) continue;
    int add = (rc(l, l1) ^ rc(r1, r));
    se.insert(add);
  }
  int res = 0;
  const int INF = 1001001001;
  rep(i, INF) {
    if (se.find(i) == se.end()) {
      res = i;
      break;
    }
  }
  return memo.at(l).at(r) = res;
}

void solve() {
  int n;
  cin >> n;
  lr.resize(n);
  rc(0, 0, true);
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    lr.at(i) = {l, r};
  }
  int r = rc(0, 99);
  if (r == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}