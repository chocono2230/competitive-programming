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
  int n, m, x1;
  cin >> n >> m >> x1;
  vector<tuple<int, int, int, int, int>> event;
  vector<ll> ans(m, 0);
  vector<ll> nt(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    int s, t;
    cin >> s >> t;
    a--;
    b--;
    event.push_back({s, 1, a, b, i});
    event.push_back({t, 0, a, b, i});
  }
  sort(ALL(event));
  for (auto [now, mode, a, b, i] : event) {
    if (mode == 1) {
      ll stt = max((ll)now, nt.at(a));
      if (i == 0)
        ans.at(i) = x1;
      else
        ans.at(i) = stt - now;
      // cerr << "P" << i << " " << ans.at(i) << endl;
    } else {
      nt.at(b) = max(nt.at(b), now + ans.at(i));
      // cerr << b << " " << nt.at(b) << endl;
    }
  }
  rep2(i, 1, m) {
    if (i != 1) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}