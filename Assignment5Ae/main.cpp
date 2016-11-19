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
      Constructs a bank account with an initial balance.
   */
   BankAccount(double initialBalance);

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


#include <iostream>
#include <cmath>

using namespace std;



int main()
{
   BankAccount account1(10000);
   account1.deposit(1000);
   cout << "Balance: " << account1.getBalance() << endl;
   cout << "Expected: 11010" << endl;

   BankAccount account2(999);
   account2.deposit(100);
   cout << "Balance: " << account2.getBalance() << endl;
   cout << "Expected: 1099" << endl;

   BankAccount account3(1000);
   account3.deposit(100);
   cout << "Balance: " << account3.getBalance() << endl;
   cout << "Expected: 1110" << endl;
}



BankAccount::BankAccount(double initialBalance)
{
	if(initialBalance >= 1000)
	{
		balance = initialBalance + 10;
	}
	else
	{
		balance += initialBalance;
	}
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

void BankAccount::withdraw(double amount)
{
	balance -= amount;
}

double BankAccount::getBalance()
{
   return balance;
}




