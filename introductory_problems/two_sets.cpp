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

    ll n, temp, sum = 0, count = 0 ;
    cin >> n ;

    temp = (n*(n+1))/2LL ;

    if(temp &1){
        cout <<"NO"<<endl ;
        return 0 ;
    }

    cout <<"YES"<<endl; 

    temp/=2 ;

    for(int i = n ; i>=1 && temp>0 ; i--){
        if(i<=temp){
            count++ ;
            visited[i] = true ;
            temp-=i ;
        }
    }

    cout <<count << endl ;
    for(int i = 1 ;i<=n ;i++){
        if(visited[i])cout <<i << ' ' ;
    }
    cout <<endl ;
    cout <<n-count << endl ;
    for(int i = 1 ; i<=n ;i++){
        if(!visited[i])cout<<i<<' ' ;
    }


    return 0 ;
}