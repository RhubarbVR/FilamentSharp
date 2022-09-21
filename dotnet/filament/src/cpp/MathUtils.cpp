#include "Export.h"
#include <math/mat3.h>
#include <math/quat.h>

using namespace filament::math;

extern "C" DOTNET_EXPORT void filament_MathUtils_nPackTangentFrame(float tangentX, float tangentY, float tangentZ,
                                                     float bitangentX, float bitangentY, float bitangentZ,
                                                     float normalX, float normalY, float normalZ,
                                                     float *quaternion, int offset) {

    float3 tangent{tangentX, tangentY, tangentZ};
    float3 bitangent{bitangentX, bitangentY, bitangentZ};
    float3 normal{normalX, normalY, normalZ};
    quatf q = mat3f::packTangentFrame({tangent, bitangent, normal});

    quaternion[0] = q[offset + 0];
    quaternion[1] = q[offset + 1];
    quaternion[2] = q[offset + 2];
    quaternion[3] = q[offset + 3];
}
