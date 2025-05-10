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
  vector event(2 * n + 1, vector<pair<int, int>>());
  vector event2(2 * n + 1, vector<pair<int, int>>());
  vector<pair<int, int>> ab(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
    event.at(a).push_back({-1, 0});
    event.at(b).push_back({a, 1});
    event2.at(a).push_back({b, 0});
    event2.at(b).push_back({-1, 1});
  }
  int q;
  cin >> q;
  rep(i, q) {
    int c, d;
    cin >> c >> d;
    event.at(d).push_back({i, c});
    event2.at(c).push_back({i, d});
  }
  vector<int> ans(q);
  fenwick_tree<int> fw(2 * n + 1);
  rep(i, 2 * n + 1) {
    auto &v = event.at(i);
    for (auto now : v) {
      if (i % 2 == 0) {
        if (now.second == 0)
          fw.add(i, 1);
        else
          fw.add(now.first, -1);
      } else {
        ans.at(now.first) = fw.sum(now.second, i);
      }
    }
  }

  fenwick_tree<int> fw2(2 * n + 1);
  fw = fw2;
  rep(i, 2 * n + 1) {
    auto &v = event2.at(i);
    for (auto now : v) {
      if (i % 2 == 0) {
        if (now.second == 0)
          fw.add(now.first, 1);
        else
          fw.add(i, -1);
      } else {
        // cerr << now.first << " " << now.second << " " << i << " "
        //      << fw.sum(now.second, i) << endl;
        // rep(i, 2 * n) cerr << fw.sum(i, i + 1) << " ";
        // cerr << endl;
        ans.at(now.first) += fw.sum(i, now.second);
      }
    }
  }
  rep(i, q) cout << ans.at(i) << endl;
  return 0;
}