// codechef plagiarism algo sucks 
// #goForCodeforces
#include <bits/stdc++.h>

using namespace std;

#define int                    long long int
#define F                      first
#define S                      second
#define si                     set <int>
#define vi                     vector <int>
#define pii                    pair <int, int>
#define vpi                    vector <pii>
#define vpp                    vector <pair<int, pii>>
#define mii                    map <int, int>
#define mpi                    map <pii, int>
#define spi                    set <pii>
#define endl                   "\n"
#define sz(x)                  ((int) x.size())
#define all(p)                 p.begin(), p.end()
#define double                 long double
#define que_max                priority_queue <int>
#define que_min                priority_queue <int, vi, greater<int>>
#define bug(...)               __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)               for(auto x : a) cout << x << " "; cout << endl
#define print1(a)              for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)          for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define MEM(a, b)             memset(a, (b), sizeof(a))
#define FOR(i, j, k, in)     for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in)     for (int i=j ; i>=k ; i-=in)
#define REP(i, j)             FOR(i, 0, j, 1)
#define RREP(i, j)             RFOR(i, j, 0, 1)
#define rall(cont)             cont.end(), cont.begin()
#define FOREACH(it, l)         for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C)         assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back


inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

inline int binary_search(vector<int>array, int x, int l, int r){
    if(r>=l){
    int mid = l + (r-l)/2;
    if(array[mid] == x)return mid;
    if(array[mid]>x) return binary_search(array,x,l,mid-1);
    return binary_search(array,x,mid+1,r);
    }
    return -1;
}

inline int gcd(int a, int b){
    if (a == 0)return b;
    if (b == 0)return a;
    if (a == b)return a;
    if (a > b)return gcd(a-b, b);
    return gcd(a, b-a);
}

inline int XOR(int x, int y){
    int res = 0;
    for (int i = 31; i >= 0; i--){
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
       bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
       res <<= 1;
       res |= xoredBit;
    }
    return res;
}

inline bool isPowerOfTwo(int n){
   if(n==0)return false;
   return (ceil(log2(n)) == floor(log2(n)));
}

inline int removeMSB(int i){
    int a = i & ~(i-1);
    return ((i-a)/2);
}

inline bool isPalindrome(string str, int low, int high){
    while (low < high){
        if (str[low] != str[high])return false;
        low++;
        high--;
    }
    return true;
}

inline int isWhat(int i){
    // function to return 1 if it is zero
    // returns 0 if it is negative
    // returns 2 if it is positive
    return 1 + (i >> 31) - (-i >> 31);
}


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int N = 200005;
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int EPS = 1e-9;
const int PI = 3.1415926535897932384626433832795;
const double pi=acos(-1.0);

void solve(){
    int n,r;
    cin>>n>>r;
    int ans=0;
    vector<int>a,b;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    
    for(int i=0;i<n;i++){
        v.push_back(make_pair(a[i]-b[i],make_pair(a[i],b[i])));
    }
    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        while(r>=v[i].second.first){
            int curr=(r)/v[i].second.first;
            curr+=(1&0);
            ans+=curr;
            ans+=(1&0);
            r-=(curr*(v[i].second.first));
            r-=(1&0);
            r+=(curr*(v[i].second.second));
            r+=(1&0);
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    }
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}