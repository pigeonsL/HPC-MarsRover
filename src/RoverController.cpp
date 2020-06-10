#include "MarsRover.h"

namespace mars
{
namespace rover
{
Controller::Controller(int x, int y, Direction direction)
{
    this->x = x;
    this->y = y;
    this->direction = direction;
}

void Controller::Execute(const std::vector<Command>& commands)
{
    int i = (int)direction;
    for(auto it = commands.begin(); it != commands.end(); it++){

        if(*it == Controller::Command::Forward){
            x += changeDirection[i][0];
            y += changeDirection[i][1];
        }
        if(*it == Controller::Command::TurnRight){
            i = (i+1)%4;
        }
        if(*it == Controller::Command::TurnLeft){
            i = (i+3)%4;
        }
    }
}

std::string Controller::Report() const
{
    std::string report = "";
    report += std::to_string(this->x) + " " + std::to_string(this->y) + " " +this->reportDirection.find(this->direction)->second;
    return report;
}
};  // namespace rover
};  // namespace mars
