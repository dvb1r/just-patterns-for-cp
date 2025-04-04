//
// Created by dvb1r on 11/25/2024.
//

#ifndef HASH_H
#define HASH_H

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

#include "ModularInt.h"

template<typename t>
void init(vector<Mint>& pow, vector<ull>& pow2, vector<Mint>& pref, vector<ull>& pref2, t s, bool rev = false) {
    int n = s.size();
    if (rev) reverse(s.begin(), s.end());
    int32_t p = 239;
    pow.resize(n); pow2.resize(n); pref.resize(n); pref2.resize(n);
    pow[0] = 1;
    pow2[0] = 1;
    for (int i = 1; !rev && i < n; ++i) {
        pow[i] = pow[i-1] * p;
        pow2[i] = pow2[i-1] * p;
    }
    Mint hsh = 0;
    ull hash2 = 0;
    for (int i = 0; i < n; ++i) {
        pref[i] = hsh * p + s[i];
        pref2[i] = hash2 * p + s[i];
        hsh = pref[i]; hash2 = pref2[i];
    }
    if (rev) reverse(pref.begin(), pref.end());
    if (rev) reverse(pref2.begin(), pref2.end());
    if (rev) reverse(s.begin(), s.end());
}

template<typename t>
t gethash(int l, int r, const vector<t>& pow, const vector<t>& pref, bool rev = false) {
    assert(l >= 0);
    if (rev) {
        return (t)(pref[l] - (r < pref.size() - 1 ? pref[r + 1] * pow[r - l + 1] : 0));
    }
    return (t)(pref[r] - (l < 1 ? 0 : pref[l - 1] * pow[r - l + 1]));
}

#endif //HASH_H
