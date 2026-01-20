#include <bits/stdc++.h>
using namespace std;

// Aliases
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// Constants
const int MOD = 1e9 + 7;

// Fast I/O
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

// Loop
#define FOR1(a) for (int _ = 0; _ < a; ++_)
#define FOR2(i, a) for (int i = 0; i < a; ++i)
#define FOR3(i, a, b) for (int i = a; i < b; ++i)
#define FOR4(i, a, b, c) for (int i = a; i < b; i += (c))
#define FOR1_R(a) for (int i = (a) - 1; i >= 0; --i)
#define FOR2_R(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FOR3_R(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define all(x) x.begin(), x.end()

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;

// Utility functions
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
int LB(vector<T> &v, T a) { return lower_bound(all(v), a) - v.begin(); }
template <class T>
int UB(vector<T> &v, T a) { return upper_bound(all(v), a) - v.begin(); }
template <class T>
bool minimize(T &a, T b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
void sort_asc(vector<T> &v) { sort(all(v)); }
template <class T>
void sort_desc(vector<T> &v) { sort(all(v), greater<T>()); }
bool print_yes_no(bool condition, bool uppercase = true)
{
    cout << (condition ? (uppercase ? "YES\n" : "Yes\n") : (uppercase ? "NO\n" : "No\n"));
    return condition;
}
template <class T>
T vector_min(const vector<T> &a)
{
    assert(!a.empty());
    return *min_element(all(a));
}
template <class T>
T vector_max(const vector<T> &a)
{
    assert(!a.empty());
    return *max_element(all(a));
}
template <class T>
T vector_sum(const vector<T> &a) { return accumulate(all(a), T(0)); }
template <typename T>
constexpr T floor_div(const T &a, const T &b)
{
    return a / b;
}
template <typename T>
constexpr T ceil_div(const T &a, const T &b)
{
    return a / b + (a % b > 0);
}
template <typename T>
constexpr pair<T, T> div_mod(const T &a, const T &b)
{
    T quotient = a / b;
    return {quotient, a - quotient * b};
}
template <typename T>
int bitcount(T x) { return __builtin_popcountll(x); } // Counts set bits efficiently

template <typename T>
constexpr T mod_add(T a, T b, T mod)
{
    return ((a % mod) + (b % mod)) % mod;
}

template <typename T>
constexpr T mod_sub(T a, T b, T mod)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

template <typename T>
constexpr T mod_mul(T a, T b, T mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

// Fast Modular Exponentiation (Binary Exponentiation)
template <typename T>
constexpr T mod_pow(T base, T exp, T mod)
{
    T result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = mod_mul(result, base, mod);
        base = mod_mul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Modular Inverse using Fermat's Little Theorem (mod must be prime)
template <typename T>
constexpr T mod_inv(T a, T mod)
{
    return mod_pow(a, mod - 2, mod);
}

// Modular Division (Only valid if `mod` is prime)
template <typename T>
constexpr T mod_div(T a, T b, T mod)
{
    return mod_mul(a, mod_inv(b, mod), mod);
}
template <typename T>
constexpr T power(T base, T exp)
{
    T result = 1;

    while (exp > 0)
    {
        if (exp & 1)
            result *= base; // If exp is odd, multiply base with result
        base *= base;       // Square the base
        exp >>= 1;          // Divide exponent by 2
    }

    return result;
}

void solve()
{
}

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
