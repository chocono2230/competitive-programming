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
  set<int> se;
  rep(i, k) {
    int in;
    cin >> in;
    se.insert(in - 1);
  }
  vector<int> v;
  rep(i, n) {
    if (!se.contains(i)) v.push_back(i);
    v.push_back(i);
  }
  if (v.size() % 2 == 0) {
    int ans = 0;
    rep(i, v.size()) {
      ans += v.at(i + 1) - v.at(i);
      i++;
    }
    cout << ans << endl;
    return 0;
  }
  vector<int> l(v.size() + 1, 0);
  rep(i, v.size()) {
    l.at(i + 1) += l.at(i);
    if (i % 2 == 1) {
      l.at(i + 1) += v.at(i) - v.at(i - 1);
    }
  }
  const int INF = 1001001001;
  int ans = INF;
  int rs = 0;
  rrep(i, v.size()) {
    if (i % 2 == 0) {
      ans = min(ans, rs + l.at(i));
    } else {
      rs += v.at(i + 1) - v.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}