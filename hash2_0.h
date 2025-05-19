template <typename T>
struct Hash {
    //T can be Mint or ull
    vector<T> pow, pref, suff;
    T p;
    template <typename T1>
    Hash(const T1& s) {
        p = 239;
        int n = s.size();
        pow.resize(n, 1), pref.resize(n);
        for (int i = 1; i < n; ++i) pow[i] = pow[i - 1] * p;
        T hsh = 0;
        for (int i = 0; i < n; ++i) {
            hsh = hsh * p + s[i];
            pref[i] = hsh;
        }
    }
    template <typename T1>
    Hash(T1 s, bool f) {
        //f - need to fill pow, or not?
        reverse(s.begin(), s.end());
        p = 239;
        int n = s.size();
        suff.resize(n);
        if (f) pow.resize(n, 1);
        for (int i = 1; i < n; ++i) pow[i] = pow[i - 1] * p;
        T hsh = 0;
        for (int i = 0; i < n; ++i) {
            hsh = hsh * p + s[i];
            suff[i] = hsh;
        }
        reverse(suff.begin(), suff.end());
    }
    template <typename T1, typename T2>
    void build_debug(const T1& s, const T2& minimal_alphabet_element) {
        p = 10;
        int n = s.size();
        pow.resize(n, 1), pref.resize(n);
        for (int i = 1; i < n; ++i) pow[i] = pow[i-1] * p;
        T hsh = 0;
        for (int i = 0; i < n; ++i) {
            hsh = hsh * p + (s[i] - minimal_alphabet_element + 1);
            pref[i] = hsh;
        }
    }
    T get(int l, int r, bool f = false) {
        if (f) return suff[l] - (r < suff.size() - 1 ? suff[r + 1] * pow[r - l + 1] : 0);
        return pref[r] - (l < 1 ? 0 : pref[l - 1] * pow[r - l + 1]);
    }
};
