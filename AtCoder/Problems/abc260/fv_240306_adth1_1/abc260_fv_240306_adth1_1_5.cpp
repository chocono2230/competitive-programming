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
  int s, t, m;
  cin >> s >> t >> m;
  vector gr(s, vector<int>());
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.at(u).push_back(v);
  }
  vector mp(t + 1, vector<int>(t + 1, -1));
  rep(i, s) {
    sort(ALL(gr.at(i)));
    rep(j, gr.at(i).size()) rep2(k, j + 1, gr.at(i).size()) {
      pair<int, int> p(gr.at(i).at(j) - s, gr.at(i).at(k) - s);
      if (mp.at(p.first).at(p.second) == -1) {
        mp.at(p.first).at(p.second) = i;
        continue;
      }
      int x = mp.at(p.first).at(p.second);
      cout << x + 1 << " " << i + 1 << " " << p.first + 1 + s << " "
           << p.second + 1 + s << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}