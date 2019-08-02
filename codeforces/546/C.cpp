
//
// Created by ahmed_drawy on 02/08/19.
//  812C

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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}

int main() {
    smile();
    int  n, k ; cin >> n ;
    cin >> k ;
    deque<int > q1;
    deque<int > tempq1;
    deque<int > q2;
    deque<int > tempq2;
    lp(i,0,k){
        int x;
        cin >> x;
        q1.push_back(x);
    }
    cin >> k ;
    lp(i,0,k){
        int x;
        cin >> x;
        q2.push_back(x);
    }
    tempq1= q1;
    tempq2= q2;
    int cnt = 0;
    while (true){
        if(tempq1.empty() || tempq2.empty()  ){
            cout<<cnt <<" ";
            if(tempq1.empty())cout<<2;
            if(tempq2.empty())cout<<1;
            break;
        }
        if(cnt>200){
            cout<<-1<<endl;
            break;
        }
        cnt++;
        int curr1 =tempq1.front();
        int curr2 =tempq2.front();
        tempq1.pop_front();
        tempq2.pop_front();
        if(curr1 > curr2){
            tempq1.push_back(curr2);
            tempq1.push_back(curr1);
        }
        else {
            tempq2.push_back(curr1);
            tempq2.push_back(curr2);
        }

    }
}
