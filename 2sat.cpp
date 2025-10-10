struct _2SAT {
    int n;
    vector<vector<int>> g, gt;
    vector<int> topsort, used;
    int timer;
    _2SAT(int N) : n(N), g(2 * N), gt(2 * N) {}

    void add_edge(int u, int v) {
        //u => j
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    void add_clause(int x, int y) {
        //x || y
        add_edge(x ^ 1, y);
        add_edge(y ^ 1, x);
    }

    void dfs(int v) {
        used[v] = 1;
        for (int u : g[v]) if (!used[u]) dfs(u);
        topsort[n * 2 - 1 - timer++] = v;
    }

    void dfs2(int v, int comp) {
        used[v] = comp;
        for (int u : gt[v]) {
            if (used[u]) continue;
            dfs2(u, comp);
        }
    }

    vector<int> solve() {
        topsort.assign(2 * n, 0), used.assign(2 * n, 0);
        timer = 0;
        for (int i = 0; i < 2 * n; ++i) if (!used[i]) dfs(i);
        used.assign(2 * n, 0);
        int c = 0;
        for (int v : topsort) {
            if (!used[v]) {
                c++;
                dfs2(v, c);
            }
        }
        vector<int> ret(n, -1);

        for (int i = 0; i < n; ++i) {
            if (used[2 * i] == used[2 * i + 1]) return {-1};
            ret[i] = used[i * 2] > used[i * 2 + 1];
        }

        return ret;
    }
};
