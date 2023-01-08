// First round
1. Max Profit cutting rod problem:
  Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

  length   | 1   2   3   4   5   6   7   8  
  --------------------------------------------
  price    | 1   5   8   9  10  17  17  20

2. Merging two sorted arrays with O(1) extra space:
  You are given two sorted arrays. We need to merge these two arrays such that the initial numbers (after complete sorting) are in the first array and the remaining numbers are in the second array in O(1) extra space

  Examples: 
  Input: ar1[] = {10}, ar2[] = {2, 3}
  Output: ar1[] = {2}, ar2[] = {3, 10}  

  Input: ar1[] = {1, 5, 9, 10, 15, 20}, ar2[] = {2, 3, 8, 13}
  Output: ar1[] = {1, 2, 3, 5, 8, 9}, ar2[] = {10, 13, 15, 20}


#include <bits/stdc++.h>
using namespace std;
/*
38641 -> 48


15324 -> 15342
15342 -> 15423
15432 -> 51234,   21345
54-> -1
9774 -> -1

153642
012345
   i
154632 -> sort from ith -> = 154236
arr[3] > arr[2]

87563 -> 87635
01234
   i
87653 -> Sort from ith -> 87635
arr[i-1] >= arr[i]
5 > 6

15432
25431
21345

123 -> 132
132 -> 213
213 -> 231
231 -> 312


int[] input = {1,5,3,2,4}; 
*/
// To execute C++, please define "int main()"
int next_max_digit_ind(vector<int> nums, int ind) {
    for(int i=nums.size()-1; i > ind; --i) {
        if(nums[i] > nums[ind]) {
            return i;
        }
    }
    return -1;
}
vector<int> get_next_greater_number(vector<int> nums) {
    int len = nums.size();
    // bool find = false;
    for(int ind = len-1; ind > 0; ind--) {
        if(nums[ind] > nums[ind-1]) {
            int next_greater_num_ind = next_max_digit_ind(nums, ind-1);
            if (next_greater_num_ind == -1) {
                break;
            }
            swap(nums[ind-1], nums[next_greater_num_ind]);
            sort(nums.begin()+ind, nums.end());
            return nums;
        }
    }
    return {-1};
}

int main() {
  vector<int> nums = {1};
  auto next_greater_numbers = get_next_greater_number(nums);
  for(auto val: next_greater_numbers) {
      cout << val;
  }
  return 0;
}

class House {
    private int floorNumber;
    private List<Rooms> rooms;
    public int getTotalFloors(){
        return floorNumber;
    }
}

class Area {
    public calculateArea(int len) {

    }
    public calculateArea(Double radius) {

    }
}

map.put(12, 45)
map.put(12, 45)

int a
AtomicInteger a - CS algo, compare and swap
synchronized{
    
}

interceptors and filters

A -> B

incercept{
    
}

Employee
eid, ename, did 
e1, krish, d1 
e2, mark, d1 
e3, alice, d2 


Departmaent 
did, dname 
d1, it 
d2, hr 
d3, operations 

it, 2 
hr, 1
operations, 0


select Departmaent.dname, count(Departmaent.dname) from Departmaent join ON from Employee group by did



class Circle {
    public calculateArea(int radius) {

    }

    public calculateArea(Double radius) {

    }
}

int main{
    Area area = new Circle();
    area.calculateArea(78)

}

class Building {
    List<House> House;
}

--- IS a relationship
class Bird {
    void fly{}
}

class sparrow extends Bird{

}
