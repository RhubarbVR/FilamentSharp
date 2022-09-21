#include "Export.h"
#include <filament/Material.h>

using namespace filament;

extern "C" DOTNET_EXPORT void *filament_Material_nBuilderBuild(void *nativeEngine, void *buffer, int bufferSizeInBytes) {
    Engine *engine = (Engine *) nativeEngine;

    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    Material *material = Material::Builder()
            .package(data, bufferSizeInBytes)
            .build(*engine);

    return (void *) material;
}

extern "C" DOTNET_EXPORT void *filament_Material_nGetDefaultInstance(void *nativeMaterial) {
    Material const *material = (Material const *) nativeMaterial;
    return (void *) material->getDefaultInstance();
}

extern "C" DOTNET_EXPORT void *filament_Material_nCreateInstance(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (void *) material->createInstance();
}

// FIXME
//extern "C" DOTNET_EXPORT void *filament_Material_nCreateInstanceWithName(void *nativeMaterial, jstring name_) {
//    Material *material = (Material *) nativeMaterial;
//    const char *name = env->GetStringUTFChars(name_, 0);
//    void *instance = (void *) material->createInstance(name);
//    env->ReleaseStringUTFChars(name_, name);
//    return instance;
//}

extern "C" DOTNET_EXPORT const char *filament_Material_nGetName(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getName();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetShading(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getShading();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetInterpolation(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getInterpolation();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetBlendingMode(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getBlendingMode();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetRefractionMode(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getRefractionMode();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetRefractionType(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getRefractionType();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetVertexDomain(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getVertexDomain();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetCullingMode(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return (int) material->getCullingMode();
}

extern "C" DOTNET_EXPORT bool filament_Material_nIsColorWriteEnabled(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->isColorWriteEnabled();
}

extern "C" DOTNET_EXPORT bool filament_Material_nIsDepthWriteEnabled(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->isDepthWriteEnabled();
}

extern "C" DOTNET_EXPORT bool filament_Material_nIsDepthCullingEnabled(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->isDepthCullingEnabled();
}

extern "C" DOTNET_EXPORT bool filament_Material_nIsDoubleSided(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->isDoubleSided();
}

extern "C" DOTNET_EXPORT float filament_Material_nGetMaskThreshold(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getMaskThreshold();
}

extern "C" DOTNET_EXPORT float filament_Material_nGetSpecularAntiAliasingVariance(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getSpecularAntiAliasingVariance();
}

extern "C" DOTNET_EXPORT float filament_Material_nGetSpecularAntiAliasingThreshold(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getSpecularAntiAliasingThreshold();
}

extern "C" DOTNET_EXPORT int filament_Material_nGetParameterCount(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getParameterCount();
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_Material_nGetParameters(void *nativeMaterial, jobject parameters, int count) {
//    Material *material = (Material *) nativeMaterial;
//
//    Material::ParameterInfo *info = new Material::ParameterInfo[count];
//    size_t received = material->getParameters(info, (size_t) count);
//    assert(received == count);
//
//    jclass parameterClass = env->FindClass("com/google/android/filament/Material$Parameter");
//    parameterClass = (jclass) env->NewLocalRef(parameterClass);
//
//    jmethodID parameterAdd = env->GetStaticMethodID(parameterClass, "add",
//                                                    "(Ljava/util/List;Ljava/lang/String;III)V");
//
//    jfieldID parameterSamplerOffset = env->GetStaticFieldID(parameterClass,
//                                                            "SAMPLER_OFFSET", "I");
//
//    jfieldID parameterSubpassOffset = env->GetStaticFieldID(parameterClass,
//                                                            "SUBPASS_OFFSET", "I");
//
//    int offset = env->GetStaticIntField(parameterClass, parameterSamplerOffset);
//    int subpassOffset = env->GetStaticIntField(parameterClass, parameterSubpassOffset);
//    for (size_t i = 0; i < received; i++) {
//        int type;
//        if (info[i].isSampler) {
//            type = (int) info[i].samplerType + offset;
//        } else if (info[i].isSubpass) {
//            type = subpassOffset;
//        } else {
//            type = (int) info[i].type;
//        }
//
//        env->CallStaticVoidMethod(
//                parameterClass, parameterAdd,
//                parameters, env->NewStringUTF(info[i].name), type, (int) info[i].precision,
//                (int) info[i].count);
//    }
//
//    env->DeleteLocalRef(parameterClass);
//
//    delete[] info;
//}

extern "C" DOTNET_EXPORT int filament_Material_nGetRequiredAttributes(void *nativeMaterial) {
    Material *material = (Material *) nativeMaterial;
    return material->getRequiredAttributes().getValue();
}

extern "C" DOTNET_EXPORT bool filament_Material_nHasParameter(void *nativeMaterial, const char *name_) {
    Material *material = (Material *) nativeMaterial;
    return material->hasParameter(name_);
}
