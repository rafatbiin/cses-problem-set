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
bool visited[N] ;

int big2(int n){
    if(n == 0)return 1 ;

    ll result = big2(n/2)%M ;
    result = ((result%M)*(result%M))%M ;

    if(n&1) result = ((result%M)*(2%M))%M ;
    return result%M ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;

    cout << big2(n) << endl;

    return 0 ;
}