#ifndef UTIL_UNO_H_
#define UTIL_UNO_H_

// I created this library to help me in some projects and it's going to improve and add new features
// with time.

// in this project I created a new simple idea that can help me to control list of  pins at once
// without to bother my self to repeat digitalWrite again and again just one simple function
// can change state of pins at once

#include <Arduino.h>

template<uint8_t T, uint8_t... Args>
class GPIO {
  public:
    GPIO(bool inverse = false){
    }
    void high() {};
    void low() {};
};

template<uint8_t... Args>
class GPIO<OUTPUT, Args...>{
  public:
    GPIO(bool inverse){
      _inverse = inverse;
      _set_output(Args...);
    }
    void high(){
      if(not _inverse){
        _set_pin_high(0, Args...);
      } else {
        _set_pin_low(0, Args...);
      }
    }
    void low(){
      if(not _inverse){
        _set_pin_low(0, Args...);
      } else {
        _set_pin_high(0, Args...);
      }
    }
  private:
    void _set_output(uint8_t pin){
      pinMode(pin, OUTPUT);
    }

    template<typename... Pins>
    void _set_output(uint8_t pin, Pins... args){
      _set_output(pin);
      _set_output(args...);
    }

    void _set_pin_high(uint8_t pin){
      digitalWrite(pin, HIGH);
    }

    void _set_pin_low(uint8_t pin){
      digitalWrite(pin, LOW);
    }

    template<typename... Pins>
    void _set_pin_high(uint8_t pin, Pins... args){
      _set_pin_high(pin);
      _set_pin_high(args...);
    }

    template<typename... Pins>
    void _set_pin_low(uint8_t pin, Pins... args){
      _set_pin_low(pin);
      _set_pin_low(args...);
    }
    
    bool _inverse = false;
};

}; // namespace io

#endif
