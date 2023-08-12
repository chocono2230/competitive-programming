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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<tuple<char, bool, int>> v(n);
  rep(i, n) {
    char c = s.at(i);
    bool f = ('A' <= c && c <= 'Z');
    v.at(i) = {tolower(c), f, -1};
  }
  int mode = -1, midx = -2;
  rep(idx, q) {
    int t, x;
    char c;
    cin >> t >> x >> c;
    x--;
    if (t == 1) {
      bool f = ('A' <= c && c <= 'Z');
      v.at(x) = {tolower(c), f, idx};
    }
    if (t == 2) {
      mode = 0;
      midx = idx;
    }
    if (t == 3) {
      mode = 1;
      midx = idx;
    }
  }
  for (auto &[a, b, c] : v) {
    if (midx < c) continue;
    if (mode == 0) {
      b = false;
    }
    if (mode == 1) {
      b = true;
    }
  }
  string ans;
  for (auto [a, b, c] : v) {
    if (b) {
      a = toupper(a);
    }
    ans.push_back(a);
  }
  cout << ans << endl;
  return 0;
}