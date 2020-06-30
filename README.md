# util-uno
I created this library to help me in some projects and it's going to improve and add new features
with time.

in this project I created a new simple idea that can help me to control list of  pins at once
without to bother my self to repeat digitalWrite again and again just one simple function 
can change state of pins at once 

how you can use it ?? well, it's really simple just include the util-uno library

and follow the example below 

```c++
#include <util-uno.hpp>

void setup()
{
  // put your setup code here, to run once:

  // set pins as output
  io::setPin<io::output, 7, 8, 9, 10, 11, 12, 13>();
  
  // set pins as input
  io::setPin<io::input, 2, 3, 4>();

  // write HIGH to pins
  io::writePin<io::high, 7, 8, 9, 10, 11, 12, 13>();

  delay(5000);

  // write low to some of pins
  io::writePin<io::low, 7, 9, 11, 13>();
}

void loop()
{
  // put your main code here, to run repeatedly:
  io::writePin<io::low, 7, 8, 9, 10, 11, 12, 13>();
  delay(1000);
  io::writePin<io::high, 7, 8, 9, 10, 11, 12, 13>();
  delay(1000);
}

```