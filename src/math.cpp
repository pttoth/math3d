#include "pt/math.h"

#include <sstream>

std::string pt::math::
VectorToString(size_t count, float* v, Verbosity mode)
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


std::string pt::math::
Float3ToString(const float3 &v, Verbosity mode)
{
    return VectorToString(3, v.v, mode);
}


std::string pt::math::
Float4ToString(const float4 &v, Verbosity mode)
{
    return PrintVector(4, v.v, mode);
}


std::string pt::math::
Float4x4ToString(const pt::math::float4x4& m, Verbosity mode)
{
    std::stringstream ss;
    if(mode == Verbosity::FRIENDLY){
        ss << "[\n";
        for(size_t j=0; j<4; ++j){
            for(size_t i=0; i<4; ++i){
                ss << m.m[j][i];
                if(i < 3){
                    ss << ",\t";
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
