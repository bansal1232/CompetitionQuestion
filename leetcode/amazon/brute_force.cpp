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

void solve() {
  int i,j,n;
  cin>>n;

  queue<pair<int, int>>q;
  map<pair<int, int>, bool> mp;
  unordered_map<int, int> ans;
  q.push({0,0});
  mp[{0,0}] = 1;

  while(!q.empty()) {
    int top_elem = q.front().first;
    int top_elem_count = q.front().second;
    q.pop();

    int left = top_elem - top_elem_count - 1;
    int right = top_elem + top_elem_count + 1;
    
    if(ans.count(top_elem)) {
      ans[top_elem] = min(top_elem_count, ans[top_elem]);
    }
    else {
      ans[top_elem] = top_elem_count;
    }


    if(abs(left) < n and !mp.count({left, top_elem_count + 1})) {
      mp[{left, top_elem_count + 1}] = 1;
      q.push({left,top_elem_count + 1});
    }


    pair<int, int> pp_right={right, top_elem_count + 1};
    if(right < n and !mp.count(pp_right)) {
      mp[pp_right] = true;
      q.push(pp_right);  
    }
    
  }

  for(int i= 0; i<n; ++i)
    trace(i, ans[i]);
  
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


