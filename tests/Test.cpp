#include <gtest/gtest.h>
#include "MarsRover.h"

using namespace mars::rover;

TEST(Report, Report_N)
{
    Controller controller(0, 0, Controller::Direction::North);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 N");
}
TEST(Report, Report_S)
{
    Controller controller(0, 0, Controller::Direction::South);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 S");
}
TEST(Report, Report_W)
{
    Controller controller(0, 0, Controller::Direction::West);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 W");
}
TEST(Report, Report_E)
{
    Controller controller(0, 0, Controller::Direction::East);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 E");
}
TEST(Execute, Report_E)
{
    Controller controller(0, 0, Controller::Direction::East);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "1 1 E");
}
TEST(Execute, Report_S)
{
    Controller controller(0, 0, Controller::Direction::South);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "1 -1 S");
}
TEST(Execute, Report_W)
{
    Controller controller(0, 0, Controller::Direction::West);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "-1 -1 W");
}
TEST(Execute, Report_N)
{
    Controller controller(0, 0, Controller::Direction::North);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "-1 1 N");
}
TEST(Execute, Report_N_1)
{
    Controller controller(1, 1, Controller::Direction::North);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 2 N");
}
TEST(Execute, random_start_and_direction)
{
    Controller controller(-1, 1, Controller::Direction::West);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "-2 0 W");
}