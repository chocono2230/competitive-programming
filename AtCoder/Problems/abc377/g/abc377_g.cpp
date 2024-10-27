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

struct Tier {
  int po;
  vector<int> edge;
  Tier(int po) : po(po) { edge = vector<int>(26, -1); }
};

int main() {
  int n;
  cin >> n;
  vector<Tier> tiers;
  const int INF = 1001001001;
  tiers.push_back(Tier(INF));
  rep(_i, n) {
    string s;
    cin >> s;
    int ans = s.size();
    int now = 0, idx = 0;
    while (1) {
      ans = min(ans, tiers.at(now).po + (int)s.size() - idx);
      if (idx == s.size()) break;
      char c = s.at(idx) - 'a';
      if (tiers.at(now).edge.at(c) == -1) break;
      idx++;
      now = tiers.at(now).edge.at(c);
    }
    cout << ans << endl;
    now = 0, idx = 0;
    while (1) {
      int cost = s.size() - idx;
      tiers.at(now).po = min(tiers.at(now).po, cost);
      if (idx == s.size()) break;
      char c = s.at(idx) - 'a';
      if (tiers.at(now).edge.at(c) == -1) {
        tiers.at(now).edge.at(c) = tiers.size();
        tiers.push_back(Tier(INF));
      }
      idx++;
      now = tiers.at(now).edge.at(c);
    }
  }
  return 0;
}