/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */

// edited by: ptoth
#ifndef HPL_QUATERNION_H
#define HPL_QUATERNION_H

#include "pt/math/float3.h"
#include "pt/math/float4x4.h"

namespace math{

namespace hpl {

    class cQuaternion
    {
    public:
        math::float3 v;
        float w = 0.0f;

        cQuaternion();
        cQuaternion( const cQuaternion& other );
        cQuaternion(float afAngle, const math::float3 &avAxis);
        cQuaternion(float afW, float afX, float afY, float afZ);

        void Normalise();
        void ToRotationMatrix( math::float4x4 &a_mtxDest) const;
        void FromRotationMatrix(const math::float4x4 &a_mtxRot);

        /**
         * Set the quaternion from and angle and axis.
         * \param afAngle
         * \param &avAxis MUST be unit length!
         */
        void FromAngleAxis(float afAngle, const math::float3 &avAxis);

        cQuaternion& operator=( const cQuaternion& other );
        cQuaternion operator+(const cQuaternion &aqB) const;
        cQuaternion operator-(const cQuaternion &aqB) const;
        cQuaternion operator*(const cQuaternion &aqB) const;
        cQuaternion operator*(float afScalar) const;

        static const cQuaternion Identity;

    private:
    };
}; // end of namespace 'hpl'

} // end of namespace 'math'

#endif // HPL_QUATERNION_H
