#ifndef __LED_LAMP_DRIVER_IMP_H__
#define __LED_LAMP_DRIVER_IMP_H__
#include <iostream>
#include "LedLamp.h"

class LedLampDriverInterface
{
public:
    void init(LedLamp &ledLamp)
    {
        ledLamp.addLedDriverApiToMap(0, 0, &ledOff);
        ledLamp.addLedDriverApiToMap(0, 1, &ledOff);
        ledLamp.addLedDriverApiToMap(1, 0, &redOn);
        ledLamp.addLedDriverApiToMap(1, 1, &whiteOn);
        ledLamp.addLedDriverApiToMap(2, 0, &RedFlash);
        ledLamp.addLedDriverApiToMap(2, 1, &WhiteFlash);
    }

    static std::string ledOff()
    {
        std::string s("LED lamp is off\n");
        //std::cout << s << std::endl;
        return s;
    }

    static std::string redOn()
    {
        std::string s("Red LED lamp is on\n");
        //std::cout << s << std::endl;
        return s;
    }

    static std::string whiteOn()
    {
        std::string s("White LED lamp is on\n");
        //std::cout << s << std::endl;
        return s;
    }

    static std::string RedFlash()
    {
        std::string s("Red LED lamp is flashing\n");
        //std::cout << s << std::endl;
        return s;
    }

    static std::string WhiteFlash()
    {
        std::string s("White LED lamp is flashing\n");
        //std::cout << s << std::endl;
        return s;
    }
};
#endif //__LED_LAMP_DRIVER_IMP_H__