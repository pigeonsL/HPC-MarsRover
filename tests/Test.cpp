#include <gtest/gtest.h>
#include "MarsRover.h"

using namespace mars::rover;

TEST(Controller, Report)
{
    Controller controller(0, 0, Controller::Direction::North);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 N");
}
TEST(Execute, Report)
{
    Controller controller(0, 0, Controller::Direction::South);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 N");
}