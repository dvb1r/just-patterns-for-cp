constexpr int32_t MOD = $MOD$;

template<typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a, swap(a, m);
        u -= t * v, swap(u, v);
    }
//    assert(m == 1);
    return u;
}

struct Mint {
    int32_t val;
//    int32_t MOD;

    constexpr Mint() : val(0) { }
    template <typename T>
    Mint(T x = 0) {
        if (-MOD <= x && x < MOD) val = x;
        else val = x % MOD;
        if (val < 0) val += MOD;
    }

    Mint& operator+=(const Mint& o) { (val + o.val >= MOD ? val = val + o.val - MOD : val = val + o.val); return *this; }
    Mint& operator-=(const Mint& o) { val = val - o.val < 0 ? val - o.val + MOD : val - o.val; return *this; }
    Mint& operator*=(const Mint& o) { val = val * 1ll * o.val % MOD; return *this; }
    Mint& operator/=(const Mint& o) { *this *= inverse(o.val, MOD); return *this; }
    template <typename T> Mint& operator+=(const T& o) { return *this += Mint(o); }
    template <typename T> Mint& operator-=(const T& o) { return *this -= Mint(o); }
    template <typename T> Mint& operator*=(const T& o) { return *this *= Mint(o); }
    template <typename T> Mint& operator/=(const T& o) { return *this /= Mint(o); }

    Mint& operator++() { return *this += 1; }
    Mint operator++(int) { Mint res(*this); return *this += 1; return res; }
    Mint& operator--() { return *this -= 1; }
    Mint operator--(int) { Mint res(*this); return *this -= 1; return res; }
    Mint operator-() { return Mint(-val); }
};

Mint operator+(const Mint& lhs, const Mint& rhs) { return Mint(lhs) += rhs; }
Mint operator-(const Mint& lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }
Mint operator*(const Mint& lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }
Mint operator/(const Mint& lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }

template<typename U> Mint operator+(const Mint& lhs, const U& rhs) { return Mint(lhs) += rhs; }
template<typename U> Mint operator+(const U& lhs, const Mint& rhs) { return Mint(lhs) += rhs; }

template<typename U> Mint operator-(const Mint& lhs, const U& rhs) { return Mint(lhs) -= rhs; }
template<typename U> Mint operator-(const U& lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }

template<typename U> Mint operator*(const Mint& lhs, const U& rhs) { return Mint(lhs) *= rhs; }
template<typename U> Mint operator*(const U& lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }

template<typename U> Mint operator/(const Mint& lhs, const U& rhs) { return Mint(lhs) /= rhs; }
template<typename U> Mint operator/(const U& lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }

bool operator<(const Mint& lhs, const Mint& rhs) { return lhs.val < rhs.val; }
template<typename U> bool operator<(const Mint& lhs, const U& rhs) { return lhs.val < rhs.val; }
template<typename U> bool operator<(const U& lhs, const Mint& rhs) { return lhs.val < rhs.val; }

bool operator>(const Mint& lhs, const Mint& rhs) { return lhs.val > rhs.val; }
template<typename U> bool operator>(const Mint& lhs, const U& rhs) { return lhs.val > rhs.val; }
template<typename U> bool operator>(const U& lhs, const Mint& rhs) { return lhs.val > rhs.val; }

bool operator<=(const Mint& lhs, const Mint& rhs) { return lhs.val <= rhs.val; }
template<typename U> bool operator<=(const Mint& lhs, const U& rhs) { return lhs.val <= rhs.val; }
template<typename U> bool operator<=(const U& lhs, const Mint& rhs) { return lhs.val <= rhs.val; }

bool operator>=(const Mint& lhs, const Mint& rhs) { return lhs.val >= rhs.val; }
template<typename U> bool operator>=(const Mint& lhs, const U& rhs) { return lhs.val >= rhs.val; }
template<typename U> bool operator>=(const U& lhs, const Mint& rhs) { return lhs.val >= rhs.val; }

bool operator==(const Mint& lhs, const Mint& rhs) { return lhs.val == rhs.val; }
template<typename U> bool operator==(const Mint& lhs, const U& rhs) { return lhs.val == rhs.val; }
template<typename U> bool operator==(const U& lhs, const Mint& rhs) { return lhs.val == rhs.val; }

template<typename U>
Mint power(const Mint& n, const U& k) {
    assert(k >= 0);
    Mint x = n, res = 1;
    U p = k;
    while (p) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

std::istream& operator>> (std::istream& in, Mint& x) { in >> x.val; return in; }
std::ostream& operator<< (std::ostream& out, const Mint& x) { out << x.val; return out; }
$END$
