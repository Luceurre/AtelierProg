//
// Created by julien on 19/04/2020.
//

#ifndef ATELIERPROG_VECTOR2D_H
#define ATELIERPROG_VECTOR2D_H

#include <iostream>

class Vector2D {
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& Add(const Vector2D& vec);
    Vector2D& Multiply(const Vector2D& vec);
    Vector2D& Substract(const Vector2D& vec);
    Vector2D& Divide(const Vector2D& vec);

    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, int& a);
    friend Vector2D& operator*(int& a, Vector2D& v1);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

#endif //ATELIERPROG_VECTOR2D_H