#include <iostream>
#include <string>
using namespace std;

class BankAccount {
   private:
    string accountHolderName;
    double balance;

   public:
    BankAccount(string name, double initialBalance) {
        accountHolderName = name;
        balance = initialBalance;
    }
    // 잔액 조회
    double getBalance() const {  // 클래스 안의 변수를 손대지 않겠다?
        return balance;
    }
    // 입금
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << " deposited. Current balance: " << balance << endl;
        }
    }
    // 출금
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << " withdrawn. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};

int main() {
    BankAccount myAccount("Alice", 1000);

    // 잔액 조회
    cout << "Initial Balance: " << myAccount.getBalance() << endl;

    // 입금 및 출금
    myAccount.deposit(500);
    myAccount.withdraw(200);

    // 직접 접근 시도 (불가능)
    // myAccount.balance = 5000;
    // myAccount.accountHolderName = "Bob";

    return 0;
}