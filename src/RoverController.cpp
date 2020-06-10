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
    for(auto it = commands.begin(); it != commands.end(); it++){

//        int i = (int)direction;
        if(*it == Controller::Command::Forward){
            if(direction == Controller::Direction::East){
                x += changeDirection[0][0];
                y += changeDirection[0][1];
                continue;
            }
            if(direction == Controller::Direction::South){
                x += changeDirection[1][0];
                y += changeDirection[1][1];
                continue;
            }
            if(direction == Controller::Direction::West){
                x += changeDirection[2][0];
                y += changeDirection[2][1];
                continue;
            }
            if(direction == Controller::Direction::North){
                x += changeDirection[3][0];
                y += changeDirection[3][1];
                continue;
            }
        }
        if(*it == Controller::Command::TurnRight){

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
