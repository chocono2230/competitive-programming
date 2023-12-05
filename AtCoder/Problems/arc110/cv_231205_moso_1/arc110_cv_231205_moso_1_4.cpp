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
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<bool> used(n - 1, false);
  vector<int> ans;
  int now = 0;
  rep(i, n) {
    if (p.at(now) == i) {
      now++;
      continue;
    }
    while (p.at(now) != i) now++;
    while (now != i) {
      if (used.at(now - 1)) {
        cout << -1 << endl;
        return 0;
      }
      used.at(now - 1) = true;
      ans.push_back(now);
      swap(p.at(now), p.at(now - 1));
      now--;
    }
    now++;
  }
  if (ans.size() != n - 1)
    cout << -1 << endl;
  else
    for (auto o : ans) cout << o << endl;
  return 0;
}