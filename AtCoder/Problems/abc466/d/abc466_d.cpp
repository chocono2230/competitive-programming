#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> rs, cs;
  rep(i, m) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    auto itr = rs.lower_bound({r, -1});
    set<pair<int, int>> er;
    while (itr != rs.end()) {
      if (itr->first != r) break;
      er.insert(*itr);
      itr++;
    }
    itr = cs.lower_bound({c, -1});
    while (itr != cs.end()) {
      if (itr->first != c) break;
      er.insert({itr->second, itr->first});
      itr++;
    }
    for (auto [i, j] : er) {
      rs.erase({i, j});
      cs.erase({j, i});
    }
    rs.insert({r, c});
    cs.insert({c, r});
  }
  cout << rs.size() << endl;
  return 0;
}