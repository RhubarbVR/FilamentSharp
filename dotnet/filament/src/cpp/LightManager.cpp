#include "Export.h"
#include <filament/LightManager.h>

#include <utils/Entity.h>

#include <algorithm>

using namespace filament;
using namespace utils;

extern "C" DOTNET_EXPORT int filament_LightManager_nGetComponentCount(void *nativeLightManager) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getComponentCount();
}

extern "C" DOTNET_EXPORT bool filament_LightManager_nHasComponent(void *nativeLightManager, int entity) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return (bool) lm->hasComponent((Entity &) entity);
}

extern "C" DOTNET_EXPORT int filament_LightManager_nGetInstance(void *nativeLightManager, int entity) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getInstance((Entity &) entity);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nDestroy(void *nativeLightManager, int entity) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->destroy((Entity &) entity);
}

extern "C" DOTNET_EXPORT void *filament_LightManager_nCreateBuilder(int lightType) {
    return (void *) new LightManager::Builder((LightManager::Type) lightType);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nDestroyBuilder(void *nativeBuilder) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderCastShadows(void *nativeBuilder, bool enable) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->castShadows(enable);
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderShadowOptions(void *nativeBuilder, int mapSize, int cascades,
//                                                            floatArray splitPositions,
//                                                            float constantBias, float normalBias, float shadowFar,
//                                                            float shadowNearHint,
//                                                            float shadowFarHint, bool stable,
//                                                            bool screenSpaceContactShadows, int stepCount,
//                                                            float maxShadowDistance, int vsmMsaaSamples) {
//    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
//    LightManager::ShadowOptions shadowOptions{
//            .mapSize = (uint32_t) mapSize,
//            .shadowCascades = (uint8_t) cascades,
//            .constantBias = constantBias,
//            .normalBias = normalBias,
//            .shadowFar = shadowFar,
//            .shadowNearHint = shadowNearHint,
//            .shadowFarHint = shadowFarHint,
//            .stable = (bool) stable,
//            .screenSpaceContactShadows = (bool) screenSpaceContactShadows,
//            .stepCount = uint8_t(stepCount),
//            .maxShadowDistance = maxShadowDistance,
//            .vsm = {
//                    .msaaSamples = (uint8_t) vsmMsaaSamples
//            }
//    };
//    float *nativeSplits = env->GetFloatArrayElements(splitPositions, NULL);
//    const jsize splitCount = std::min((jsize) 3, env->GetArrayLength(splitPositions));
//    for (jsize i = 0; i < splitCount; i++) {
//        shadowOptions.cascadeSplitPositions[i] = nativeSplits[i];
//    }
//    env->ReleaseFloatArrayElements(splitPositions, nativeSplits, 0);
//    builder->shadowOptions(shadowOptions);
//}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderCastLight(void *nativeBuilder, bool enabled) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->castLight(enabled);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderPosition(void *nativeBuilder, float x, float y, float z) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->position({x, y, z});
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderDirection(void *nativeBuilder, float x, float y, float z) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->direction({x, y, z});
}

extern "C" DOTNET_EXPORT void
filament_LightManager_nBuilderColor(void *nativeBuilder, float linearR, float linearG, float linearB) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->color({linearR, linearG, linearB});
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderIntensityCandela(void *nativeBuilder, float intensity) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->intensityCandela(intensity);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderIntensity__JF(void *nativeBuilder, float intensity) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->intensity(intensity);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderIntensity__JFF(void *nativeBuilder, float watts, float efficiency) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->intensity(watts, efficiency);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderFalloff(void *nativeBuilder, float radius) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->falloff(radius);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderSpotLightCone(void *nativeBuilder, float inner, float outer) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->spotLightCone(inner, outer);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderAngularRadius(void *nativeBuilder, float angularRadius) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->sunAngularRadius(angularRadius);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderHaloSize(void *nativeBuilder, float haloSize) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->sunHaloSize(haloSize);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nBuilderHaloFalloff(void *nativeBuilder, float haloFalloff) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    builder->sunHaloFalloff(haloFalloff);
}

// FIXME:
//extern "C" DOTNET_EXPORT void filament_LightManager_nComputeUniformSplits(floatArray splitPositions, int cascades) {
//    float *nativeSplits = env->GetFloatArrayElements(splitPositions, NULL);
//    LightManager::ShadowCascades::computeUniformSplits(nativeSplits, (uint8_t) cascades);
//    env->ReleaseFloatArrayElements(splitPositions, nativeSplits, 0);
//}
//
//extern "C" DOTNET_EXPORT void filament_LightManager_nComputeLogSplits(JNIEnv *env, jclass,
//                                                        floatArray splitPositions, int cascades, float near,
//                                                        float far) {
//    float *nativeSplits = env->GetFloatArrayElements(splitPositions, NULL);
//    LightManager::ShadowCascades::computeLogSplits(nativeSplits, (uint8_t) cascades, near, far);
//    env->ReleaseFloatArrayElements(splitPositions, nativeSplits, 0);
//}
//
//extern "C" DOTNET_EXPORT void filament_LightManager_nComputePracticalSplits(JNIEnv *env, jclass,
//                                                              floatArray splitPositions, int cascades, float near,
//                                                              float far, float lambda) {
//    float *nativeSplits = env->GetFloatArrayElements(splitPositions, NULL);
//    LightManager::ShadowCascades::computePracticalSplits(nativeSplits, (uint8_t) cascades, near, far, lambda);
//    env->ReleaseFloatArrayElements(splitPositions, nativeSplits, 0);
//}

extern "C" DOTNET_EXPORT bool filament_LightManager_nBuilderBuild(void *nativeBuilder, void *nativeEngine, int entity) {
    LightManager::Builder *builder = (LightManager::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return bool(builder->build(*engine, (Entity &) entity) == LightManager::Builder::Success);
}

extern "C" DOTNET_EXPORT int filament_LightManager_nGetType(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return (int) lm->getType((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetPosition(void *nativeLightManager, int i, float x, float y, float z) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setPosition((LightManager::Instance) i, {x, y, z});
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_LightManager_nGetPosition(void *nativeLightManager, int i, floatArray out_) {
//    LightManager *lm = (LightManager *) nativeLightManager;
//    float *out = env->GetFloatArrayElements(out_, nullptr);
//    *reinterpret_cast<filament::math::float3 *>(out) = lm->getPosition((LightManager::Instance) i);
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetDirection(void *nativeLightManager, int i, float x, float y, float z) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setDirection((LightManager::Instance) i, {x, y, z});
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_LightManager_nGetDirection(JNIEnv *env, jclass,
//                                                    void *nativeLightManager, int i, floatArray out_) {
//    LightManager *lm = (LightManager *) nativeLightManager;
//    float *out = env->GetFloatArrayElements(out_, nullptr);
//    *reinterpret_cast<filament::math::float3 *>(out) = lm->getDirection((LightManager::Instance) i);
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}

extern "C" DOTNET_EXPORT void
filament_LightManager_nSetColor(void *nativeLightManager, int i, float linearR, float linearG, float linearB) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setColor((LightManager::Instance) i, {linearR, linearG, linearB});
}

extern "C" DOTNET_EXPORT void filament_LightManager_nGetColor(void *nativeLightManager, int i, float* out_) {
    LightManager *lm = (LightManager *) nativeLightManager;
    *reinterpret_cast<filament::math::float3 *>(out_) = lm->getColor((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetIntensity__JIF(void *nativeLightManager, int i, float intensity) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setIntensity((LightManager::Instance) i, intensity);
}

extern "C" DOTNET_EXPORT void
filament_LightManager_nSetIntensity__JIFF(void *nativeLightManager, int i, float watts, float efficiency) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setIntensity((LightManager::Instance) i, watts, efficiency);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetIntensityCandela(void *nativeLightManager, int i, float intensity) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setIntensityCandela((LightManager::Instance) i, intensity);
}

extern "C" DOTNET_EXPORT float filament_LightManager_nGetIntensity(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getIntensity((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetFalloff(void *nativeLightManager, int i, float falloff) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setFalloff((LightManager::Instance) i, falloff);
}

extern "C" DOTNET_EXPORT float filament_LightManager_nGetFalloff(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getFalloff((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetSpotLightCone(void *nativeLightManager, int i, float inner, float outer) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setSpotLightCone((LightManager::Instance) i, inner, outer);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetSunAngularRadius(void *nativeLightManager, int i, float angularRadius) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setSunAngularRadius((LightManager::Instance) i, angularRadius);
}

extern "C" DOTNET_EXPORT float filament_LightManager_nGetSunAngularRadius(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getSunAngularRadius((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetSunHaloSize(void *nativeLightManager, int i, float haloSize) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setSunHaloSize((LightManager::Instance) i, haloSize);
}

extern "C" DOTNET_EXPORT float filament_LightManager_nGetSunHaloSize(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getSunHaloSize((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetSunHaloFalloff(void *nativeLightManager, int i, float haloFalloff) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setSunHaloFalloff((LightManager::Instance) i, haloFalloff);
}

extern "C" DOTNET_EXPORT float filament_LightManager_nGetSunHaloFalloff(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return lm->getSunHaloFalloff((LightManager::Instance) i);
}

extern "C" DOTNET_EXPORT void filament_LightManager_nSetShadowCaster(void *nativeLightManager, int i, bool shadowCaster) {
    LightManager *lm = (LightManager *) nativeLightManager;
    lm->setShadowCaster((LightManager::Instance) i, shadowCaster);
}

extern "C" DOTNET_EXPORT bool filament_LightManager_nIsShadowCaster(void *nativeLightManager, int i) {
    LightManager *lm = (LightManager *) nativeLightManager;
    return (bool) lm->isShadowCaster((LightManager::Instance) i);
}
