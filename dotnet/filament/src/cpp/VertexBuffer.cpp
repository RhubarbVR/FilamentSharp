#include "Export.h"
#include <stdlib.h>
#include <string.h>

#include <filament/VertexBuffer.h>
#include "Callback.h"

#include <math/vec3.h>
#include <math/vec4.h>

using namespace filament;
using namespace filament::math;
using namespace backend;

extern "C" DOTNET_EXPORT void *filament_VertexBuffer_nCreateBuilder() {
    return (void *) new VertexBuffer::Builder();
}

extern "C" DOTNET_EXPORT void filament_VertexBuffer_nDestroyBuilder(void *nativeBuilder) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_VertexBuffer_nBuilderVertexCount(void *nativeBuilder, int vertexCount) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    builder->vertexCount((uint32_t) vertexCount);
}

extern "C" DOTNET_EXPORT void filament_VertexBuffer_nBuilderBufferCount(void *nativeBuilder, int bufferCount) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    builder->bufferCount((uint8_t) bufferCount);
}

extern "C" DOTNET_EXPORT void
filament_VertexBuffer_nBuilderAttribute(void *nativeBuilder, int attribute, int bufferIndex, int attributeType,
                                        int byteOffset,
                                        int byteStride) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    builder->attribute((VertexAttribute) attribute, (uint8_t) bufferIndex,
                       (VertexBuffer::AttributeType) attributeType,
                       (uint32_t) byteOffset, (uint8_t) byteStride);
}

extern "C" DOTNET_EXPORT void filament_VertexBuffer_nBuilderNormalized(void *nativeBuilder, int attribute, bool normalized) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    builder->normalized((VertexAttribute) attribute, normalized);
}

extern "C" DOTNET_EXPORT void *filament_VertexBuffer_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    VertexBuffer::Builder *builder = (VertexBuffer::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

extern "C" DOTNET_EXPORT int filament_VertexBuffer_nGetVertexCount(void *nativeVertexBuffer) {
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    return vertexBuffer->getVertexCount();
}

extern "C" DOTNET_EXPORT void filament_VertexBuffer_nSetBufferAt(void *nativeVertexBuffer, void *nativeEngine, int bufferIndex,
                                                   void *buffer, int bufferSizeInBytes,
                                                   int destOffsetInBytes) {
    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    BufferDescriptor desc(std::move(data), bufferSizeInBytes, &ManagedBufferCallback::invoke, nullptr);

    Engine *engine = (Engine *) nativeEngine;
    VertexBuffer *vertexBuffer = (VertexBuffer *) nativeVertexBuffer;
    vertexBuffer->setBufferAt(*engine, (uint8_t) bufferIndex, std::move(desc),
                              (uint32_t) destOffsetInBytes);
}
