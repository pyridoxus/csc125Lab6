//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "Array.h"

Array::Array(void)
{
//	cout << "Empty Constructor " << this << endl;	// Debugging
	this->n = 0;
	this->f = 0;
	return;
}

Array::Array(int n)
{
//	cout << "Initialize Constructor " << this << endl;	// Debugging
	this->n = n;
	this->f = new float[n];
	return;
}

Array::Array(const Array &a)
{
//	cout << "Copy Constructor " << this << " from " << &a << endl;	// Debugging
	if(f)	delete[] this->f;
	*this = a;
	return;
}

Array::~Array()
{
//	cout << "Destructor " << this << endl; 	// Debugging
	if(f) delete[] this->f;
	return;
}

int Array::getSize(void)
{
	return this->n;
}

int Array::setValue(int n, float v)
{
	if((n >= 0) && (n < this->n))
	{
		this->f[n] = v;
		return 0;	// index in range
	}
	return 1;	// index out of range
}

float *Array::getAddress(void)
{
	return this->f;	// This is for printing object to cout, and also debugging
}

float Array::getValue(int n)
{
	return this->f[n];
}

void Array::operator =(const Array &a)
{
	int d;
//	cout << "Array " << this << " = Array " << &a << endl;	// Debugging
	if(this != &a)	// Don't copy itself
	{
		if(f) delete[] this->f;
		this->n = a.n;
		this->f = new float[this->n];
		for(d = 0; d < this->n; d++) this->f[d] = a.f[d];
	}
	return;
}

Array operator +(Array &a, Array &b)
{
	int c, d;
//	cout << "Array = Array + Array" << endl;	// Debugging
	// If arrays a and b are different sizes, only use the number of floats
	// equal to the smallest array (to prevent accessing outside an array)
	if(a.getSize() < b.getSize()) c = a.getSize();
	else c = b.getSize();
	Array n(c);
	for(d = 0; d < c; d++) n.setValue(d, a.getValue(d) + b.getValue(d));
	return n;
}

Array operator +(Array &a, float b)
{
	int d;
//	cout << "Array = Array + float" << endl;	// Debugging
	Array n(a.getSize());
	for(d = 0; d < a.getSize(); d++) n.setValue(d, a.getValue(d) + b);
	return n;
}

ostream &operator <<(ostream &output, const Array &a)
{
	output << "Size: " << a.n << endl;
	output << "Array addr: " << a.f << endl;
	output << "Array Contents:" << endl;
	for(int b = 0; b < a.n; b++) output << a.f[b] << endl;
	return output;
}


