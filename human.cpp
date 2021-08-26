#include "human.h"
#include <iostream>





human::human() : rooms(5), spa(100), drycleaning(70), nights(500)
{
}

int human::extend(int r, int ext)
{
	return nights*r*ext;
}
 
	 void human::setrooms(int r)
 {
	 rooms -= r;
 }

	 int human::getrooms()
	 {
		 return rooms;
	 }

	 int human::getcost(int r, int n)
	 {
		 return nights*r*n;
	 }

	 int human::drycleancost()
	 {
		 return drycleaning;
	 }

	 int human::spacost()
	 {
		 return spa;
	 }

	 void human::makeAvailable(int r)
	 {
		 rooms += r;
	 }
