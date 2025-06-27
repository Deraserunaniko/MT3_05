#include "Function.h"

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result = {};

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result = {};
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
}

Vector3 Multiply(float scalar, const Vector3& v1) {
	Vector3 result = {};

	result.x = scalar * v1.x;
	result.y = scalar * v1.y;
	result.z = scalar * v1.z;

	return result;
}

float Dot(const Vector3& v1, const Vector3& v2) {
	float result = {};

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return result;
}

float Length(const Vector3& v1) { return sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z); }

Vector3 Normalize(const Vector3& v2) {
	Vector3 result = {};

	result.x = v2.x / Length(v2);
	result.y = v2.y / Length(v2);
	result.z = v2.z / Length(v2);
	return result;
}

void VectorScreenPrint(int x, int y, Vector3& vector, const char* label) {

	Novice::ScreenPrintf(x, y, " %.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, " % s", label);
}