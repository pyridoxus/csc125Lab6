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
#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;

class Array
{
	public:
		Array(void);
		Array(int n);
		Array(const Array &a);
		~Array();
		int getSize(void);
		int setValue(int n, float v);
		float *getAddress(void);	// Debugging
		float getValue(int n);
		void operator =(const Array &a);
		friend Array operator +(Array &a, Array &b);
		friend Array operator +(Array &a, float b);
		friend ostream &operator <<(ostream &output, const Array &a);
	private:
		float *f;
		int n;
};

#endif
