#pragma once
#include <cmath>
#include <algorithm>
#include <utility>
#include "Functions.h"

namespace Functions 
{
    struct ErrorFunction;

    struct ActivationFunction;
}


float Functions::MSqrEFunc(float Expected, float Actual) 
{
    return ((Actual - Expected) * (Actual - Expected));
}

//float(*Functions::MSqrE)(float Expected, float Actual)

float Functions::MSqrEDeriv(float Real, float Expected)
{
    return (2 * (Real - Expected));
}

Functions::ErrorFunction MeanSquaredError{ Functions::MSqrEFunc, Functions::MSqrEDeriv };

float Functions::MAbsE(float Expected, float Actual) {return abs(Actual - Expected);}

float Functions::MSqrLogE(float Expected, float Actual)
{
    return std::pow((std::log10(Actual) - std::log10(Expected)), 2.0);
}

float Functions::MAbsPerE (float Expected, float Actual)
{
    return ((100 * abs(Actual - Expected)) / Actual);
}

//Loss functions for classification
float Functions::HingeLoss(float Expected, float Actual)
{
    return std::max((float)0, (1 - Actual - Expected));
}

float Functions::LogisticLoss(float Expected, float Actual)
{
    return 0.0;
}

float Functions::NegativeLogLikelihood(float Expected, float Actual)
{
    return 0.0;
}

//Loss functions for reconstruction
float Functions::KLDivergence(float Expected, float Actual)
{
    return 0.0;
}

float Functions::SigmoidFunc(float x) {return (1 / (1 + std::exp(-x)));}

float Functions::SigmoidDeriv(float x) {return SigmoidFunc(x) * (1 - SigmoidFunc(x));}

Functions::ActivationFunction Sigmoid{ Functions::SigmoidFunc, Functions::SigmoidDeriv };

float Functions::ReLUFunc(float x)
{
    if (x <= 0.0) {return 0.0;}
    else {return x;};
}

float Functions::ReLUDeriv(float x)
{
    if (x <= 0.0) {return 0.0;}
    else {return 1.0;}
}

Functions::ActivationFunction ReLU{ Functions::ReLUFunc, Functions::ReLUDeriv };

float Functions::LinearFunc(float x) { return x; }

float Functions::LinearDeriv(float x) {return 1;}

Functions::ActivationFunction Linear{ Functions::LinearFunc, Functions::LinearDeriv };

float Functions::TanhFunc(float x) {return std::tanh(x);}

float Functions::TanhDeriv(float x) {return (1-(std::tanh(x) * std::tanh(x)));}

Functions::ActivationFunction Tanh{ Functions::TanhFunc, Functions::TanhDeriv };

float Functions::HardTanhFunc(float x)
{
    if (x < 0) {return -1.0;}
    if (x > 0) {return 1.0;}
    else {return 0;}
}

float Functions::HardTanhDeriv(float x)
{
    if (x < 1.0 && x > -1.0) {return 1;}
    else {return 0;}
}

Functions::ActivationFunction HardTanh{ Functions::HardTanhFunc, Functions::HardTanhDeriv };
