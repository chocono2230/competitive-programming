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
  int a, n;
  cin >> a >> n;
  int sz = 10000000;
  vector<int> d(sz, -1);
  queue<ll> q;
  q.push(1);
  d.at(1) = 0;
  while (!q.empty()) {
    ll now = q.front();
    q.pop();
    if (now * a < sz && d.at(now * a) == -1) {
      d.at(now * a) = d.at(now) + 1;
      q.push(now * a);
    }
    if (now % 10 != 0) {
      string s = to_string(now);
      string t = s.substr(s.size() - 1) + s.substr(0, s.size() - 1);
      int nx = stoi(t);
      if (d.at(nx) == -1) {
        d.at(nx) = d.at(now) + 1;
        q.push(nx);
      }
    }
  }
  cout << d.at(n) << endl;
  return 0;
}