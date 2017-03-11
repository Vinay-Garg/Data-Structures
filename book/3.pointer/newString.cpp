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

