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
int a[N],tail[N] ;
bool visited[N] ;

int solve(int l, int r, int key){
    int mid ;

    while(l<r){
        mid = (l+r)/2 ;
        if(tail[mid] >=key)r = mid ;
        else l = mid+1 ;
    }
    return r ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, len = 1 ;
    cin >> n ;
    for(int i = 0 ; i<n ;i++)cin >>a[i] ;
    tail[1] = a[0] ;

    for(int i = 0 ;i<n ; i++){
        if(a[i] > tail[len]){
            len++ ;
            tail[len] = a[i] ;
        }else {
            tail[solve(1,len, a[i])] = a[i] ;
        }
    }
    cout << len << endl; 



    

    return 0 ;
}