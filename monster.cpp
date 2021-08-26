#include "monster.h"
#include <iostream>

monster::monster() : rooms(15), spa(50), drycleaning(30), nights(200)
{
}

void monster::setrooms(int r)
{
	rooms -= r;
}

int monster::getrooms()
{
	return rooms;
}

int monster::getcost(int r, int n)
{
	return nights*r*n;
}

int monster::drycleancost()
{
	return drycleaning;
}

int monster::spacost()
{
	return spa;
}

int monster::extend(int r, int ext)
{
	return nights* r* ext;
}

void monster::makeAvailable(int r)
{
	rooms += r;
}
