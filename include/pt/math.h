/*
 * -------------------------------------------------------------------------
 * FILE:    math.h
 * AUTHOR:  Dr. Szécsi László - szecsi@iit.bme.hu
 *          Peter Toth - peter.t.toth92@gmail.com  (minor modifications)
 * -------------------------------------------------------------------------
 */

#pragma once

#include <cmath>
#include <cstdlib>
#include <stdexcept>

//#pragma warning( disable : 4201 )
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wgnu-anonymous-struct"
//#pragma GCC diagnostic ignored "-Wnested-anon-types"
//#pragma GCC diagnostic ignored "-Wtautological-unsigned-zero-compare"
#pragma GCC diagnostic ignored "-Wunused-value"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wreturn-type"

#include "math/boolswizzle.h"
#include "math/bool1.h"
#include "math/bool2.h"
#include "math/bool3.h"
#include "math/bool4.h"

#include "math/intswizzle.h"
#include "math/int1.h"
#include "math/int2.h"
#include "math/int3.h"
#include "math/int4.h"

#include "math/floatswizzle.h"
#include "math/float2swizzle.h"
#include "math/float3swizzle.h"
#include "math/float4swizzle.h"
#include "math/float1.h"
#include "math/float2.h"
#include "math/float3.h"
#include "math/float4.h"

#include "math/float4x4.h"

#include "math/FRotator.h"
#include "math/quaternion.h"

namespace math{

using vec2 = math::float2;
using vec3 = math::float3;
using vec4 = math::float4;
using mat4 = math::float4x4;
using quat = math::quaternion;

// controls print functions' output verbosity
enum class Verbosity{
    COMPACT,
    FRIENDLY
};


std::string ToString( const int2& iv, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const int3& iv, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const int4& iv, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const float2& v, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const float3& v, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const float4& v, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const float4x4& m, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const FRotator& r, Verbosity mode = Verbosity::FRIENDLY );
std::string ToString( const quaternion& q, Verbosity mode = Verbosity::FRIENDLY );


inline float
DegToRad( float angle )
{
    return angle * M_PI/180.0f;
}

inline float
RadToDeg( float angle )
{
    return angle * 180.0f/M_PI;
}


inline float
CalcAngle( const float3& a, const float3& b )
{
    // TODO: use atan2
    return acosf( a.dot(b) / sqrtf( (a.lengthSquared() * b.lengthSquared()) ) );
}

inline float
CalcAngle( const float4& a, const float4& b )
{
    // TODO: use atan2
    return acosf( a.dot(b) / sqrtf( (a.lengthSquared() * b.lengthSquared()) ) );
}

inline float3
Vecf3FromVecf4( const float4& vec )
{
    return float3( vec.x/vec.w, vec.y/vec.w, vec.z/vec.w );
}

} // math

#pragma GCC diagnostic pop
//#pragma warning( enable : 4201 )
