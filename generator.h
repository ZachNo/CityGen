#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstdint>
#include "utility.h"

class Generator
{
public:
    Generator(int64_t seed = 0);
    virtual ~Generator() = 0;
    virtual void update(Coordinate s, Coordinate e);
};

#endif // GENERATOR_H
