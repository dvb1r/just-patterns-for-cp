//
// Created by dvb1r on 7/21/2024.
//

// #ifdef dvb1r
// #include "algo_debug.h"
// #include "Timer.h"
// #define debug(tc) dbg::watch(#tc, tc)
// #else
//     #define debug(...)
// #endif


#ifndef DEBUG_H
#define DEBUG_H
#include <bits/stdc++.h>

namespace dbg {
    inline std::string wrapper(const char x) {
        return std::string("'") + x + "'";
    }
    inline std::string wrapper(const std::string &x) {
        return std::string("") + '\"' + x + '\"';
    }
    inline std::string wrapper(const int &x) {
        return std::to_string(x);
    }
    inline std::string wrapper(const long long &x) {
        return std::to_string(x);
    }
    inline std::string wrapper(const long double &x) {
        return std::to_string(x);
    }
    inline std::string wrapper(const double &x) {
        return std::to_string(x);
    }
    inline std::string wrapper(const bool &x) {
        return x ? "true" : "false";
    }
    template<typename T1, typename T2>
    std::string wrapper(const std::pair<T1, T2> &p) {
        return "[" + wrapper(p.first) + ", " + wrapper(p.second) + "]";
    }

    template<typename T>
    std::string wrapper(const std::vector<T> &v) {
        std::string returning = "{";
        for(auto it = v.begin(); it != v.end(); ++it) {
            T x = *it;
            returning += wrapper(x);
            if(it+1 != v.end()) {
                returning += ", ";
            }
        }
        returning += "}";
        return returning;
    }
    template<typename T1, typename T2>
    std::string wrapper(const char *name, const std::map<T1, T2> mp) {
        std::string res = name;
        res += "->{";
        int cnt = 0;
        for (auto &[a, b]: mp) {
            cnt++;
            res += "[";
            res += wrapper(a) + ": " + wrapper(b);
            res += ']';
            if (cnt < mp.size())
                res += ", ";
        }
        res += "}";
        return res;
    }

    template<typename T1, typename T2>
    void watch(const char *name, const std::map<T1, T2> mp) {
        std::cout << name << "->" << "{";
        int cnt = 0;
        for (auto &[a, b]: mp) {
            cnt++;
            std::cout << "[";
            std::cout << wrapper(a) << ": " << wrapper(b);
            std::cout << ']';
            if (cnt < mp.size())
                std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }

    template<typename T1, typename T2>
    void watch(const char *name, const std::unordered_map<T1, T2> mp) {
        std::cout << name << "->" << "{";
        int cnt = 0;
        for (auto &[a, b]: mp) {
            cnt++;
            std::cout << "[";
            std::cout << wrapper(a) << ": " << wrapper(b);
            std::cout << ']';
            if (cnt < mp.size())
                std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }

    template<typename T>
    void watch(const char *name, const std::vector<std::vector<T>> &v) {
        std::cout << name << ": ";
        std::cout << '{';
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0)
                for (int x = 0; x < std::strlen(name) + 2; ++x)
                    std::cout << ' ';
            std::cout << wrapper(v[i]);
            if(i < v.size()-1) std::cout<<","<<std::endl;
        }
        std::cout << "}" << std::endl;
    }

    template<typename T>
    void watch(const char *name, const std::vector<T> &v) {
        std::cout << name << ": " << wrapper(v) << std::endl;
    }

    template <typename T>
    void watch(const char *name, const std::set<T> &s) {
        std::vector<T> v;
        for(auto &x : s) v.push_back(x);
        watch(name, v);
    }
    template <typename T>
    void watch(const char *name, const std::multiset<T> &s) {
        std::vector<T> v;
        for(auto &x : s) v.push_back(x);
        watch(name, v);
    }

    template<typename T>
    void watch(const char *name, const T &x) {
        std::cout << name << ": ";
        std::cout << wrapper(x) << std::endl;
    }
    template<typename T, typename... Tail>
    void watch(T x, Tail... tail) {
        watch(x);
        watch(tail...);
    }
}

namespace stress {
    inline std::vector<long long> generate_random_vector(long long n, long long distmin = 1, long long distmax = 100) {
        std::vector<long long> a(n);
        std::random_device rd;
        std::uniform_int_distribution dist(distmin, distmax);
        for(int i = 0; i < n; ++i) a[i] = dist(rd);
        return a;
    }
    //generate a vector which is 1...n, and then do smth using next_permutation
    inline std::vector<long long> gen_vec(long long n) {
        std::vector<long long> a(n);
        std::iota(a.begin(), a.end(), 1);
        return a;
    }
    inline std::vector<long long> vector_of_equal_elements(long long &n, long long &elem) {
        std::vector<long long> a(n);
        for(auto &x : a) x = elem;
        return a;
    }
}

#define debug(tc) dbg::watch(#tc, tc)
#endif //DEBUG_H
