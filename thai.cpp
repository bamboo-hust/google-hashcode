#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a).size())
#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
    #define DEBUG 0
#else
    #define DEBUG 1
#endif
#define debug(a) if(DEBUG) cout<<#a<<" = "<<(a)<<endl
#define x first
#define y second
#define Time ((long long)(clock()*1000/CLOCKS_PER_SEC))
template<typename T>ostream&operator<<(ostream&os,vector<T>a){os<<"( ";for(T&x:a)os<<x<<" ";os<<")"<<endl;return os;}
template<typename T>ostream&operator<<(ostream&os,set<T>a){os<<"( ";for(T x:a)os<<x<<" ";os<<")"<<endl;return os;}
template<typename T>ostream&operator<<(ostream&os,stack<T>a){vector<T>b;while(sz(a))b.push_back(a.back()),a.pop();reverse(all(b));os<<b;return os;}
template<typename T>ostream&operator<<(ostream&os,queue<T>a){vector<T>b;while(sz(a))b.push_back(a.front()),a.pop();os<<b;return os;}
template<typename T>ostream&operator<<(ostream&os,priority_queue<T>a){vector<T>b;while(sz(a))b.push_back(a.top()),a.pop();os<<b;return os;}
template<typename X,typename Y>ostream&operator<<(ostream&os,pair<X,Y>a){os<<"("<<a.first<<" "<<a.second<<")";os.flush();return os;}
template<typename T>ostream&operator<<(ostream&os,complex<T>a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";os.flush();return os;}
template<typename X,typename Y>pair<X,Y>&operator-=(pair<X,Y>&A,pair<X,Y>B){A.x-=B.x;A.y-=B.y;return A;}
template<typename X,typename Y>pair<X,Y>&operator+=(pair<X,Y>&A,pair<X,Y>B){A.x+=B.x;A.y+=B.y;return A;}
//template<typename X,typename Y,typename Z>pair<X,Y>&operator*=(pair<X,Y>&A,Z n){A.x*=n;A.y*=n;return A;}
template<typename X,typename Y>X operator*(pair<X,Y>A,pair<X,Y>B){return A.x*B.x+A.y*B.y;}
template<typename X,typename Y>X operator^(pair<X,Y>A,pair<X,Y>B){return A.x*B.y-A.y*B.x;}
template<typename X,typename Y>X operator^(X a,Y b){return a^=b;}
template<typename X,typename Y>X operator+(X a,Y b){return a+=b;}template<typename X,typename Y>X operator-(X a,Y b){return a-=b;}
template<typename X,typename Y>X operator*(X a,Y b){return a*=b;}template<typename X,typename Y>X operator/(X a,Y b){return a/=b;}
typedef long long ll;typedef double dd;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<pii>vii;typedef vector<vi>vvi;
const int base=1000000007;
ll power(ll a,ll n,ll mod=base){a=a<0?(mod-(-a)%mod):(a%mod);ll r=1;while(n){if(n&1)r=r*a%mod;a=a*a%mod;n>>=1;}return r;}

//================================================================Head=========================================================================//
const int L = 10;

pair<int, vi> greedy(vi &a, int M){
    int ans = 0;
    vi ern;
    for (int i = 0; i < a.size(); i += L){
        int n = min(L, (int)a.size() - i);
        int maxSum = 0, bestMask = 0;
        for (int mask = 1 << n; mask--; ){
            int sum = 0;
            for (int j = 0; j < n; ++j) if (mask >> j & 1){
                sum += a[i+j];
            }
            if (ans + sum <= M && sum > maxSum){
                maxSum = sum;
                bestMask = mask;
            }
        }
        ans += maxSum;
        for (int j = 0; j < n; ++j) if (bestMask >> j & 1){
            ern.push_back(i + j);
        }
    }
    return make_pair(ans, ern);
}

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    srand(time(0));
    int n, M;
    cin >> M >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    vi id(n), b(n);
    iota(all(id), 0);
    pair<int, vi> ans(0, vi(0));
    for (int repeat = 100; repeat--; ){
        random_shuffle(all(id));
        if (repeat == 1) sort(all(id));
        if (repeat == 0) sort(all(id), greater<int>());
        for (int i = 0; i < n; ++i) b[i] = a[id[i]];
        auto tmp = greedy(b, M);
        if (tmp.first > ans.first){
            ans.first = tmp.first;
            ans.second.clear();
            for (int i : tmp.second) ans.second.push_back(id[i]);
        }
    }
    if (1) {//openfile
        char s[111];
        sprintf(s, "%c %d %d.out", argv[1][0], M, ans.first);
        freopen(s, "w", stdout);
    }
    cout << ans.second.size() << endl;
    sort(all(ans.second));
    for (int i : ans.second) cout << i << ' ';
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

}
