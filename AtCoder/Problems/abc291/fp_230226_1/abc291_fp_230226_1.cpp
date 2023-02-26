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
  vector<string> sv(n);
  vector gr(n, vector<int>());
  vector rgr(n, vector<int>());
  rep(i, n) {
    string s;
    cin >> s;
    sv.at(i) = s;
    rep(j, m) {
      if (s.at(j) == '1') {
        gr.at(i).push_back(i + j + 1);
        rgr.at(i + j + 1).push_back(i);
      }
    }
  }
  const int INF = 1001001001;
  vector<int> fd(n, INF), bd(n, INF);
  fd.front() = 0;
  rep(i, n) {
    for (auto nx : gr.at(i)) {
      fd.at(nx) = min(fd.at(nx), fd.at(i) + 1);
    }
  }
  bd.back() = 0;
  rrep(i, n) {
    for (auto nx : rgr.at(i)) {
      bd.at(nx) = min(bd.at(nx), bd.at(i) + 1);
    }
  }
  // rep(i, n) { cout << fd.at(i) << " "; }
  // cout << endl;
  // rep(i, n) { cout << bd.at(i) << " "; }
  // cout << endl;

  vector<int> ans(n, INF);
  rep2(now, 1, n - 1) {
    rep(pi, m) {
      int p = now - pi - 1;
      if (p < 0) break;
      rep(qi, m) {
        int q = now + qi + 1;
        if (q >= n) break;
        if (pi + qi + 1 >= m) break;
        if (sv.at(p).at(pi + qi + 1) == '0') continue;
        int add = fd.at(p) + bd.at(q) + 1;
        ans.at(now) = min(ans.at(now), add);
      }
    }
  }
  rep2(i, 1, n - 1) {
    if (i != 1) cout << " ";
    int o = ans.at(i) == INF ? -1 : ans.at(i);
    cout << o;
  }
  cout << endl;
  return 0;
}