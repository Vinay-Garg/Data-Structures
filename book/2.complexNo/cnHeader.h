#ifndef cn_
#define cn_

#include <iostream>
using namespace std;
class complexType
{
public:
	void setComplex(const double &, const double &);
	complexType(double=0, double=0);
	complexType operator+(const complexType&) const;
	complexType operator*(const complexType&) const;
	bool operator==(const complexType& otherComplex) const;

	friend ostream& operator<<(ostream& osObj, const complexType &complex)
	{
	osObj<<"("<<complex.realPart<<","<<complex.complexPart<<")";
	return osObj;
	}

	friend istream& operator>>(istream& isObj, complexType &complex)
	{
	char ch;
	isObj>>ch;
	isObj>>complex.realPart;
	isObj>>ch;
	isObj>>complex.complexPart;
	isObj>>ch;
	return isObj;
	}

private:
	double realPart;
	double complexPart;
};

void complexType::setComplex(const double& real, const double& imag)
{	
	realPart = real;
	complexPart = imag;
}

complexType::complexType(double real, double imag)
{
	realPart = real;
	complexPart = imag;
}

complexType complexType::operator+(const complexType& otherComplex) const
{
	complexType temp;
	temp.realPart = realPart + otherComplex.realPart;
	temp.complexPart = complexPart + otherComplex.complexPart;
	return temp;
}

complexType complexType::operator*(const complexType& otherComplex) const
{
	complexType temp;
	temp.realPart = (realPart * otherComplex.realPart) - (complexPart * otherComplex.complexPart);
	temp.complexPart = (realPart * otherComplex.complexPart) + (complexPart * otherComplex.realPart);
	return temp;
}

bool complexType::operator==(const complexType& otherComplex) const
{
	return(realPart==otherComplex.realPart && complexPart==otherComplex.realPart);
} 
#endif
