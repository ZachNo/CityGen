#ifndef NOISE_H
#define NOISE_H

#include <cstdint>

const int DEFAULT_SEED = 123456789;

class NoiseGen
{
public:
    NoiseGen(int64_t seed_ = DEFAULT_SEED) : seed(seed_){};
    virtual ~NoiseGen(){};

    virtual double noise(double x, double y) = 0;
    virtual double noise(double x, double y, double z) = 0;
    virtual double noise(double x, double y, double z, double w) = 0;
protected:
    int64_t seed;
};

double octave(double x, double y, int octaves, NoiseGen *gen);
double octave(double x, double y, double z, int octaves, NoiseGen *gen);
double octave(double x, double y, double z, double w, int octaves, NoiseGen *gen);

#endif // NOISE_H
