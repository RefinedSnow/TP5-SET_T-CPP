#include <iostream>
#include <ostream>
using namespace std;
template<typename T> T carre(T n){
	return n*n;
}
int main(){
	double i = 0;
	double n = 5;
	i = carre(n);
	cout << "Le carre de " << n << " vaut "<< i<<endl;
	return 0;
}