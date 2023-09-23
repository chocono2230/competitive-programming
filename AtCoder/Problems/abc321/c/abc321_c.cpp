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
  ll k;
  cin >> k;
  if (k <= 9) {
    cout << k << endl;
    return 0;
  }
  queue<string> q;
  rep2(i, 1, 10) q.push(to_string(i));
  ll co = 9;
  while (!q.empty()) {
    string now = q.front();
    q.pop();
    int st = now.back() - '0';
    rep(i, st) {
      string nx = now + to_string(i);
      co++;
      if (co == k) {
        cout << nx << endl;
        return 0;
      }
      q.push(nx);
    }
  }
  return 0;
}