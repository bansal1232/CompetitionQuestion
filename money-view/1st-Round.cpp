/*
Given an array of size n that has the following specifications: 

Each element in the array contains either a policeman or a thief.
Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.
We need to find the maximum number of thieves that can be caught.


N K
N - int no of chars - 
P or T
Policemen can catch only one thief

k >= 0
N >= 1


K - int 

6 
[P T T P T T]
I  > i-k<= j <= i+k


6 3
T T P P T P -> 3
0 1 2 3 4 5

mark[0] =true
mark[1] =true
mark[]


T T P P T P
0 1 2 3 4 5
                i
             j

k = 2
T T T P P
             i
       j

k=1
P P T T
       i 
          j        


k = 1
P P T T P
0 1  2 3 4
              i
           j

if(j > i)
     ++i;
else
     ++j;

if(abs(i-j) <= k)
	++caught_theif;
   ++i,++j;
else {
	++j
}






6 1
T T P P T P -> 2
0 1 2 3 4 5
         pl
      th

*/

int getMaximumTheif(vector<int> arr, int N, int K) {

  int thief = 0;
  int police = 0;
  
while(thief < N && thief != ‘T’) ++thief;
while(police < N && police != ‘P’) ++police;

if(thief == N || police == N) return 0;

int max_thief = 0;

while(thief < N && police < N) {

  
   if (abs(police - thief) <= K) {
       ++max_thief; 
       ++police;
       ++thief;
  }
  else {
     if(thief > police) {  
        ++police;
    }
    else{  
     ++thief;
}
  }
   while(thief < N && thief != ‘T’) ++thief;
   while(police < N && police != ‘P’) ++police;
 
}
return max_thief;
}


/*





Builder DP: creational DP

n = 5

Class String = new ABC();
abc.setA(“”);
abc.setB(“”);
abc.setA();

Class Person {
   string name;
   string address;
   string phoneNo;

}

Class PersonBuilder {
  private string name;
   string address;
   string phoneNo;


public static Builder

  
  public static StringBuilder setName(string name) {
	this.name= name;
  }

 public static StringBuilder setName(string name) {

  }

public static Person build(){
Person p = new Person();
p.setName(this.name);
p.setAddress(this.address);

 
}
	
}

abc.builder().setA().setB().build();
*/