#ifndef C_SETT
#define C_SETT

#include <iostream>
#include <ostream>

using namespace std;

template<typename T> class set_T{
	private:
	T *elements;
	int nbelements;
	int taille;
	
	public:
	set_T(int nb);
	set_T(const set_T& set);
	set_T& operator=(const set_T& set);
	int cardinal();
	int getTaille();
	T operator[](int numElement);

	friend set_T operator+(set_T& ensemble, T n){
		if(ensemble.nbelements < ensemble.taille){
		ensemble.elements[ensemble.nbelements] = n;
		ensemble.nbelements++;
	}
	return ensemble;
	}
	friend set_T operator-(set_T& ensemble, T n){
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
	friend int operator%(T n, const set_T& ensemble){
		int exist = 0;
		for(int i = 0; i < ensemble.nbelements; i++)
		{
			if(ensemble.elements[i] == n){
				exist = 1;
			}
		}
		return exist;
	}
	friend ostream& operator<<(ostream& strm, const set_T& ensemble){
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
};

template<typename T>
set_T<T>::set_T(int nb){
	nbelements = 0;
	taille = nb;
	elements = new T[nb];
	cout << "construction" << endl;
}
template<typename T>
set_T<T>::set_T(const set_T& set) :set_T(set.taille){
	memcpy(elements,&set.elements,sizeof(T)*set.nbelements);
	cout << "copy" << endl;
}
template<typename T>
set_T<T>& set_T<T>::operator=(const set_T& set){
	if(this == &set){
		return (*this);
	}
	if(taille != set.taille){
		delete[] elements;
		nbelements = set.nbelements;
		taille = set.taille;
		elements = new T[set.taille];
	}
	cout << "affectation" << endl;
	memcpy(elements,&set.elements,sizeof(T)*set.nbelements);
	return *this;
}
template<typename T>
int set_T<T>::cardinal(){
	return nbelements;
}
template<typename T>
int set_T<T>::getTaille(){
	return taille;
}
template<typename T>
T set_T<T>::operator[](int numElement){
	if(numElement >= nbelements){
		throw "Index out of bound";
	}
	return elements[numElement];
}
#endif