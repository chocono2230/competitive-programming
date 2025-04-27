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
    bool flg = false;
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

  void init() { nodes.push_back(Node()); }

  int operation1(string &t) {
    int res = 0;
    int nowId = 0;
    rep(idx, t.size()) {
      auto c = t.at(idx);
      auto &now = nodes.at(nowId);
      int nextId = now.next(c, nodes);
      if (idx == t.size() - 1) {
        auto &next = nodes.at(nextId);
        res = next.value;
        next.flg = true;
      }
      nowId = nextId;
    }
    if (res == 0) return res;

    nowId = 0;
    rep(idx, t.size()) {
      auto c = t.at(idx);
      auto &now = nodes.at(nowId);
      int nextId = now.next(c, nodes);
      auto &next = nodes.at(nextId);
      if (idx != t.size() - 1) next.value -= res;
      nowId = nextId;
    }
    auto rc = [&](const auto &self, int now) -> void {
      if (nodes.at(now).value == 0) return;
      nodes.at(now).value = 0;
      for (auto p : nodes.at(now).edges) {
        self(self, p.second);
      }
    };
    rc(rc, nowId);
    return res;
  }

  int operation2(string &t) {
    int nowId = 0;
    bool p = false;
    for (auto c : t) {
      auto &now = nodes.at(nowId);
      int nextId = now.next(c, nodes);
      auto &next = nodes.at(nextId);
      p |= next.flg;
      nowId = nextId;
    }
    if (p) return 0;
    nowId = 0;
    for (auto c : t) {
      auto &now = nodes.at(nowId);
      int nextId = now.next(c, nodes);
      auto &next = nodes.at(nextId);
      next.value++;
      nowId = nextId;
    }
    return 1;
  }
};

int main() {
  int q;
  cin >> q;
  TrieTree tr;
  tr.init();
  int now = 0;
  while (q--) {
    int mode;
    string s;
    cin >> mode >> s;
    if (mode == 1) {
      now -= tr.operation1(s);
    } else {
      now += tr.operation2(s);
    }
    cout << now << endl;
  }
  return 0;
}