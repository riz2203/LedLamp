#include <limits.h>
#include "LedLamp.h"
#include "LedLampDriverInterface.h"
#include "gtest/gtest.h"
namespace {

//addLedDriverApiToMap test cases
////////////////////////////////////////////////////////////
//add null method, with button1 and button2 state = 0
TEST(AddLedDriverApiToMapTest, AddNullFunction)
{
  LedLamp ledLamp;

  EXPECT_FALSE(ledLamp.addLedDriverApiToMap(0, 0, NULL));
}

//add null method, with invalid button1 state
TEST(AddLedDriverApiToMapTest, Button1InvalidState)
{
  LedLamp ledLamp;

  EXPECT_FALSE(ledLamp.addLedDriverApiToMap(5 ,0, NULL));
}

//add null method, with invalid button2 state
TEST(AddLedDriverApiToMapTest, Button2InvalidState)
{
  LedLamp ledLamp;

  EXPECT_FALSE(ledLamp.addLedDriverApiToMap(0 ,5, NULL));
}

//add ledOff method, with button1 state = 0 and button2 state = 0
TEST(AddLedDriverApiToMapTest, ledOffWithValiddState)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  EXPECT_TRUE(ledLamp.addLedDriverApiToMap(0 ,0, &ledLampDriverInterface.ledOff));
}

//Button1 test cases
///////////////////////////////////////////////////////////////
//Button1 push 1 time
TEST(LedLampButton1Test, PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  std::string outPut = ledLamp.button1Pushed(); //push button1 once

  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 2 times
TEST(LedLampButton1Test, PushTwoTimes)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);
  
  ledLamp.button1Pushed();  //push button1 once
  std::string outPut = ledLamp.button1Pushed(); //2nd time
  std::string expectedResult = ledLampDriverInterface.RedFlash();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 3 times
TEST(LedLampButton1Test, PushThreeTimes)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);
  
  ledLamp.button1Pushed();  //push button1 one time
  ledLamp.button1Pushed(); //2nd time
  std::string outPut = ledLamp.button1Pushed(); //3rd time
  std::string expectedResult = ledLampDriverInterface.ledOff();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 4 times
TEST(LedLampButton1Test, PushFourTimes)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp); //3rd time

  ledLamp.button1Pushed();  //push button1 one time
  ledLamp.button1Pushed(); //2nd time
  ledLamp.button1Pushed(); //3nd time
  std::string outPut = ledLamp.button1Pushed(); //4th time
  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}
/////////////////////////////////////////////////////////////////
//Button2 test cases
///////////////////////////////////////////////////////////////
//Button2 push 1 time
TEST(LedLampButton2Test, PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  std::string outPut = ledLamp.button2Pushed(); //push button1 once
  std::string expectedResult = ledLampDriverInterface.ledOff();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button2 push 2 times
TEST(LedLampButton2Test, PushTwoTimes)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);
  
  ledLamp.button2Pushed();  //push button1 once
  std::string outPut = ledLamp.button2Pushed(); //2nd time
  std::string expectedResult = ledLampDriverInterface.ledOff();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

////////////////////////////////////////////////////////////////
//Button1 and Button2 test cases
///////////////////////////////////////////////////////////////
//Button1 push 1 time and then push Button2 1 time
TEST(LedLampButton1AndButton2Test, Button1PushOneTimeAndButton2PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  std::string outPut = ledLamp.button2Pushed(); //push button2 once
  std::string expectedResult = ledLampDriverInterface.whiteOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 2 time and then push Button2 1 time
TEST(LedLampButton1AndButton2Test, Button1PushTwoTimeAndButton2PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  std::string outPut = ledLamp.button2Pushed(); //push button2 once
  std::string expectedResult = ledLampDriverInterface.WhiteFlash();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 3 time and then push Button2 1 time
TEST(LedLampButton1AndButton2Test, Button1PushThreeTimeAndButton2PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  ledLamp.button1Pushed(); //push button1 3rd time
  std::string outPut = ledLamp.button2Pushed(); //push button2 once
  std::string expectedResult = ledLampDriverInterface.ledOff();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 4 time and then push Button2 1 time
TEST(LedLampButton1AndButton2Test, Button1PushFourTimeAndButton2PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  ledLamp.button1Pushed(); //push button1 3rd time
  ledLamp.button1Pushed(); //push button1 4rd time
  std::string outPut = ledLamp.button2Pushed(); //push button2 once
  std::string expectedResult = ledLampDriverInterface.whiteOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 1 time and then push Button2 2 time
TEST(LedLampButton1AndButton2Test, Button1PushOneTimeAndButton2PushTwoTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button2Pushed(); //push button2 once
  std::string outPut = ledLamp.button2Pushed(); //push button2 2nd time
  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 2 time and then push Button2 2 time
TEST(LedLampButton1AndButton2Test, Button1PushTwoTimeAndButton2PushTwoTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  ledLamp.button2Pushed(); //push button2 once
  std::string outPut = ledLamp.button2Pushed(); //push button2 2nd time
  std::string expectedResult = ledLampDriverInterface.RedFlash();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 3 time and then push Button2 2 time
TEST(LedLampButton1AndButton2Test, Button1PushThreeTimeAndButton2PushTwoTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  ledLamp.button1Pushed(); //push button1 3rd time
  ledLamp.button2Pushed(); //push button2 once
  std::string outPut = ledLamp.button2Pushed(); //push button2 2nd time
  std::string expectedResult = ledLampDriverInterface.ledOff();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button1 push 4 time and then push Button2 2 time
TEST(LedLampButton1AndButton2Test, Button1PushFourTimeAndButton2PushTwoTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button1Pushed(); //push button1 once
  ledLamp.button1Pushed(); //push button1 2nd time
  ledLamp.button1Pushed(); //push button1 3rd time
  ledLamp.button1Pushed(); //push button1 4rd time
  ledLamp.button2Pushed(); //push button2 once
  std::string outPut = ledLamp.button2Pushed(); //push button2 2nd time
  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//////////////////////////////////////////////////////////////////////////
//Button2 push first and then Button1 test cases
////////////////////////////////////////////////////////////////////////////
//Button2 push 1 time and then push Button1 1 time
TEST(LedLampButton2AndButton1Test, Button2PushOneTimeAndButton1PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button2Pushed(); //push button2 once
  std::string outPut = ledLamp.button1Pushed(); //push button1 one time
  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}

//Button2 push 2 time and then push Button1 1 time
TEST(LedLampButton2AndButton1Test, Button2PushTwoTimeAndButton1PushOneTime)
{
  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  ledLamp.button2Pushed(); //push button2 once
  ledLamp.button2Pushed(); //push button2 2nd time
  std::string outPut = ledLamp.button1Pushed(); //push button1 one time
  std::string expectedResult = ledLampDriverInterface.redOn();

  EXPECT_STREQ(outPut.c_str(), expectedResult.c_str());
}
}//namespace
