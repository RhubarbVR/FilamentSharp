#include "../Export.h"
#include <filament/Engine.h>
#include <filament/Material.h>

#include <filameshio/MeshReader.h>

using namespace filament;
using namespace filamesh;

extern "C" DOTNET_EXPORT void
filament_MeshIO_MeshReader_nLoadMeshFromBufferMaterial(void *nativeEngine, void *buffer,
                                                       void *nativeDefaultMaterialInstance, int &outRenderable,
                                                       VertexBuffer **outVertexBuffer, IndexBuffer **outIndexBuffer) {
    Engine *engine = (Engine *) nativeEngine;
    MaterialInstance *materialInstance = (MaterialInstance *) nativeDefaultMaterialInstance;

    MeshReader::Mesh mesh = MeshReader::loadMeshFromBuffer(engine, buffer, nullptr, nullptr, materialInstance);

    outRenderable = mesh.renderable.getId();

    *outVertexBuffer = mesh.vertexBuffer;
    *outIndexBuffer = mesh.indexBuffer;
}