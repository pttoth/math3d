#pragma once

#include "pt/math/float4x4.h"

namespace math{

// Represents a rotation, or orientation of an object.
// Conventions:
//   angles:    degrees, CCW-positive
//   matrix:    right-handed, column-major
//   rotation:  y-z-x'' rotation in pitch-yaw-roll order (pitch & yaw are extrinsic, roll is instrinsic)
//   transform: Mtx = R(x'', roll) * R(yaw) * R(pitch)
struct FRotator{
    float mPitch = 0.0f;
    float mYaw   = 0.0f;
    float mRoll  = 0.0f;

    FRotator() = default;
    virtual ~FRotator(){}
    FRotator( const FRotator& other ) = default;
    FRotator( FRotator&& source ) = default;
    FRotator& operator=( const FRotator& other ) = default;
    FRotator& operator=( FRotator&& source ) = default;
    bool operator==( const FRotator& other ) const;

    FRotator( float pitch, float yaw, float roll );
    FRotator( const float3& values );
    //FRotator( const float4x4& transform );
    float4x4 GetTransform() const;
};


} // end of namespace 'math'
