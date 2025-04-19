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
  vector<vector<int>> gr(n, vector<int>());
  vector<vector<int>> rgr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);
    gr.at(a).push_back(b);
    rgr.at(b).push_back(a);
  }

  set<int> se;
  vector<int> ans(n, -1);
  dsu uf(n);
  rep(i, n) {
    for (auto nx : gr.at(i)) {
      se.insert(nx);
    }
    while (!se.empty()) {
      if (*se.begin() > i) break;
      se.erase(se.begin());
    }
    for (auto nx : rgr.at(i)) {
      uf.merge(i, nx);
    }
    if (uf.same(i, 0)) ans.at(i) = se.size();
  }
  for (auto now : ans) cout << now << endl;
  return 0;
}