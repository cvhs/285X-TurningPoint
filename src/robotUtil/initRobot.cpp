#include "C:\Users\clove\Desktop\X4\src\robotUtil\initrobot.hpp"
#include "main.h"

Motor scraper (4, true, AbstractMotor::gearset::green);;
Motor intake (8, false, AbstractMotor::gearset::green);
Motor* flywheel = new okapi::Motor(7);
Motor indexer (3,false, AbstractMotor::gearset::blue);
 ChassisControllerIntegrated drive = ChassisControllerFactory::create(
   {1,9},
   {-10,-2},
   AbstractMotor::gearset::green,
   {4.125_in, 12.125_in}
 );
 AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
   2,  // Maximum linear velocity of the Chassis in m/s
   2.0,  // Maximum linear acceleration of the Chassis in m/s/s
   2.5, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
 );
