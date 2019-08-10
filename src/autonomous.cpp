#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
QLength sideCapDistance = 3.5_ft;
QLength frontFlagDistance = 4.5_ft;
QLength frontCapDistance = 4.0_ft;
QLength midFlagDistance = 1.0_ft;
QLength platformAlignDistance = -4.0_ft;
QLength alliancePlatformDistance = 4.0_ft;
QLength centerPlatformDistance = 6.0_ft;

void front(){
  profileController.setTarget("Ball");
  intake.moveVelocity(200);
  profileController.waitUntilSettled();
  profileController.setTarget("Ball", true); //Go back to starting tile
  profileController.waitUntilSettled();
  profileController.removePath("Ball"); //Ball path removed here


  drive.turnAngle(-45_deg);
  //Should shoot mid flags here

  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{2_ft, 0_ft, 0_deg}},
  "Scrape"
  );
  profileController.setTarget("Scrape");
  profileController.waitUntilSettled();
  profileController.setTarget("Scrape", true);
  profileController.waitUntilSettled();
  profileController.removePath("Scrape");

  drive.turnAngle(-45_deg);
  //Should shoot top and mid flags
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
  );
  profileController.setTarget("botFlag");
  profileController.waitUntilSettled();
  profileController.setTarget("botFlag", true);
  profileController.waitUntilSettled();
  profileController.removePath("botFlag");
}

void autonomous() {
//  profile.generatePath({Point{1_ft, 7ft, 0_deg}, Point{5_ft, 7_ft, 0_deg}}, "Cap"});
front();


}
