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

int m;
double e;
random_device seed_gen;
mt19937 engine(seed_gen());

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202211117,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double xor_shift() { return (double)(xor128() % LLONG_MAX) / LLONG_MAX; }
void massert(bool f, string msg = "") {
  return;
  if (!f) {
    cerr << "Error : " << msg << endl;
    exit(1);
  }
}

const clock_t start_time = clock();
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

int rand_ans() { return xor_shift() * m; }

class Graph {
  int n;
  int popcount = 0;
  vector<vector<int>> gr;
  vector<bitset<100>> bitgr;
  map<int, int> degmp;

  void swap_graph(Graph &g) {
    gr = g.gr;
    bitgr = g.bitgr;
    n = g.n;
    popcount = g.popcount;
    degmp = g.degmp;
  }

 public:
  Graph(int n)
      : n(n), gr(vector(n, vector<int>())), bitgr(vector(n, bitset<100>())) {}
  Graph(int n, string s)
      : n(n), gr(vector(n, vector<int>())), bitgr(vector(n, bitset<100>())) {
    int idx = 0;
    rep(i, n) rep2(j, i + 1, n) {
      if (s.at(idx++) == '1') {
        add_edge(i, j);
      }
    }
  }
  Graph(Graph &g, int l, int r, const vector<int> &p)
      : n(g.n), gr(vector(n, vector<int>())), bitgr(vector(n, bitset<100>())) {
    rep(i, n) rep2(j, i + 1, n) {
      int ii = i, jj = j;
      if (l <= i && i < r) {
        ii = p.at(i - l) + l;
      }
      if (l <= j && j < r) {
        jj = p.at(j - l) + l;
      }
      if (g.is_connect(i, j)) {
        add_edge(ii, jj);
      }
    }
  }

  const vector<int> &edges(int i) { return gr.at(i); }
  const bitset<100> &bit_edges(int i) { return bitgr.at(i); }

  void add_edge(int i, int j) {
    if (bitgr.at(i)[j]) return;
    popcount++;
    gr.at(i).push_back(j);
    gr.at(j).push_back(i);
    bitgr.at(i).set(j);
    bitgr.at(j).set(i);
  }
  bool is_connect(int i, int j) { return bitgr.at(i)[j]; }

  void init_degmp() {
    degmp.clear();
    rep(i, n) { degmp[bit_edges(i).count()]++; }
  }

  int search_t() {
    bool f = false;
    int mx = 0, mxi = -1;
    rep(i, n) {
      if (mx < (int)gr.at(i).size()) {
        mx = gr.at(i).size();
        mxi = i;
        f = false;
      } else if (mx == (int)gr.at(i).size())
        f = true;
    }
    if (f) return -1;
    return mxi;
  }
  int search_s() {
    rep(i, n) {
      if (gr.at(i).size() == 1) return i;
    }
    // massert(false, "no find s");
    return -1;
  }

  set<int> ss(int pt) {
    int st = search_s();
    if (st == -1) {
      set<int> se;
      se.insert(rand_ans());
      return se;
    }
    set<int> res;
    rep(p, n) {
      if (p == st || p == pt || p == gr.at(st).front()) continue;
      int now = gr.at(st).front(), bf = st;
      vector<int> v;
      v.push_back(now);
      bool chk = false;
      rep(c, n - 3 - 1) {
        int t = -1;
        for (auto nx : gr.at(now)) {
          if (nx == bf || nx == p || nx == pt) continue;
          if (t == -1)
            t = nx;
          else {
            chk = true;
            break;
          }
        }
        if (t == -1) chk = true;
        if (chk) break;
        bf = now;
        now = t;
        v.push_back(now);
      }
      if (!chk) {
        int add = 0, p2 = 1;
        for (auto i : v) {
          if (is_connect(i, p)) add += p2;
          p2 *= 2;
        }
        if (add >= m) continue;
        res.insert(add);
      }
    }
    return res;
  }

  Graph extract_graph(int l, int r) {
    Graph res(r - l);
    rep2(i, l, r) rep2(j, i + 1, r) {
      if (is_connect(i, j)) {
        res.add_edge(i - l, j - l);
      }
    }
    return res;
  }

  void sort_deg() {
    vector<pair<int, int>> v(n, {0, 0});
    rep(i, n) {
      int p = bitgr.at(i).count();
      v.at(i) = {-p, i};
    }
    sort(ALL(v));
    Graph nxg(n);
    rep(i, n) rep(j, n) {
      int ii = v.at(i).second, jj = v.at(j).second;
      if (is_connect(ii, jj)) {
        nxg.add_edge(i, j);
      }
    }
    swap_graph(nxg);
  }

  void add_noise(double e) {
    vector<int> p(n);
    rep(i, n) p.at(i) = i;
    shuffle(ALL(p), engine);
    Graph nxgr(n);
    rep(i, n) rep2(j, i + 1, n) {
      bool rv = (xor_shift() < e);
      bool connect = is_connect(i, j);
      if (connect ^ rv) {
        int ii = p.at(i), jj = p.at(j);
        nxgr.add_edge(ii, jj);
      }
    }
    swap_graph(nxgr);
  }

  string gr2st() {
    string res;
    rep(i, n) rep2(j, i + 1, n) {
      if (bitgr.at(i)[j])
        res.push_back('1');
      else
        res.push_back('0');
    }
    return res;
  }
  void test_printgr() {
    rep(i, n) {
      rep(j, n) { cerr << bitgr.at(i)[j] << " "; }
      cerr << endl;
    }
  }
  void test_printgr2() {
    rep(i, n) {
      cerr << i << " " << gr.at(i).size() << " : ";
      for (auto nx : gr.at(i)) cerr << " " << nx;
      cerr << endl;
    }
  }
  int get_popcount() { return popcount; }
  int get_deg(int i) { return bitgr.at(i).count(); }
  int get_n() { return n; }
  map<int, int> get_mp() { return degmp; }
};

int hamming_distance(Graph &l, Graph &r) {
  int res = 0;
  massert(l.get_n() == r.get_n(), "hamming_distance");
  rep(i, l.get_n()) { res += (l.bit_edges(i) ^ r.bit_edges(i)).count(); }
  return res;
}

void e0() {
  int n = 1 + 3;
  int p = 2;
  while (1) {
    if (p >= m) break;
    p *= 2;
    n++;
  }
  vector<Graph> gs(m, Graph(n));
  rep2(bit, 1, m) {
    gs.at(bit).add_edge(0, n - 3);
    rep(i, n - 4) gs.at(bit).add_edge(i, i + 1);
    gs.at(bit).add_edge(n - 4, n - 2);
    gs.at(bit).add_edge(n - 2, n - 1);

    rep(i, n - 3) {
      if ((bit & (1 << i)) != 0) gs.at(bit).add_edge(i, n - 1);
      gs.at(bit).add_edge(i, n - 2);
    }
  }
  cout << n << endl;
  for (auto &&g : gs) {
    cout << g.gr2st() << endl;
  }
  rep(qe, 100) {
    string ss;
    cin >> ss;
    Graph sg(n, ss);
    if (sg.get_popcount() == 0) {
      cout << 0 << endl;
      continue;
    }
    int t = sg.search_t();
    if (t == -1) {
      int ans = (1 << (n - 3)) - 1;
      if (ans >= m) ans = rand_ans();
      cout << ans << endl;
      continue;
    }
    auto se = sg.ss(t);
    if (se.empty())
      cout << rand_ans() << endl;
    else {
      int p = xor128() % se.size();
      auto itr = se.begin();
      while (p != 0) {
        itr++;
        p--;
      }
      cout << *itr << endl;
    }
    // massert(se.size() == 1, "se.size() == 1");
    // cout << *se.begin() << endl;
  }
}

vector<Graph> make_graph(bool test, int n, int xx) {
  if (!test) {
    cout << n << endl;
  }
  vector<Graph> gs(m, Graph(n));

  rep(mi, m) {
    int co = min(n, (mi + 1) * xx);
    rep(i, co) rep2(j, i + 1, co) gs.at(mi).add_edge(i, j);
    vector<int> b, w;
    rep(i, n) {
      if (i < co)
        b.push_back(i);
      else
        w.push_back(i);
    }
    int bc = b.size() * (b.size() - 1) / 2;
    int wc = w.size() * (w.size() - 1) / 2;
    int z = b.size() * w.size();
    int bi = 0, wi = 0;
    vector<bool> chk(w.size(), false);
    while (z != 0) {
      if ((wc + z) - bc <= 1) break;
      int nbi = b.at(bi), nwi = w.at(wi);
      massert(!gs.at(mi).is_connect(nbi, nwi),
              "is connect" + to_string(bi) + to_string(wi));
      if (nbi == 0) chk.at(wi) = true;
      gs.at(mi).add_edge(nbi, nwi);
      bc++;
      z--;
      bi++;
      wi = (wi + 1) % w.size();
      if (z != 0 && bi == (int)b.size()) {
        bi = 0;
        while (chk.at(wi)) {
          wi = (wi + 1) % w.size();
        }
      }
    }
    gs.at(mi).init_degmp();
    if (!test) {
      cout << gs.at(mi).gr2st() << endl;
    }
  }
  return gs;
}

double solve(bool test, vector<Graph> &gs, int xx, int n, int mode) {
  int test_wrong = 0;
  rep(qe, 100) {
    int test_ans = -1;
    string s;
    if (test) {
      test_ans = xor128() % m;
      Graph test_ans_graph = gs.at(test_ans);
      test_ans_graph.add_noise(e);
      s = test_ans_graph.gr2st();
    } else {
      cin >> s;
    }
    Graph ss(n, s);

    ss.sort_deg();
    int ans = -1;
    double mn = 1e18;
    auto fc = [&](int l, int r) -> double {
      if (l == r) return 0;
      int sum = 0;
      rep2(i, l, r) { sum += ss.get_deg(i); }
      double avg = (double)sum / (r - l);
      double vv = 0;
      rep2(i, l, r) {
        double p = ss.get_deg(i) - avg;
        vv += p * p;
      }
      if (mode == 1) {
        vv /= (r - l);
      }
      return vv;
    };

    rep2(add, 1, n + 1) {
      double s = fc(0, add) + fc(add, n);
      if (s < mn) {
        mn = s;
        int b = add / xx * xx, t = (add + xx - 1) / xx * xx;
        if (abs(add - b) <= abs(add - t)) {
          ans = max(1, add / xx) - 1;
        } else {
          ans = min(m, (add + xx - 1) / xx) - 1;
        }
      }
    }

    if (test) {
      if (ans != test_ans) test_wrong++;
    } else {
      cout << ans << endl;
    }
  }
  if (test) {
    double r = pow(0.9, test_wrong);
    r /= n;
    return round(1e9 * r);
  }
  return 0;
}

double complete_graph_old(int mode, bool test = false) {
  int n = min(100, m + 1);
  int xx = 1;
  n *= xx;
  auto gs = make_graph(test, n, xx);

  return solve(test, gs, xx, n, mode);
}

double complete_graph(int mode, bool test = false) {
  int n = min(100, m + 1);
  int xx = 100 / n;
  n *= xx;
  auto gs = make_graph(test, n, xx);

  return solve(test, gs, xx, n, mode);
}

int main() {
  cin >> m >> e;
  cerr << m << " " << e << endl;
  if (e == 0) {
    e0();
  } else {
    double oc0 = 0, nc0 = 0;
    double oc1 = 0, nc1 = 0;
    int nn = min(100, m + 1);
    int nx = 100 / nn;
    nn *= nx;
    auto nwgs = make_graph(true, nn, nx);
    int on = min(100, m + 1);
    auto odgs = make_graph(true, on, 1);
    int l = 0;
    while (time_from_clock() < 4.5) {
      oc0 += solve(true, odgs, 1, on, 0);
      nc0 += solve(true, nwgs, nx, nn, 0);
      oc1 += solve(true, odgs, 1, on, 1);
      nc1 += solve(true, nwgs, nx, nn, 1);
      l++;
    }
    cerr << l << " " << oc0 << " " << nc0 << " " << oc1 << " " << nc1 << " ";
    vector<double> v = {oc0, nc0, oc1, nc1};
    int mxi = max_element(ALL(v)) - v.begin();
    cerr << mxi << endl;
    if (mxi == 0)
      complete_graph_old(0);
    else if (mxi == 1)
      complete_graph(0);
    else if (mxi == 2)
      complete_graph_old(1);
    else if (mxi == 3)
      complete_graph(1);
    else
      massert(false);
  }
  cerr << time_from_clock() << endl;
  return 0;
}