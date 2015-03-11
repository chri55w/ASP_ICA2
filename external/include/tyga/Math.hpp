/**
 @file      Math.hpp
 @author    Tyrone Davison
 @date      September 2012
 */

#pragma once
#ifndef __TYGA_MATH__
#define __TYGA_MATH__

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

// TODO: document me

namespace tyga
{

float
dot(Vector2, Vector2);

float
length(Vector2);

Vector2
unit(Vector2);

Vector2
operator-(Vector2);

Vector2
operator+(Vector2, Vector2);

Vector2
operator-(Vector2, Vector2);

Vector2
operator*(float, Vector2);

Vector2
operator*(Vector2, float);

Vector2
operator/(Vector2, float);

Vector2
operator+=(Vector2&, Vector2);

Vector2
operator-=(Vector2&, Vector2);

Vector2
operator*=(Vector2&, float);

Vector2
operator/=(Vector2&, float);

float
dot(Vector3, Vector3);

float
length(Vector3);

Vector3
unit(Vector3);

Vector3
operator-(Vector3);

Vector3
operator+(Vector3, Vector3);

Vector3
operator-(Vector3, Vector3);

Vector3
operator*(float, Vector3);

Vector3
operator*(Vector3, float);

Vector3
operator/(Vector3, float);

Vector3
operator+=(Vector3&, Vector3);

Vector3
operator-=(Vector3&, Vector3);

Vector3
operator*=(Vector3&, float);

Vector3
operator/=(Vector3&, float);

Vector3
cross(Vector3, Vector3);

Vector3
standardize(Vector4);

Vector3
truncate(Vector4);

Vector4
operator*(Vector4, Matrix4x4);

Vector4
operator*(Matrix4x4, Vector4);

Matrix4x4
inverse(Matrix4x4);

Matrix4x4
transpose(Matrix4x4);

Matrix4x4
operator*=(Matrix4x4&, Matrix4x4);

Matrix4x4
operator+=(Matrix4x4&, Matrix4x4);

Matrix4x4
operator-=(Matrix4x4&, Matrix4x4);

Matrix4x4
operator*=(Matrix4x4&, float);

Matrix4x4
operator*(Matrix4x4, Matrix4x4);

Matrix4x4
operator*(Matrix4x4, float);

Matrix4x4
operator*(float, Matrix4x4);

Matrix4x4
operator+(Matrix4x4, Matrix4x4);

Matrix4x4
operator-(Matrix4x4, Matrix4x4);

float
norm(Quaternion);

Quaternion
conjugate(Quaternion);

Quaternion
inverse(Quaternion);

Quaternion
unit(Quaternion);

Quaternion
operator-(Quaternion);

Quaternion
operator+(Quaternion, Quaternion);

Quaternion
operator-(Quaternion, Quaternion);

Quaternion
operator*(Quaternion, Quaternion);

Quaternion
operator*(float, Quaternion);

Quaternion
operator*(Quaternion, float);

Quaternion
operator/(Quaternion, float);

Quaternion
operator+=(Quaternion&, Quaternion);

Quaternion
operator-=(Quaternion&, Quaternion);

Quaternion
operator*=(Quaternion&, Quaternion);

Quaternion
operator*=(Quaternion&, float);

Quaternion
operator/=(Quaternion&, float);

} // end namespace tyga

#endif
