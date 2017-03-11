#include <iostream>
using namespace std;
#include "cnHeader.h"

int main(int argc, char const *argv[])
{
	complexType num1(23, 34), num2 ,num3;

	cout <<"num1 = "<<num1<<endl;
	cout <<"num2 = "<<num2<<endl;

	cout <<"enter num2 = ";
	cin>>num2; 
	cout<<endl<<"num2 = "<<num2<<endl;

	num3 = num1+num2;
	cout<<"num3 = "<<num3<<endl;

	num3 = num1*num2;
	cout<<"num3 = "<<num3<<endl;

	return 0;
}
