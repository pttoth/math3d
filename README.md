# 3d Math library (by: dr. László Szécsi)

### Author: dr. László Szécsi https://www.iit.bme.hu/users/dr-szécsi-lászló

### Legal: Any reuse of this library has to credit him as the author of the original code.

---

## Modifications made to the original

### Added macro: MATH_ENABLE_SWIZZLE

> Swizzle is a syntax helper to easily rearrange vector coordinates (eg.: v2 = v1.zyx).

> A tradeoff is that it bloats the debug binaries and severely slows down compilation when included in multiple compilation units.

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
