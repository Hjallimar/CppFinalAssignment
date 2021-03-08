#include "Math.h"

Math::Math() {

}
Math::~Math()
{}

Vector2 Math::AngleToVector(float angle) { // angle in radians
	Vector2 dir;
	dir.x = cos(angle);
	dir.y = sin(angle);
	return dir;
}

float Math::VectorToAngle(Vector2 dir) {
	float angle;
	angle = atan2(dir.y, dir.x);
	return angle;
}

float Math::DegreesToRadians(float angle) {
	return angle * 0.0174532925;
}