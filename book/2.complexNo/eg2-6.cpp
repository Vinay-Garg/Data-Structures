#include <iostream>
using namespace std;

class opOverClass
{
public:
	void print() const
	{
		cout << "("<<a<<", "<<b<<")";
	}

	opOverClass(int i, int j)
	{
		a=i;
		b=j;
	}
	opOverClass operator+(const opOverClass &right) const
	{
		opOverClass temp(0,0);
		temp.a = a + right.a;
		temp.b = b + right.b;
		return temp;
	}

	bool operator==(const opOverClass &right) const
	{
		return (a==right.a && b==right.b);
	}
	
	friend ostream& operator<<(ostream& osObj, const opOverClass &right)
	{
		osObj << "("<<right.a<<", "<<right.b<<")";
		return osObj;
	}

private:
	int a;
	int b;
};

int main(int argc, char const *argv[])
{
	opOverClass u(1, 1);
	u.print();
	opOverClass v(2, 2);
	v.print();
	
	cout << (u == v);
	
	cout << (u+v);

	return 0;
}
