#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[30] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, ans = "" ;
    int n , count = 0, idx = -1 ;

    cin >> s ;

    n = s.length() ;

    for(int i = 0 ;i<n ; i++){
        a[s[i]-'A']++ ;
    }
    for(int i = 0 ;i<26 ;i++){
        if(a[i]&1){
            idx = i ;
            count++ ;
        }
    }

    if(count>1){
        cout <<"NO SOLUTION"<<endl ;
        return 0 ;
    }

    ans = string(a[idx], (idx+'A')) ;
    for(int i = 0 ;i<26 ;i++){
        if(i == idx)continue ;
        ans = string(a[i]/2, (i+'A')) + ans + string(a[i]/2, (i+'A')) ;
    }
    cout << ans <<endl ;

    return 0 ;
}