#include <iostream>

#include "robot_1d.h"
#include "robot_2d.h"
#include "robot_3d.h"
#include "robot_4d.h"

Robot_1D robot_1D;
Robot_2D robot_2D("Wally");
Robot_3D robot_3D("Eva");
Robot_4D robot_4D("Lego");

void printRobots()
{
    std::cout << robot_1D << '\n'
              << robot_2D << '\n'
              << robot_3D << '\n'
              << robot_4D << '\n';
}

int main()
{
    printRobots();

    robot_1D.setPosition({1.1});
    robot_2D.setPosition({1, 2});
    robot_3D.setPosition({1, 2, 3});
    robot_4D.setPosition({1, 2, 1, 4});

    printRobots();

    robot_1D.setMotion({1, 1});
    robot_2D.setMotion({1, 1});
    robot_3D.setMotion({1, 1});
    robot_4D.setMotion(Position(robot_3D.getPosition() + robot_2D.getPosition()));

    printRobots();

    return 0;
}
