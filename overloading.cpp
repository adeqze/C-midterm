#include <iostream>
#include <cassert>
using namespace std;

class fraction
{
	int numer, denom;
public:
	fraction(int = 0, int = 1);
	void operator!(void) const;		// print the fraction
	fraction& operator~(void);			// reduce the fraction
	fraction operator-(void) const;	// negative of fraction
	fraction operator*(void) const;	// reciprocal of fraction
	fraction& operator+=(const fraction&);
	fraction& operator-=(const fraction&);
	fraction& operator*=(const fraction&);
	fraction& operator/=(const fraction&);
	fraction operator+(int) const;
	fraction operator-(int) const;
	fraction operator*(int) const;
	fraction operator/(int) const;
	bool operator>(const fraction&) const;
	bool operator<(const fraction&) const;
	bool operator>=(const fraction&) const;
	bool operator<=(const fraction&) const;
	bool operator==(const fraction&) const;
	bool operator!=(const fraction&) const;
	fraction operator+(const fraction&) const;
	fraction operator-(const fraction&) const;
	fraction operator*(const fraction&) const;
	fraction operator/(const fraction&) const;
	fraction& operator++();			// prefix operator returns by reference
	fraction operator++(int);			// postix operator returns by value
};

// member function definitions
fraction::fraction(int n, int d)
{
	assert(d != 0);
	numer = n;
	denom = d;
}

void fraction::operator!(void) const {
	cout << numer << '/' << denom << endl;
}

fraction& fraction::operator~(void) {
	int min;
	// find the minimum of the denom and numer
	min = denom < numer ? denom : numer;
	for (int i = 2; i <= min; i++)
	{
		while ((numer % i == 0) && (denom % i == 0))
		{
			numer /= i;
			denom /= i;
		}
	}
	return *this;
}

fraction fraction::operator-(void) const {
	return fraction(-numer,denom);
}

fraction fraction::operator*(void) const {
	return fraction(denom,numer);
}

fraction& fraction::operator+=(const fraction& f) {
	numer = numer*f.denom+denom*f.numer;
	denom = denom*f.denom;
	return *this;
}

fraction& fraction::operator-=(const fraction& f) {
	*this += (-f);
	return *this;
}

fraction& fraction::operator*=(const fraction& f) {
	numer = numer*f.numer;
	denom = denom*f.denom;
	return *this;
}

fraction& fraction::operator/=(const fraction& f) {
	*this *= (*f);
	return *this;
}

bool fraction::operator>(const fraction& f) const {
	return (float) numer/denom > (float) f.numer/f.denom;
}

bool fraction::operator<(const fraction& f) const {
	return f>*this;
}

bool fraction::operator==(const fraction& f) const {
	return numer*f.denom == denom*f.numer;
}

bool fraction::operator!=(const fraction& f) const {
	return !(*this == f);
}

bool fraction::operator<=(const fraction& f) const {
	return !(*this > f);
}

bool fraction::operator>=(const fraction& f) const {
	return !(*this<f);
}

fraction fraction::operator+(const fraction& f) const {
	return fraction(numer*f.denom+denom*f.numer,denom*f.denom);
}

fraction fraction::operator-(const fraction& f) const {
	return fraction(numer*f.denom-denom*f.numer,denom*f.denom);
}

fraction fraction::operator*(const fraction& f) const {
	return fraction(numer*f.numer,denom*f.denom);
}

fraction fraction::operator/(const fraction& f) const {
	return (*this) * (*f);
}

fraction fraction::operator+(int i) const {
	return fraction(numer+i*denom,denom);
}

fraction fraction::operator-(int i) const {
	return (*this) + -i;
}

fraction fraction::operator*(int i) const {
	return fraction(numer*i,denom);
}

fraction fraction::operator/(int i) const {
	return fraction(numer,i*denom);
}

// prefix increment operator
fraction& fraction::operator++() {
	numer += denom;
	return *this;
}

// postfix increment operator
fraction fraction::operator++(int) {		// Note dummy int argument
	fraction temp(*this);
	++*this;							// call the prefix operator
	return temp;
}



int main(void)
{
	fraction f(3,4);           // initialize fraction f & g
	fraction g(1,2);
	cout << "!f ";  !f;
	cout << "!g ";  !g;
	cout << endl;
	cout << "-g ";  !-g;
	cout << "*g ";  !*g;
	fraction h = g + f;
	cout << endl;
	cout << "h=g+f " << " !h ";  !h;
	cout << "!~h ";  !~h;
	cout << endl;
	cout << "f+g ";  ! (f + g);
	cout << "f-g ";  ! (f - g);
	cout << "f*g ";  ! (f * g);
	cout << "f/g ";  ! (f / g);
	cout << endl;
	cout << "f+=g "; !~(f+=g);
	cout << "f-=g "; !~(f-=g);
	cout << "f*=g "; !~(f*=g);
	cout << "f/=g "; !~(f/=g);
	cout << endl;
	cout << "f<g " << (f<g) << endl;
	cout << "f>g " << (f>g) << endl;
	cout << "f==g " << (f==g) << endl;
	cout << "f!=g " << (f!=g) << endl;
	cout << "f<=g " << (f<=g) << endl;
	cout << "f>=g " << (f>=g) << endl;
	cout << endl;
	cout << "f+5 ";  !(f+5);
	cout << "f-5 ";  !(f-5);
	cout << "f*5 ";  !(f*5);
	cout << "f/5 ";  !(f/5);
	cout << endl;
	cout << "f+=5 "; f+=5;   cout << "!~f ";  !~f;  // How does this work?
	cout << "++f "; !++f; cout << "f="; !f; 
	cout << "f++ "; !f++; cout << "f="; !f; 
	return 0;
}
