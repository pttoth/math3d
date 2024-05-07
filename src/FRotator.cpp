#include "pt/math.h"

using namespace math;

FRotator::
FRotator( float pitch, float yaw, float roll ):
    mPitch( pitch ), mYaw( yaw ), mRoll( roll )
{}


FRotator::
FRotator( const float3& values ):
    FRotator( values.v[0], values.v[1], values.v[2] ) //avoiding ".x .y .z" notations, as they can be misleading for rotation axes
{}


/*
math::FRotator::
FRotator( const math::float4x4& transform )
{
    // DEPRECATED
    //   angles for extrinsic roll-pitch-yaw rotation axes
    //   fails in some cases (weird quick-twists occur in some angle-intervals, eg.: (near-zero yaw, near-PI pitch, zero roll) )
    //   '-0' matrix values may occur, could be, what's spoiling the formulas

    // transform is column-major
    // transform = R(yaw)*R(pitch)*R(roll)=...
    // | cos(yaw)cos(pitch)    cos(yaw)sin(pitch)sin(roll)-sin(yaw)cos(roll)   cos(yaw)sin(pitch)cos(roll)+sin(yaw)sin(roll)       0
    // | sin(yaw)cos(pitch)    sin(yaw)sin(pitch)sin(roll)+cos(yaw)cos(roll)   sin(yaw)sin(pitch)cos(roll)-cos(yaw)sin(roll)       0
    // | -sin(pitch)           cos(pitch)sin(roll)                             cos(pitch)cos(roll)                                 0
    // |       0                                 0                                               0                                 1

    const mat4& m = transform;
    float yaw, pitch, roll;
    float sin_pitch = (-1) * m._20;
    if( (1.0f == sin_pitch) || (-1.0f == sin_pitch) ){
        // gimbal lock, object is looking upwards(1), or downwards(-1)
        // in this case, a R(yaw)*R(+-pi/2)*R(0) can be calculated, which has the exact same transformation result, but simplifies the formula and makes 'yaw' calculable
        // m._02 = cos(yaw)sin(pitch)cos(roll)+sin(yaw)sin(roll) = cos(yaw) * (+-1) * 1 + sin(yaw) * 0 = +-cos(yaw) = scale * cos(yaw)
        // m._12 = sin(yaw)sin(pitch)cos(roll)-cos(yaw)sin(roll) = sin(yaw) * (+-1) * 1 - cos(yaw) * 0 = +-sin(yaw) = scale * sin(yaw) | 'scale' -> discardable :)
        roll   = 0.0f;
        pitch  = M_PI/2 * sin_pitch;
        yaw    = atan2f( m._12, m._02 );
    }else{
        roll   = atan2f( m._21, m._22 );
        pitch  = asinf( sin_pitch ); // asinf() only returns [-pi/2;pi/2], so cos(pitch) could still be '+-' here. Can the '-' case be discarded as 'atan2f' yields both other angles in [-pi; pi]?
        //mPitch  = atan2f( sin_pitch, sqrt( m._21*m._21 + m._22*m._22 ) );
        yaw    = atan2f( m._01, m._00 );
    }

    mRoll = roll / M_PI*180;
    mPitch = pitch / M_PI*180;
    mYaw = yaw / M_PI*180;
}
*/


float4x4 FRotator::
GetTransform() const
{
    mat4 pitchMtx = mat4::identity;
    mat4 yawMtx   = mat4::identity;
    mat4 rollMtx  = mat4::identity;

    float cosf_mPitch   = cosf( DegToRad( mPitch ) );
    float sinf_mPitch   = sinf( DegToRad( mPitch ) );
    float cosf_mYaw     = cosf( DegToRad( mYaw ) );
    float sinf_mYaw     = sinf( DegToRad( mYaw ) );
    //float cosf_mRoll    = cosf( DegToRad( mRoll ) );
    //float sinf_mRoll    = sinf( DegToRad( mRoll ) );

    pitchMtx.m[0][0] = cosf_mPitch;
    pitchMtx.m[0][2] = sinf_mPitch;
    pitchMtx.m[2][0] = sinf_mPitch * -1;
    pitchMtx.m[2][2] = cosf_mPitch;
    yawMtx.m[0][0] = cosf_mYaw;
    yawMtx.m[0][1] = sinf_mYaw * -1;
    yawMtx.m[1][0] = sinf_mYaw;
    yawMtx.m[1][1] = cosf_mYaw;
    //rollMtx.m[1][1] = cosf_mRoll;
    //rollMtx.m[1][2] = sinf_mRoll * -1;
    //rollMtx.m[2][1] = sinf_mRoll;
    //rollMtx.m[2][2] = cosf_mRoll;

    //  TODO: small optimization: write up end-matrix manually instead of multiplying thrice
    //return rollMtx * yawMtx * pitchMtx;

    mat4 res = yawMtx * pitchMtx;
    rollMtx = mat4::rotation( float3( res._00, res._10, res._20 ), mRoll );
    return rollMtx * res;
}


bool math::FRotator::
operator==( const FRotator& other ) const
{
    return (mPitch == other.mPitch) && (mYaw == other.mYaw) && (mRoll == other.mRoll);
}

