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
  while (qe--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ab(n);
    rep(i, n) {
      int in;
      cin >> in;
      ab.at(i).first = in;
    }
    rep(i, n) {
      int in;
      cin >> in;
      ab.at(i).second = in;
    }
    sort(ALL(ab));
    priority_queue<ll> q;
    ll sum = 0;
    rep(i, k - 1) {
      sum += ab.at(i).second;
      q.push(ab.at(i).second);
    }
    const ll INF = 1e18;
    ll ans = INF;
    rep2(i, k - 1, n) {
      ll mx = ab.at(i).first;
      // cerr << mx << " " << sum << " " << ab.at(i).second << endl;
      ans = min(ans, mx * (sum + (ll)ab.at(i).second));
      sum += ab.at(i).second;
      q.push(ab.at(i).second);
      if (q.size() == k) {
        sum -= q.top();
        q.pop();
      }
    }
    cout << ans << endl;
    // cerr << "-----------" << endl;
  }
  return 0;
}