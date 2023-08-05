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

int io(vector<int> &v) {
  cout << "?";
  for (auto now : v) cout << " " << now + 1;
  cout << endl;
  int in;
  cin >> in;
  if (in == -1) exit(1);
  return in;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ans(n, 0);
  vector<int> v(k, 0);
  vector<int> p(k + 1);
  rep(i, k + 1) {
    int idx = 0;
    rep(j, k + 1) {
      if (j == i) continue;
      v.at(idx++) = j;
    }
    p.at(i) = io(v);
  }
  int ss = (reduce(ALL(p)) % 2);
  rep(i, k + 1) { ans.at(i) = (ss ^ p.at(i)); }
  rep2(i, k + 1, n) {
    rep(j, k) { v.at(j) = i - j; }
    int r = io(v);
    int s = 0;
    rep2(j, 1, k) {
      int idx = i - j;
      s += ans.at(idx);
      s %= 2;
    }
    ans.at(i) = (r ^ s);
  }
  cout << "!";
  for (auto now : ans) cout << " " << now;
  cout << endl;
  return 0;
}