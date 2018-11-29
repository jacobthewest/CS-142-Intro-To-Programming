#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
	double balance;
	double interestRate;
	string accountNumber;
public:
	BankAccount(double initialBalance);
	double getBalance();
	double getInterestRate();
	void deposit(double depoositAmmount);
	double withdraw(double withdrawAmount);
	double calculateInterest();
};

BankAccount::BankAccount(double initialBalance) {
	balance = initialBalance;
	interestRate = 0.00;
}
double BankAccount::getBalance() {
	return balance;
}
double BankAccount::getInterestRate() {
	return interestRate;
}
void BankAccount::deposit(double depositAmmount) {
	balance += depositAmmount;
}
double BankAccount::withdraw(double withdrawAmount) {
	if (withdrawAmount > balance) {
		cout << "Error, You be poor boi!" << endl;
		return -1;
	}
	else {
		return balance -= withdrawAmount;
	}	
}
double BankAccount::calculateInterest() {

}

class CheckingAccount : public BankAccount {

};
class SavingsAccount : public BankAccount {
private:
public:
};

int main() {

	
	return 0;
}