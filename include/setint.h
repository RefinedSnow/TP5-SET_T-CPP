#ifndef C_SETINT
#define C_SETINT

#include <iostream>
#include <ostream>

using namespace std;

class set_int{
	private:
	int *elements;
	int nbelements;
	int taille;
	
	public:
	set_int(int nb);
	set_int(const set_int& set);
	set_int& operator=(const set_int& set);
	int cardinal();
	int getTaille();
	int operator[](int numElement);

	friend set_int operator+(set_int& ensemble, int n);
	friend set_int operator-(set_int& ensemble, int n);
	friend int operator%(int n, const set_int& ensemble);
	friend ostream& operator<<(ostream& strm, const set_int& ensemble);
};
#endif