///Codeforces Round #587 (Div. 3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}



int main(){
    smile();
    int n ; cin >> n ;
    vector<pii>vec(n);
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        vec[i] = {x,i};
    }
    sort(vec.rbegin() , vec.rend());

    ll res = 0 ;
    map <int , int > indices;
    for (int j = 0; j <n ; ++j) {
        res+=vec[j].first*j + 1;
    }
    cout << res<<endl;
    for (int j = 0; j <n ; ++j) {
        cout << vec[j].second + 1 << " ";
    }

}