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
  dsu uf(n);
  map<int, vector<int>> mp;
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int in;
      cin >> in;
      mp[in].push_back(i);
    }
  }
  for (auto &p : mp) {
    rep(i, p.second.size() - 1) {
      uf.merge(p.second.at(i), p.second.at(i + 1));
    }
  }
  auto g = uf.groups();
  if (g.size() == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}