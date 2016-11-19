/*
 * Box.h
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */

#ifndef BOX_H_
#define BOX_H_


class Box
{
 public:
   Box();
   Box(int v);
   Box(const Box& other);
   ~Box();
   Box& operator=(const Box& other);
   int value() const;
   void value(int v);
   static int objects();
 private:
   int _value;
   static int _objects;
};






#endif /* BOX_H_ */
