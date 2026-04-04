#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    b--;
    ab.at(i) = {a, b};
  }
  int m;
  cin >> m;
  vector<string> s(m);
  rep(i, m) cin >> s.at(i);
  vector v(11, vector(11, set<char>()));
  rep(i, s.size()) {
    auto ss = s.at(i);
    rep(j, ss.size()) { v.at(ss.size()).at(j).insert(ss.at(j)); }
  }

  rep(i, m) {
    if (s.at(i).size() != n) {
      cout << "No" << endl;
      continue;
    }
    auto base = s.at(i);
    bool f = true;
    rep(j, ab.size()) {
      auto [a, b] = ab.at(j);
      if (v.at(a).at(b).find(base.at(j)) == v.at(a).at(b).end()) {
        f = false;
        break;
      }
    }
    if (f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}