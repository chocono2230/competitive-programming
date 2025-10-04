#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  map<int, int> mp;
  rep(i, n) mp[i + 1] = 1;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    auto itr = mp.upper_bound(x);
    vector<int> ta;
    while (itr != mp.begin()) {
      itr--;
      ans += itr->second;
      ta.push_back(itr->first);
    }
    cout << ans << endl;
    for (auto now : ta) mp.erase(now);
    mp[y] += ans;
  }
  return 0;
}