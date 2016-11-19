/*
 * main.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Karan
 */
/*
 * main.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Karan
 */
#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;

const int range = 100;

int main(){
	bool a[range];
	for(int i = 1; i <= range; i++ ){
		a[i]=true;
	}
	for(int i=2; i < sqrt(range); i++){
		int count=0;
		for(int j = 2; j < i; j++){
			if(i%j == 0){
				count++;
			}
		}
		if(count != 0){
			a[i] = false;
		}
	}
	for(int i=2; i < sqrt(range); i++){
		if(a[i] == true){
			for(int j = sqrt(range); j <= range; j++){
				if(j%i == 0){
					a[j] = false;
				}
			}
		}
	}
	cout << "Primes:" << endl;
	cout << endl;
	for(int i = 1; i <= range; i++){
		a[1] = false;
		if(a[i] == true){
			cout << setw(4) << i ;
			if(i%10 == 0){
				cout << endl;
			}
		}
		else{
			cout << setw(4) << "." ;
			if(i%10 == 0){
				cout << endl;
			}
		}

	}


	//Testing Goldbach's Conjecture
	cout << endl << "Test of Goldbach's Conjecture:" << endl;

	for(int i = 4; i <= range ; i+=2){
		int count_num = 1;
		vector<int> copy_j;
		vector<int> copy_k;
		bool flag = true;
		for(int j = 2; j < range; j++){
			for(int k = 2; k < range; k++){
				if(a[j] == true && a[k] == true){
					if(i == j+k){

						for(int m=0; m<copy_k.size(); m++){
							if( j == copy_k.at(m)){
								//cout << "********************" << endl;
								flag=false;
							}
						}
						copy_j.push_back(j);
						copy_k.push_back(k);
						count_num++;
						if(flag){
						if(count_num <= 2){
							cout << endl;
							cout << setw(4) << i << ":";
						}
						else{
							cout << setw(4) << " " <<" " ;
						}
							cout << setw(4) << j << setw(4) << k << endl;
					}
					}
				}
			}
		}
	}
	return 0;
}







