#include "cellnoise.h"
#include <algorithm>
#include <iostream>
#include <random>
using std::max;
using std::min;

double CellNoise::noise(double x, double y)
{
    double smallestDist = 10., dump;
    Coordinate2D iPoint = Coordinate2D(floor(x), floor(y));
    Coordinate2D fPoint = Coordinate2D(modf(x, &dump), modf(y, &dump));

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            Coordinate2D neighbor(i, j);
            Coordinate2D point = random(neighbor + iPoint);
            double dist;
            switch(distFunc)
            {
            case DistanceType::EUCLID:
                dist = euclidianDist(neighbor + point, fPoint);
                break;
            case DistanceType::MANHAT:
                dist = manhattanDist(neighbor + point, fPoint);
                break;
            case DistanceType::CHEBY:
                dist = chebyshevDist(neighbor + point, fPoint);
                break;
            }
            smallestDist = min(dist, smallestDist);
        }
    }
    return smallestDist/1.75;
}

double CellNoise::noise(double x, double y, double z)
{
    return 0.0;
}

double CellNoise::noise(double x, double y, double z, double w)
{
    return 0.0;
}

double CellNoise::euclidianDist(const Coordinate2D &a, const Coordinate2D &b)
{
    return minusSquare(a.x,b.x) +
           minusSquare(a.y,b.y);
}

double CellNoise::euclidianDist(const Coordinate3D &a, const Coordinate3D &b)
{
    return minusSquare(a.x,b.x) +
           minusSquare(a.y,b.y) +
           minusSquare(a.z,b.z);
}

double CellNoise::euclidianDist(const Coordinate4D &a, const Coordinate4D &b)
{
    return minusSquare(a.x,b.x) +
           minusSquare(a.y,b.y) +
           minusSquare(a.z,b.z) +
           minusSquare(a.w,b.w);
}

double CellNoise::manhattanDist(const Coordinate2D &a, const Coordinate2D &b)
{
    return abs(a.x - b.x) +
           abs(a.y - b.y);
}

double CellNoise::manhattanDist(const Coordinate3D &a, const Coordinate3D &b)
{
    return abs(a.x - b.x) +
           abs(a.y - b.y) +
           abs(a.z - b.z);
}

double CellNoise::manhattanDist(const Coordinate4D &a, const Coordinate4D &b)
{
    return abs(a.x - b.x) +
           abs(a.y - b.y) +
           abs(a.z - b.z) +
           abs(a.w - b.w);
}

double CellNoise::chebyshevDist(const Coordinate2D &a, const Coordinate2D &b)
{
    Coordinate2D diff = a - b;
    return max(abs(diff.x), abs(diff.y));
}

double CellNoise::chebyshevDist(const Coordinate3D &a, const Coordinate3D &b)
{
    Coordinate3D diff = a - b;
    return max(max(abs(diff.x), abs(diff.y)), abs(diff.z));
}

double CellNoise::chebyshevDist(const Coordinate4D &a, const Coordinate4D &b)
{
    Coordinate4D diff = a - b;
    return max(max(max(abs(diff.x), abs(diff.y)), abs(diff.z)), abs(diff.w));
}

Coordinate2D CellNoise::random(const Coordinate2D &c)
{
    std::minstd_rand rgen;
    rgen.seed((unsigned)((c.x+65793.0)*1664525*(c.y+69069.0) + seed));
    return Coordinate2D(
        (double)(rgen() % 10000) / 10000.f,
        (double)(rgen() % 10000) / 10000.f
    );
}
