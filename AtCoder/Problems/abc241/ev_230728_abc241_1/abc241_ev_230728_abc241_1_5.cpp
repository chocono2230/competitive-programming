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
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector gr(60, vector<int>(n, 0));
  vector db(60, vector<ll>(n, 0));
  rep(i, n) {
    gr.at(0).at(i) = (i + a.at(i)) % n;
    db.at(0).at(i) = a.at(i);
  }
  rep(i, 59) {
    rep(j, n) {
      gr.at(i + 1).at(j) = gr.at(i).at(gr.at(i).at(j));
      db.at(i + 1).at(j) = db.at(i).at(j) + db.at(i).at(gr.at(i).at(j));
    }
  }
  // rep(i, 5) {
  //   rep(j, n) cerr << gr.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  // cerr << endl;
  // rep(i, 5) {
  //   rep(j, n) cerr << db.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  // cerr << endl;
  ll ans = 0;
  int now = 0;
  rep(i, 60) {
    if ((k & (1LL << i)) == 0) continue;
    // cerr << now << " ";
    ans += db.at(i).at(now);
    now = gr.at(i).at(now);
    // cerr << now << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}