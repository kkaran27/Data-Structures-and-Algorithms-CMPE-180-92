/*
 * main.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Karan
 */
/*
   Implement a function called boxInfo that computes the surface
   area AND the volume of a box.
   Choose appropriate types for the parameters and
   the return value.
   @param a, b, c the side lengths
   @param surfaceArea set to the surface area
   @param volume set to the volume
*/
void boxInfo(double a, double b, double c, double& surfaceArea, double& volume)
{
   surfaceArea = 2*(a*b + b*c + a*c);
   volume = a*b*c;
}



