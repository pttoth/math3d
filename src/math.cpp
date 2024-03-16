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


