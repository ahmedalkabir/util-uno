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

// you must write OUTPUT as first template parameter 
// otherwise it will not work properly 
// if you need inverse output just write true inside constructor parameter
GPIO<OUTPUT, A1, A2, A3> output_a1_a2_a3(false);
void setup() {
}

void loop() {
  // setup the pins high
  output_a1_a2_a3.high();
  delay(500);
  // setup the pins low
  output_a1_a2_a3.low();
  delay(500);
  // or 
  // in case you want inline method
  (GPIO<OUTPUT, A1, A2, A3>(true)).high();
  delay(500);
  (GPIO<OUTPUT, A1, A2, A3>(true)).low();
  delay(500);
}

```
