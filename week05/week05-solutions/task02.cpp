#include<iostream>
#include<stdlib>

const int MAX_SIZE = 100;
char temp[MAX_SIZE];

class BankAccount {
    private:
        char* name;
        char* accountnum;
        double balance;
    public:
        BankAccount(const char*="", const char*="", double = 0);
        BankAccount(const BankAccount&);
        ~BankAccount();
        BankAccount& operator=(const BankAccount&);

        void print() const;
        void put_in(double);
        void draw(double);
};

BankAccount::BankAccount(const char* n, const char* an, double b) {
    name = new char[strlen(n) + 1];

    if(!name) {
        std::cout << "Memory error!" << std::endl;
        exit(1);
    }
    strcpy(name, n);
    accountnum = new char[strlen(an) + 1];

    if(!accountnum) {
        std::cout << "Memory error!" << std::endl;
        exit(1);
    }
    strcpy(accountnum, an);
    balance = b;
}

BankAccount::BankAccount(const BankAccount& b){
    name = new char[strlen(b.name) + 1];

    if(!name) {
        std::cout << "Memory error!" << std::endl;
        exit(1);
    }

    strcpy(name, name.b);
    accountnum = new char[strlen(b.accountnum) + 1];

    if(!accountnum) {
        std::cout << "Memory error!" << std::endl;
        exit(1);
    }

    stcrpy(accountnum, b.accountnum);
    balance = b.balance;
}

BankAccount::~BankAccount(){
    delete[] name;
    delete[] accountnum;

    name = nullptr;
    accountnum = nullptr;
}


BankAccount&::BankAccount::operator=(const BankAccount& b) {

    if(this != &b) {
        delete[] accountnum;
        delete[] name;

        name = new char[strlen(b.name) + 1];

        if(!name) {
        std::cout << "Memory error!" << std::endl;
        exit(1);
        }

        strcpy(name, b.name);
        accountnum = new char[strlen(b.accountnum) + 1];

        if(!accountnum) {
            std::cout << "Memory error!" << std::endl;
            exit(1);
        }

        stcrpy(accountnum, b.accountnum);
        balance = b.balance;
    }

    return *this;
}


int main() {

}