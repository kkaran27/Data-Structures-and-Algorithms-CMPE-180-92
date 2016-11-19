/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Karan
 */
/**
   A bank account has a balance that can be changed by
   deposits and withdrawals.
*/
class BankAccount
{
 public:
   /**
      Constructs a bank account with a zero balance.
   */
   BankAccount();

   /**
      Deposits money into the bank account.
      @param amount the amount to deposit
   */
   void deposit(double amount);

   /**
      Withdraws money from the bank account.
      @param amount the amount to withdraw
   */
   void withdraw(double amount);

   /**
      Gets the current balance of the bank account.
      @return the current balance
   */
   double getBalance();

   /**
      Gets the number of transactions of the bank account.
      @return the transaction count
   */
   double getTransactionCount();

 private:
   double balance;
   int transactions;
};

#include <iostream>

using namespace std;
int main()
{
   BankAccount account1;
   account1.deposit(1000);
   account1.withdraw(100);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 900" << endl;
   cout << account1.getTransactionCount() << endl;
   cout << "Expected: 2" << endl;

   BankAccount account2;
   account2.deposit(1000);
   account2.withdraw(100);
   account2.withdraw(100);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 800" << endl;
   cout << account2.getTransactionCount() << endl;
   cout << "Expected: 3" << endl;
}

BankAccount::BankAccount()
{
   balance = 0;
   transactions = 0;
}

void BankAccount::deposit(double amount)
{
	transactions++;
	balance += amount;
}

// Declare the withdraw method
void BankAccount::withdraw(double amount)
{
	transactions++;
	balance -= amount;

}

double BankAccount::getBalance()
{
   return balance;
}

double BankAccount::getTransactionCount()
{
	return transactions;
}


