/*
Find all valid path from first index(0,0) to last position(n-1,m-n)
1 represent wall
0 valid path
*/

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

#define WALL 1

bool valid(int new_x, int new_y, int n, int m) {
    return (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) ? false : true;
}
int X[] = {0,1};
int Y[] = {1,0};

typedef pair<int,int>  pp;

struct info {
    vector<pp> q_vec;
    int x_ind;
    int y_ind;
};

void print_path (vector<pp> &vec) {
    for(const auto &x: vec)
        cout<<x.first<<x.second<<", ";
    cout<<endl;
}


class Solution {
public:
    int pathCount(vector<vector<int>>& arr) {

        queue<info> Q;
        vector<pp>temp;
        temp.push_back({0,0});
        Q.push({ {{0,0}}, 0, 0});
        
        int n = arr.size();
        
        int m = arr[0].size();

        int total_path_cnt = 0;

        while(!Q.empty()) {
            auto x  = Q.front().x_ind;
            auto y  = Q.front().y_ind;
            auto temp_vec = Q.front().q_vec;

            Q.pop();

            for(int i=0; i < 2; ++i) {
        
                int new_x = X[i] + x;
                int new_y = Y[i] + y;
        
                if(valid(new_x, new_y, n, m) and arr[new_x][new_y] != WALL) {
                    temp_vec.push_back( {new_x, new_y}  );

                    if(new_x == n - 1 and new_y == m - 1) {
                        print_path(temp_vec);
                        total_path_cnt++;
                        continue;
                    }
                    Q.push({temp_vec, new_x, new_y});
                    temp_vec.pop_back();
                }
             }

        }
        return total_path_cnt;
    }
};



int main() {
    Solution *sol = new Solution();
    vector<vector<int>> vec = { 
        {0,0,0,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };

    int ans=sol->pathCount(vec);
    trace(ans);
}
