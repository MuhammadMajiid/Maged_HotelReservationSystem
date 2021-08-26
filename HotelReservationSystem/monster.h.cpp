#pragma once
class monster
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
	int getcost(int r, int n);
	int drycleancost();
	int spacost();
	int extend(int r , int ext);
	void makeAvailable(int r);
	monster();

};
