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

const string U = "UNSOLVABLE";

int main() {
  vector<string> s(3);
  rep(i, 3) cin >> s.at(i);
  map<char, int> mp;
  int sz = 0;
  rep(i, 3) {
    rep(j, s.at(i).size()) {
      auto c = s.at(i).at(j);
      if (mp.find(c) != mp.end()) {
      } else {
        mp[c] = sz++;
        if (sz >= 11) {
          cout << U << endl;
          return 0;
        }
      }
    }
  }
  vector<int> p;
  rep(i, 10) p.push_back(i);
  do {
    vector<ll> v(3, 0);
    bool f = false;
    rep(i, 3) {
      rep(j, s.at(i).size()) {
        auto c = s.at(i).at(j);
        int idx = mp[c];
        int z = p.at(idx);
        v.at(i) *= 10;
        v.at(i) += z;
      }
      if (v.at(i) == 0 || s.at(i).size() != to_string(v.at(i)).size()) f = true;
    }
    if (f) continue;
    if (v.at(0) + v.at(1) == v.at(2)) {
      for (auto i : v) cout << i << endl;
      return 0;
    }
  } while (next_permutation(ALL(p)));
  cout << U << endl;
  return 0;
}