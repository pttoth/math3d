#include "pt/math/quaternion.h"

#include "pt/math.h"

using namespace math;

const quaternion quaternion::identity = quaternion( 1.0f,0.0f,0.0f,0.0f );

quaternion::
quaternion()
{}


quaternion::
quaternion( float afW, float afX, float afY, float afZ ):
    mQuat( afW, afX, afY, afZ )
{}


quaternion::
quaternion( float afAngle, float3 avAxis ):
    mQuat( afAngle, avAxis )
{}


quaternion::
quaternion( float4x4 rotation_mtx )
{
    mQuat.FromRotationMatrix( rotation_mtx );
}


quaternion::
quaternion( const quaternion& other ):
    mQuat( other.mQuat )
{}


quaternion &quaternion::
operator=( const quaternion& other )
{
    mQuat = other.mQuat;
}


bool quaternion::
operator==( const quaternion& other ) const
{
    return ( mQuat.w == other.mQuat.w ) && (mQuat.v == other.mQuat.v).all();
}


quaternion quaternion::
operator+( const quaternion& aqB ) const
{
    quaternion ret;
    ret.mQuat = mQuat + aqB.mQuat;
    return ret;
}


quaternion quaternion::
operator-( const quaternion& aqB ) const
{
    quaternion ret;
    ret.mQuat = mQuat - aqB.mQuat;
    return ret;
}


quaternion quaternion::
operator*( const quaternion& aqB ) const
{
    quaternion ret;
    ret.mQuat = mQuat * aqB.mQuat;
    return ret;
}


quaternion quaternion::
operator*( float afScalar ) const
{
    quaternion ret;
    ret.mQuat = mQuat * afScalar;
    return ret;
}


void quaternion::
Normalize()
{
    mQuat.Normalise();
}


float4x4 quaternion::
GetRotationMtx() const
{
    mat4 ret = mat4::identity;
    mQuat.ToRotationMatrix( ret );
    return ret;
}


