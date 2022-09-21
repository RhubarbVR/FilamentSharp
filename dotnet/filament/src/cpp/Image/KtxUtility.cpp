//#include "../Export.h"
//#include <filament/Engine.h>
//
//#include <image/KtxUtility.h>
//
//using namespace filament;
//using namespace image;
//
//extern "C" DOTNET_EXPORT void *
//filament_Image_KtxUtility_CreateTexture(void *nativeEngine, void *nativeKtxBundle, bool forceSrgb) {
//    Engine *engine = (Engine *) nativeEngine;
//    KtxBundle *ktx = (KtxBundle *) nativeKtxBundle;
//
//    return (void *) ktx::createTexture(
//            engine,
//            ktx,
//            forceSrgb
//    );
//}
