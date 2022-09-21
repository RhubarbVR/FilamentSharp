#include "Export.h"
#include <filament/Scene.h>

#include <utils/Entity.h>

using namespace filament;
using namespace utils;

extern "C" DOTNET_EXPORT void filament_Scene_nSetSkybox(void *nativeScene, void *nativeSkybox) {
    Scene *scene = (Scene *) nativeScene;
    Skybox *skybox = (Skybox *) nativeSkybox;
    scene->setSkybox(skybox);
}

extern "C" DOTNET_EXPORT void filament_Scene_nSetIndirectLight(void *nativeScene, void *nativeIndirectLight) {
    Scene *scene = (Scene *) nativeScene;
    IndirectLight *indirectLight = (IndirectLight *) nativeIndirectLight;
    scene->setIndirectLight(indirectLight);
}

extern "C" DOTNET_EXPORT void filament_Scene_nAddEntity(void *nativeScene, int entity) {
    Scene *scene = (Scene *) nativeScene;
    scene->addEntity((Entity &) entity);
}

// FIXME:
//extern "C" DOTNET_EXPORT void filament_Scene_nAddEntities(void* nativeScene,                                            intArray entities) {
//    Scene *scene = (Scene *) nativeScene;
//    Entity *nativeEntities = (Entity *) env->GetIntArrayElements(entities, nullptr);
//    scene->addEntities(nativeEntities, env->GetArrayLength(entities));
//    env->ReleaseIntArrayElements(entities, (int *) nativeEntities, JNI_ABORT);
//}

extern "C" DOTNET_EXPORT void filament_Scene_nRemove(void *nativeScene,
                                       int entity) {
    Scene *scene = (Scene *) nativeScene;
    scene->remove((Entity &) entity);
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_Scene_nRemoveEntities(void* nativeScene,
//                                               intArray entities) {
//    Scene *scene = (Scene *) nativeScene;
//    Entity *nativeEntities = (Entity *) env->GetIntArrayElements(entities, nullptr);
//    scene->removeEntities(nativeEntities, env->GetArrayLength(entities));
//    env->ReleaseIntArrayElements(entities, (int *) nativeEntities, JNI_ABORT);
//}

extern "C" DOTNET_EXPORT int filament_Scene_nGetRenderableCount(void *nativeScene) {
    Scene *scene = (Scene *) nativeScene;
    return scene->getRenderableCount();
}

extern "C" DOTNET_EXPORT int filament_Scene_nGetLightCount(void *nativeScene) {
    Scene *scene = (Scene *) nativeScene;
    return scene->getLightCount();
}
