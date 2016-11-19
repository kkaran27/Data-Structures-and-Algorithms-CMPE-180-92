/*
 * employee.h
 *
 *  Created on: Nov 9, 2016
 *      Author: Karan
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

using namespace std;

class Employee
{
 public:
   Employee(string name, double salary) {
      _name = name;
      _salary = salary;
   }
   bool operator==(const Employee& other) {
      return _name == other._name && _salary == other._salary;
   }
   string name() const { return _name; }
   double salary() const { return _salary; }
 private:
   string _name;
   double _salary;
};



#endif /* EMPLOYEE_H_ */
