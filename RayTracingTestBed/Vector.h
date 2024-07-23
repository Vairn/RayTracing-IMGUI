#pragma once
#include <cmath>

#define EPSILON 0.00001f
#define Vec2(x,y) TUPLE(x,y,0,0)
#define Vec3(x,y,z) TUPLE(x,y,z,0)

#define Point(x,y,z) TUPLE(x,y,z,1.0)

class TUPLE
{
public:
	TUPLE() : x(0), y(0), z(0), w(0) {}
	TUPLE(float x, float y, float z) : x(x), y(y), z(z), w(0) {}
	TUPLE(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	union 
	{
		float f[4];
		struct
		{
			float x, y, z, w;
		};
		struct {
			float r, g, b, a;
		};
	};

	TUPLE operator+(const TUPLE& rhs) const
	{
		return TUPLE(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	}

	TUPLE operator+=(const TUPLE& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	TUPLE operator-(const TUPLE& rhs) const
	{
		return TUPLE(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
	}

	TUPLE operator-=(const TUPLE& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}



	TUPLE operator-() const
	{
		return TUPLE(-x, -y, -z, -w);
	}

	TUPLE operator*(float scalar) const
	{
		return TUPLE(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	TUPLE operator*= (float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	TUPLE operator/(float scalar) const
	{
		return TUPLE(x / scalar, y / scalar, z / scalar, w / scalar);
	}

	TUPLE operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
		return *this;
	}

	TUPLE operator*(const TUPLE& rhs) const
	{
		return TUPLE(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
	}

	TUPLE operator*=(const TUPLE& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}

	TUPLE operator/(const TUPLE& rhs) const
	{
		return TUPLE(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	}

	TUPLE operator/=(const TUPLE& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}

	bool operator==(const TUPLE& rhs) const
	{
		return (fabs(x - rhs.x) < EPSILON) && (fabs(y - rhs.y) < EPSILON) && (fabs(z - rhs.z) < EPSILON) && (fabs(w - rhs.w) < EPSILON);
	}

	bool operator!=(const TUPLE& rhs) const
	{
		return !(*this == rhs);
	}

	float Dot(const TUPLE& rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	}

	TUPLE Cross(const TUPLE& rhs) const
	{
		return Vec3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}

	float Magnitude() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	float MagnitudeSquared() const
	{
		return x * x + y * y + z * z + w * w;
	}



	TUPLE Normalise() const
	{
		float mag = Magnitude();
		return TUPLE(x / mag, y / mag, z / mag, w / mag);
	}

	TUPLE Reflect(const TUPLE& normal) const
	{
		return *this - normal * 2 * Dot(normal);
	}
};


typedef TUPLE Colour;
typedef TUPLE Point;
typedef TUPLE Vec3;