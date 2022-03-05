#include "LedLamp.h"
#include "LedLampDriverInterface.h"
#include "gtest/gtest.h"
#include <iostream>



int main(int argc, char **argv)
{

  std::string test("test");
  if(argc > 1 && argv[1] != NULL && (test.compare(argv[1]) == 0))
  {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
  }

  LedLamp ledLamp;

  LedLampDriverInterface ledLampDriverInterface;

  ledLampDriverInterface.init(ledLamp);

  int button = 1;

  while(true)
  {
    std::cout << "Enter 1 to simulate button1 push, 2 for button2 push. Any other key to quit." << std::endl;

    std::cin >> button; //get the user input for button 1 or 2
    
    if(button == 1)
      std::cout << ledLamp.button1Pushed();
    else if(button == 2)
      std::cout << ledLamp.button2Pushed();
    else
      break;
  }

  std::cout << "End of the simulation." << std::endl;
  return 0;
}
