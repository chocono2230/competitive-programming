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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  map<int, pair<int, int>> mp;
  rep(i, n) mp[a.at(i)] = {0, i};
  rep(i, m) mp[b.at(i)] = {1, i};

  auto c = a;
  for (auto add : b) c.push_back(add);
  sort(ALL(c));

  vector ans(2, vector<int>(max(n, m), 0));
  rep(i, c.size()) {
    int now = c.at(i);
    auto [p, q] = mp[now];
    ans.at(p).at(q) = i;
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(0).at(i) + 1;
  }
  cout << endl;
  rep(i, m) {
    if (i != 0) cout << " ";
    cout << ans.at(1).at(i) + 1;
  }
  cout << endl;
  return 0;
}