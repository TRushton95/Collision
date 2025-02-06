#ifndef VECTOR2_CPP
#define VECTOR2_CPP

#include <math.h>

struct Vector2
{
	float x{};
	float y{};

	Vector2 Normalise()
	{
		Vector2 result{};

		if (x == 0 && y == 0)
		{
			return result;
		}

		float length = sqrt(powf(x, 2) + powf(y, 2));
		result.x = x / length;
		result.y = y / length;

		return result;
	}

	Vector2 operator+(const Vector2& vector)
	{
		return Vector2(this->x + vector.x, this->y + vector.y);
	}

	Vector2 operator-(const Vector2& vector)
	{
		return Vector2(this->x - vector.x, this->y - vector.y);
	}

	Vector2 operator*(const Vector2& vector)
	{
		return Vector2(this->x * vector.x, this->y * vector.y);
	}

	Vector2 operator/(const Vector2& vector)
	{
		return Vector2(this->x / vector.x, this->y / vector.y);
	}

	Vector2 operator*(const float& scalar)
	{
		return Vector2(this->y * scalar, this->y * scalar);
	}

	Vector2 operator/(const float& scalar)
	{
		return Vector2(this->y / scalar, this->y / scalar);
	}
};

#endif