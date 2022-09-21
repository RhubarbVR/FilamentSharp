#include "Export.h"
#include <functional>
#include <stdlib.h>
#include <string.h>

#include <filament/RenderTarget.h>

using namespace filament;
using namespace backend;

extern "C" DOTNET_EXPORT void *filament_RenderTarget_nCreateBuilder() {
    return (void *) new RenderTarget::Builder();
}

extern "C" DOTNET_EXPORT void filament_RenderTarget_nDestroyBuilder(void *nativeBuilder) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_RenderTarget_nBuilderTexture(void *nativeBuilder, int attachment, void *nativeTexture) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    Texture *texture = (Texture *) nativeTexture;
    builder->texture(RenderTarget::AttachmentPoint(attachment), texture);
}

extern "C" DOTNET_EXPORT void filament_RenderTarget_nBuilderMipLevel(void *nativeBuilder, int attachment, int level) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    builder->mipLevel(RenderTarget::AttachmentPoint(attachment), level);
}

extern "C" DOTNET_EXPORT void filament_RenderTarget_nBuilderFace(void *nativeBuilder, int attachment, int face) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    RenderTarget::CubemapFace cubeface = (RenderTarget::CubemapFace) face;
    builder->face(RenderTarget::AttachmentPoint(attachment), cubeface);
}

extern "C" DOTNET_EXPORT void filament_RenderTarget_nBuilderLayer(void *nativeBuilder, int attachment, int layer) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    builder->layer(RenderTarget::AttachmentPoint(attachment), layer);
}

extern "C" DOTNET_EXPORT void *filament_RenderTarget_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    RenderTarget::Builder *builder = (RenderTarget::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

extern "C" DOTNET_EXPORT int filament_RenderTarget_nGetMipLevel(void *nativeTarget, int attachment) {
    RenderTarget *target = (RenderTarget *) nativeTarget;
    return target->getMipLevel(RenderTarget::AttachmentPoint(attachment));
}

extern "C" DOTNET_EXPORT int filament_RenderTarget_nGetFace(long nativeTarget, int attachment) {
    RenderTarget *target = (RenderTarget *) nativeTarget;
    return (int) target->getFace(RenderTarget::AttachmentPoint(attachment));
}

extern "C" DOTNET_EXPORT int filament_RenderTarget_nGetLayer(long nativeTarget, int attachment) {
    RenderTarget *target = (RenderTarget *) nativeTarget;
    return target->getLayer(RenderTarget::AttachmentPoint(attachment));
}
