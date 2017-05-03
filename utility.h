#ifndef UTILITY_H
#define UTILITY_H

struct Coordinate
{};

struct Coordinate2D : public Coordinate
{
    double x, y;
    Coordinate2D(double x_ = 0.0, double y_ = 0.0)
        : x(x_), y(y_)
    {};
    Coordinate2D operator-(const Coordinate2D &r) const
    { return Coordinate2D(x-r.x, y-r.y); }
    Coordinate2D operator+(const Coordinate2D &r) const
    { return Coordinate2D(x+r.x, y+r.y); }
    Coordinate2D& operator+=(const Coordinate2D &r)
    { x += r.x; y += r.y; return *this; }
};

inline double dot(const Coordinate2D &a, const Coordinate2D &b)
{
    return (a.x*b.x)+(a.y*b.y);
}

struct Coordinate3D : public Coordinate
{
    double x, y, z;
    Coordinate3D(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0)
        : x(x_), y(y_), z(z_)
    {};
    Coordinate3D operator-(const Coordinate3D &r) const
    { return Coordinate3D(x-r.x,y-r.y,z-r.z); }
};

struct Coordinate4D : public Coordinate
{
    double x, y, z, w;
    Coordinate4D(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0, double w_ = 0.0)
        : x(x_), y(y_), z(z_), w(w_)
    {};
    Coordinate4D operator-(const Coordinate4D &r) const
    { return Coordinate4D(x-r.x,y-r.y,z-r.z,w-r.w); }
};

inline double minusSquare(double a, double b)
{ return (a-b)*(a-b); }

#endif // UTILITY_H
