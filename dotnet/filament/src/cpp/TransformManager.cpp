#include "Export.h"
#include <iostream>

#include <filament/TransformManager.h>
#include <utils/Entity.h>
#include <math/mat4.h>

using namespace utils;
using namespace filament;
using namespace filament::math;

extern "C" DOTNET_EXPORT bool filament_TransformManager_nHasComponent(void *nativeTransformManager, int entity_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    return tm->hasComponent(entity);
}

extern "C" DOTNET_EXPORT int filament_TransformManager_nGetInstance(void *nativeTransformManager, int entity_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    return tm->getInstance(entity);
}

extern "C" DOTNET_EXPORT int filament_TransformManager_nCreate(void *nativeTransformManager, int entity_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    tm->create(entity);
    return tm->getInstance(entity);
}

// TODO
//extern "C" DOTNET_EXPORT int filament_TransformManager_nCreateArray(void *nativeTransformManager, int entity_, int parent,
//                                                      jfloatArray localTransform_) {
//    TransformManager *tm = (TransformManager *) nativeTransformManager;
//    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
//    if (localTransform_) {
//        jfloat *localTransform = env->GetFloatArrayElements(localTransform_, NULL);
//        tm->create(entity, (TransformManager::Instance) parent,
//                   *reinterpret_cast<const filament::math::mat4f *>(localTransform));
//        env->ReleaseFloatArrayElements(localTransform_, localTransform, JNI_ABORT);
//    } else {
//        tm->create(entity, (TransformManager::Instance) parent);
//    }
//    return tm->getInstance(entity);
//}

extern "C" DOTNET_EXPORT void filament_TransformManager_nDestroy(void *nativeTransformManager, int entity_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    tm->destroy(entity);
}

extern "C" DOTNET_EXPORT void filament_TransformManager_nSetParent(void *nativeTransformManager, int i, int newParent) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    tm->setParent((TransformManager::Instance) i,
                  (TransformManager::Instance) newParent);
}

extern "C" DOTNET_EXPORT void
filament_TransformManager_nSetTransform(void *nativeTransformManager, int i, float* localTransform_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    tm->setTransform((TransformManager::Instance) i,
                     *reinterpret_cast<const filament::math::mat4f *>(localTransform_));
}

// FIXME:
//extern "C" DOTNET_EXPORT void
//filament_TransformManager_nGetTransform(void *nativeTransformManager, int i, jfloatArray outLocalTransform_) {
//    TransformManager *tm = (TransformManager *) nativeTransformManager;
//    jfloat *outLocalTransform = env->GetFloatArrayElements(outLocalTransform_, NULL);
//    *reinterpret_cast<filament::math::mat4f *>(outLocalTransform) = tm->getTransform(
//            (TransformManager::Instance) i);
//    env->ReleaseFloatArrayElements(outLocalTransform_, outLocalTransform, 0);
//}

extern "C" DOTNET_EXPORT void
filament_TransformManager_nGetWorldTransform(void *nativeTransformManager, int i, float* outWorldTransform_) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    mat4f transform = tm->getWorldTransform((TransformManager::Instance) i);

    for (int r = 0; r < mat4f::NUM_ROWS; r++) {
        for (int c = 0; c < mat4f::NUM_COLS; c++) {
            outWorldTransform_[r * mat4f::NUM_COLS + c] = transform[r][c];
        }
    }
}

extern "C" DOTNET_EXPORT void filament_TransformManager_nOpenLocalTransformTransaction(void *nativeTransformManager) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    tm->openLocalTransformTransaction();
}

extern "C" DOTNET_EXPORT void filament_TransformManager_nCommitLocalTransformTransaction(void *nativeTransformManager) {
    TransformManager *tm = (TransformManager *) nativeTransformManager;
    tm->commitLocalTransformTransaction();
}
