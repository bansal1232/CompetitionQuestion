#include<bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

#define int long long
/*
k*k + k  - 2*target = 0; 
k = (-1 + sqrt(1+ 8 * target) ) / 2;
*/
void solve() {
  int i,j,n, ans;
  cin>>n;
  for (int i = 0; i < n; i++)
  { 
      double root = (-1 + sqrt(1 + 8 * i)) / 2.0;
      if(root == ceil(root))
        ans = root;
      else {
        int k = ceil(root);
        int near_target = abs((k * (k + 1)) / 2 - i);
        
        if(near_target & 1) {
            if(k & 1)
                ans = k + 2;
            else 
                ans = k + 1;
        }
        else 
            ans = k;
    }
    trace(i, ans) ;
  }
}

signed main() {
int t;
#ifdef LOCAL
freopen("/Users/bansal1232/Documents/Visual_C++/in","r",stdin);
//freopen("/Users/bansal1232/Documents/Visual_C++/out_other","w",stdout);
#endif
  cin >> t;
  while (t--) {
    solve();
  }
}


