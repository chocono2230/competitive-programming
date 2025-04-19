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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans = s;
  int sco = 0;
  rep(i, n) {
    if (s.at(i) == 'o') {
      if (i != 0) ans.at(i - 1) = '.';
      if (i != n - 1) ans.at(i + 1) = '.';
      sco++;
    }
  }
  vector<pair<char, int>> v;
  vector<int> idxv;
  v.push_back({ans.front(), 1});
  idxv.push_back(0);
  rep2(i, 1, ans.size()) {
    if (v.back().first == ans.at(i))
      v.back().second++;
    else {
      v.push_back({ans.at(i), 1});
      idxv.push_back(i);
    }
  }
  int mx = 0;
  vector<pair<int, int>> hi;
  rep(ii, v.size()) {
    auto p = v.at(ii);
    // cerr << p.first << " " << p.second << endl;
    if (p.first == '?') {
      mx += (p.second + 1) / 2;
      hi.push_back({idxv.at(ii), p.second});
    }
  }
  if (k - sco == 0) {
    rep(i, n) {
      if (ans.at(i) == '?') ans.at(i) = '.';
    }
  } else if (mx == k - sco) {
    for (auto [ii, ss] : hi) {
      if (ss % 2 == 0) continue;
      bool x = true;
      rep2(i, ii, ii + ss) {
        if (x)
          ans.at(i) = 'o';
        else
          ans.at(i) = '.';
        x ^= true;
      }
    }
  }
  cout << ans << endl;

  return 0;
}