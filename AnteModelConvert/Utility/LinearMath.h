// This file is auto-generated
#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

typedef unsigned int uint;

////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////
constexpr float Pi               = 3.1415926535897932f;
constexpr float TwoPi            = 6.2831853071795865f; // 2 * Pi
constexpr float FourPi           = 12.566370614359173f; // 4 * Pi
constexpr float HalfPi           = 1.5707963267948966f; // Pi / 2
constexpr float PiOverFour       = 0.7853981633974483f; // Pi / 4
constexpr float RcpPi            = 0.3183098861837907f; // 1 / Pi
constexpr float TwoOverPi        = 0.6366197723675813f; // 2 / Pi
constexpr float FourOverPi       = 1.2732395447351627f; // 4 / Pi
constexpr float RcpHalfPi        = 0.6366197723675813f; // 1 / (Pi/2)
constexpr float RcpTwoPi         = 0.1591549430918953f; // 1 / (2 * Pi) = 0.5 / Pi
constexpr float RcpFourPi        = 0.0795774715459477f; // 1 / (4 * Pi)
constexpr float SqrtPi           = 1.7724538509055160f; // sqrt(Pi)
constexpr float PiSquare         = 9.8696044010893586f; // Pi^2
constexpr float FourPiSquare     = 39.478417604357434f; // 4 * Pi^2
constexpr float RcpPiSquare      = 0.1013211836423378f; // 1 / (Pi^2) = (1 / Pi)^2
constexpr float RcpFourPiSquare  = 0.0253302959105844f; // 1 / (4 * Pi^2)
constexpr float FourOverPiSquare = 0.4052847345693511f; // 1 / (4 * Pi^2)
constexpr float SqrtTwo          = 1.4142135623730950f; // sqrt(2)
constexpr float RcpSqrtTwo       = 0.7071067811865475f; // 1 / sqrt(2) = sqrt(2) / 2
constexpr float SqrtThree        = 1.7320508075688773f; // sqrt(3)
constexpr float GoldenRatio      = 1.6180339887498948f; // (1 + sqrt(5)) / 2
constexpr float Ln10             = 2.3025850929940457f; // ln(10)
constexpr float Phi              = 1.6180339887498948f; // Golden Ratio

constexpr float DegToRad         = 3.14159265359f / 180.f;
constexpr float RadToDeg         = 180.f / 3.14159265359f;

////////////////////////////////////////////////////////////////
// Generic math
////////////////////////////////////////////////////////////////
inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline float fminf(float a, float b)
{
	return a < b ? a : b;
}

inline float fmaxf(float a, float b)
{
	return a > b ? a : b;
}

inline float rsqrtf(float x)
{
	return 1.0f / sqrtf(x);
}

////////////////////////////////////////////////////////////////
// vector types
////////////////////////////////////////////////////////////////
struct alignas(8) int2
{
	int x, y;
};

struct int3
{
	int x, y, z;
};

struct alignas(16) int4
{
	int x, y, z, w;
};

struct alignas(8) uint2
{
	uint x, y;
};

struct uint3
{
	uint x, y, z;
};

struct alignas(16) uint4
{
	uint x, y, z, w;
};

struct alignas(8) float2
{
	float x, y;
};

struct float3
{
	float x, y, z;
};

struct alignas(16) float4
{
	float x, y, z, w;
};

////////////////////////////////////////////////////////////////
// constructors
////////////////////////////////////////////////////////////////
// int2
inline int2 make_int2(int x, int y)
{
	int2 t; t.x = x; t.y = y; return t;
}
inline int2 make_int2(int s)
{
	return make_int2(s, s);
}
inline int2 make_int2(const uint2& a)
{
	return make_int2(int(a.x), int(a.y));
}
inline int2 make_int2(const float2& a)
{
	return make_int2(int(a.x), int(a.y));
}
inline int2 make_int2(const int3& a)
{
	return make_int2(a.x, a.y);
}
inline int2 make_int2(const int4& a)
{
	return make_int2(a.x, a.y);
}

// int3
inline int3 make_int3(int x, int y, int z)
{
	int3 t; t.x = x; t.y = y; t.z = z; return t;
}
inline int3 make_int3(int s)
{
	return make_int3(s, s, s);
}
inline int3 make_int3(const uint3& a)
{
	return make_int3(int(a.x), int(a.y), int(a.z));
}
inline int3 make_int3(const float3& a)
{
	return make_int3(int(a.x), int(a.y), int(a.z));
}
inline int3 make_int3(const int2& a)
{
	return make_int3(a.x, a.y, 0);
}
inline int3 make_int3(const int2& a, int z)
{
	return make_int3(a.x, a.y, z);
}
inline int3 make_int3(const int4& a)
{
	return make_int3(a.x, a.y, a.z);
}

// int4
inline int4 make_int4(int x, int y, int z, int w)
{
	int4 t; t.x = x; t.y = y; t.z = z; t.w = w; return t;
}
inline int4 make_int4(int s)
{
	return make_int4(s, s, s, s);
}
inline int4 make_int4(const uint4& a)
{
	return make_int4(int(a.x), int(a.y), int(a.z), int(a.w));
}
inline int4 make_int4(const float4& a)
{
	return make_int4(int(a.x), int(a.y), int(a.z), int(a.w));
}
inline int4 make_int4(const int2& a)
{
	return make_int4(a.x, a.y, 0, 0);
}
inline int4 make_int4(const int2& a, int z, int w)
{
	return make_int4(a.x, a.y, z, w);
}
inline int4 make_int4(const int3& a)
{
	return make_int4(a.x, a.y, a.z, 0);
}
inline int4 make_int4(const int3& a, int w)
{
	return make_int4(a.x, a.y, a.z, w);
}

// uint2
inline uint2 make_uint2(uint x, uint y)
{
	uint2 t; t.x = x; t.y = y; return t;
}
inline uint2 make_uint2(uint s)
{
	return make_uint2(s, s);
}
inline uint2 make_uint2(const int2& a)
{
	return make_uint2(uint(a.x), uint(a.y));
}
inline uint2 make_uint2(const float2& a)
{
	return make_uint2(uint(a.x), uint(a.y));
}
inline uint2 make_uint2(const uint3& a)
{
	return make_uint2(a.x, a.y);
}
inline uint2 make_uint2(const uint4& a)
{
	return make_uint2(a.x, a.y);
}

// uint3
inline uint3 make_uint3(uint x, uint y, uint z)
{
	uint3 t; t.x = x; t.y = y; t.z = z; return t;
}
inline uint3 make_uint3(uint s)
{
	return make_uint3(s, s, s);
}
inline uint3 make_uint3(const int3& a)
{
	return make_uint3(uint(a.x), uint(a.y), uint(a.z));
}
inline uint3 make_uint3(const float3& a)
{
	return make_uint3(uint(a.x), uint(a.y), uint(a.z));
}
inline uint3 make_uint3(const uint2& a)
{
	return make_uint3(a.x, a.y, 0);
}
inline uint3 make_uint3(const uint2& a, uint z)
{
	return make_uint3(a.x, a.y, z);
}
inline uint3 make_uint3(const uint4& a)
{
	return make_uint3(a.x, a.y, a.z);
}

// uint4
inline uint4 make_uint4(uint x, uint y, uint z, uint w)
{
	uint4 t; t.x = x; t.y = y; t.z = z; t.w = w; return t;
}
inline uint4 make_uint4(uint s)
{
	return make_uint4(s, s, s, s);
}
inline uint4 make_uint4(const int4& a)
{
	return make_uint4(uint(a.x), uint(a.y), uint(a.z), uint(a.w));
}
inline uint4 make_uint4(const float4& a)
{
	return make_uint4(uint(a.x), uint(a.y), uint(a.z), uint(a.w));
}
inline uint4 make_uint4(const uint2& a)
{
	return make_uint4(a.x, a.y, 0, 0);
}
inline uint4 make_uint4(const uint2& a, uint z, uint w)
{
	return make_uint4(a.x, a.y, z, w);
}
inline uint4 make_uint4(const uint3& a)
{
	return make_uint4(a.x, a.y, a.z, 0);
}
inline uint4 make_uint4(const uint3& a, uint w)
{
	return make_uint4(a.x, a.y, a.z, w);
}

// float2
inline float2 make_float2(float x, float y)
{
	float2 t; t.x = x; t.y = y; return t;
}
inline float2 make_float2(float s)
{
	return make_float2(s, s);
}
inline float2 make_float2(const int2& a)
{
	return make_float2(float(a.x), float(a.y));
}
inline float2 make_float2(const uint2& a)
{
	return make_float2(float(a.x), float(a.y));
}
inline float2 make_float2(const float3& a)
{
	return make_float2(a.x, a.y);
}
inline float2 make_float2(const float4& a)
{
	return make_float2(a.x, a.y);
}

// float3
inline float3 make_float3(float x, float y, float z)
{
	float3 t; t.x = x; t.y = y; t.z = z; return t;
}
inline float3 make_float3(float s)
{
	return make_float3(s, s, s);
}
inline float3 make_float3(const int3& a)
{
	return make_float3(float(a.x), float(a.y), float(a.z));
}
inline float3 make_float3(const uint3& a)
{
	return make_float3(float(a.x), float(a.y), float(a.z));
}
inline float3 make_float3(const float2& a)
{
	return make_float3(a.x, a.y, 0);
}
inline float3 make_float3(const float2& a, float z)
{
	return make_float3(a.x, a.y, z);
}
inline float3 make_float3(const float4& a)
{
	return make_float3(a.x, a.y, a.z);
}

// float4
inline float4 make_float4(float x, float y, float z, float w)
{
	float4 t; t.x = x; t.y = y; t.z = z; t.w = w; return t;
}
inline float4 make_float4(float s)
{
	return make_float4(s, s, s, s);
}
inline float4 make_float4(const int4& a)
{
	return make_float4(float(a.x), float(a.y), float(a.z), float(a.w));
}
inline float4 make_float4(const uint4& a)
{
	return make_float4(float(a.x), float(a.y), float(a.z), float(a.w));
}
inline float4 make_float4(const float2& a)
{
	return make_float4(a.x, a.y, 0, 0);
}
inline float4 make_float4(const float2& a, float z, float w)
{
	return make_float4(a.x, a.y, z, w);
}
inline float4 make_float4(const float3& a)
{
	return make_float4(a.x, a.y, a.z, 0);
}
inline float4 make_float4(const float3& a, float w)
{
	return make_float4(a.x, a.y, a.z, w);
}

////////////////////////////////////////////////////////////////
// Comparison
////////////////////////////////////////////////////////////////
inline bool operator==(const int2& a, const int2& b)
{
	return (a.x == b.x) && (a.y == b.y);
}
inline bool operator==(const int3& a, const int3& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
inline bool operator==(const int4& a, const int4& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}
inline bool operator==(const uint2& a, const uint2& b)
{
	return (a.x == b.x) && (a.y == b.y);
}
inline bool operator==(const uint3& a, const uint3& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
inline bool operator==(const uint4& a, const uint4& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}
inline bool operator==(const float2& a, const float2& b)
{
	return (a.x == b.x) && (a.y == b.y);
}
inline bool operator==(const float3& a, const float3& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
inline bool operator==(const float4& a, const float4& b)
{
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}

inline bool operator!=(const int2& a, const int2& b)
{
	return (a.x != b.x) || (a.y != b.y);
}
inline bool operator!=(const int3& a, const int3& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}
inline bool operator!=(const int4& a, const int4& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}
inline bool operator!=(const uint2& a, const uint2& b)
{
	return (a.x != b.x) || (a.y != b.y);
}
inline bool operator!=(const uint3& a, const uint3& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}
inline bool operator!=(const uint4& a, const uint4& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}
inline bool operator!=(const float2& a, const float2& b)
{
	return (a.x != b.x) || (a.y != b.y);
}
inline bool operator!=(const float3& a, const float3& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}
inline bool operator!=(const float4& a, const float4& b)
{
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}

////////////////////////////////////////////////////////////////
// negate
////////////////////////////////////////////////////////////////
inline int2 operator-(const int2& a)
{
	return make_int2(-a.x, -a.y);
}
inline int3 operator-(const int3& a)
{
	return make_int3(-a.x, -a.y, -a.z);
}
inline int4 operator-(const int4& a)
{
	return make_int4(-a.x, -a.y, -a.z, -a.w);
}
inline float2 operator-(const float2& a)
{
	return make_float2(-a.x, -a.y);
}
inline float3 operator-(const float3& a)
{
	return make_float3(-a.x, -a.y, -a.z);
}
inline float4 operator-(const float4& a)
{
	return make_float4(-a.x, -a.y, -a.z, -a.w);
}

////////////////////////////////////////////////////////////////
// addition
////////////////////////////////////////////////////////////////
// int2
inline int2 operator+(const int2& a, const int2& b)
{
	return make_int2(a.x + b.x, a.y + b.y);
}
inline int2 operator+=(int2& a, const int2& b)
{
	a.x += b.x;
	a.y += b.y;
}
inline int2 operator+(const int2& a, int b)
{
	return make_int2(a.x + b, a.y + b);
}
inline int2 operator+(int b, const int2& a)
{
	return make_int2(a.x + b, a.y + b);
}
inline int2 operator+=(int2& a, int b)
{
	a.x += b;
	a.y += b;
}

// int3
inline int3 operator+(const int3& a, const int3& b)
{
	return make_int3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline int3 operator+=(int3& a, const int3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}
inline int3 operator+(const int3& a, int b)
{
	return make_int3(a.x + b, a.y + b, a.z + b);
}
inline int3 operator+(int b, const int3& a)
{
	return make_int3(a.x + b, a.y + b, a.z + b);
}
inline int3 operator+=(int3& a, int b)
{
	a.x += b;
	a.y += b;
	a.z += b;
}

// int4
inline int4 operator+(const int4& a, const int4& b)
{
	return make_int4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline int4 operator+=(int4& a, const int4& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
}
inline int4 operator+(const int4& a, int b)
{
	return make_int4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline int4 operator+(int b, const int4& a)
{
	return make_int4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline int4 operator+=(int4& a, int b)
{
	a.x += b;
	a.y += b;
	a.z += b;
	a.w += b;
}

// uint2
inline uint2 operator+(const uint2& a, const uint2& b)
{
	return make_uint2(a.x + b.x, a.y + b.y);
}
inline uint2 operator+=(uint2& a, const uint2& b)
{
	a.x += b.x;
	a.y += b.y;
}
inline uint2 operator+(const uint2& a, uint b)
{
	return make_uint2(a.x + b, a.y + b);
}
inline uint2 operator+(uint b, const uint2& a)
{
	return make_uint2(a.x + b, a.y + b);
}
inline uint2 operator+=(uint2& a, uint b)
{
	a.x += b;
	a.y += b;
}

// uint3
inline uint3 operator+(const uint3& a, const uint3& b)
{
	return make_uint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline uint3 operator+=(uint3& a, const uint3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}
inline uint3 operator+(const uint3& a, uint b)
{
	return make_uint3(a.x + b, a.y + b, a.z + b);
}
inline uint3 operator+(uint b, const uint3& a)
{
	return make_uint3(a.x + b, a.y + b, a.z + b);
}
inline uint3 operator+=(uint3& a, uint b)
{
	a.x += b;
	a.y += b;
	a.z += b;
}

// uint4
inline uint4 operator+(const uint4& a, const uint4& b)
{
	return make_uint4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline uint4 operator+=(uint4& a, const uint4& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
}
inline uint4 operator+(const uint4& a, uint b)
{
	return make_uint4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline uint4 operator+(uint b, const uint4& a)
{
	return make_uint4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline uint4 operator+=(uint4& a, uint b)
{
	a.x += b;
	a.y += b;
	a.z += b;
	a.w += b;
}

// float2
inline float2 operator+(const float2& a, const float2& b)
{
	return make_float2(a.x + b.x, a.y + b.y);
}
inline float2 operator+=(float2& a, const float2& b)
{
	a.x += b.x;
	a.y += b.y;
}
inline float2 operator+(const float2& a, float b)
{
	return make_float2(a.x + b, a.y + b);
}
inline float2 operator+(float b, const float2& a)
{
	return make_float2(a.x + b, a.y + b);
}
inline float2 operator+=(float2& a, float b)
{
	a.x += b;
	a.y += b;
}

// float3
inline float3 operator+(const float3& a, const float3& b)
{
	return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline float3 operator+=(float3& a, const float3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}
inline float3 operator+(const float3& a, float b)
{
	return make_float3(a.x + b, a.y + b, a.z + b);
}
inline float3 operator+(float b, const float3& a)
{
	return make_float3(a.x + b, a.y + b, a.z + b);
}
inline float3 operator+=(float3& a, float b)
{
	a.x += b;
	a.y += b;
	a.z += b;
}

// float4
inline float4 operator+(const float4& a, const float4& b)
{
	return make_float4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline float4 operator+=(float4& a, const float4& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
}
inline float4 operator+(const float4& a, float b)
{
	return make_float4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline float4 operator+(float b, const float4& a)
{
	return make_float4(a.x + b, a.y + b, a.z + b, a.w + b);
}
inline float4 operator+=(float4& a, float b)
{
	a.x += b;
	a.y += b;
	a.z += b;
	a.w += b;
}

////////////////////////////////////////////////////////////////
// subtract
////////////////////////////////////////////////////////////////
// int2
inline int2 operator-(const int2& a, const int2& b)
{
	return make_int2(a.x - b.x, a.y - b.y);
}
inline int2 operator-=(int2& a, const int2& b)
{
	a.x -= b.x;
	a.y -= b.y;
}
inline int2 operator-(const int2& a, int b)
{
	return make_int2(a.x - b, a.y - b);
}
inline int2 operator-(int b, const int2& a)
{
	return make_int2(a.x - b, a.y - b);
}
inline int2 operator-=(int2& a, int b)
{
	a.x -= b;
	a.y -= b;
}

// int3
inline int3 operator-(const int3& a, const int3& b)
{
	return make_int3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline int3 operator-=(int3& a, const int3& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
}
inline int3 operator-(const int3& a, int b)
{
	return make_int3(a.x - b, a.y - b, a.z - b);
}
inline int3 operator-(int b, const int3& a)
{
	return make_int3(a.x - b, a.y - b, a.z - b);
}
inline int3 operator-=(int3& a, int b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
}

// int4
inline int4 operator-(const int4& a, const int4& b)
{
	return make_int4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
inline int4 operator-=(int4& a, const int4& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
}
inline int4 operator-(const int4& a, int b)
{
	return make_int4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline int4 operator-(int b, const int4& a)
{
	return make_int4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline int4 operator-=(int4& a, int b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
	a.w -= b;
}

// uint2
inline uint2 operator-(const uint2& a, const uint2& b)
{
	return make_uint2(a.x - b.x, a.y - b.y);
}
inline uint2 operator-=(uint2& a, const uint2& b)
{
	a.x -= b.x;
	a.y -= b.y;
}
inline uint2 operator-(const uint2& a, uint b)
{
	return make_uint2(a.x - b, a.y - b);
}
inline uint2 operator-(uint b, const uint2& a)
{
	return make_uint2(a.x - b, a.y - b);
}
inline uint2 operator-=(uint2& a, uint b)
{
	a.x -= b;
	a.y -= b;
}

// uint3
inline uint3 operator-(const uint3& a, const uint3& b)
{
	return make_uint3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline uint3 operator-=(uint3& a, const uint3& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
}
inline uint3 operator-(const uint3& a, uint b)
{
	return make_uint3(a.x - b, a.y - b, a.z - b);
}
inline uint3 operator-(uint b, const uint3& a)
{
	return make_uint3(a.x - b, a.y - b, a.z - b);
}
inline uint3 operator-=(uint3& a, uint b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
}

// uint4
inline uint4 operator-(const uint4& a, const uint4& b)
{
	return make_uint4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
inline uint4 operator-=(uint4& a, const uint4& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
}
inline uint4 operator-(const uint4& a, uint b)
{
	return make_uint4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline uint4 operator-(uint b, const uint4& a)
{
	return make_uint4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline uint4 operator-=(uint4& a, uint b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
	a.w -= b;
}

// float2
inline float2 operator-(const float2& a, const float2& b)
{
	return make_float2(a.x - b.x, a.y - b.y);
}
inline float2 operator-=(float2& a, const float2& b)
{
	a.x -= b.x;
	a.y -= b.y;
}
inline float2 operator-(const float2& a, float b)
{
	return make_float2(a.x - b, a.y - b);
}
inline float2 operator-(float b, const float2& a)
{
	return make_float2(a.x - b, a.y - b);
}
inline float2 operator-=(float2& a, float b)
{
	a.x -= b;
	a.y -= b;
}

// float3
inline float3 operator-(const float3& a, const float3& b)
{
	return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline float3 operator-=(float3& a, const float3& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
}
inline float3 operator-(const float3& a, float b)
{
	return make_float3(a.x - b, a.y - b, a.z - b);
}
inline float3 operator-(float b, const float3& a)
{
	return make_float3(a.x - b, a.y - b, a.z - b);
}
inline float3 operator-=(float3& a, float b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
}

// float4
inline float4 operator-(const float4& a, const float4& b)
{
	return make_float4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
inline float4 operator-=(float4& a, const float4& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
}
inline float4 operator-(const float4& a, float b)
{
	return make_float4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline float4 operator-(float b, const float4& a)
{
	return make_float4(a.x - b, a.y - b, a.z - b, a.w - b);
}
inline float4 operator-=(float4& a, float b)
{
	a.x -= b;
	a.y -= b;
	a.z -= b;
	a.w -= b;
}

////////////////////////////////////////////////////////////////
// multiply
////////////////////////////////////////////////////////////////
// int2
inline int2 operator*(const int2& a, const int2& b)
{
	return make_int2(a.x * b.x, a.y * b.y);
}
inline int2 operator*=(int2& a, const int2& b)
{
	a.x *= b.x;
	a.y *= b.y;
}
inline int2 operator*(const int2& a, int b)
{
	return make_int2(a.x * b, a.y * b);
}
inline int2 operator*(int b, const int2& a)
{
	return make_int2(a.x * b, a.y * b);
}
inline int2 operator*=(int2& a, int b)
{
	a.x *= b;
	a.y *= b;
}

// int3
inline int3 operator*(const int3& a, const int3& b)
{
	return make_int3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline int3 operator*=(int3& a, const int3& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
}
inline int3 operator*(const int3& a, int b)
{
	return make_int3(a.x * b, a.y * b, a.z * b);
}
inline int3 operator*(int b, const int3& a)
{
	return make_int3(a.x * b, a.y * b, a.z * b);
}
inline int3 operator*=(int3& a, int b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
}

// int4
inline int4 operator*(const int4& a, const int4& b)
{
	return make_int4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
inline int4 operator*=(int4& a, const int4& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
}
inline int4 operator*(const int4& a, int b)
{
	return make_int4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline int4 operator*(int b, const int4& a)
{
	return make_int4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline int4 operator*=(int4& a, int b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	a.w *= b;
}

// uint2
inline uint2 operator*(const uint2& a, const uint2& b)
{
	return make_uint2(a.x * b.x, a.y * b.y);
}
inline uint2 operator*=(uint2& a, const uint2& b)
{
	a.x *= b.x;
	a.y *= b.y;
}
inline uint2 operator*(const uint2& a, uint b)
{
	return make_uint2(a.x * b, a.y * b);
}
inline uint2 operator*(uint b, const uint2& a)
{
	return make_uint2(a.x * b, a.y * b);
}
inline uint2 operator*=(uint2& a, uint b)
{
	a.x *= b;
	a.y *= b;
}

// uint3
inline uint3 operator*(const uint3& a, const uint3& b)
{
	return make_uint3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline uint3 operator*=(uint3& a, const uint3& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
}
inline uint3 operator*(const uint3& a, uint b)
{
	return make_uint3(a.x * b, a.y * b, a.z * b);
}
inline uint3 operator*(uint b, const uint3& a)
{
	return make_uint3(a.x * b, a.y * b, a.z * b);
}
inline uint3 operator*=(uint3& a, uint b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
}

// uint4
inline uint4 operator*(const uint4& a, const uint4& b)
{
	return make_uint4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
inline uint4 operator*=(uint4& a, const uint4& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
}
inline uint4 operator*(const uint4& a, uint b)
{
	return make_uint4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline uint4 operator*(uint b, const uint4& a)
{
	return make_uint4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline uint4 operator*=(uint4& a, uint b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	a.w *= b;
}

// float2
inline float2 operator*(const float2& a, const float2& b)
{
	return make_float2(a.x * b.x, a.y * b.y);
}
inline float2 operator*=(float2& a, const float2& b)
{
	a.x *= b.x;
	a.y *= b.y;
}
inline float2 operator*(const float2& a, float b)
{
	return make_float2(a.x * b, a.y * b);
}
inline float2 operator*(float b, const float2& a)
{
	return make_float2(a.x * b, a.y * b);
}
inline float2 operator*=(float2& a, float b)
{
	a.x *= b;
	a.y *= b;
}

// float3
inline float3 operator*(const float3& a, const float3& b)
{
	return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline float3 operator*=(float3& a, const float3& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
}
inline float3 operator*(const float3& a, float b)
{
	return make_float3(a.x * b, a.y * b, a.z * b);
}
inline float3 operator*(float b, const float3& a)
{
	return make_float3(a.x * b, a.y * b, a.z * b);
}
inline float3 operator*=(float3& a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
}

// float4
inline float4 operator*(const float4& a, const float4& b)
{
	return make_float4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
inline float4 operator*=(float4& a, const float4& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
}
inline float4 operator*(const float4& a, float b)
{
	return make_float4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline float4 operator*(float b, const float4& a)
{
	return make_float4(a.x * b, a.y * b, a.z * b, a.w * b);
}
inline float4 operator*=(float4& a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	a.w *= b;
}

////////////////////////////////////////////////////////////////
// divide
////////////////////////////////////////////////////////////////
// int2
inline int2 operator/(const int2& a, const int2& b)
{
	return make_int2(a.x / b.x, a.y / b.y);
}
inline int2 operator/=(int2& a, const int2& b)
{
	a.x /= b.x;
	a.y /= b.y;
}
inline int2 operator/(const int2& a, int b)
{
	return make_int2(a.x / b, a.y / b);
}
inline int2 operator/(int b, const int2& a)
{
	return make_int2(a.x / b, a.y / b);
}
inline int2 operator/=(int2& a, int b)
{
	a.x /= b;
	a.y /= b;
}

// int3
inline int3 operator/(const int3& a, const int3& b)
{
	return make_int3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline int3 operator/=(int3& a, const int3& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
}
inline int3 operator/(const int3& a, int b)
{
	return make_int3(a.x / b, a.y / b, a.z / b);
}
inline int3 operator/(int b, const int3& a)
{
	return make_int3(a.x / b, a.y / b, a.z / b);
}
inline int3 operator/=(int3& a, int b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
}

// int4
inline int4 operator/(const int4& a, const int4& b)
{
	return make_int4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}
inline int4 operator/=(int4& a, const int4& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
}
inline int4 operator/(const int4& a, int b)
{
	return make_int4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline int4 operator/(int b, const int4& a)
{
	return make_int4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline int4 operator/=(int4& a, int b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	a.w /= b;
}

// uint2
inline uint2 operator/(const uint2& a, const uint2& b)
{
	return make_uint2(a.x / b.x, a.y / b.y);
}
inline uint2 operator/=(uint2& a, const uint2& b)
{
	a.x /= b.x;
	a.y /= b.y;
}
inline uint2 operator/(const uint2& a, uint b)
{
	return make_uint2(a.x / b, a.y / b);
}
inline uint2 operator/(uint b, const uint2& a)
{
	return make_uint2(a.x / b, a.y / b);
}
inline uint2 operator/=(uint2& a, uint b)
{
	a.x /= b;
	a.y /= b;
}

// uint3
inline uint3 operator/(const uint3& a, const uint3& b)
{
	return make_uint3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline uint3 operator/=(uint3& a, const uint3& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
}
inline uint3 operator/(const uint3& a, uint b)
{
	return make_uint3(a.x / b, a.y / b, a.z / b);
}
inline uint3 operator/(uint b, const uint3& a)
{
	return make_uint3(a.x / b, a.y / b, a.z / b);
}
inline uint3 operator/=(uint3& a, uint b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
}

// uint4
inline uint4 operator/(const uint4& a, const uint4& b)
{
	return make_uint4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}
inline uint4 operator/=(uint4& a, const uint4& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
}
inline uint4 operator/(const uint4& a, uint b)
{
	return make_uint4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline uint4 operator/(uint b, const uint4& a)
{
	return make_uint4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline uint4 operator/=(uint4& a, uint b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	a.w /= b;
}

// float2
inline float2 operator/(const float2& a, const float2& b)
{
	return make_float2(a.x / b.x, a.y / b.y);
}
inline float2 operator/=(float2& a, const float2& b)
{
	a.x /= b.x;
	a.y /= b.y;
}
inline float2 operator/(const float2& a, float b)
{
	return make_float2(a.x / b, a.y / b);
}
inline float2 operator/(float b, const float2& a)
{
	return make_float2(a.x / b, a.y / b);
}
inline float2 operator/=(float2& a, float b)
{
	a.x /= b;
	a.y /= b;
}

// float3
inline float3 operator/(const float3& a, const float3& b)
{
	return make_float3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline float3 operator/=(float3& a, const float3& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
}
inline float3 operator/(const float3& a, float b)
{
	return make_float3(a.x / b, a.y / b, a.z / b);
}
inline float3 operator/(float b, const float3& a)
{
	return make_float3(a.x / b, a.y / b, a.z / b);
}
inline float3 operator/=(float3& a, float b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
}

// float4
inline float4 operator/(const float4& a, const float4& b)
{
	return make_float4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}
inline float4 operator/=(float4& a, const float4& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
}
inline float4 operator/(const float4& a, float b)
{
	return make_float4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline float4 operator/(float b, const float4& a)
{
	return make_float4(a.x / b, a.y / b, a.z / b, a.w / b);
}
inline float4 operator/=(float4& a, float b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	a.w /= b;
}

////////////////////////////////////////////////////////////////
// min
////////////////////////////////////////////////////////////////
inline int2 min(const int2& a, const int2& b)
{
	return make_int2(min(a.x, b.x), min(a.y, b.y));
}
inline int3 min(const int3& a, const int3& b)
{
	return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}
inline int4 min(const int4& a, const int4& b)
{
	return make_int4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}
inline uint2 min(const uint2& a, const uint2& b)
{
	return make_uint2(min(a.x, b.x), min(a.y, b.y));
}
inline uint3 min(const uint3& a, const uint3& b)
{
	return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}
inline uint4 min(const uint4& a, const uint4& b)
{
	return make_uint4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}
inline float2 fminf(const float2& a, const float2& b)
{
	return make_float2(fminf(a.x, b.x), fminf(a.y, b.y));
}
inline float3 fminf(const float3& a, const float3& b)
{
	return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
}
inline float4 fminf(const float4& a, const float4& b)
{
	return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
}

////////////////////////////////////////////////////////////////
// max
////////////////////////////////////////////////////////////////
inline int2 max(const int2& a, const int2& b)
{
	return make_int2(max(a.x, b.x), max(a.y, b.y));
}
inline int3 max(const int3& a, const int3& b)
{
	return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}
inline int4 max(const int4& a, const int4& b)
{
	return make_int4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}
inline uint2 max(const uint2& a, const uint2& b)
{
	return make_uint2(max(a.x, b.x), max(a.y, b.y));
}
inline uint3 max(const uint3& a, const uint3& b)
{
	return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}
inline uint4 max(const uint4& a, const uint4& b)
{
	return make_uint4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}
inline float2 fmaxf(const float2& a, const float2& b)
{
	return make_float2(fmaxf(a.x, b.x), fmaxf(a.y, b.y));
}
inline float3 fmaxf(const float3& a, const float3& b)
{
	return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
}
inline float4 fmaxf(const float4& a, const float4& b)
{
	return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
}

////////////////////////////////////////////////////////////////
// clamp
////////////////////////////////////////////////////////////////
inline int clamp(int v, int a, int b)
{
	return max(a, min(v, b));
}
inline int2 clamp(const int2& v, int a, int b)
{
	return make_int2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline int2 clamp(const int2& v, const int2& a, const int2& b)
{
	return make_int2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline int3 clamp(const int3& v, int a, int b)
{
	return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline int3 clamp(const int3& v, const int3& a, const int3& b)
{
	return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
inline int4 clamp(const int4& v, int a, int b)
{
	return make_int4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
inline int4 clamp(const int4& v, const int4& a, const int4& b)
{
	return make_int4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}
inline uint clamp(uint v, uint a, uint b)
{
	return max(a, min(v, b));
}
inline uint2 clamp(const uint2& v, uint a, uint b)
{
	return make_uint2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline uint2 clamp(const uint2& v, const uint2& a, const uint2& b)
{
	return make_uint2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline uint3 clamp(const uint3& v, uint a, uint b)
{
	return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline uint3 clamp(const uint3& v, const uint3& a, const uint3& b)
{
	return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
inline uint4 clamp(const uint4& v, uint a, uint b)
{
	return make_uint4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
inline uint4 clamp(const uint4& v, const uint4& a, const uint4& b)
{
	return make_uint4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}
inline float clamp(float v, float a, float b)
{
	return fmaxf(a, fminf(v, b));
}
inline float2 clamp(const float2& v, float a, float b)
{
	return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline float2 clamp(const float2& v, const float2& a, const float2& b)
{
	return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline float3 clamp(const float3& v, float a, float b)
{
	return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline float3 clamp(const float3& v, const float3& a, const float3& b)
{
	return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
inline float4 clamp(const float4& v, float a, float b)
{
	return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
inline float4 clamp(const float4& v, const float4& a, const float4& b)
{
	return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

////////////////////////////////////////////////////////////////
// lerp
////////////////////////////////////////////////////////////////
inline float lerp(float a, float b, float t)
{
	return a + t*(b-a);
}
inline float2 lerp(const float2& a, const float2& b, float t)
{
	return a + t*(b-a);
}
inline float3 lerp(const float3& a, const float3& b, float t)
{
	return a + t*(b-a);
}
inline float4 lerp(const float4& a, const float4& b, float t)
{
	return a + t*(b-a);
}

////////////////////////////////////////////////////////////////
// dot product
////////////////////////////////////////////////////////////////
inline int dot(const int2& a, const int2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}
inline int dot(const int3& a, const int3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
inline int dot(const int4& a, const int4& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
inline uint dot(const uint2& a, const uint2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}
inline uint dot(const uint3& a, const uint3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
inline uint dot(const uint4& a, const uint4& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
inline float dot(const float2& a, const float2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}
inline float dot(const float3& a, const float3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
inline float dot(const float4& a, const float4& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

////////////////////////////////////////////////////////////////
// length
////////////////////////////////////////////////////////////////
inline float length(const float2& v)
{
	return sqrtf(dot(v, v));
}
inline float length(const float3& v)
{
	return sqrtf(dot(v, v));
}
inline float length(const float4& v)
{
	return sqrtf(dot(v, v));
}

////////////////////////////////////////////////////////////////
// normalize
////////////////////////////////////////////////////////////////
inline float2 normalize(const float2& v)
{
	return v * rsqrtf(dot(v, v));
}
inline float3 normalize(const float3& v)
{
	return v * rsqrtf(dot(v, v));
}
inline float4 normalize(const float4& v)
{
	return v * rsqrtf(dot(v, v));
}

////////////////////////////////////////////////////////////////
// cross product
////////////////////////////////////////////////////////////////
inline float3 cross(const float3& a, const float3& b)
{
	return make_float3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

////////////////////////////////////////////////////////////////
// floor
////////////////////////////////////////////////////////////////
inline float2 floorf(const float2& v)
{
	return make_float2(floorf(v.x), floorf(v.y));
}
inline float3 floorf(const float3& v)
{
	return make_float3(floorf(v.x), floorf(v.y), floorf(v.z));
}
inline float4 floorf(const float4& v)
{
	return make_float4(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
}

////////////////////////////////////////////////////////////////
// ceil
////////////////////////////////////////////////////////////////
inline float2 ceilf(const float2& v)
{
	return make_float2(ceilf(v.x), ceilf(v.y));
}
inline float3 ceilf(const float3& v)
{
	return make_float3(ceilf(v.x), ceilf(v.y), ceilf(v.z));
}
inline float4 ceilf(const float4& v)
{
	return make_float4(ceilf(v.x), ceilf(v.y), ceilf(v.z), ceilf(v.w));
}

////////////////////////////////////////////////////////////////
// frac
////////////////////////////////////////////////////////////////
inline float fracf(float v)
{
	return v - floorf(v);
}
inline float2 fracf(const float2& v)
{
	return make_float2(fracf(v.x), fracf(v.y));
}
inline float3 fracf(const float3& v)
{
	return make_float3(fracf(v.x), fracf(v.y), fracf(v.z));
}
inline float4 fracf(const float4& v)
{
	return make_float4(fracf(v.x), fracf(v.y), fracf(v.z), fracf(v.w));
}

////////////////////////////////////////////////////////////////
// modulo
////////////////////////////////////////////////////////////////
inline float2 fmodf(const float2& a, const float2& b)
{
	return make_float2(fmodf(a.x, b.x), fmodf(a.y, b.y));
}
inline float3 fmodf(const float3& a, const float3& b)
{
	return make_float3(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z));
}
inline float4 fmodf(const float4& a, const float4& b)
{
	return make_float4(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z), fmodf(a.w, b.w));
}

////////////////////////////////////////////////////////////////
// absolute
////////////////////////////////////////////////////////////////
inline int2 abs(const int2& v)
{
	return make_int2(abs(v.x), abs(v.y));
}
inline int3 abs(const int3& v)
{
	return make_int3(abs(v.x), abs(v.y), abs(v.z));
}
inline int4 abs(const int4& v)
{
	return make_int4(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
}
inline float2 fabsf(const float2& v)
{
	return make_float2(fabsf(v.x), fabsf(v.y));
}
inline float3 fabsf(const float3& v)
{
	return make_float3(fabsf(v.x), fabsf(v.y), fabsf(v.z));
}
inline float4 fabsf(const float4& v)
{
	return make_float4(fabsf(v.x), fabsf(v.y), fabsf(v.z), fabsf(v.w));
}

////////////////////////////////////////////////////////////////
// reflect
////////////////////////////////////////////////////////////////
inline float3 reflect(const float3& i, const float3& n)
{
	return i - 2.0f * n * dot(n, i);
}

////////////////////////////////////////////////////////////////
// smoothstep
////////////////////////////////////////////////////////////////
inline float smnoothstep(float a, float b, float t)
{
	float y = clamp((t - a) / (b - a), float(0), float(1));
	return (y * y * (float(3) - (float(2) * y)));
}
inline float2 smnoothstep(const float2& a, const float2& b, const float2& t)
{
	float2 y = clamp((t - a) / (b - a), float(0), float(1));
	return (y * y * (make_float2(3) - (make_float2(2) * y)));
}
inline float3 smnoothstep(const float3& a, const float3& b, const float3& t)
{
	float3 y = clamp((t - a) / (b - a), float(0), float(1));
	return (y * y * (make_float3(3) - (make_float3(2) * y)));
}
inline float4 smnoothstep(const float4& a, const float4& b, const float4& t)
{
	float4 y = clamp((t - a) / (b - a), float(0), float(1));
	return (y * y * (make_float4(3) - (make_float4(2) * y)));
}

////////////////////////////////////////////////////////////////
// float3x4
////////////////////////////////////////////////////////////////
struct alignas(16) float3x4
{
	float3 x; float tx;
	float3 y; float ty;
	float3 z; float tz;
};

// creation
inline float3x4 make_float3x4(float xx = 1, float xy = 0, float xz = 0,
								float yx = 0, float yy = 1, float yz = 0,
								float zx = 0, float zy = 0, float zz = 1,
								float tx = 0, float ty = 0, float tz = 0)
{
	float3x4 t;
	t.x = make_float3(xx, xy, xz);
	t.y = make_float3(yx, yy, yz);
	t.z = make_float3(zx, zy, zz);
	t.tx = tx;
	t.ty = ty;
	t.tz = tz;
	return t;
}

inline float3x4 make_float3x4(const float3& x, const float3& y, const float3& z, float3 w)
{
	float3x4 t;
	t.x = x;
	t.y = y;
	t.z = z;
	t.tx = w.x;
	t.ty = w.y;
	t.tz = w.z;
	return t;
}

// transform
inline float3x4 transform(const float3x4& a, const float3x4& b)
{
	const float3 t = make_float3(a.tx, a.ty, a.tz);
	const float3 b_x = make_float3(b.x.x, b.y.x, b.z.x);
	const float3 b_y = make_float3(b.x.y, b.y.y, b.z.y);
	const float3 b_z = make_float3(b.x.z, b.y.z, b.z.z);

	return make_float3x4(
		dot(a.x, b_x),
		dot(a.x, b_y),
		dot(a.x, b_z),

		dot(a.y, b_x),
		dot(a.y, b_y),
		dot(a.y, b_z),

		dot(a.z, b_x),
		dot(a.z, b_y),
		dot(a.z, b_z),

		dot(t, b_x) + b.tx,
		dot(t, b_y) + b.ty,
		dot(t, b_z) + b.tz);
}

inline float4 transform(const float3x4& a, const float4& b)
{
	return make_float4(
		dot(b, make_float4(a.x.x, a.y.x, a.z.x, a.tx)),
		dot(b, make_float4(a.x.y, a.y.y, a.z.y, a.ty)),
		dot(b, make_float4(a.x.z, a.y.z, a.z.z, a.tz)),
		b.w);
}

// rotate
inline float3x4 rotate_x_3x4(float a)
{
	const float s = sinf(a);
	const float c = cosf(a);

	float3x4 m = make_float3x4();
	m.y.y = c;
	m.y.z = s;
	m.z.y = -s;
	m.z.z = c;
	return m;
}

inline float3x4 rotate_y_3x4(float a)
{
	const float s = sinf(a);
	const float c = cosf(a);

	float3x4 m = make_float3x4();
	m.x.x = c;
	m.x.z = -s;
	m.z.x = s;
	m.z.z = c;
	return m;
}

inline float3x4 rotate_z_3x4(float a)
{
	const float s = sinf(a);
	const float c = cosf(a);

	float3x4 m = make_float3x4();
	m.x.x = c;
	m.x.y = s;
	m.y.x = -s;
	m.y.y = c;
	return m;
}

inline float3x4 rotate_3x4(float x, float y, float z)
{
	const float cx = cosf(x);
	const float sx = sinf(x);
	const float cy = cosf(y);
	const float sy = sinf(y);
	const float cz = cosf(z);
	const float sz = sinf(z);

	return make_float3x4(
		cy * cz,
		sy*sx - cy*sz*cx,
		cy*sz*sx + sy*cx,
		sz,
		cz*cx,
		-cz*sx,
		-sy*cz,
		sy*sz*cx + cy*sx,
		-sy*sz*sx + cy*cx);
}

inline float3x4 rotate_3x4(const float3& euler)
{
	return rotate_3x4(euler.x, euler.y, euler.z);
}

// scale
inline float3x4 scale_3x4(float scale)
{
	float3x4 m = make_float3x4();
	m.x.x = scale;
	m.y.y = scale;
	m.z.z = scale;
	return m;
}

inline float3x4 scale_3x4(float x, float y, float z)
{
	float3x4 m = make_float3x4();
	m.x.x = x;
	m.y.y = y;
	m.z.z = z;
	return m;
}

inline float3x4 scale_3x4(const float3& scale)
{
	return scale_3x4(scale.x, scale.y, scale.z);
}

// translate
inline float3x4 translate_3x4(float x, float y, float z)
{
	float3x4 m = make_float3x4();
	m.tx = x;
	m.ty = y;
	m.tz = z;
	return m;
}

inline float3x4 translate_3x4(const float3& t)
{
	return translate_3x4(t.x, t.y, t.z);
}

// look at
inline float3x4 look_at(const float3& from, const float3& to, const float3& up)
{
	const float3 z = normalize(to - from);
	const float3 x = normalize(cross(up, z));
	const float3 y = normalize(cross(z, x));

	float3x4 m = make_float3x4();
	m.x = x;
	m.y = y;
	m.z = z;
	m.tx = from.x;
	m.ty = from.y;
	m.tz = from.z;
	return m;
}

// interpolation
inline float3x4 lerp(const float3x4& a, const float3x4& b, float t)
{
	const float3 ta = make_float3(a.tx, a.ty, a.tz);
	const float3 tb = make_float3(b.tx, b.ty, b.tz);
	return make_float3x4(lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t), lerp(ta, tb, t));
}

// deteminant
inline float determinant(const float3x4& a)
{
	return (a.x.x * (a.y.y * a.z.z - a.y.z * a.z.y) +
			a.x.y * (a.y.z * a.z.x - a.y.x * a.z.z) +
			a.x.z * (a.y.x * a.z.y - a.y.y * a.z.x));
}

// inverse
inline float3x4 inverse(const float3x4& a)
{
	const float det3 = a.x.x * (a.y.y*a.z.z - a.y.z*a.z.y) - a.x.y * (a.y.x*a.z.z - a.y.z*a.z.x) + a.x.z * (a.y.x*a.z.y - a.y.y*a.z.x);
	const float inv_det3 = 1.0f / det3;

	const float inv00 = inv_det3 * (a.y.y*a.z.z - a.z.y*a.y.z);
	const float inv01 = inv_det3 * (a.x.z*a.z.y - a.z.z*a.x.y);
	const float inv02 = inv_det3 * (a.x.y*a.y.z - a.y.y*a.x.z);

	const float inv10 = inv_det3 * (a.y.z*a.z.x - a.z.z*a.y.x);
	const float inv11 = inv_det3 * (a.x.x*a.z.z - a.z.x*a.x.z);
	const float inv12 = inv_det3 * (a.x.z*a.y.x - a.y.z*a.x.x);

	const float inv20 = inv_det3 * (a.y.x*a.z.y - a.z.x*a.y.y);
	const float inv21 = inv_det3 * (a.x.y*a.z.x - a.z.y*a.x.x);
	const float inv22 = inv_det3 * (a.x.x*a.y.y - a.y.x*a.x.y);

	float3x4 result;
	result.x.x = inv00;
	result.x.y = inv01;
	result.x.z = inv02;

	result.y.x = inv10;
	result.y.y = inv11;
	result.y.z = inv12;

	result.z.x = inv20;
	result.z.y = inv21;
	result.z.z = inv22;

	result.tx = -inv00 * a.tx - inv01 * a.ty - inv02 * a.tz;
	result.ty = -inv10 * a.tx - inv11 * a.ty - inv12 * a.tz;
	result.tz = -inv20 * a.tx - inv21 * a.ty - inv22 * a.tz;
	return result;
}

// decompose
inline void decompose(const float3x4& a, float3& pos, float3& euler, float3& scale)
{
	pos = make_float3(a.tx, a.ty, a.tz);
	scale = make_float3(length(a.x), length(a.y), length(a.z));

	const float3 tx = normalize(a.x);
	const float3 ty = normalize(a.y);
	const float3 tz = normalize(a.z);
	if(ty.x > .998f)
	{
		euler = make_float3(0, atan2f(tx.z, tz.z), Pi * .5f);
	}
	else if(ty.x < -.998f)
	{
		euler = make_float3(0, atan2f(tx.z, tz.z), -Pi * .5f);
	}
	else
	{
		euler = make_float3(atan2f(-ty.z, ty.y), atan2f(-tz.x, tx.x), asinf(ty.x));
	}
}

// operators
inline float4 operator*(const float3x4& a, const float4& b) { return transform(a, b); }
inline float3x4 operator*(const float3x4& a, const float3x4& b) { return transform(a, b); }
inline float3x4& operator*=(float3x4& a, const float3x4& b) { return a = transform(a, b); }

