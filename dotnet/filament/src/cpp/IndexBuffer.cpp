#include "Export.h"
#include <functional>
#include <stdlib.h>
#include <string.h>

#include <filament/IndexBuffer.h>
#include "Callback.h"

#include <backend/BufferDescriptor.h>

using namespace filament;
using namespace backend;

extern "C" DOTNET_EXPORT void *filament_IndexBuffer_nCreateBuilder() {
    return (void *) new IndexBuffer::Builder();
}

extern "C" DOTNET_EXPORT void filament_IndexBuffer_nDestroyBuilder(void *nativeBuilder) {
    IndexBuffer::Builder *builder = (IndexBuffer::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_IndexBuffer_nBuilderIndexCount(void *nativeBuilder, int indexCount) {
    IndexBuffer::Builder *builder = (IndexBuffer::Builder *) nativeBuilder;
    builder->indexCount((uint32_t) indexCount);
}

extern "C" DOTNET_EXPORT void filament_IndexBuffer_nBuilderBufferType(void *nativeBuilder, int indexType) {
    using IndexType = IndexBuffer::IndexType;
    IndexBuffer::Builder *builder = (IndexBuffer::Builder *) nativeBuilder;
    IndexType types[] = {IndexType::USHORT, IndexType::UINT};
    builder->bufferType(types[indexType & 1]);
}

extern "C" DOTNET_EXPORT void *filament_IndexBuffer_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    IndexBuffer::Builder *builder = (IndexBuffer::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

extern "C" DOTNET_EXPORT int filament_IndexBuffer_nGetIndexCount(void *nativeIndexBuffer) {
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    return indexBuffer->getIndexCount();
}

extern "C" DOTNET_EXPORT void filament_IndexBuffer_nSetBuffer(void *nativeIndexBuffer, void *nativeEngine,
                                                void *buffer, int bufferSizeInBytes,
                                                int destOffsetInBytes) {
    IndexBuffer *indexBuffer = (IndexBuffer *) nativeIndexBuffer;
    Engine *engine = (Engine *) nativeEngine;

    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    BufferDescriptor desc(std::move(data), bufferSizeInBytes, &ManagedBufferCallback::invoke, nullptr);

    indexBuffer->setBuffer(*engine, std::move(desc), (uint32_t) destOffsetInBytes);
}
