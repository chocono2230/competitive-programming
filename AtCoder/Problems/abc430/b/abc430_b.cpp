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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  set<vector<string>> se;
  rep(i, n - m + 1) rep(j, n - m + 1) {
    vector<string> v;
    rep2(ii, i, i + m) { v.push_back(s.at(ii).substr(j, m)); }
    // if (i == 0 && j == 0) {
    //   for (auto t : v) cerr << t << endl;
    // }
    // cerr << i << " " << v.size() << " " << v.front().size() << " " << m <<
    // endl;
    assert(v.size() == m);
    assert(v.front().size() == m);
    se.insert(v);
  }
  cout << se.size() << endl;
  return 0;
}