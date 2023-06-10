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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int q;
  cin >> q;

  vector<tuple<int, int, int>> event;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    event.push_back({l, i, 0});
    event.push_back({r, i, 1});
  }
  rep(i, n) {
    if (i % 2 == 0)
      event.push_back({a.at(i), -1, 0});
    else
      event.push_back({a.at(i), -2, 0});
  }
  sort(ALL(event));
  vector<int> ans(q, 0);
  int sum = 0, bf = 0;
  for (auto [a, b, c] : event) {
    if (b == -1) {
      sum += a - bf;
      bf = -1;
    }
    if (b == -2) {
      bf = a;
    }
    if (b >= 0) {
      if (c == 0) {
        int add = sum;
        if (bf != -1) add += a - bf;
        ans.at(b) = -add;
      } else {
        int add = sum;
        if (bf != -1) add += a - bf;
        ans.at(b) += add;
      }
    }
  }

  for (auto now : ans) cout << now << endl;
  return 0;
}