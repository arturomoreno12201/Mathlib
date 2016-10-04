#pragma once

bool fequals(float lhs, float rjs);

float deg2rad(float deg);
float rad2deg(float rad);


float linearHalf(float x);

float growfast(float x);

float growSlow(float x);

float growTent(float x);

float bounce(float x);

float bounceFlip(float x);

float parab(float x);

float parabshift(float x);

float parabshifty(float x);

float parabwhith(float x);

float parabdie(float x);
////need ones 

float lerp(float start, float end, float alpha);

float quadbraz(float start, float mid, float end, float alpha);

float hermiteSpline(float start, float s_tan,float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float tightness, float alpha);

float  catRomSpline(float start, float mid, float end, float alpha);
