#include <filament/SwapChain.h>

using namespace filament;

// FIXME:
//extern "C" JNIEXPORT void JNICALL
//Java_com_google_android_filament_SwapChain_nSetFrameCompletedCallback(JNIEnv* env, jclass,
//        jlong nativeSwapChain, jobject handler, jobject runnable) {
//    SwapChain* swapChain = (SwapChain*) nativeSwapChain;
//    auto *callback = JniCallback::make(env, handler, runnable);
//    swapChain->setFrameCompletedCallback(&JniCallback::invoke, callback);
//}
