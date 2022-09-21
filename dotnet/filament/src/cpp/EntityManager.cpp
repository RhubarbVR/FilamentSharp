#include "Export.h"
#include <utils/EntityManager.h>

using namespace utils;

extern "C" DOTNET_EXPORT void *filament_EntityManager_nGetEntityManager() {
    return (void *) &EntityManager::get();
}

// FIXME
//extern "C" DOTNET_EXPORT void filament_EntityManager_nCreateArray(void * nativeEntityManager, int n, intArray entities_) {
//    EntityManager *em = (EntityManager *) nativeEntityManager;
//    int *entities = env->GetIntArrayElements(entities_, NULL);
//
//    // This is very very gross, we just pretend Entity is just like an int
//    // (which it is), but still.
//    em->create((size_t) n, reinterpret_cast<Entity *>(entities));
//
//    env->ReleaseIntArrayElements(entities_, entities, 0);
//}

extern "C" DOTNET_EXPORT int filament_EntityManager_nCreate(void *nativeEntityManager) {
    EntityManager *em = (EntityManager *) nativeEntityManager;
    return em->create().getId();
}

// FIXME
//extern "C" DOTNET_EXPORT void
//filament_EntityManager_nDestroyArray(void * nativeEntityManager, int n, intArray entities_) {
//    EntityManager *em = (EntityManager *) nativeEntityManager;
//    int *entities = env->GetIntArrayElements(entities_, NULL);
//
//    // This is very very gross, we just pretend Entity is just like an
//    // int (which it is), but still.
//    em->destroy((size_t) n, reinterpret_cast<Entity *>(entities));
//
//    env->ReleaseIntArrayElements(entities_, entities, JNI_ABORT);
//}

extern "C" DOTNET_EXPORT void filament_EntityManager_nDestroy(void *nativeEntityManager, int entity_) {
    EntityManager *em = (EntityManager *) nativeEntityManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    em->destroy(entity);
}

extern "C" DOTNET_EXPORT bool filament_EntityManager_nIsAlive(void *nativeEntityManager, int entity_) {
    EntityManager *em = (EntityManager *) nativeEntityManager;
    Entity &entity = *reinterpret_cast<Entity *>(&entity_);
    return (bool) em->isAlive(entity);
}
