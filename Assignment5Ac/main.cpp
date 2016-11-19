/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Karan
 */
#include <iostream>
#include <cmath>

using namespace std;
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

 private:
   double balance;
};

int main()
{
   BankAccount account1;
   account1.deposit(1000);
   account1.withdraw(100);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 899" << endl;

   BankAccount account2;
   account2.deposit(1000);
   account2.withdraw(100);
   account2.withdraw(100);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 798" << endl;
}



BankAccount::BankAccount()
{
   balance = 0;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

// Declare the withdraw method
void BankAccount::withdraw(double amount)
{
	balance = balance-amount-1;
}

double BankAccount::getBalance()
{
   return balance;
}



