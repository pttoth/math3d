#pragma once

#include "pt/HPL1/Quaternion.h"

namespace math{

class bool1;
class bool2;
class bool3;
class bool4;

class int1;
class int2;
class int3;
class int4;

class float1;
class float2;
class float3;
class float4;

class float4x4;

// note: For now, this is just a wrapper around Frictional Games' quaternion implementation
class quaternion
{
private:
    math::hpl::cQuaternion mQuat;
public:
    const math::float3& v = mQuat.v;
    const float& w = mQuat.w;

    quaternion();
    quaternion( float afW, float afX, float afY, float afZ );
    quaternion( float afAngle, float3 avAxis );
    quaternion( float4x4 rotation_mtx );

    quaternion( const quaternion& other );
    //quaternion( quaternion&& source );
    virtual ~quaternion(){}
    quaternion& operator=( const quaternion& other );
    //quaternion& operator=( quaternion&& source );

    bool operator==( const quaternion& other ) const;

    quaternion operator+( const quaternion& aqB ) const;
    quaternion operator-( const quaternion& aqB ) const;
    quaternion operator*( const quaternion& aqB ) const;
    quaternion operator*( float afScalar ) const;


    void Normalize();
    float4x4 GetRotationMtx() const;

    static const quaternion identity;
};

} // end of namespace 'math'
