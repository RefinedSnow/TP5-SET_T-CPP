#include <iostream>
#include <ostream>
#include "setint.h"

using namespace std;

int main(){
	set_int myset(5);
	cout << "creation ok"<<endl;
	cout <<"taille : " << myset.getTaille()<<endl;
	cout << "nbelements : " << myset.cardinal()<<endl;
	set_int mycopy(myset);
	cout << "copy ok"<<endl;;
	cout <<"taille : " << mycopy.getTaille()<<endl;
	cout <<"nbelements : " << mycopy.cardinal()<<endl;
	set_int affect(6);
	affect = myset;
	cout << "affect ok" << endl;
	cout <<"taille : " << affect.getTaille()<<endl;
	cout <<"nbelements : " << affect.cardinal()<<endl;
	set_int copy(0);
	myset + 1;
	cout << "add ok" << endl;
	cout <<"taille : " << myset.getTaille()<<endl;
	cout <<"nbelements : " << myset.cardinal()<<endl;
	try{
		myset + 6;
		cout <<"taille : " << myset.getTaille()<<endl;
		cout <<"nbelements : " << myset.cardinal()<<endl;
		myset - 6;
		cout <<"taille : " << myset.getTaille()<<endl;
		cout <<"nbelements : " << myset.cardinal()<<endl;
		myset - 8;
		cout <<"taille : " << myset.getTaille()<<endl;
		cout <<"nbelements : " << myset.cardinal()<<endl;
	}catch (const char * err){
		cout << err << endl;
	}
	cout << 6%myset << endl;
	myset + 6;
	cout << myset;
	return 0;
}