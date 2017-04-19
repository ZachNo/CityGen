#ifndef ROADGEN_H
#define ROADGEN_H

#include <cstdint>
#include <deque>
#include "generator.h"
#include "utility.h"

class Road;

class RoadGen : Generator
{
public:
    RoadGen(int64_t seed);
    virtual ~RoadGen();
    virtual void update(Coordinate s, Coordinate e);
    virtual int size() { return roads.size(); }
    virtual Road getRoad(int index) { return roads[index]; }

private:
    std::deque<Road> roads;
};

class Road
{
public:
    Road(double sx, double sy, double ex, double ey, RoadType type = RoadType::CityRoad);
    Road(Coordinate s, Coordinate e, RoadType type = RoadType::CityRoad);

    Coordinate getStart() { return start; }
    Coordinate getEnd() { return end; }
    RoadType getType() { return type; }

    enum RoadType { Highway, CityRoad, SuburbRoad, DirtRoad };
private:
    Coordinate start, end;
    RoadType type;
};

#endif // ROADGEN_H
