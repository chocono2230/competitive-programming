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

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<pair<int, int>, vector<int>> qe;
  rep(i, q) {
    int x, k;
    cin >> x >> k;
    qe[{x, k}].push_back(i);
  }
  vector<int> ans(q, -1);
  map<int, int> co;
  int idx = 0;
  for (auto now : a) {
    idx++;
    co[now]++;
    auto &v = qe[{now, co[now]}];
    for (auto i : v) {
      ans.at(i) = idx;
    }
  }
  for (auto p : ans) cout << p << endl;
  return 0;
}