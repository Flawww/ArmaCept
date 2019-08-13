#pragma once
#include "pch.h"

class vec2 {
public:
    vec2(): x(0.f), y(0.f) {};
    vec2(float X, float Y): x(X), y(Y) {};

    float x, y;
};