#include "Export.h"
#include <filament/IndirectLight.h>
#include <filament/Texture.h>
#include <math/mat4.h>

using namespace filament;

extern "C" DOTNET_EXPORT void *filament_IndirectLight_nCreateBuilder() {
    return (void *) new IndirectLight::Builder();
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nDestroyBuilder(void *nativeBuilder) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void *filament_IndirectLight_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderReflections(void *nativeBuilder, void *nativeTexture) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    const Texture *texture = (const Texture *) nativeTexture;
    builder->reflections(texture);
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderIntensity(void *nativeBuilder, float envIntensity) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    builder->intensity(envIntensity);
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderIrradiance(void *nativeBuilder, int bands, void *sh_) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    float *sh = static_cast<float*>(sh_);
    builder->irradiance((uint8_t) bands, (const filament::math::float3 *) sh);
}

// TODO
//
//extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderRadiance(void *nativeBuilder, int bands, floatArray sh_) {
//    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
//    float *sh = env->GetFloatArrayElements(sh_, NULL);
//    builder->radiance((uint8_t) bands, (const filament::math::float3 *) sh);
//    env->ReleaseFloatArrayElements(sh_, sh, JNI_ABORT);
//}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderIrradianceAsTexture(void *nativeBuilder, void *nativeTexture) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    const Texture *texture = (const Texture *) nativeTexture;
    builder->irradiance(texture);
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nBuilderRotation(void *nativeBuilder,
                                                 float v0, float v1, float v2, float v3, float v4, float v5, float v6,
                                                 float v7,
                                                 float v8) {
    IndirectLight::Builder *builder = (IndirectLight::Builder *) nativeBuilder;
    builder->rotation(filament::math::mat3f{v0, v1, v2, v3, v4, v5, v6, v7, v8});
}

extern "C" DOTNET_EXPORT void filament_IndirectLight_nSetIntensity(void *nativeIndirectLight, float intensity) {
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    indirectLight->setIntensity(intensity);
}

extern "C" DOTNET_EXPORT float filament_IndirectLight_nGetIntensity(void *nativeIndirectLight) {
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    return indirectLight->getIntensity();
}

extern "C" DOTNET_EXPORT void
filament_IndirectLight_nSetRotation(void *nativeIndirectLight, float v0, float v1, float v2, float v3, float v4,
                                    float v5, float v6, float v7, float v8) {
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    indirectLight->setRotation(filament::math::mat3f{v0, v1, v2, v3, v4, v5, v6, v7, v8});
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_IndirectLight_nGetRotation(void *nativeIndirectLight, floatArray outRotation_) {
//    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
//    float *outRotation = env->GetFloatArrayElements(outRotation_, NULL);
//    *reinterpret_cast<filament::math::mat3f *>(outRotation) = indirectLight->getRotation();
//    env->ReleaseFloatArrayElements(outRotation_, outRotation, 0);
//}

extern "C" DOTNET_EXPORT void *filament_IndirectLight_nGetReflectionsTexture(void *nativeIndirectLight) {
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    Texture const *tex = indirectLight->getReflectionsTexture();
    return (void *) tex;
}

extern "C" DOTNET_EXPORT void *filament_IndirectLight_nGetIrradianceTexture(void *nativeIndirectLight) {
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    Texture const *tex = indirectLight->getIrradianceTexture();
    return (void *) tex;
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_IndirectLight_nGetDirectionEstimateStatic(floatArray sh_, floatArray outDirection_) {
//    float *sh = env->GetFloatArrayElements(sh_, NULL);
//    float *outDirection = env->GetFloatArrayElements(outDirection_, NULL);
//    *reinterpret_cast<filament::math::float3 *>(outDirection) = IndirectLight::getDirectionEstimate(
//            (filament::math::float3 *) sh);
//    env->ReleaseFloatArrayElements(outDirection_, outDirection, 0);
//    env->ReleaseFloatArrayElements(sh_, sh, JNI_ABORT);
//}
//
//extern "C" DOTNET_EXPORT void filament_IndirectLight_nGetColorEstimateStatic(floatArray outColor_, floatArray sh_, float x, float y,
//                                                               float z) {
//    float *sh = env->GetFloatArrayElements(sh_, NULL);
//    float *outColor = env->GetFloatArrayElements(outColor_, NULL);
//    *reinterpret_cast<filament::math::float4 *>(outColor) =
//            IndirectLight::getColorEstimate((filament::math::float3 *) sh, math::float3{x, y, z});
//    env->ReleaseFloatArrayElements(outColor_, outColor, 0);
//    env->ReleaseFloatArrayElements(sh_, sh, JNI_ABORT);
//}
