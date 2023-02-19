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
  vector gr(n + 5, vector<int>());
  rep(i, n) { gr.at(a.at(i)).push_back(i); }
  ll ans = 0;
  int p = -1;
  for (auto &v : gr) {
    p++;
    if (v.size() < 1) continue;
    if (p < 7) {
      // cerr << p << ": ";
      // for (auto zz : v) cerr << zz << " ";
      // cerr << endl;
    }
    deque<int> q;
    int co = 0;
    ll ss = 0;
    for (auto now : v) {
      int z = n - now;
      while (!q.empty()) {
        if (q.back() + 1 > z) {
          co++;
          ss -= q.back() + 1;
          q.pop_back();
        } else
          break;
      }
      ans += (ll)co * z + ss;
      // if (co * z + ss != 0)
      // cerr << p << " " << now << " " << co * z + ss << " " << ss << " "
      // <<
      // co
      //      << " " << z << endl;
      ss += now + 1;
      q.push_back(now);
    }
  }
  cerr << ans << endl;
  ans *= -1;
  deque<int> q;
  int co = 0;
  ll ss = 0;
  rep(i, n) {
    int now = i;
    int z = n - now;
    while (!q.empty()) {
      if (q.back() + 1 > z) {
        co++;
        ss -= q.back() + 1;
        q.pop_back();
      } else
        break;
    }
    ans += (ll)co * z + ss;
    // if (co * z + ss != 0)
    // cerr << p << " " << now << " " << co * z + ss << " " << ss << " " <<
    // co
    //      << " " << z << endl;
    ss += now + 1;
    q.push_back(now);
  }
  cout << ans << endl;
  return 0;
}