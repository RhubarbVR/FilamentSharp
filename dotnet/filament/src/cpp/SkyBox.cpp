#include "Export.h"
#include <filament/Skybox.h>

#include <math/vec4.h>

using namespace filament;

extern "C" DOTNET_EXPORT void *filament_Skybox_nCreateBuilder() {
    return (void *) new Skybox::Builder{};
}

extern "C" DOTNET_EXPORT void filament_Skybox_nDestroyBuilder(void *nativeSkyBoxBuilder) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_Skybox_nBuilderEnvironment(void *nativeSkyBoxBuilder, void *nativeTexture) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    Texture *texture = (Texture *) nativeTexture;
    builder->environment(texture);
}

extern "C" DOTNET_EXPORT void filament_Skybox_nBuilderShowSun(void *nativeSkyBoxBuilder, bool show) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->showSun(show);
}

extern "C" DOTNET_EXPORT void filament_Skybox_nBuilderIntensity(void *nativeSkyBoxBuilder, float intensity) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->intensity(intensity);
}

extern "C" DOTNET_EXPORT void filament_Skybox_nBuilderColor(void *nativeSkyBoxBuilder, float r, float g, float b, float a) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->color({r, g, b, a});
}

extern "C" DOTNET_EXPORT void *filament_Skybox_nBuilderBuild(void *nativeSkyBoxBuilder, void *nativeEngine) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

extern "C" DOTNET_EXPORT void filament_Skybox_nSetLayerMask(void *nativeSkybox, int select, int value) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    skybox->setLayerMask((uint8_t) select, (uint8_t) value);
}

extern "C" DOTNET_EXPORT int filament_Skybox_nGetLayerMask(void *nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    return static_cast<int>(skybox->getLayerMask());
}

extern "C" DOTNET_EXPORT float filament_Skybox_nGetIntensity(void *nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    return static_cast<int>(skybox->getIntensity());
}

extern "C" DOTNET_EXPORT void filament_Skybox_nSetColor(void *nativeSkybox, float r, float g, float b, float a) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    skybox->setColor({r, g, b, a});
}

extern "C" DOTNET_EXPORT void *filament_Skybix_nGetTexture(void *nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    Texture const *tex = skybox->getTexture();
    return (void *) tex;
}
