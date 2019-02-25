#include<bits/stdc++.h>
using namespace std;
#define FIXED_DEPOSIT "Fixed Deposit"

enum amountType{DEBIT, CREDIT, INTEREST, CREATED};
string amountTypeStr[4] = {"debit", "credit", "interest", "created"};

string offer1 = "Offer1", offer2 = "Offer2";
unordered_map<string, int>accountCreate, transaction,creditCount, fdAmount,fdTransaction;
int const offer1Amount = 10, fdInterest=10;
int times = 0;
vector<string>names;

struct allStatementsTypes
{
    string way;
    short type;
    float amount;
    allStatementsTypes() {}
    allStatementsTypes(string way, short type, float amount) : way(way), type(type), amount(amount)
    {
    }
}allStatements;

map<string, vector<allStatementsTypes> > statement;
unordered_map<string, float> balance;
void showBalance()
{
    for(int i=0; i<times; ++i)
    {
        cout << names[i]<< " " << balance[names[i]];
        if(fdAmount.find(names[i]) != fdAmount.end())
        {
            cout << " " << fdAmount[names[i]];
        }
            cout << endl;
    }
}

void fdTransactionPerson(string person)
{
    if(fdAmount.find(person) != fdAmount.end())
    {
    fdTransaction[person]++;
    if(balance[person] < fdAmount[person])
    {
        fdAmount.erase(person);
        fdTransaction.erase(person);
    }
    else if(fdTransaction[person] == 5)
    {
        balance[person] += 10;
        statement[person].emplace_back(FIXED_DEPOSIT, INTEREST, fdInterest);
    }
}
}
void transferMoney( string person1, string person2, float amount)
{
    if(balance.find(person1) == balance.end())
    {
        cerr << "Account of " << person1 << " doesn't exist\n";
        exit(1);
    }
    else if (balance.find(person2) == balance.end())
    {
        cerr << "Account of " << person2 << " doesn't exist\n";
        exit(1);
    }
    else if (balance[person1] - amount < 0)
    {
        cerr << "Insufficient balance, amount can't be transferred\n";
        exit(1);
    }
    else
    {
        balance[person1] -= amount;
        balance[person2] += amount;

        ++transaction[person1];
        ++transaction[person2];



        fdTransactionPerson(person1);
        fdTransactionPerson(person2);
        statement[person1].emplace_back(person2, DEBIT, amount);
        statement[person2].emplace_back(person1, CREDIT, amount);
        // offer 1
        if (balance[person1] == balance[person2])
        {
            balance[person1] += 10;
            balance[person2] += 10;

          statement[person1].emplace_back(offer1, CREDIT, offer1Amount);
        statement[person2].emplace_back(offer1, CREDIT, offer1Amount);
        }
    }

   // int money1 =
}
bool cmp(pair<int, string>p1, pair<int, string>p2)
{
    if(p1.first != p2.first)
    {
        return p1.first > p2.first;
    }
    else if(balance[p1.second] != balance[p2.second])
    {
        return balance[p1.second] > balance[p2.second];
    }
    else
    {
        return accountCreate[p1.second] < accountCreate[p2.second];
    }
}
void fetchOffer2()
{
    vector<pair<int, string>>vec;
    for(const auto x: transaction)
    {
        vec.emplace_back(x.second, x.first);
    }

    sort(vec.begin(), vec.end(), cmp);


    balance[vec[0].second ] +=10;
    balance[vec[1].second ] +=5;
    balance[vec[2].second ] +=2;
}
void createFD(string name, float amount)
{
    if(balance[name] < amount)
    {
        cout << "FD can't created\n";
        exit(1);
    }
    fdAmount[name] = amount;
    statement[name].emplace_back(FIXED_DEPOSIT, CREATED, amount);
}
int main()
{
     freopen("in.c","r",stdin);
    string command, a, b, name, person1, person2, line;
    float amount;

    while(getline(cin, line))
    {
    stringstream cinstr(line);
    cinstr >> command;

    if (command == "CreateWallet"){
        cinstr >> name >> amount;
        names.emplace_back(name);
        balance[name] = amount;
        accountCreate[name] = times++;
    }

    else if (command ==  "Overview"){
            cout << endl;
        showBalance();
    }

    else if (command == "TransferMoney"){
        cinstr >> person1 >> person2 >> amount;
        transferMoney(person1, person2, amount);
        }

    else if (command == "Statement"){
        cinstr >> name;
        cout<<"\n";
        for(const auto person: statement[name])
        {
            cout << person.way << " " << amountTypeStr[person.type] << " " << person.amount << "\n";
        }
    }
    else if(command == "Offer2")
    {
        fetchOffer2();
    }
    else if(command == "FixedDeposit")
    {
        cinstr >> name >> amount;
        createFD(name, amount);
    }
    }
	return 0;
}
