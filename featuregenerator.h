#ifndef FEATUREGENERATOR_H
#define FEATUREGENERATOR_H

class FeatureGenerator
{
public:
    FeatureGenerator(int seed_ = 0, double x_ = 0.0, double y_ = 0.0) :
        seed(seed_), x(x_), y(y_);
    ~FeatureGenerator();
private:

};

#endif // FEATUREGENERATOR_H
