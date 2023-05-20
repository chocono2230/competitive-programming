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
  vector<set<int>> gr(n);
  int ans = n;
  rep(i, q) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (gr.at(u).size() == 0) ans--;
      if (gr.at(v).size() == 0) ans--;
      gr.at(u).insert(v);
      gr.at(v).insert(u);
    } else {
      int in;
      cin >> in;
      in--;
      if (gr.at(in).size() != 0) {
        for (auto nx : gr.at(in)) {
          gr.at(nx).erase(in);
          if (gr.at(nx).size() == 0) ans++;
        }
        gr.at(in).clear();
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}