#include <iostream>
using namespace std;

class ptrDataClass
{
public:
	void print() const;
	void setData();
	void destroyP();
	ptrDataClass(int sizeP=10);
	ptrDataClass(const ptrDataClass& otherObj); // copy constructor
	~ptrDataClass();
	const ptrDataClass&  operator==(const ptrDataClass& otherObj); // assignment overload
private:
	int x, lenP, *p;
}


void print() const
{
	cout << "x = " << x<<endl;
	cout << "p = ";
	for (int i = 0; i < lenP; i++)
		cout<<p[i]<<" ";
	cout<<endl;
}

void setData()
{
	cout<<"set x = "; cin>>x;
	cout<<"enter "<<lenP<<" numbers: ";
	for (int i = 0; i < lenP; i++)
		cin>>p[i];
	cout<<endl;
}

void destroyP()
{
	lenP=0;
	delete []p;
	p=NULL;
}

ptrDataClass(int sizeP)
{
	x=0;
	lenP = sizeP;
	p = new int[lenP];
}

~ptrDataClass()
{
	delete []p;
}

ptrDataClass(const ptrDataClass& otherObj)
{
	x = otherObj.x;
	lenP = otherObj.lenP;
	p = new int[lenP];
	for (int i = 0; i < lenP; i++)
		p[i] = otherObj.p[i];
}

const ptrDataClass&  operator==(const ptrDataClass& otherObj)
{
	x = otherObj.x;
	lenP = otherObj.lenP;
	p = new int[lenP];
	for (int i = 0; i < lenP; i++)
		p[i] = otherObj.p[i];
}