#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s ;
    cin >> s ;

    int max_so_far = 1, max_curr = 1, n ;
    n = s.length() ;

    for(int i = 1 ;i<n ;i++){
        if(s[i-1] == s[i]) max_curr++ ;
        else max_curr = 1 ;
        max_so_far = max(max_so_far, max_curr) ;
    }
    cout << max_so_far << endl ;

    return 0 ;
}