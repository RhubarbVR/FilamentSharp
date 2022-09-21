#include "Export.h"

#include <filament/Engine.h>

#include <utils/Entity.h>
#include <utils/EntityManager.h>

using namespace filament;
using namespace utils;

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateEngine(int backend, void *sharedContext) {
    return (void *) Engine::create((Engine::Backend) backend, nullptr, (void *) sharedContext);
}

extern "C" DOTNET_EXPORT void filament_Engine_nDestroyEngine(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    Engine::destroy(&engine);
}

// SwapChain

extern "C" DOTNET_EXPORT void *filament_Engine_nGetBackend(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->getBackend();
}

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateSwapChain(void *nativeEngine, void *win, void *flags) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createSwapChain(win, (uint64_t) flags);
}

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateSwapChainHeadless(void *nativeEngine, int width, int height, void *flags) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createSwapChain(width, height, (uint64_t) flags);
}

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateSwapChainFromRawPointer(void *nativeEngine, void *pointer, void *flags) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createSwapChain((void *) pointer, (uint64_t) flags);
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroySwapChain(void *nativeEngine, void *nativeSwapChain) {
    Engine *engine = (Engine *) nativeEngine;
    SwapChain *swapChain = (SwapChain *) nativeSwapChain;
    return engine->destroy(swapChain);
}

// View

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateView(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createView();
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyView(void *nativeEngine, void *nativeView) {
    Engine *engine = (Engine *) nativeEngine;
    View *view = (View *) nativeView;
    return engine->destroy(view);
}

// Renderer

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateRenderer(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createRenderer();
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyRenderer(void *nativeEngine, void *nativeRenderer) {
    Engine *engine = (Engine *) nativeEngine;
    Renderer *renderer = (Renderer *) nativeRenderer;
    return engine->destroy(renderer);
}

// Camera

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateCamera(void *nativeEngine, int entity_) {
    Engine *engine = (Engine *) nativeEngine;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    return (void *) engine->createCamera(entity);
}

extern "C" DOTNET_EXPORT void *filament_Engine_nGetCameraComponent(void *nativeEngine, int entity_) {
    Engine *engine = (Engine *) nativeEngine;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    return (void *) engine->getCameraComponent(entity);
}

extern "C" DOTNET_EXPORT void filament_Engine_nDestroyCameraComponent(void *nativeEngine, int entity_) {
    Engine *engine = (Engine *) nativeEngine;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    engine->destroyCameraComponent(entity);
}

// Scene

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateScene(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createScene();
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyScene(void *nativeEngine, void *nativeScene) {
    Engine *engine = (Engine *) nativeEngine;
    Scene *scene = (Scene *) nativeScene;
    return engine->destroy(scene);
}

// Fence

extern "C" DOTNET_EXPORT void *filament_Engine_nCreateFence(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->createFence();
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyFence(void *nativeEngine, void *nativeFence) {
    Engine *engine = (Engine *) nativeEngine;
    Fence *fence = (Fence *) nativeFence;
    return engine->destroy(fence);
}

// Stream

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyStream(void *nativeEngine, void *nativeStream) {
    Engine *engine = (Engine *) nativeEngine;
    Stream *stream = (Stream *) nativeStream;
    return engine->destroy(stream);
}

// Others...

extern "C" DOTNET_EXPORT bool
filament_Engine_nDestroyIndexBuffer(void *nativeEngine, void *nativeIndexBuffer) {
    Engine *engine = (Engine *) nativeEngine;
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    return engine->destroy(indexBuffer);
}

extern "C" DOTNET_EXPORT bool
filament_Engine_nDestroyVertexBuffer(void *nativeEngine, void *nativeVertexBuffer) {
    Engine *engine = (Engine *) nativeEngine;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    return engine->destroy(vertexBuffer);
}

extern "C" DOTNET_EXPORT bool
filament_Engine_nDestroyIndirectLight(void *nativeEngine, void *nativeIndirectLight) {
    Engine *engine = (Engine *) nativeEngine;
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    return engine->destroy(indirectLight);
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyMaterial(void *nativeEngine, void *nativeMaterial) {
    Engine *engine = (Engine *) nativeEngine;
    Material *material = (Material *) nativeMaterial;
    return engine->destroy(material);
}

extern "C" DOTNET_EXPORT bool
filament_Engine_nDestroyMaterialInstance(void *nativeEngine, void *nativeMaterialInstance) {
    Engine *engine = (Engine *) nativeEngine;
    MaterialInstance *materialInstance = (MaterialInstance *) nativeMaterialInstance;
    return engine->destroy(materialInstance);
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroySkybox(void *nativeEngine, void *nativeSkybox) {
    Engine *engine = (Engine *) nativeEngine;
    Skybox *skybox = (Skybox *) nativeSkybox;
    return engine->destroy(skybox);
}

extern "C" DOTNET_EXPORT bool
filament_Engine_nDestroyColorGrading(void *nativeEngine, void *nativeColorGrading) {
    Engine *engine = (Engine *) nativeEngine;
    ColorGrading *colorGrading = (ColorGrading *) nativeColorGrading;
    return engine->destroy(colorGrading);
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyTexture(void *nativeEngine, void *nativeTexture) {
    Engine *engine = (Engine *) nativeEngine;
    Texture *texture = (Texture *) nativeTexture;
    return engine->destroy(texture);
}

extern "C" DOTNET_EXPORT bool filament_Engine_nDestroyRenderTarget(void *nativeEngine, void *nativeTarget) {
    Engine *engine = (Engine *) nativeEngine;
    RenderTarget *target = (RenderTarget *) nativeTarget;
    return engine->destroy(target);
}

extern "C" DOTNET_EXPORT void filament_Engine_nDestroyEntity(void *nativeEngine, int entity_) {
    Engine *engine = (Engine *) nativeEngine;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    engine->destroy(entity);
}

extern "C" DOTNET_EXPORT void filament_Engine_nFlushAndWait(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    engine->flushAndWait();
}

// Managers...

extern "C" DOTNET_EXPORT void *filament_Engine_nGetTransformManager(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) &engine->getTransformManager();
}

extern "C" DOTNET_EXPORT void *filament_Engine_nGetLightManager(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) &engine->getLightManager();
}

extern "C" DOTNET_EXPORT void *filament_Engine_nGetRenderableManager(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) &engine->getRenderableManager();
}

extern "C" DOTNET_EXPORT void *filament_Engine_nGetJobSystem(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) &engine->getJobSystem();
}

extern "C" DOTNET_EXPORT void *filament_Engine_nGetDefaultMaterial(void *nativeEngine) {
    Engine *engine = (Engine *) nativeEngine;
    return (void *) engine->getDefaultMaterial();
}
