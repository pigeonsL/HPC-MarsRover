#pragma once
#include <string>
#include <vector>
#include <map>

namespace mars
{
namespace rover
{
class Controller
{
public:
    enum class Direction {
        North,
        East,
        South,
        West,
    };

    enum class Command {
        Forward,
        TurnLeft,
        TurnRight,
    };

public:
    Controller(int x, int y, Direction direction);

public:
    void Execute(const std::vector<Command>& commands);
    std::string Report() const;
    int x;
    int y;
    Direction direction;
    int changeDirection[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

    std::map<Direction, std::string> reportDirection{
            {(Direction::North), "N"},
            {(Direction::East), "E"},
            {(Direction::South), "S"},
            {(Direction::West), "W"}
    };
};

};  // namespace rover
};  // namespace mars
