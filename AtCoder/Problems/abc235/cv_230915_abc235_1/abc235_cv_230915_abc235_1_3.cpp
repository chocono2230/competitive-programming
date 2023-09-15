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
  map<pair<int, int>, vector<int>> mp;
  vector<int> ans(q, -1);
  rep(i, q) {
    int x, k;
    cin >> x >> k;
    mp[{x, k}].push_back(i);
  }
  map<int, int> co;
  rep(i, n) {
    co[a.at(i)]++;
    auto itr = mp.find({a.at(i), co[a.at(i)]});
    if (itr == mp.end()) continue;
    for (auto now : itr->second) {
      ans.at(now) = i + 1;
    }
  }
  rep(i, q) cout << ans.at(i) << endl;
  return 0;
}