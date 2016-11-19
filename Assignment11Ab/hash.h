/*
 * hash.h
 *
 *  Created on: Nov 9, 2016
 *      Author: Karan
 */

#ifndef HASH_H_
#define HASH_H_

#include <vector>

using namespace std;

const int EMPTY = 0x80000000;
int hashCode(int x, int n);
int find(const vector<int>& table, int element);




#endif /* HASH_H_ */
