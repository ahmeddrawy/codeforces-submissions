//
// Created by ahmed_drawy on 15/08/19.
// virtual contest sheet
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
    int s ,x1,x2,t1,t2,p,d; cin >>s>>x1>>x2>>t1>>t2>>p>>d;
//   s++;
    int dist = 0 ;
    if(d==1 ){
        if(x1<x2){
            if(p<=x1){
                cerr<<"a";
                dist = x2-p;
            }
            else {
                cerr<<"b";
//                dist = s -p+x2;
                dist = 2*s -p+x2;
            }
        }
        else {
            cerr<<"c";
            dist = 2*s - p -x2;
        }

    }
    else {
        if(x1<x2){
            cerr<<"d";
            dist = p+x2;
        }
        else {
            if(p>=x1){
                cerr<<"e";
                dist = p-x2;
            }
            else {
                cerr<<"f";
                dist = 2*s + p -x2;
            }
        }
    }
    double v1 = 1.0/t1;
    double v2 = 1.0/t2;
    cout << min(dist/v1 , abs(x2-x1) /v2);
}