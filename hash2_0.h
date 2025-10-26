//
// Created by dvb1r on 5/19/2025.
//

#ifndef UNTITLED_HASH2_0_H
#define UNTITLED_HASH2_0_H
#include <bits/stdc++.h>
using namespace std;
template<class C>
struct HASH {
    vector<C> pref, pow, suff;
    int p = 239;

    template <typename T>
    HASH(T a, int n, int p = 239) : pref(n + 1), suff(n + 1), pow(n + 1, 1) {
        for (int i = 0; i < n; ++i) {
            pow[i + 1] = pow[i] * p;
            pref[i + 1] = pref[i] * p + a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = suff[i + 1] * p + a[i];
        }
    }

    C operator()(int l, int r) {
        if (l > r) return suff[r] - suff[l + 1] * pow[l - r + 1];
        return pref[r + 1] - pref[l] * pow[r - l + 1];
    }
};

#endif //UNTITLED_HASH2_0_H




