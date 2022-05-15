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

namespace pt{
namespace math{

//controls print functions' verbosity
enum class Verbosity{
    COMPACT,
    FRIENDLY
};

std::string Float3ToString(const float3& v, Verbosity mode = Verbosity::FRIENDLY);
std::string Float4ToString(const float4& v, Verbosity mode = Verbosity::FRIENDLY);

std::string Float4x4ToString(const float4x4& m, Verbosity mode = Verbosity::FRIENDLY);

inline float
CalcAngle(const float3& a, const float3& b)
{
    return acosf( a.dot(b) / sqrtf( (a.lengthSquared() * b.lengthSquared()) ) );
}

inline float
CalcAngle(const float4& a, const float4& b)
{
    return acosf( a.dot(b) / sqrtf( (a.lengthSquared() * b.lengthSquared()) ) );
}

inline float3
Vecf3FromVecf4(const float4& vec)
{
    return float3( vec.x/vec.w, vec.y/vec.w, vec.z/vec.w );
}


} }

#pragma GCC diagnostic pop
//#pragma warning( enable : 4201 )
