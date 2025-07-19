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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> table(s.size() + 1, false);
    queue<int> q;
    q.push(0);
    table.at(0) = true;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      rep(i, n) {
        int nxbit = (now | (1 << i));
        if (table.at(nxbit)) continue;
        if (s.at(nxbit - 1) == '1') continue;
        table.at(nxbit) = true;
        q.push(nxbit);
      }
    }
    if (table.back())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}