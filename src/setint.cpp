#include <iostream>
#include <ostream>
#include "setint.h"
using namespace std;

set_int::set_int(int nb){
	nbelements = 0;
	taille = nb;
	elements = new int[nb];
	cout << "construction" << endl;
}
set_int::set_int(const set_int& set) :set_int(set.taille){
	memcpy(elements,&set.elements,sizeof(int)*set.nbelements);
	cout << "copy" << endl;
}
set_int& set_int::operator=(const set_int& set){
	if(this == &set){
		return (*this);
	}
	if(taille != set.taille){
		delete[] elements;
		nbelements = set.nbelements;
		taille = set.taille;
		elements = new int[set.taille];
	}
	cout << "affectation" << endl;
	memcpy(elements,&set.elements,sizeof(int)*set.nbelements);
	return *this;
}
int set_int::cardinal(){
	return nbelements;
}
int set_int::getTaille(){
	return taille;
}

int set_int::operator[](int numElement){
	if(numElement >= nbelements){
		throw "Index out of bound";
	}
	return elements[numElement];
}

set_int operator+(set_int& ensemble, int n){
	if(ensemble.nbelements < ensemble.taille){
		ensemble.elements[ensemble.nbelements] = n;
		ensemble.nbelements++;
	}
	return ensemble;
}
set_int operator-(set_int& ensemble, int n){
	int j = 0;
	bool exist = false;
	for(int i = 0; i < ensemble.nbelements; i++)
	{
		if(ensemble.elements[i] == n){
			j=i;
			exist = true;
		}
	}
	if(exist && j!=0){
		for(int k = j ;k<ensemble.nbelements;k++){
			ensemble.elements[k] = ensemble.elements[k+1];
		}
	}
	if(!exist){
		throw "Element not found";
	}
	ensemble.nbelements--;
	return ensemble;
}
int operator%(int n, const set_int& ensemble){
	int exist = 0;
	for(int i = 0; i < ensemble.nbelements; i++)
	{
		if(ensemble.elements[i] == n){
			exist = 1;
		}
	}
	return exist;
}
ostream& operator<<(ostream& strm, const set_int& ensemble){
	strm << "[";
	for(int i = 0; i < ensemble.nbelements; i++)
	{
		if(i != ensemble.nbelements -1){
			strm << ensemble.elements[i] << ", ";
		}
		else{
			strm << ensemble.elements[i];
		}
	}
	strm << "]";
	return strm << endl;
}