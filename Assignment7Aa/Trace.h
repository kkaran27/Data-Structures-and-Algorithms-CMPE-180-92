/*
 * Trace.h
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */

#ifndef TRACE_H_
#define TRACE_H_


#include <string>
using namespace std;

class Trace
{
 public:
   Trace(string s);
   Trace(const Trace& other);
   Trace& operator=(const Trace& other);
   ~Trace();
 private:
   string str;
};


#endif /* TRACE_H_ */
