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



}

std::string Controller::Report() const
{
    std::string report = "";
    report += std::to_string(this->x) + " " + std::to_string(this->y) + " " +this->reportDirection.find(this->direction)->second;
    return report;
}
};  // namespace rover
};  // namespace mars
