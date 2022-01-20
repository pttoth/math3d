# 3d Math library (by: dr. László Szécsi)

### Author: dr. László Szécsi https://www.iit.bme.hu/users/dr-szécsi-lászló

### Legal: Any reusage of this library has to credit him as the author of the original code.

-----

## Modifications made to the original

### Moved everything under the namespace 'pt'

### Added macro: MATH_REMOVE_PT_NAMESPACE

> Define it during compilation, if needed

### Added macro: MATH_ENABLE_SWIZZLE

> Swizzle is a feature to easily rearrange vector coordinates (eg.: v2 = v1.zyx).

> A tradeoff is that it bloats the binaries and severely slows down compilation when included in multiple compilation units.

> Define it during compilation, if needed

### Temporarily removed features that used VS compiler-specific syntax:

#### float1-4 functions

- isfinite()
- isinf()
- isnan()

### Clarified the inclusion hierarchy a bit

### Rewrote cases where the code used the optional swizzle features
#### float4

- quatExp()
- quatLn()

#### float4x4

- reflection()

### Suppressed some GCC warnings in math.h

### Removed original Visual Studio compiler warning suppressions
