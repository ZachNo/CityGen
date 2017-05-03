#ifndef CELLNOISE_H
#define CELLNOISE_H

#include <cstdint>
#include "noise.h"
#include "utility.h"

class CellNoise : public NoiseGen
{
public:
    enum DistanceType { EUCLID, MANHAT, CHEBY };

    CellNoise(int64_t seed_ = DEFAULT_SEED, DistanceType d = DistanceType::EUCLID)
        : NoiseGen(seed_), distFunc(d)
    {};

    double noise(double x, double y);
    double noise(double x, double y, double z);
    double noise(double x, double y, double z, double w);

private:
    inline double euclidianDist(const Coordinate2D &a, const Coordinate2D &b);
    inline double euclidianDist(const Coordinate3D &a, const Coordinate3D &b);
    inline double euclidianDist(const Coordinate4D &a, const Coordinate4D &b);

    inline double manhattanDist(const Coordinate2D &a, const Coordinate2D &b);
    inline double manhattanDist(const Coordinate3D &a, const Coordinate3D &b);
    inline double manhattanDist(const Coordinate4D &a, const Coordinate4D &b);

    inline double chebyshevDist(const Coordinate2D &a, const Coordinate2D &b);
    inline double chebyshevDist(const Coordinate3D &a, const Coordinate3D &b);
    inline double chebyshevDist(const Coordinate4D &a, const Coordinate4D &b);

    inline Coordinate2D random(const Coordinate2D &c);

    DistanceType distFunc;
};

#endif // CELLNOISE_H
