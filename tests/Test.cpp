#include <gtest/gtest.h>
#include "MarsRover.h"

using namespace mars::rover;

TEST(Report_controller, should_report_position_with_set_point_and_direction_N)
{
    Controller controller(0, 0, Controller::Direction::North);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 N");
}
TEST(Report_controller, should_report_position_with_set_point_and_direction_S)
{
    Controller controller(0, 0, Controller::Direction::South);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 S");
}
TEST(Report_controller, should_report_position_with_set_point_and_direction_W)
{
    Controller controller(0, 0, Controller::Direction::West);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 W");
}
TEST(Report_controller, should_report_position_with_set_point_and_direction_E)
{
    Controller controller(0, 0, Controller::Direction::East);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 E");
}


TEST(Execute, should_forward_with_set_command_Forward_and_direction_E)
{
    Controller controller(0, 0, Controller::Direction::East);
    std::vector<Controller::Command> command{{Controller::Command::Forward}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "1 0 E");
}
TEST(Execute, should_forward_with_set_command_Forward_and_direction_W)
{
    Controller controller(0, 0, Controller::Direction::West);
    std::vector<Controller::Command> command{{Controller::Command::Forward}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "-1 0 W");
}
TEST(Execute, should_forward_with_set_command_Forward_and_direction_S)
{
    Controller controller(0, 0, Controller::Direction::South);
    std::vector<Controller::Command> command{{Controller::Command::Forward}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 -1 S");
}
TEST(Execute, should_forward_with_set_command_Forward_and_direction_N)
{
    Controller controller(0, 0, Controller::Direction::North);
    std::vector<Controller::Command> command{{Controller::Command::Forward}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 1 N");
}


TEST(Execute, should_turnleft_with_set_command_TurnLeft)
{
    Controller controller(0, 0, Controller::Direction::South);
    std::vector<Controller::Command> command{{Controller::Command::TurnLeft}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 E");
}
TEST(Execute, should_turnright_with_set_command_TurnRight)
{
    Controller controller(0, 0, Controller::Direction::West);
    std::vector<Controller::Command> command{{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 0 N");
}
TEST(Execute, should_change_position_with_all_command)
{
    Controller controller(0, 0, Controller::Direction::North);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "-1 1 N");
}
TEST(Execute, should_change_position_with_set_startPoint_and_all_command)
{
    Controller controller(1, 1, Controller::Direction::North);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "0 2 N");
}
TEST(Execute, should_change_position_with_set_startPoint_and_more_command)
{
    Controller controller(-2, 1, Controller::Direction::South);
    std::vector<Controller::Command> command{{Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::TurnRight},
                                             {Controller::Command::Forward},{Controller::Command::TurnLeft},
                                             {Controller::Command::Forward},{Controller::Command::Forward}};
    controller.Execute(command);
    auto actual = controller.Report();
    EXPECT_EQ(actual, "1 -1 E");
}