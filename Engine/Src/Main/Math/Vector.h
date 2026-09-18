/*********************

Vector.h
Created by Josh Billena

*********************/

#ifndef VECTOR_H
#define VECTOR_H



namespace Alphalabs{

struct Vector2{

    float x;

    float y;

    Vector2 Add(const Vector2& Other);

    Vector2 Subtract(const Vector2& Other);

    Vector2 Divide(const Vector2& Other);

    Vector2 Multiply(const Vector2& Other);

};

}

#endif //VECTOR_H
