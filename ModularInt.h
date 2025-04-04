//
// Created by dvb1r on 11/25/2024.
//

#ifndef MODULARINT_H
#define MODULARINT_H
#include <bits/stdc++.h>
const int mod = 1e9 + 7;

struct Mint {
    int32_t val;
    int32_t MOD;
    Mint(int32_t x = 0, int32_t md = 1e9 + 7) : val(x % md), MOD(md) {}

    Mint operator+(const Mint& o) const {return {(val + o.val >= MOD ? val + o.val - MOD : val + o.val), MOD};}
    Mint operator-(const Mint& o) const {return {(val - o.val < 0 ? val - o.val + MOD : val - o.val), MOD};}
    Mint operator*(const Mint& o) const {return {(int32_t)((val * 1ll * o.val) % MOD), MOD};}
    bool operator>(const Mint& o) const {return val > o.val;}
    bool operator<(const Mint& o) const {return val < o.val;}
    bool operator>=(const Mint& o) const {return val >= o.val;}
    bool operator<=(const Mint& o) const {return val <= o.val;}
    Mint operator+=(const Mint& o) {(val + o.val >= MOD ? val = val + o.val - MOD : val = val + o.val); return *this;}
    Mint operator*=(const Mint& o) {val = val * 1ll * o.val % MOD; return *this;}
    Mint operator-=(const Mint& o) {val = val - o.val < 0 ? val - o.val + MOD : val - o.val; return *this;}
    Mint operator%(const Mint& o) const {return {val % o.val, MOD};}
    bool operator==(const Mint& o) const {return val == o.val;}
    [[nodiscard]] Mint pow(int64_t k) const {
        Mint rs = 1;
        Mint x = *this;
        while (k > 0) {
            if (k & 1) rs *= x;
            x *= x;
            k >>= 1;
        }
        return rs;
    }
    Mint operator/(const Mint& o) const {return *this * o.pow(MOD - 2);}
    Mint operator/=(const Mint& o) {*this = *this / o; return *this;}
};
std::istream& operator>> (std::istream& in, Mint& x) {
    x = Mint(); in >> x.val; return in;
}
std::ostream& operator<< (std::ostream& out, const Mint& x) {
    out << x.val; return out;
}

#endif //MODULARINT_H
