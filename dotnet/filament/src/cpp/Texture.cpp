#include "Export.h"
#include <algorithm>
#include <functional>

#include <backend/BufferDescriptor.h>
#include <filament/Engine.h>
#include <filament/Stream.h>
#include <filament/Texture.h>
#include <image/LinearImage.h>

#include "Callback.h"

using namespace filament;
using namespace backend;

extern "C" DOTNET_EXPORT bool filament_Texture_nIsTextureFormatSupported(void *nativeEngine, int internalFormat) {
    Engine *engine = (Engine *) nativeEngine;
    return (bool) Texture::isTextureFormatSupported(*engine, (Texture::InternalFormat) internalFormat);
}

// Texture::Builder...

extern "C" DOTNET_EXPORT void *filament_Texture_nCreateBuilder() {
    return (void *) new Texture::Builder();
}

extern "C" DOTNET_EXPORT void filament_Texture_nDestroyBuilder(void *nativeBuilder) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderWidth(void *nativeBuilder, int width) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->width((uint32_t) width);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderHeight(void *nativeBuilder, int height) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->height((uint32_t) height);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderDepth(void *nativeBuilder, int depth) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->depth((uint32_t) depth);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderLevels(void *nativeBuilder, int levels) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->levels((uint8_t) levels);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderSampler(void *nativeBuilder, int sampler) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->sampler((Texture::Sampler) sampler);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderFormat(void *nativeBuilder, int format) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->format((Texture::InternalFormat) format);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderUsage(void *nativeBuilder, int flags) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->usage((Texture::Usage) flags);
}

extern "C" DOTNET_EXPORT void filament_Texture_nBuilderSwizzle(void *nativeBuilder, int r, int g, int b, int a) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    builder->swizzle((Texture::Swizzle) r, (Texture::Swizzle) g, (Texture::Swizzle) b, (Texture::Swizzle) a);
}

extern "C" DOTNET_EXPORT void *filament_Texture_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    Texture::Builder *builder = (Texture::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}

// Texture...

extern "C" DOTNET_EXPORT int filament_Texture_nGetWidth(void *nativeTexture, int level) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getWidth((size_t) level);
}

extern "C" DOTNET_EXPORT int filament_Texture_nGetHeight(void *nativeTexture, int level) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getHeight((size_t) level);
}

extern "C" DOTNET_EXPORT int filament_Texture_nGetDepth(void *nativeTexture, int level) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getDepth((size_t) level);
}

extern "C" DOTNET_EXPORT int filament_Texture_nGetLevels(void *nativeTexture) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getLevels();
}

extern "C" DOTNET_EXPORT int filament_Texture_nGetTarget(void *nativeTexture) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getTarget();
}

extern "C" DOTNET_EXPORT int filament_Texture_nGetInternalFormat(void *nativeTexture) {
    Texture *texture = (Texture *) nativeTexture;
    return (int) texture->getFormat();
}

extern "C" DOTNET_EXPORT void filament_Texture_nSetImage(void *nativeTexture, void *nativeEngine, int level, int xOffset, int yOffset,
                                           int width, int height, void *buffer, int bufferSizeInBytes,
                                           int left, int top, int type, int alignment, int stride, int format) {
    Engine *engine = (Engine *) nativeEngine;
    Texture *texture = (Texture *) nativeTexture;

    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    Texture::PixelBufferDescriptor desc(std::move(data), bufferSizeInBytes, (backend::PixelDataFormat) format,
                                        (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left,
                                        (uint32_t) top,
                                        (uint32_t) stride, &ManagedBufferCallback::invoke, nullptr);


    texture->setImage(*engine, (size_t) level, (uint32_t) xOffset, (uint32_t) yOffset,
                      (uint32_t) width, (uint32_t) height, std::move(desc));
}

extern "C" DOTNET_EXPORT void filament_Texture_nSetImageLinear(void *nativeTexture, void *nativeEngine, int level, int xOffset, int yOffset,
                                           int width, int height, void *nativeLinearImage,
                                           int left, int top, int type, int alignment, int stride, int format) {
    Engine *engine = (Engine *) nativeEngine;
    Texture *texture = (Texture *) nativeTexture;
    image::LinearImage *linearImage = (image::LinearImage *) nativeLinearImage;

    size_t bufferSizeInBytes = width * height * sizeof(float);

    Texture::PixelBufferDescriptor desc(std::move(linearImage->getPixelRef()), bufferSizeInBytes, (backend::PixelDataFormat) format,
                                        (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left,
                                        (uint32_t) top,
                                        (uint32_t) stride, &ManagedBufferCallback::invoke, nullptr);


    texture->setImage(*engine, (size_t) level, (uint32_t) xOffset, (uint32_t) yOffset,
                      (uint32_t) width, (uint32_t) height, std::move(desc));
}

// FIXME:
//extern "C" DOTNET_EXPORT int filament_Texture_nSetImageCompressed(void *nativeTexture, void *nativeEngine, int level, int xoffset,
//                                                    int yoffset,
//                                                    int width, int height, jobject storage, int remaining,
//                                                    int, int, int, int, int compressedSizeInBytes, int compressedFormat,
//                                                    jobject handler, jobject runnable) {
//    Texture *texture = (Texture *) nativeTexture;
//    Engine *engine = (Engine *) nativeEngine;
//
//    size_t sizeInBytes = (size_t) compressedSizeInBytes;
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (size_t(remaining) << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    Texture::PixelBufferDescriptor desc(buffer, sizeInBytes,
//                                        (backend::CompressedPixelDataType) compressedFormat,
//                                        (uint32_t) compressedSizeInBytes,
//                                        &JniBufferCallback::invoke, callback);
//
//    texture->setImage(*engine, (size_t) level, (uint32_t) xoffset, (uint32_t) yoffset,
//                      (uint32_t) width, (uint32_t) height, std::move(desc));
//
//    return 0;
//}
//
//extern "C" DOTNET_EXPORT int filament_Texture_nSetImage3D(JNIEnv *env, jclass, void *nativeTexture,
//                                            void *nativeEngine, int level,
//                                            int xoffset, int yoffset, int zoffset,
//                                            int width, int height, int depth,
//                                            jobject storage, int remaining,
//                                            int left, int bottom, int type, int alignment,
//                                            int stride, int format,
//                                            jobject handler, jobject runnable) {
//    Texture *texture = (Texture *) nativeTexture;
//    Engine *engine = (Engine *) nativeEngine;
//
//    size_t sizeInBytes = getTextureDataSize(texture, (size_t) level, (Texture::Format) format,
//                                            (Texture::Type) type, (size_t) stride, (size_t) alignment);
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (size_t(remaining) << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    Texture::PixelBufferDescriptor desc(buffer, sizeInBytes, (backend::PixelDataFormat) format,
//                                        (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left,
//                                        (uint32_t) bottom,
//                                        (uint32_t) stride, &JniBufferCallback::invoke, callback);
//
//    texture->setImage(*engine, (size_t) level,
//                      (uint32_t) xoffset, (uint32_t) yoffset, (uint32_t) zoffset,
//                      (uint32_t) width, (uint32_t) height, (uint32_t) depth,
//                      std::move(desc));
//
//    return 0;
//}
//
//extern "C" DOTNET_EXPORT int filament_Texture_nSetImage3DCompressed(JNIEnv *env, jclass,
//                                                      void *nativeTexture, void *nativeEngine, int level,
//                                                      int xoffset, int yoffset, int zoffset,
//                                                      int width, int height, int depth,
//                                                      jobject storage, int remaining,
//                                                      int, int, int, int, int compressedSizeInBytes,
//                                                      int compressedFormat,
//                                                      jobject handler, jobject runnable) {
//    Texture *texture = (Texture *) nativeTexture;
//    Engine *engine = (Engine *) nativeEngine;
//
//    size_t sizeInBytes = (size_t) compressedSizeInBytes;
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (size_t(remaining) << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    Texture::PixelBufferDescriptor desc(buffer, sizeInBytes,
//                                        (backend::CompressedPixelDataType) compressedFormat,
//                                        (uint32_t) compressedSizeInBytes,
//                                        &JniBufferCallback::invoke, callback);
//
//    texture->setImage(*engine, (size_t) level,
//                      (uint32_t) xoffset, (uint32_t) yoffset, (uint32_t) zoffset,
//                      (uint32_t) width, (uint32_t) height, (uint32_t) depth,
//                      std::move(desc));
//
//    return 0;
//}
//
extern "C" DOTNET_EXPORT int filament_Texture_nSetImageCubemap(void *nativeTexture, void *nativeEngine, int level,
                                                 void* buffer, int bufferSizeInBytes,
                                                 int left, int bottom, int type, int alignment, int stride, int format,
                                                 void* faceOffsetsInBytes_) {
    Texture *texture = (Texture *) nativeTexture;
    Engine *engine = (Engine *) nativeEngine;

    int *faceOffsetsInBytes = static_cast<int*>(faceOffsetsInBytes_);
    Texture::FaceOffsets faceOffsets;
    std::copy_n(faceOffsetsInBytes, 6, faceOffsets.offsets);

    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    Texture::PixelBufferDescriptor desc(buffer, bufferSizeInBytes, (backend::PixelDataFormat) format,
                                        (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left,
                                        (uint32_t) bottom,
                                        (uint32_t) stride, &ManagedBufferCallback::invoke, nullptr);

    texture->setImage(*engine, (size_t) level, std::move(desc), faceOffsets);

    return 0;
}

extern "C" DOTNET_EXPORT int filament_Texture_nSetImageCubemapCompressed(void *nativeTexture, void *nativeEngine, int level,
                                                           void* buffer, int bufferSizeInBytes,
                                                           int left, int bottom, int type, int alignment,
                                                           int compressedSizeInBytes, int compressedFormat,
                                                           void* faceOffsetsInBytes_) {

    Texture *texture = (Texture *) nativeTexture;
    Engine *engine = (Engine *) nativeEngine;

    int *faceOffsetsInBytes = static_cast<int*>(faceOffsetsInBytes_);
    Texture::FaceOffsets faceOffsets;
    std::copy_n(faceOffsetsInBytes, 6, faceOffsets.offsets);

    size_t sizeInBytes = 6 * (size_t) compressedSizeInBytes;


    // FIXME: is copying the best thing to do here?
    void *data = malloc(bufferSizeInBytes);
    memcpy(data, buffer, bufferSizeInBytes);

    Texture::PixelBufferDescriptor desc(buffer, sizeInBytes,
                                        (backend::CompressedPixelDataType) compressedFormat,
                                        (uint32_t) compressedSizeInBytes,
                                        &ManagedBufferCallback::invoke, nullptr);

    texture->setImage(*engine, (size_t) level, std::move(desc), faceOffsets);

    return 0;
}

extern "C" DOTNET_EXPORT void filament_Texture_nSetExternalImage(void *nativeTexture, void *nativeEngine, void *eglImage) {
    Texture *texture = (Texture *) nativeTexture;
    Engine *engine = (Engine *) nativeEngine;
    texture->setExternalImage(*engine, (void *) eglImage);
}

extern "C" DOTNET_EXPORT void filament_Texture_nSetExternalStream(void *nativeTexture, void *nativeEngine, void *nativeStream) {
    Texture *texture = (Texture *) nativeTexture;
    Engine *engine = (Engine *) nativeEngine;
    Stream *stream = (Stream *) nativeStream;
    texture->setExternalStream(*engine, stream);
}

extern "C" DOTNET_EXPORT void filament_Texture_nGenerateMipmaps(void *nativeTexture, void *nativeEngine) {
    Texture *texture = (Texture *) nativeTexture;
    Engine *engine = (Engine *) nativeEngine;
    texture->generateMipmaps(*engine);
}

extern "C" DOTNET_EXPORT bool filament_Texture_nIsStreamValidForTexture(void *nativeTexture, void *) {
    Texture *texture = (Texture *) nativeTexture;
    return (texture->getTarget() == SamplerType::SAMPLER_EXTERNAL);
}

//
//extern "C" DOTNET_EXPORT int filament_Texture_nGeneratePrefilterMipmap(JNIEnv *env, jclass,
//                                                         void *nativeTexture, void *nativeEngine, int width, int height,
//                                                         jobject storage, int remaining, int left,
//                                                         int top, int type, int alignment, int stride, int format,
//                                                         intArray faceOffsetsInBytes_, jobject handler,
//                                                         jobject runnable, int sampleCount,
//                                                         bool mirror) {
//
//    Texture *texture = (Texture *) nativeTexture;
//    Engine *engine = (Engine *) nativeEngine;
//
//    int *faceOffsetsInBytes = env->GetIntArrayElements(faceOffsetsInBytes_, nullptr);
//    Texture::FaceOffsets faceOffsets;
//    std::copy_n(faceOffsetsInBytes, 6, faceOffsets.offsets);
//    env->ReleaseIntArrayElements(faceOffsetsInBytes_, faceOffsetsInBytes, JNI_ABORT);
//
//    stride = stride ? stride : width;
//    size_t sizeInBytes = 6 *
//                         Texture::computeTextureDataSize((Texture::Format) format, (Texture::Type) type,
//                                                         (size_t) stride, (size_t) height, (size_t) alignment);
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (size_t(remaining) << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    Texture::PixelBufferDescriptor desc(buffer, sizeInBytes, (backend::PixelDataFormat) format,
//                                        (backend::PixelDataType) type, (uint8_t) alignment,
//                                        (uint32_t) left, (uint32_t) top, (uint32_t) stride,
//                                        &JniBufferCallback::invoke, callback);
//
//    Texture::PrefilterOptions options;
//    options.sampleCount = sampleCount;
//    options.mirror = mirror;
//    texture->generatePrefilterMipmap(*engine, std::move(desc), faceOffsets, &options);
//
//    return 0;
//}
