#include "Export.h"
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/Viewport.h>
#include <backend/PixelBufferDescriptor.h>

using namespace filament;
using namespace backend;

extern "C" DOTNET_EXPORT bool filament_Renderer_nBeginFrame(void *nativeRenderer, void *nativeSwapChain, void *frameTimeNanos) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    SwapChain *swapChain = (SwapChain *) nativeSwapChain;
    return (bool) renderer->beginFrame(swapChain, uint64_t(frameTimeNanos));
}

extern "C" DOTNET_EXPORT void filament_Renderer_nEndFrame(void *nativeRenderer) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    renderer->endFrame();
}

extern "C" DOTNET_EXPORT void filament_Renderer_nRender(void *nativeRenderer, void *nativeView) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    View *view = (View *) nativeView;
    renderer->render(view);
}

extern "C" DOTNET_EXPORT void filament_Renderer_nCopyFrame(void *nativeRenderer,
                                             void *nativeDstSwapChain,
                                             int dstLeft, int dstBottom, int dstWidth, int dstHeight,
                                             int srcLeft, int srcBottom, int srcWidth, int srcHeight,
                                             int flags) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    SwapChain *dstSwapChain = (SwapChain *) nativeDstSwapChain;
    const filament::Viewport dstViewport{dstLeft, dstBottom, (uint32_t) dstWidth, (uint32_t) dstHeight};
    const filament::Viewport srcViewport{srcLeft, srcBottom, (uint32_t) srcWidth, (uint32_t) srcHeight};
    renderer->copyFrame(dstSwapChain, dstViewport, srcViewport, (uint32_t) flags);
}

// FIXME:
//extern "C" DOTNET_EXPORT int filament_Renderer_nReadPixels(void *nativeRenderer, void *nativeEngine,
//                                             int xoffset, int yoffset, int width, int height,
//                                             jobject storage, int remaining,
//                                             int left, int top, int type, int alignment, int stride, int format,
//                                             jobject handler, jobject runnable) {
//    Renderer *renderer = (Renderer *) nativeRenderer;
//    Engine *engine = (Engine *) nativeEngine;
//
//    stride = stride ? stride : width;
//    size_t sizeInBytes = PixelBufferDescriptor::computeDataSize(
//            (PixelDataFormat) format, (PixelDataType) type,
//            (size_t) stride, (size_t) (height + top), (size_t) alignment);
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    PixelBufferDescriptor desc(buffer, sizeInBytes, (backend::PixelDataFormat) format,
//                               (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left, (uint32_t) top,
//                               (uint32_t) stride, &JniBufferCallback::invoke, callback);
//
//    renderer->readPixels(uint32_t(xoffset), uint32_t(yoffset), uint32_t(width), uint32_t(height),
//                         std::move(desc));
//
//    return 0;
//}
//
//extern "C" DOTNET_EXPORT int filament_Renderer_nReadPixelsEx(void *nativeRenderer, void *nativeEngine, void *nativeRenderTarget,
//                                               int xoffset, int yoffset, int width, int height,
//                                               jobject storage, int remaining,
//                                               int left, int top, int type, int alignment, int stride, int format,
//                                               jobject handler, jobject runnable) {
//    Renderer *renderer = (Renderer *) nativeRenderer;
//    Engine *engine = (Engine *) nativeEngine;
//    RenderTarget *renderTarget = (RenderTarget *) nativeRenderTarget;
//
//    stride = stride ? stride : width;
//    size_t sizeInBytes = PixelBufferDescriptor::computeDataSize(
//            (PixelDataFormat) format, (PixelDataType) type,
//            (size_t) stride, (size_t) (height + top), (size_t) alignment);
//
//    AutoBuffer nioBuffer(env, storage, 0);
//    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
//        // BufferOverflowException
//        return -1;
//    }
//
//    void *buffer = nioBuffer.getData();
//    auto *callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));
//
//    PixelBufferDescriptor desc(buffer, sizeInBytes, (backend::PixelDataFormat) format,
//                               (backend::PixelDataType) type, (uint8_t) alignment, (uint32_t) left, (uint32_t) top,
//                               (uint32_t) stride, &JniBufferCallback::invoke, callback);
//
//    renderer->readPixels(renderTarget,
//                         uint32_t(xoffset), uint32_t(yoffset), uint32_t(width), uint32_t(height),
//                         std::move(desc));
//
//    return 0;
//}

extern "C" DOTNET_EXPORT float filament_Renderer_nGetUserTime(void *nativeRenderer) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    return renderer->getUserTime();
}

extern "C" DOTNET_EXPORT void filament_Renderer_nResetUserTime(void *nativeRenderer) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    renderer->resetUserTime();
}

extern "C" DOTNET_EXPORT void filament_Renderer_nSetDisplayInfo(void *nativeRenderer,
                                                  float refreshRate, void *presentationDeadlineNanos,
                                                  void *vsyncOffsetNanos) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    renderer->setDisplayInfo({.refreshRate = refreshRate,
                                     .presentationDeadlineNanos = (uint64_t) presentationDeadlineNanos,
                                     .vsyncOffsetNanos = (uint64_t) vsyncOffsetNanos});
}

extern "C" DOTNET_EXPORT void filament_Renderer_nSetFrameRateOptions(void *nativeRenderer, float interval, float headRoomRatio,
                                                       float scaleRate, int history) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    renderer->setFrameRateOptions({.headRoomRatio = headRoomRatio,
                                          .scaleRate = scaleRate,
                                          .history = (uint8_t) history,
                                          .interval = (uint8_t) interval});
}

extern "C" DOTNET_EXPORT void filament_Renderer_nSetClearOptions(void *nativeRenderer, float r, float g, float b, float a,
                                                   bool clear, bool discard) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    renderer->setClearOptions({.clearColor = {r, g, b, a},
                                      .clear = (bool) clear,
                                      .discard = (bool) discard});
}

extern "C" DOTNET_EXPORT void *filament_Renderer_nGetEngine(void *nativeRenderer) {
    Renderer *renderer = (Renderer *) nativeRenderer;
    return renderer->getEngine();
}
