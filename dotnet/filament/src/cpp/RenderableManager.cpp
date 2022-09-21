#include "Export.h"
#include <filament/RenderableManager.h>
#include <filament/MaterialInstance.h>

#include <utils/Entity.h>

using namespace filament;
using namespace utils;

extern "C" DOTNET_EXPORT bool filament_RenderableManager_nHasComponent(void *nativeRenderableManager, int entity) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return rm->hasComponent((Entity &) entity);
}

extern "C" DOTNET_EXPORT int filament_RenderableManager_nGetInstance(void *nativeRenderableManager, int entity) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return rm->getInstance((Entity &) entity);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nDestroy(void *nativeRenderableManager, int entity) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->destroy((Entity &) entity);
}

extern "C" DOTNET_EXPORT void *filament_RenderableManager_nCreateBuilder(int count) {
    return (void *) new RenderableManager::Builder((size_t) count);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nDestroyBuilder(void *nativeBuilder) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT bool filament_RenderableManager_nBuilderBuild(void *nativeBuilder, void *nativeEngine, int entity) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return bool(builder->build(*engine, (Entity &) entity) == RenderableManager::Builder::Success);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderGeometry__JIIJJ(void *nativeBuilder, int index,
                                                                   int primitiveType, void *nativeVertexBuffer,
                                                                   void *nativeIndexBuffer) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    builder->geometry((size_t) index, (RenderableManager::PrimitiveType) primitiveType, vertexBuffer, indexBuffer);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderGeometry__JIIJJII(void *nativeBuilder,
                                                                     int index,
                                                                     int primitiveType,
                                                                     void *nativeVertexBuffer,
                                                                     void *nativeIndexBuffer,
                                                                     int offset, int count) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    builder->geometry((size_t) index, (RenderableManager::PrimitiveType) primitiveType, vertexBuffer, indexBuffer,
                      (size_t) offset, (size_t) count);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderGeometry__JIIJJIIII(void *nativeBuilder,
                                                                       int index,
                                                                       int primitiveType,
                                                                       void *nativeVertexBuffer,
                                                                       void *nativeIndexBuffer,
                                                                       int offset, int minIndex,
                                                                       int maxIndex,
                                                                       int count) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    builder->geometry((size_t) index, (RenderableManager::PrimitiveType) primitiveType,
                      vertexBuffer, indexBuffer, (size_t) offset, (size_t) minIndex, (size_t) maxIndex,
                      (size_t) count);
}

extern "C" DOTNET_EXPORT void
filament_RenderableManager_nBuilderMaterial(void *nativeBuilder, int index, void *nativeMaterialInstance) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->material((size_t) index, (const MaterialInstance *) nativeMaterialInstance);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderBlendOrder(void *nativeBuilder, int index, int blendOrder) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->blendOrder((size_t) index, (uint16_t) blendOrder);
}

extern "C" DOTNET_EXPORT void
filament_RenderableManager_nBuilderBoundingBox(void *nativeBuilder, float cx, float cy,
                                               float cz, float ex, float ey, float ez) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->boundingBox({{cx, cy, cz},
                          {ex, ey, ez}});
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderLayerMask(void *nativeBuilder, int select, int value) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->layerMask((uint8_t) select, (uint8_t) value);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderPriority(void *nativeBuilder, int priority) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->priority((uint8_t) priority);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderCulling(void *nativeBuilder, bool enabled) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->culling(enabled);
}

extern "C" DOTNET_EXPORT void
filament_RenderableManager_nBuilderCastShadows(void *nativeBuilder, bool enabled) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->castShadows(enabled);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderReceiveShadows(void *nativeBuilder, bool enabled) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->receiveShadows(enabled);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderScreenSpaceContactShadows(void *nativeBuilder, bool enabled) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->screenSpaceContactShadows(enabled);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderSkinning(void *nativeBuilder, int boneCount) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->skinning((size_t) boneCount);
}

// FIXME
//extern "C" DOTNET_EXPORT int filament_RenderableManager_nBuilderSkinningBones(void *nativeBuilder, int boneCount, jobject bones,
//                                                                int remaining) {
//    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
//    AutoBuffer nioBuffer(env, bones, boneCount * 8);
//    void *data = nioBuffer.getData();
//    size_t sizeInBytes = nioBuffer.getSize();
//    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//    builder->skinning((size_t) boneCount, static_cast<RenderableManager::Bone const *>(data));
//    return 0;
//}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nBuilderMorphing(void *nativeBuilder, bool enabled) {
    RenderableManager::Builder *builder = (RenderableManager::Builder *) nativeBuilder;
    builder->morphing(enabled);
}

// FIXME
//extern "C" DOTNET_EXPORT int filament_RenderableManager_nSetBonesAsMatrices(void *nativeRenderableManager, int i, jobject matrices,
//                                                              int remaining,
//                                                              int boneCount, int offset) {
//    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
//    AutoBuffer nioBuffer(env, matrices, boneCount * 16);
//    void *data = nioBuffer.getData();
//    size_t sizeInBytes = nioBuffer.getSize();
//    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//    rm->setBones((RenderableManager::Instance) i,
//                 static_cast<filament::math::mat4f const *>(data), (size_t) boneCount, (size_t) offset);
//    return 0;
//}

//extern "C" DOTNET_EXPORT int
//filament_RenderableManager_nSetBonesAsQuaternions(void *nativeRenderableManager, int i, jobject quaternions,
//                                                  int remaining,
//                                                  int boneCount, int offset) {
//    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
//    AutoBuffer nioBuffer(env, quaternions, boneCount * 8);
//    void *data = nioBuffer.getData();
//    size_t sizeInBytes = nioBuffer.getSize();
//    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//    rm->setBones((RenderableManager::Instance) i,
//                 static_cast<RenderableManager::Bone const *>(data), (size_t) boneCount, (size_t) offset);
//    return 0;
//}
//
//extern "C" DOTNET_EXPORT void
//filament_RenderableManager_nSetMorphWeights(void *nativeRenderableManager, int instance, floatArray weights) {
//    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
//    float *vec = env->GetFloatArrayElements(weights, NULL);
//    math::float4 floatvec(vec[0], vec[1], vec[2], vec[3]);
//    env->ReleaseFloatArrayElements(weights, vec, JNI_ABORT);
//    rm->setMorphWeights((RenderableManager::Instance) instance, floatvec);
//}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetAxisAlignedBoundingBox(void *nativeRenderableManager, int i, float cx,
                                                                      float cy, float cz,
                                                                      float ex, float ey,
                                                                      float ez) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setAxisAlignedBoundingBox((RenderableManager::Instance) i, {{cx, cy, cz},
                                                                    {ex, ey, ez}});
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetLayerMask(void *nativeRenderableManager, int i, int select, int value) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setLayerMask((RenderableManager::Instance) i, (uint8_t) select, (uint8_t) value);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetPriority(void *nativeRenderableManager, int i, int priority) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setPriority((RenderableManager::Instance) i, (uint8_t) priority);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetCulling(void *nativeRenderableManager, int i, bool enabled) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setCulling((RenderableManager::Instance) i, enabled);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetCastShadows(void *nativeRenderableManager, int i, bool enabled) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setCastShadows((RenderableManager::Instance) i, enabled);
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetReceiveShadows(void *nativeRenderableManager, int i, bool enabled) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setReceiveShadows((RenderableManager::Instance) i, enabled);
}

extern "C" DOTNET_EXPORT void
filament_RenderableManager_nSetScreenSpaceContactShadows(void *nativeRenderableManager, int i, bool enabled) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setScreenSpaceContactShadows((RenderableManager::Instance) i, enabled);
}

extern "C" DOTNET_EXPORT bool filament_RenderableManager_nIsShadowCaster(void *nativeRenderableManager, int i) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return (bool) rm->isShadowCaster((RenderableManager::Instance) i);
}

extern "C" DOTNET_EXPORT bool filament_RenderableManager_nIsShadowReceiver(void *nativeRenderableManager, int i) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return (bool) rm->isShadowReceiver((RenderableManager::Instance) i);
}

// FIXME:
//extern "C" DOTNET_EXPORT void filament_RenderableManager_nGetAxisAlignedBoundingBox(void *nativeRenderableManager, int i,
//                                                                      floatArray center_,
//                                                                      floatArray halfExtent_) {
//    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
//    float *center = env->GetFloatArrayElements(center_, NULL);
//    float *halfExtent = env->GetFloatArrayElements(halfExtent_, NULL);
//    Box const &aabb = rm->getAxisAlignedBoundingBox((RenderableManager::Instance) i);
//    *reinterpret_cast<filament::math::float3 *>(center) = aabb.center;
//    *reinterpret_cast<filament::math::float3 *>(halfExtent) = aabb.halfExtent;
//    env->ReleaseFloatArrayElements(center_, center, 0);
//    env->ReleaseFloatArrayElements(halfExtent_, halfExtent, 0);
//}

extern "C" DOTNET_EXPORT int filament_RenderableManager_nGetPrimitiveCount(void *nativeRenderableManager, int i) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return (int) rm->getPrimitiveCount((RenderableManager::Instance) i);
}

extern "C" DOTNET_EXPORT void
filament_RenderableManager_nSetMaterialInstanceAt(void *nativeRenderableManager, int i, int primitiveIndex,
                                                  void *nativeMaterialInstance) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    const MaterialInstance *materialInstance = (const MaterialInstance *) nativeMaterialInstance;
    rm->setMaterialInstanceAt((RenderableManager::Instance) i, (size_t) primitiveIndex,
                              materialInstance);
}

extern "C" DOTNET_EXPORT void *
filament_RenderableManager_nGetMaterialInstanceAt(void *nativeRenderableManager, int i, int primitiveIndex) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    return (void *) rm->getMaterialInstanceAt((RenderableManager::Instance) i, (size_t) primitiveIndex);
}

extern "C" DOTNET_EXPORT void *filament_RenderableManager_nGetMaterialAt(void *nativeRenderableManager, int i,
                                                           int primitiveIndex) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    MaterialInstance *mi = rm->getMaterialInstanceAt((RenderableManager::Instance) i, (size_t) primitiveIndex);
    return (void *) mi->getMaterial();
}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetGeometryAt__JIIIJJII(void *nativeRenderableManager,
                                                                    int i, int primitiveIndex,
                                                                    int primitiveType,
                                                                    void *nativeVertexBuffer,
                                                                    void *nativeIndexBuffer,
                                                                    int offset, int count) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    rm->setGeometryAt((RenderableManager::Instance) i, (size_t) primitiveIndex,
                      (RenderableManager::PrimitiveType) primitiveType, vertexBuffer, indexBuffer,
                      (size_t) offset, (size_t) count);
}

//extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetGeometryAt__JIIIII(void *nativeRenderableManager, int i,
//                                                                  int primitiveIndex, int primitiveType,
//                                                                  int offset,
//                                                                  int count) {
//    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
//    rm->setGeometryAt((RenderableManager::Instance) i, (size_t) primitiveIndex,
//                      (RenderableManager::PrimitiveType) primitiveType, (size_t) offset, (size_t) count);
//}

extern "C" DOTNET_EXPORT void filament_RenderableManager_nSetBlendOrderAt(void *nativeRenderableManager, int i,
                                                            int primitiveIndex, int blendOrder) {
    RenderableManager *rm = (RenderableManager *) nativeRenderableManager;
    rm->setBlendOrderAt((RenderableManager::Instance) i, (size_t) primitiveIndex,
                        (uint16_t) blendOrder);
}

extern "C" DOTNET_EXPORT int
filament_RenderableManager_nGetEnabledAttributesAt(void *nativeRenderableManager, int i, int primitiveIndex) {
    RenderableManager const *rm = (RenderableManager const *) nativeRenderableManager;
    AttributeBitset enabled = rm->getEnabledAttributesAt((RenderableManager::Instance) i, (size_t) primitiveIndex);
    return enabled.getValue();
}
