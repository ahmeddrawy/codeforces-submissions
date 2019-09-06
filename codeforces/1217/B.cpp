
//
// Created by ahmed_drawy on 03/09/19.
/// Educational Codeforces Round 72 (Rated for Div. 2)
#include <bits/stdc++.h>
#include <string.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
//bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
//    return  x.first != y.first ? x.first > y.first : x.second < y.second ;
//}
bool sortpair( const  pair <int  , pair<int , int> > & x, const pair <int ,  pair<int , int> > & y){
    return  x.first != y.first ? x.first > y.first : x.second.first >y.second.first ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}

int main() {
    smile();
    int t;
    cin >> t;
    while (t--) {
        int h, d, n, x;
        cin >> n >> x;
        int mx = 0 , mxdff= 0 ;
        lp(i, 0, n) {
            cin >> d >> h;
            mxdff= max(mxdff , d-h);
            mx = max(mx , d);
        }
        if(mx >= x){
            cout << 1 << endl;
            continue;
        }
        if (mxdff <= 0 ) {
            cout << -1 << endl;
            continue;
        }
        cout << (x-mx + mxdff -1) /mxdff + 1 <<endl;
        continue;

    }
}
