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

int main() {
  int n;
  cin >> n;
  vector<pair<string, string>> st(n);
  map<string, int> mp;
  rep(i, n) {
    string s, t;
    cin >> s >> t;
    mp[s] = -1;
    mp[t] = -1;
    st.at(i) = {s, t};
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  scc_graph gr(sz);
  rep(i, n) {
    int si = mp[st.at(i).first];
    int ti = mp[st.at(i).second];
    gr.add_edge(si, ti);
  }
  auto grp = gr.scc();
  for (auto &v : grp) {
    if (v.size() > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}