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
#include <iostream>
using namespace std;

int main(void)
{
  Array a1( 3 );

  a1.setValue( 0, 1.0 );
  a1.setValue( 1, 22.0 );
  a1.setValue( 2, 12.2 );

  Array a2( 3 );
  a2.setValue( 0, 3.3 );
  a2.setValue( 1, 44.5 );
  a2.setValue( 2, 21.7 );

  Array tmp;
  tmp = a1 + a2;
  cout << tmp;

  Array tmp2;
  tmp2 = tmp + 10.0;
  cout << tmp2;

	return 0;
}
