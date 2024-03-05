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
  vector<int> a(k);
  rep(i, k) {
    cin >> a.at(i);
    a.at(i)--;
  }
  int idx = 0;
  vector<int> v;
  rep(i, n) {
    v.push_back(i);
    if (idx != k && a.at(idx) == i) {
      idx++;
    } else {
      v.push_back(i);
    }
  }
  ll ans = 0;
  rep(i, v.size() - 1) {
    ans += v.at(i + 1) - v.at(i);
    i++;
  }
  if (v.size() % 2 == 0) {
    cout << ans << endl;
    return 0;
  }
  ll now = ans;
  rrep(i, v.size() - 1) {
    if (i % 2 == 0) {
      now -= v.at(i + 2) - v.at(i);
      now += v.at(i + 2) - v.at(i + 1);
    } else {
      now -= v.at(i) - v.at(i - 1);
      now += v.at(i + 1) - v.at(i - 1);
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}