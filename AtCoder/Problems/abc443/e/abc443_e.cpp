#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    c--;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    vector bk(n, vector<int>());
    rep(i, n) rep(j, n) {
      if (s.at(i).at(j) == '#') bk.at(j).push_back(i);
    }
    vector table(n, vector<bool>(n, false));
    table.at(n - 1).at(c) = true;
    rrep(i, n - 1) rep(j, n) {
      rep2(d, -1, 2) {
        int pi = i + 1, pj = j + d;
        if (pj < 0 || pj >= n) continue;
        if (!table.at(pi).at(pj)) continue;
        if (s.at(i).at(j) == '#') {
          if (bk.at(j).back() != i) continue;
          bk.at(j).pop_back();
        }
        table.at(i).at(j) = true;
        break;
      }
    }
    string ans(n, '0');
    rep(i, n) {
      if (table.at(0).at(i)) ans.at(i) = '1';
    }
    // rep(i, n) {
    //   rep(j, n) cerr << table.at(i).at(j);
    //   cerr << endl;
    // }
    cout << ans << endl;
  }
  return 0;
}