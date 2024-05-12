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

struct TrieTree {
  struct Node {
    using Key = char;
    using Value = int;
    Value value = 0;
    map<Key, int> edges;

    int next(Key key, vector<Node> &nodes) {
      auto itr = edges.find(key);
      if (itr != edges.end()) return itr->second;
      int res = nodes.size();
      edges[key] = res;
      nodes.push_back(Node());
      return res;
    }
  };
  vector<Node> nodes;

  ll operation(vector<string> &vs) {
    ll res = 0;
    nodes.push_back(Node());
    for (const auto &s : vs) {
      int nowId = 0;
      for (auto c : s) {
        auto &now = nodes.at(nowId);
        int nextId = now.next(c, nodes);
        auto &next = nodes.at(nextId);
        res += next.value;
        next.value++;
        nowId = nextId;
      }
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  rep(i, n) cin >> vs.at(i);
  TrieTree tree;
  ll ans = tree.operation(vs);
  cout << ans << endl;
  return 0;
}