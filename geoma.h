//
// Created by dvb1r on 11/25/2024.
//

#ifndef GEOMA_H
#define GEOMA_H

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

template<typename T>
struct pointt {
    T x, y;

    pointt() : x(0), y(0) {}

    pointt(T _x, T _y) : x(_x), y(_y) {}

    pointt operator+(const pointt &o) const {
        return pointt(x + o.x, y + o.y);
    }

    pointt operator-(const pointt &o) const {
        return pointt(x - o.x, y - o.y);
    }

    T operator*(const pointt &o) const {
        return (x * o.x + y * o.y);
    }

    pointt operator*(const T k) const {
        return pointt(x * k, y * k);
    }

    pointt operator/(const T k) const {
        return pointt(x / k, y / k);
    }

    T operator%(const pointt &o) const {
        return (x * o.y - o.x * y);
    }

    bool operator==(const pointt &o) const {
        return x == o.x && y == o.y;
    }

    T len2() const {
        return x * x + y * y;
    }

    ld len() const {
        return sqrt(len2());
    }

    bool operator<(const pointt<T>& o) const {
        if (*this % o != 0) return *this % o > 0;
        return len2() < o.len2();
    }
};

using point = pointt<ld>;

istream &operator>>(istream &in, point &a) {
    in >> a.x >> a.y;
    return in;
}

ostream &operator<<(ostream &out, const point &a) {
    out << a.x << ' ' << a.y;
    return out;
}

#endif //GEOMA_H
