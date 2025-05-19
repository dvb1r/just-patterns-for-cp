//
// Created by dvb1r on 5/19/2025.
//

#ifndef UNTITLED_HASH2_0_H
#define UNTITLED_HASH2_0_H
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Hash {
    //T can be Mint or ull
    vector<T> pow, pref, suff;
    T p;
    Hash(const string& s) {
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
    Hash(string s, bool f) {
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
    void build_debug(const string& s) {
        p = 10;
        int n = s.size();
        pow.resize(n, 1), pref.resize(n);
        for (int i = 1; i < n; ++i) pow[i] = pow[i-1] * p;
        T hsh = 0;
        for (int i = 0; i < n; ++i) {
            hsh = hsh * p + (s[i] - 'a' + 1);
            pref[i] = hsh;
        }
    }
    T get(int l, int r, bool f = false) {
        if (f) return suff[l] - (r < suff.size() - 1 ? suff[r + 1] * pow[r - l + 1] : 0);
        return pref[r] - (l < 1 ? 0 : pref[l - 1] * pow[r - l + 1]);
    }
};

#endif //UNTITLED_HASH2_0_H
