//
// Created by ahmed_drawy on 17/08/19.
// virtual contest Educational Codeforces Round 70
#include <bits/stdc++.h>
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
typedef long long               ll;
//typedef first                    ft;
//typedef second                   sd;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;
ll mod(ll x) {
    return (x%modul + modul)%modul;
}
ll gcd(ll a , ll b)
{
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}
int main() {
    smile();
    int t ; cin >>t;
    while (t--){
        string s1 , s2; cin >>s1 >> s2;
        int sz1 = s1.size();
        int sz2 = s2.size();
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());

        int ret2 = 0 ;
        for (int i = 0; i <sz2 ; ++i) {
            if(s2[i] == '1'){
                ret2 = i ;
                break;
            }
        }
        int ret1 = -1 ;
        for (int j = ret2; j <sz1 ; ++j) {
            if(s1[j] == '1'){
                ret1 = j ;
                break;
            }
        }
        if(ret1<= ret2 || ret1 ==-1){
            cout<<"0\n";
        }
        else {
            cout <<ret1 - ret2<<'\n';
        }


    }

}