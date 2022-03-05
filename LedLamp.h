#ifndef __LED_LAMP_H__
#define __LED_LAMP_H__

#include <iostream>
#include <map>
#include <string>

typedef std::string (*LedDriverApi)();

class LedLamp {
public:
  LedLamp() : m_button1State(0), m_button2State(0){};
  ~LedLamp();

  bool addLedDriverApiToMap(int button1State, int button2State, LedDriverApi apiFunc);
  std::string button1Pushed();
  std::string button2Pushed();

  //define a std::map to store LED Driver API functions
  //where as button1 abd button2 state (int, int) is the key for this map
  typedef std::map<std::pair<int, int>, LedDriverApi> LedDriverApiFunctionMap;

private:
  int m_button1State;  //0 = off, 1 = red/white on, 2 = flash red/white
  int m_button2State;   //0 = red,  1 = white
  LedDriverApiFunctionMap m_ledDriverApiMap;
};

#endif //__LED_LAMP_H__
