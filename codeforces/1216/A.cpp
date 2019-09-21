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
    string s ; cin >> s;
    string res  = s;
    int cnt = 0 ;
    for (int i = 0; i <n ; i+=2) {
        if (s[i] == 'a' && s[i + 1] == 'b')continue;
        if (s[i] == 'a' && s[i + 1] == 'b')continue;
        if(s[i] == 'a'){
            if(s[i+1] != 'b') {
                cnt++;
                res[i+1] = 'b';
            }
        }
        else {
            if(s[i+1]!='a') {
                res[i+1] = 'a';
                cnt ++;
            }

        }
    }
    cout << cnt << endl<< res;

}