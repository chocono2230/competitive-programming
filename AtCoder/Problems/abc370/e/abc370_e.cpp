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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  ll sum = 0;
  mint now = 1, ans = 0;
  map<ll, mint> mp;
  mp[0]++;
  rep(i, n) {
    ll in;
    cin >> in;
    auto itr = mp.find(sum + in - k);
    // cerr << "D" << sum + in - k << endl;
    mint dd = 0;
    if (itr != mp.end()) {
      dd += itr->second;
    }
    if (i == n - 1) {
      ans = now - dd;
    }
    mint pnow = now;
    now += (now - dd);
    sum += in;
    mp[sum] += (pnow - dd);
    // cerr << "S"
    //      << " " << sum << " " << (now - dd).val() << endl;
    // cerr << i << " " << in << " " << sum << " " << now.val() << " " <<
    // dd.val()
    //      << " " << pnow.val() << " " << endl;
  }
  cout << ans.val() << endl;
  return 0;
}