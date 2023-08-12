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
  string s;
  cin >> s;
  vector<int> c(n);
  rep(i, n) {
    cin >> c.at(i);
    c.at(i)--;
  }
  vector<queue<int>> v(m);
  rep(i, n) { v.at(c.at(i)).push(i); }
  string ans(n, '.');
  rep(i, n) {
    int idx = c.at(i);
    v.at(idx).push(v.at(idx).front());
    v.at(idx).pop();
    ans.at(v.at(idx).front()) = s.at(i);
  }
  cout << ans << endl;
  return 0;
}