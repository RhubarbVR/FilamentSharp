#include "Export.h"
#include <filament/MaterialInstance.h>
#include <filament/Texture.h>
#include <filament/TextureSampler.h>

#include <math/mat3.h>
#include <math/mat4.h>
#include <math/vec2.h>
#include <math/vec3.h>
#include <math/vec4.h>

using namespace filament;
using namespace filament::math;

enum BooleanElement {
    BOOL,
    BOOL2,
    BOOL3,
    BOOL4
};

enum IntElement {
    INT,
    INT2,
    INT3,
    INT4
};

enum FloatElement {
    FLOAT,
    FLOAT2,
    FLOAT3,
    FLOAT4,
    MAT3,
    MAT4
};

template<typename T>
static void setParameter(void *nativeMaterialInstance, const char *name, T v) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setParameter(name, v);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterBool(void *nativeMaterialInstance, const char *name_, bool x) {
    setParameter(nativeMaterialInstance, name_, bool(x));
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterBool2(void *nativeMaterialInstance, const char *name_, bool x, bool y) {
    setParameter(nativeMaterialInstance, name_, bool2{x, y});
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterBool3(void *nativeMaterialInstance, const char *name_, bool x, bool y,
                                             bool z) {
    setParameter(nativeMaterialInstance, name_, bool3{x, y, z});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterBool4(void *nativeMaterialInstance, const char *name_,
                                                             bool x, bool y, bool z, bool w) {
    setParameter(nativeMaterialInstance, name_, bool4{x, y, z, w});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterInt(void *nativeMaterialInstance, const char *name_, int x) {
    setParameter(nativeMaterialInstance, name_, int32_t(x));
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterInt2(void *nativeMaterialInstance, const char *name_, int x, int y) {
    setParameter(nativeMaterialInstance, name_, int2{x, y});
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterInt3(void *nativeMaterialInstance, const char *name_, int x, int y, int z) {
    setParameter(nativeMaterialInstance, name_, int3{x, y, z});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterInt4(void *nativeMaterialInstance, const char *name_,
                                                            int x, int y, int z, int w) {
    setParameter(nativeMaterialInstance, name_, int4{x, y, z, w});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterFloat(void *nativeMaterialInstance, const char *name_, float x) {
    setParameter(nativeMaterialInstance, name_, float(x));
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterFloat2(void *nativeMaterialInstance, const char *name_, float x, float y) {
    setParameter(nativeMaterialInstance, name_, float2{x, y});
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetParameterFloat3(void *nativeMaterialInstance, const char *name_, float x, float y,
                                              float z) {
    setParameter(nativeMaterialInstance, name_, float3{x, y, z});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterFloat4(void *nativeMaterialInstance, const char *name_,
                                                              float x, float y, float z, float w) {
    setParameter(nativeMaterialInstance, name_, float4{x, y, z, w});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterTexture(void *nativeMaterialInstance, void *nativeTexture,
                                                               const char *name_, void *sampler_) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    Texture *texture = (Texture *) nativeTexture;
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);

    instance->setParameter(name_, texture, sampler);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterRgbColor(void *nativeMaterialInstance,
                                                                const char *name_, int type, float r, float g, float b) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;

    instance->setParameter(name_, (RgbType) type, {r, g, b});
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterRgbaColor(void *nativeMaterialInstance,
                                                                const char *name_, int type, float r, float g, float b, float a) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;

    instance->setParameter(name_, (RgbaType) type, {r, g, b, a});
}

//extern "C" DOTNET_EXPORT void
//filament_MaterialInstance_nSetBooleanParameterArray(void *nativeMaterialInstance, jstring name_, int element,
//                                                    boolArray v_, int offset, int count) {
//    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
//
//    const char *name = env->GetStringUTFChars(name_, 0);
//    bool *v = env->GetBooleanArrayElements(v_, NULL);
//
//    // NOTE: In C++, bool has an implementation-defined size. Here we assume
//    // it has the same size as bool, which is 1 byte.
//
//    switch ((BooleanElement) element) {
//        case BOOL:
//            instance->setParameter(name, ((const bool *) v) + offset, count);
//            break;
//        case BOOL2:
//            instance->setParameter(name, ((const bool2 *) v) + offset, count);
//            break;
//        case BOOL3:
//            instance->setParameter(name, ((const bool3 *) v) + offset, count);
//            break;
//        case BOOL4:
//            instance->setParameter(name, ((const bool4 *) v) + offset, count);
//            break;
//    }
//
//    env->ReleaseBooleanArrayElements(v_, v, 0);
//
//    env->ReleaseStringUTFChars(name_, name);
//}
//
//extern "C" DOTNET_EXPORT void
//filament_MaterialInstance_nSetIntParameterArray(void *nativeMaterialInstance, jstring name_, int element,
//                                                intArray v_, int offset, int count) {
//    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
//
//    const char *name = env->GetStringUTFChars(name_, 0);
//    int *v = env->GetIntArrayElements(v_, NULL);
//
//    switch ((IntElement) element) {
//        case INT:
//            instance->setParameter(name, ((const int32_t *) v) + offset, count);
//            break;
//        case INT2:
//            instance->setParameter(name, ((const int2 *) v) + offset, count);
//            break;
//        case INT3:
//            instance->setParameter(name, ((const int3 *) v) + offset, count);
//            break;
//        case INT4:
//            instance->setParameter(name, ((const int4 *) v) + offset, count);
//            break;
//    }
//
//    env->ReleaseIntArrayElements(v_, v, 0);
//
//    env->ReleaseStringUTFChars(name_, name);
//}
//
//extern "C" DOTNET_EXPORT void
//filament_MaterialInstance_nSetFloatParameterArray(void *nativeMaterialInstance, jstring name_, int element,
//                                                  floatArray v_, int offset, int count) {
//    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
//
//    const char *name = env->GetStringUTFChars(name_, 0);
//    float *v = env->GetFloatArrayElements(v_, NULL);
//
//    switch ((FloatElement) element) {
//        case FLOAT:
//            instance->setParameter(name, ((const float *) v) + offset, count);
//            break;
//        case FLOAT2:
//            instance->setParameter(name, ((const float2 *) v) + offset, count);
//            break;
//        case FLOAT3:
//            instance->setParameter(name, ((const float3 *) v) + offset, count);
//            break;
//        case FLOAT4:
//            instance->setParameter(name, ((const float4 *) v) + offset, count);
//            break;
//        case MAT3:
//            instance->setParameter(name, ((const mat3f *) v) + offset, count);
//            break;
//        case MAT4:
//            instance->setParameter(name, ((const mat4f *) v) + offset, count);
//            break;
//    }
//
//    env->ReleaseFloatArrayElements(v_, v, 0);
//
//    env->ReleaseStringUTFChars(name_, name);
//}
//
//extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetParameterTexture(
//        void *nativeMaterialInstance, jstring name_,
//        void *nativeTexture, int sampler_) {
//    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
//    Texture *texture = (Texture *) nativeTexture;
//    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
//
//    const char *name = env->GetStringUTFChars(name_, 0);
//    instance->setParameter(name, texture, sampler);
//    env->ReleaseStringUTFChars(name_, name);
//}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetScissor(void *nativeMaterialInstance, int left, int bottom, int width, int height) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setScissor(left, bottom, width, height);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nUnsetScissor(void *nativeMaterialInstance) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->unsetScissor();
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetPolygonOffset(void *nativeMaterialInstance, float scale, float constant) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setPolygonOffset(scale, constant);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetMaskThreshold(void *nativeMaterialInstance, float threshold) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setMaskThreshold(threshold);
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetSpecularAntiAliasingVariance(void *nativeMaterialInstance, float variance) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setSpecularAntiAliasingVariance(variance);
}

extern "C" DOTNET_EXPORT void
filament_MaterialInstance_nSetSpecularAntiAliasingThreshold(void *nativeMaterialInstance, float threshold) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setSpecularAntiAliasingThreshold(threshold);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetDoubleSided(void *nativeMaterialInstance, bool doubleSided) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setDoubleSided(doubleSided);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetCullingMode(void *nativeMaterialInstance, int cullingMode) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setCullingMode((MaterialInstance::CullingMode) cullingMode);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetColorWrite(void *nativeMaterialInstance, bool enable) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setColorWrite(enable);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetDepthWrite(void *nativeMaterialInstance, bool enable) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setDepthWrite(enable);
}

extern "C" DOTNET_EXPORT void filament_MaterialInstance_nSetDepthCulling(void *nativeMaterialInstance, bool enable) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    instance->setDepthCulling(enable);
}

extern "C" DOTNET_EXPORT const char* filament_MaterialInstance_nGetName(void *nativeMaterialInstance) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    return instance->getName();
}

extern "C" DOTNET_EXPORT void *filament_MaterialInstance_nGetMaterial(void *nativeMaterialInstance) {
    MaterialInstance *instance = (MaterialInstance *) nativeMaterialInstance;
    return (void *) instance->getMaterial();
}
