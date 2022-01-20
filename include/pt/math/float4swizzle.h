/*
 * -------------------------------------------------------------------------
 * FILE:    float4swizzle.h
 * AUTHOR:  Dr. Szécsi László - szecsi@iit.bme.hu
 *          Peter Toth - peter.t.toth92@gmail.com  (minor modifications)
 * -------------------------------------------------------------------------
 */
#pragma once

#ifndef MATH_REMOVE_PT_NAMESPACE
namespace pt {
#endif
namespace math {

class float4;

template<int nBase, class T, int s0=0, int s1=1, int s2=2, int s3=3>
class float4swizzle : public floatswizzle<nBase, T, int4, bool4, s0, s1, s2, s3> 
{

};

} //math

#ifndef MATH_REMOVE_PT_NAMESPACE
} //PT
#endif
