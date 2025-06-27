#pragma once
#include <Vector3.h>
#include  <math.h>
#include <time.h>
#define _USE_MATH_DEFINE
#include <stdio.h>
#include <stdlib.h>
#include <Novice.h>

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v1);

//内積
float Dot(const Vector3& v1, const Vector3& v2);

//長さ(ノルム)
float Length(const Vector3& v1);

//正規化
Vector3 Normalize(const Vector3& v2);

static const int kColumnWidth = 60;

static const int kColumnHeight = 20;

void VectorScreenPrint(int x, int y, Vector3& vector, const char* label);