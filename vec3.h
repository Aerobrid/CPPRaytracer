// include guard -> to prevent multiple inclusion
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// 3d-vector class
class vec3 {
  public:
    // vector
    double e[3];

    // constructors
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // accessors for each vector value
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // operator overloading to acquire the opposite (negated) vector
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // operator overloading for indexing operation (support both const and non-const)
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    // compound operator overloading -> add another vec3 object to this one
    // Return reference to this object to allow chaining
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // compound operator overloading -> multiplication scaling
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // compound operator overloading -> division scaling
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    // magnitude of vector
    double length() const {
        return std::sqrt(length_squared());
    }

    // sum of squares of vector components
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
// kindof like using typedef in C language with structs
using point3 = vec3;


// Vector Utility Functions
// inline to increase raytracing performance with decreased function call overhead
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// dot-product 
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// cross-product (gives vector perpendicular to both)
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// normalized vector output
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif