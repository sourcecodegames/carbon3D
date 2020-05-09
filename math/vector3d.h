#ifndef CARBON3D_VECTOR3D_H
#define CARBON3D_VECTOR3D_H

#include <cmath>

namespace Carbon3D {
    struct Vector3D {
        float x, y, z;

        Vector3D() = default;

        Vector3D(float a, float b, float c) {
            x = a;
            y = b;
            z = c;
        }

        float& operator [](int i) {
            return ((&x)[i]);
        }

        const float& operator [](int i) const {
            return ((&x)[i]);
        }

        Vector3D& operator *=(float s) {
            x *= s;
            y *= s;
            z *= s;

            return (*this);
        }

        Vector3D& operator /=(float s) {
            s = 1.0F / s;
            x *= s;
            y *= s;
            z *= s;

            return (*this);
        }

        Vector3D& operator +=(const Vector3D& v) {
            x += v.x;
            y += v.y;
            z += v.z;

            return (*this);
        }

        Vector3D& operator -=(const Vector3D& v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;

            return (*this);
        }
    };

    inline Vector3D operator *(const Vector3D& v, float s) {
        return {v.x * s, v.y * s, v.z * s};
    }

    inline Vector3D operator /(const Vector3D& v, float s) {
        s = 1.0F / s;
        return {v.x * s, v.y * s, v.z * s };
    }

    inline Vector3D operator -(const Vector3D v) {
        return { -v.x, -v.y, -v.z };
    }

    inline float Magnitude(const Vector3D& v) {
        // https://en.wikipedia.org/wiki/Fast_inverse_square_root
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    inline Vector3D Normalize(const Vector3D& v) {
        return v / Magnitude(v);
    }

    inline Vector3D operator +(const Vector3D& a, const Vector3D& b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z };
    }

    inline Vector3D operator -(const Vector3D& a, const Vector3D& b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z };
    }

    inline float Dot(const Vector3D& a, const Vector3D& b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    inline Vector3D Cross(const Vector3D& a, const Vector3D& b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    inline Vector3D Project(const Vector3D& a, const Vector3D& b) {
        return b * (Dot(a, b) / Dot(b, b));
    }

    inline Vector3D Reject(const Vector3D& a, const Vector3D& b) {
        return a - (b * (Dot(a, b) / Dot(b, b)));
    }
}

#endif //CARBON3D_VECTOR3D_H
