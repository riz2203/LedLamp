#include "LedLamp.h"
#include <sstream>

LedLamp::~LedLamp()
{
  m_ledDriverApiMap.clear();
}

bool LedLamp::addLedDriverApiToMap(int button1State, int button2State, LedDriverApi apiFunc)
{
  bool retVal = false;
  if(apiFunc != NULL)
  {
    if (button1State < 0 || button1State > 2)
    {
      std::cout << "Button1 state (" << button1State << ") is not valid." << std::endl;
    }
    else if (button2State < 0 || button2State > 1)
    {
      std::cout << "Button2 state (" << button2State << ") is not valid." << std::endl;
    }
    else
    {
      m_ledDriverApiMap.insert(std::make_pair(std::make_pair(button1State, button2State), apiFunc));
      retVal = true;
    }
  }
  
  return retVal;
}

std::string LedLamp::button1Pushed()
{
  std::stringstream ss;

  if(m_button1State >= 2) //reset button1 state 0
  {
    m_button1State = 0;
  }
  else if (m_button1State == 0)
  {
    m_button2State = 0;  //always start with Red LED
    m_button1State++;
  }
  else
  {
    m_button1State++;
  }
 
  LedDriverApiFunctionMap::const_iterator iter = m_ledDriverApiMap.find(std::make_pair(m_button1State, m_button2State));

  if(iter != m_ledDriverApiMap.end())
  {
    ss << (*iter->second)();
  }
  else
  {
    ss << "No LED Driver API function is defined for Button1 state:" << m_button1State
        << ", Button2 state:" << m_button2State << std::endl;
  }

  return ss.str();
}

std::string LedLamp::button2Pushed()
{
  std::stringstream ss;

  m_button2State  = !m_button2State; //toggle button2 on ecah push
  
  LedDriverApiFunctionMap::const_iterator iter = m_ledDriverApiMap.find(std::make_pair(m_button1State, m_button2State));

  if(iter != m_ledDriverApiMap.end())
  {
    ss << (*iter->second)();
  }
  else
  {
    ss << "No LED Driver API function is defined for Button1 state:" << m_button1State
        << ", Button2 state:" << m_button2State << std::endl;
  }

  return ss.str();
}

