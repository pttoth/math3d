#include "pt/math.h"

#include <sstream>

using namespace math;

std::string
VectorToString( size_t count, const float* const v, Verbosity mode )
{
    std::stringstream ss;
    if(mode == Verbosity::FRIENDLY){
        ss << "(";
        for(size_t i=0; i<count; ++i){
            ss << v[i];
            if(i < count-1){
                ss << ";\t";
            }
        }
        ss << ")\n";
    }else{
        ss << "(";
        for(size_t i=0; i<count; ++i){
            ss << v[i];
            if(i < count-1){
                ss << ",";
            }
        }
        ss << ")";
    }
    return ss.str();
}


std::string math::
ToString( const float2& v, Verbosity mode )
{
    return VectorToString( 2, v.v, mode );
}


std::string math::
ToString( const float3& v, Verbosity mode )
{
    return VectorToString( 3, v.v, mode );
}


std::string math::
ToString( const float4& v, Verbosity mode )
{
    return VectorToString( 4, v.v, mode );
}


std::string math::
ToString( const math::float4x4& m, Verbosity mode )
{
    std::stringstream ss;
    if(mode == Verbosity::FRIENDLY){
        ss << "[\n";
        for(size_t j=0; j<4; ++j){
            for(size_t i=0; i<4; ++i){
                size_t lastlength = ss.tellp();
                ss << m.m[j][i];
                if(i < 3){
                    size_t len = ((size_t)ss.tellp()) - lastlength; // get length of written float
                    if( len < 7 ){
                        ss << ",\t\t";
                    }else{
                        ss << ",\t";
                    }
                }else{
                    ss << ";\n";
                }
            }
        }
        ss << "]\n";
    }else{
        ss << "[";
        for(size_t j=0; j<4; ++j){
            for(size_t i=0; i<4; ++i){
                ss << m.m[j][i];
                if(i < 3){
                    ss << ",";
                }else{
                    ss << ";\n";
                }
            }
        }
        ss << "]";
    }
    return ss.str();
}


float4x4 FRotator::
GetTransform() const
{
/*
    math::float4x4 yawMtx = math::float4x4::identity;
    math::float4x4 pitchMtx = math::float4x4::identity;
    math::float4x4 rollMtx = math::float4x4::identity;
*/
    float cosf_mYaw     = cosf( mYaw );
    float sinf_mYaw     = 1 - cosf_mYaw;
    float cosf_mPitch   = cosf( mPitch );
    float sinf_mPitch   = 1 - cosf_mPitch;
    float cosf_mRoll    = cosf( mRoll );
    float sinf_mRoll    = 1 - cosf_mRoll;
/*
    yawMtx.m[0][0] = cosf_mYaw;
    yawMtx.m[0][1] = sinf_mYaw * -1;
    yawMtx.m[1][0] = sinf_mYaw;
    yawMtx.m[1][1] = cosf_mYaw;
    pitchMtx.m[0][0] = cosf_mPitch;
    pitchMtx.m[0][2] = sinf_mPitch;
    pitchMtx.m[2][0] = sinf_mPitch * -1;
    pitchMtx.m[2][2] = cosf_mPitch;
    rollMtx.m[1][1] = cosf_mRoll;
    rollMtx.m[1][2] = sinf_mRoll * -1;
    rollMtx.m[2][1] = sinf_mRoll;
    rollMtx.m[2][2] = cosf_mRoll;
*/
    //return yawMtx * pitchMtx * rollMtx;


    // this is the resulting matrix from the above matrix multiplications
    math::float4x4 transform = math::float4x4::identity;
    transform.m[0][0] = cosf_mPitch * cosf_mRoll;
    transform.m[0][1] = sinf_mYaw * sinf_mPitch * cosf_mRoll - cosf_mYaw * sinf_mRoll;
    transform.m[0][2] = cosf_mYaw * sinf_mPitch * cosf_mRoll + sinf_mYaw * sinf_mRoll;

    transform.m[1][0] = cosf_mPitch * sinf_mRoll;
    transform.m[1][1] = sinf_mYaw * sinf_mPitch * sinf_mRoll + cosf_mYaw * cosf_mRoll;
    transform.m[1][2] = cosf_mYaw * sinf_mPitch * sinf_mRoll - sinf_mYaw * cosf_mRoll;

    transform.m[2][0] = sinf_mPitch * -1;
    transform.m[2][1] = sinf_mYaw * cosf_mPitch;
    transform.m[2][2] = cosf_mYaw * cosf_mPitch;

    return transform;
}
