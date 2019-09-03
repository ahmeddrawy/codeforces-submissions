//
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
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
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
int n ;
int arr[201];
int kadane (int &l , int &r ){
    int curr = 0 , mx = INT_MIN , ll = 0 ;
    r = -1 ;
    for (int i = 0; i <n ; ++i) {
        curr +=arr[i];
        if(arr[i] < 0){
            curr = 0 ;
            ll= i+1;
        }
        else if(curr >mx){
            mx = curr;
            r = i ;
            l = ll ;
        }
    }
    if(r== -1){
        r = l = -1;
        sort(arr , arr+ n);
        return arr[n-1];
    }
    else return mx ;

}

int main() {
    smile();
    int k ;
    cin >> n >> k ;
//    inN(arr ,n )
    vector<int > mvec(n);
    vector<int > cumm(n);
    inN(mvec , n );
    cumm = mvec ;

    lp(i,0,n){
        cumm[i] = mvec[i];
        if(i)
            cumm[i] +=cumm[i-1];
    }
    int  ans = INT_MIN   ;
    for (int left = 0; left <n ; ++left) {
        for (int right = left; right <n ; ++right) {
            priority_queue<int ,vector<int>, greater <>  > in ;
            priority_queue<int> out ;
            lp(i,0,left)
            out.push(mvec[i]);
            lp(i,right +1,n)
            out.push(mvec[i]);
            int s = 0 ;
            lp(i,left , right+1) {
                s+=mvec[i];
                in.push(mvec[i]);
            }
            int t = k ;
            while(!out.empty() && t && !in.empty() ) {
                int a = out.top(), b = in.top();
                out.pop();
                in.pop();
                if (a > b) {
                    s += a;
                    s -= b;
                    t--;
                } else break;
            }
            ans = max(ans , s);

        }
    }
    cout<<ans;




}