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
int a[N] ;

int n ;
string s ;
set<string> ans ;
bool visited[10] ;

void solve(int x, string temp){
    if(x == n){
        ans.insert(temp) ;
        return ;
    }

    for(int i = 0 ;i<n ;i++){
        if(visited[i])continue ;
        visited[i] = true ;
        temp+=s[i];
        solve(x+1, temp) ;
        visited[i] = false ;
        temp.pop_back() ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s ;
    n = s.length() ;

    solve(0, "") ;
    cout << ans.size() << endl ;

    for(auto it:ans){
        cout << it <<endl ;
    }

    

    return 0 ;
}