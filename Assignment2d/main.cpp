/*
 * main.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Karan
 */
/**
   We have four t-shirts, one of which is extra-large.
   Write a function that takes the weights of four people
   and returns the weight of the person who should get
   the t-shirt, i.e. the heaviest one.
*/
int xlshirt(int w1, int w2, int w3, int w4)
{
	int w;
   if(w1>w2 && w1>w3 && w1>w4){
	   w=w1;
   }else if(w2>w1 && w2>w3 && w2>w4){
	   w=w2;
   }else if(w3>w1 && w3>w2 && w3>w4){
	   w=w3;
   }else{
	   w=w4;
   }
   return w;
}




