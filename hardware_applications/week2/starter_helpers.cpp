// This file intentionally left blank
#include "starter_helpers.h"
#include <iostream>
using namespace std;

void run_robot(RJRobot &robot, const std::string &commands) {

// "forward backward left right left forward waitForButton stop";

    size_t index = commands.find(" "); //returns index of first white space int string
    size_t index_prev = 0;
    while (index != commands.length()) {
        string sub_cmd = commands.substr(index_prev, index - index_prev);
        //execute_command(robot, sub_cmd);
        cout << sub_cmd << endl;
        index_prev = index + 1;
        index = commands.find(" ", index + 1); // find next space starting from index + 1
    }
}


//forward
void execute_command(RJRobot &robot, const std::string &command) {
    if (command == "forward") {
        robot.SetMotor(MotorPort::A, 100);
        robot.SetMotor(MotorPort::B, 100);
        robot.Wait(250ms);
    } else if (command == "backward") {
        robot.SetMotor(MotorPort::A, -100);
        robot.SetMotor(MotorPort::B, -100);
        robot.Wait(250ms);
    }
}
