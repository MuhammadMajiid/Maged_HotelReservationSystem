#pragma once
using namespace std;

class human
{
private :
	int drycleaning;
	int spa;
	int nights;
	int rooms;
	int ext;

public :
	void setrooms(int r);
	int getrooms();
	int getcost(int r , int n);
	int drycleancost();
	int spacost();
	void makeAvailable(int rooms);
	int extend(int r, int ext);
	human();



};

