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
  int qe;
  cin >> qe;
  priority_queue<int, vector<int>, greater<int>> q;
  queue<int> qq;
  while (qe--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      cin >> x;
      qq.push(x);
    }
    if (mode == 2) {
      int ans = 0;
      if (q.empty()) {
        ans = qq.front();
        qq.pop();
      } else {
        ans = q.top();
        q.pop();
      }
      cout << ans << endl;
    }
    if (mode == 3) {
      while (!qq.empty()) {
        q.push(qq.front());
        qq.pop();
      }
    }
  }
  return 0;
}