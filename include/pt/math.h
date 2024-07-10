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

#define PT_MATH_ERROR_MARGIN 0.00001f

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


inline bool
IsNaN( const float2& vec )
{
    return std::isnan(vec.x) || std::isnan(vec.y);
}


inline bool
IsNaN( const float3& vec )
{
    return std::isnan(vec.x) || std::isnan(vec.y) || std::isnan(vec.z);
}


inline bool
IsNaN( const float4& vec )
{
    return std::isnan(vec.x) || std::isnan(vec.y)|| std::isnan(vec.z) || std::isnan(vec.w);
}


inline float
CalcAngle( const float3& a, const float3& b )
{
    const float margin = PT_MATH_ERROR_MARGIN;
    const vec3 A = a.normalize();
    const vec3 B = b.normalize();
    const vec3 N = A.cross( B ).normalize();
    if( IsNaN(A) || IsNaN(B) ){ // one or both input vectors were invalid, or had zero length
        //TODO: when this is moved to 'ptlib', enable the code below:
/*
        PT_LOG_WARN( "Tried to calculate angle between invalid vectors!" << ToString(a) << ToString(b) );
        #ifdef PT_DEBUG_ENABLED
            pt::PrintStacktrace();
        #endif
*/
        return 0.0f;
    }
    if( IsNaN( N ) ){ // vectors were parallel
        if( (A - B).length() < margin ){
            return 0.0f;
        }
        return M_PI;
    }


    // find out the direction of the angle
    int angle_sign = 1;
    if( N.z < -margin){ // use the XY plane as reference (X right, Y up, CCW: Z-positive normal)
        angle_sign = -1;
    }else if( (-margin < N.z) && (N.z < margin) ){ // if the axis of the angle is on the XY plane
        if ( 0 < (B-A).z ){
            angle_sign = -1;
        }
    }

    float dot    = A.dot( B );
    float det    = A[0]*B[1]*N[2] + A[1]*B[2]*N[0] + A[2]*B[0]*N[1] - A[2]*B[1]*N[0] - A[1]*B[0]*N[2] - A[0]*B[2]*N[1];
    return atan2f( det, dot ) * angle_sign;
}


inline float
CalcAngle( const float4& a, const float4& b )
{
    return CalcAngle( a.XYZ(), b.XYZ() );
}


inline float3
Vecf3FromVecf4( const float4& vec )
{
    return float3( vec.x/vec.w, vec.y/vec.w, vec.z/vec.w );
}

} // math

#pragma GCC diagnostic pop
//#pragma warning( enable : 4201 )
