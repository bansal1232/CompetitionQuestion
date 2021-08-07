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

/*
23.03;31.85

'PENNY': .01,
'NICKEL': .05,
'DIME': .10,
'QUARTER': .25,
'HALF DOLLAR': .50,
'ONE': 1.00,
'TWO': 2.00,
'FIVE': 5.00,
'TEN': 10.00,
'TWENTY': 20.00,
'FIFTY': 50.00,
'ONE HUNDRED': 100.00
*/

#define ZERO "ZERO"
#define ERROR "ERROR"
#define TOTAL 12

void solve(){
      #ifdef LOCAL
freopen("/Users/bansal1232/Documents/Visual_C++/in","r",stdin);
//freopen("/Users/bansal1232/Documents/Visual_C++/out_other","w",stdout);
#endif
  string pp, cc,line;
   float notes[TOTAL] = { 100,50,20,10,5,2,1, 0.5, 0.25, 0.10, 0.05, .01 };
  unordered_map<float, string> mp {
    {100.0,"ONE HUNDRED"},
    {50,"FIFTY"},
    {20.0,"TWENTY"},
    {10,"TEN"},
    {5, "FIVE"},
    {2, "TWO"},
    {1, "ONE"},
    {0.5,"HALF DOLLAR" },
    {.25,"QUARTER"},
    {.10,"DIME"},
    {.05,"NICKEL"},
    {.01,"PENNY"}    
  }; 

  while (getline(cin, line)) {
      vector<string> ans;
      stringstream ss(line);
      getline(ss,pp,';');
      getline(ss,cc,';');

    float price = stof(pp);
    float cash = stof(cc);

    if(cash == price) {
      cout<<ZERO<<endl;
    }
    else if(cash <  price) {
      cout<<ERROR<<endl;
    }
    else {
    float amount = cash - price;
    
    for (int i = 0; i < TOTAL; i++) {
    if (amount >= notes[i]) {

        int noteCounter = amount / notes[i];

        if(i == TOTAL-1) {
          noteCounter=round(amount/notes[i]);
        }

        if(noteCounter <= 1)
          noteCounter = 1;

        double x = amount - notes[i];

        amount = amount - noteCounter * notes[i];
        amount = round(amount*100)/100.0;

        while(noteCounter) {
            ans.push_back(mp[notes[i]]);
            noteCounter--;
        }
    }
}


  }
  // sort(ans.begin(), ans.end());
  for(int i=0;i<ans.size()-1; ++i)
    cout<<ans[i]<<",";
  cout<<ans.back()<<endl;

  }
}
int main() {

  solve();
}
