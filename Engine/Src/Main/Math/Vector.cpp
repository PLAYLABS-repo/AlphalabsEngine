/*********************

Vector.cpp
Created by Josh Billena

*********************/

#include "Vector.h"


namespace Alphalabs{

    Vector2 Vector2::Add(const Vector2& Other){

        return{

            x + Other.x,
            y + Other.y

        };
    }
    Vector2 Vector2::Subtract(const Vector2& Other){

        return{

            x - Other.x,
            y - Other.y

        };
    }
    Vector2 Vector2::Divide(const Vector2& Other){

        return{

            x / Other.x,
            y / Other.y

        };
    }
    Vector2 Vector2::Multiply(const Vector2& Other){

        return{

            x * Other.x,
            y * Other.y

        };
    }
}



