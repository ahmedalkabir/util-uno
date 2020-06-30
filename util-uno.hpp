#ifndef UTIL_UNO_H_
#define UTIL_UNO_H_

// I created this library to help me in some projects and it's going to improve and add new features
// with time.

// in this project I created a new simple idea that can help me to control list of  pins at once
// without to bother my self to repeat digitalWrite again and again just one simple function
// can change state of pins at once

#include <Arduino.h>

namespace io
{

struct mode_t
{
};

struct status_t
{
};

struct input_t : mode_t
{
};
struct output_t : mode_t
{
};

struct hight_t : status_t
{
};
struct low_t : status_t
{
};

typedef input_t input;
typedef output_t output;

typedef hight_t high;
typedef low_t low;

// setPin Function
template <typename T, uint8_t... Args>
class setPin
{
public:
    // static void create(){

    // };
    setPin() {}
};

template <uint8_t... Args>
class setPin<input, Args...>
{
public:
    setPin()
    {
        _setPin(Args...);
    }

private:
    static void _setPin(uint8_t pin)
    {
        pinMode(pin, INPUT);
    }

    template <typename... Pins>
    static void _setPin(uint8_t pin, Pins... args)
    {
        _setPin(pin);
        _setPin(args...);
    }
};

template <uint8_t... Args>
class setPin<output, Args...>
{
public:
    setPin()
    {
        _setPin(Args...);
    }

private:
    static void _setPin(uint8_t pin)
    {
        pinMode(pin, OUTPUT);
    }

    template <typename... Pins>
    static void _setPin(uint8_t pin, Pins... args)
    {
        _setPin(pin);
        _setPin(args...);
    }
};

// writePin Function
template <typename T, uint8_t... Args>
class writePin
{
public:
    writePin() {}
};

template <uint8_t... Args>
class writePin<low, Args...>
{
public:
    writePin(bool write = true)
    {
        if (write)
        {
            _writePin(Args...);
        }
    }

    void write()
    {
        _writePin(Args...);
    }

private:
    static void _writePin(uint8_t pin)
    {
        digitalWrite(pin, LOW);
    }

    template <typename... Pins>
    static void _writePin(uint8_t pin, Pins... args)
    {
        _writePin(pin);
        _writePin(args...);
    }
};

template <uint8_t... Args>
class writePin<high, Args...>
{
public:
    writePin(bool write = true)
    {
        if (write)
        {
            _writePin(Args...);
        }
    }

    void write()
    {
        _writePin(Args...);
    }

private:
    void _writePin(uint8_t pin)
    {
        digitalWrite(pin, HIGH);
    }

    template <typename... Pins>
    void _writePin(uint8_t pin, Pins... args)
    {
        _writePin(pin);
        _writePin(args...);
    }
};

}; // namespace io

#endif