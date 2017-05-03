#include "noise.h"

double octave(double x, double y, int octaves, NoiseGen *gen)
{
    double total = 0, init = octaves;
    for(int i = 0; i < octaves; i++)
    {
        total += gen->noise(x/octaves, y/octaves) * octaves;
        octaves /= 2;
    }
    return total / init;
}

double octave(double x, double y, double z, int octaves, NoiseGen *gen)
{
    return 0.0;
}

double octave(double x, double y, double z, double w, int octaves, NoiseGen *gen)
{
    return 0.0;
}
