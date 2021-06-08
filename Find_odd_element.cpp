/*
Elements are occuring in pairs, find odd elements which doesn't occurs in pair.
arr = {1, 1, 2, 2, 3}  -> 3
arr = {7,7, 5, 9, 9, 2, 2} -> 5
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


int solve(vector<int> arr) {
    int n=arr.size();

    int low = 0, high = n-1;

    while(high - low > 2) {

        int mid = low + (high - low) >> 1;

        if( (mid - low + 1) & 1) { // left side odd
            if(mid + 2 <= high and arr[mid+1] == arr[mid+2]) // right side even and perfect
                high = mid;
            else
                low = mid;

        }
        else { // left is even
            if(mid - 1 >= low and arr[mid - 1] == arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    int xor_ans = 0;

    for(int i=low; i<=high; ++i)
        xor_ans ^= arr[i];

    return xor_ans;
}


int main()
{
    vector<int>arr={1,1,3,8,8};
    auto ans = solve(arr);
    trace(ans);
}

