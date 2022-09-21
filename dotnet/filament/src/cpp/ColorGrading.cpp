#include "Export.h"
#include <filament/ColorGrading.h>

#include <math/vec3.h>
#include <math/vec4.h>

using namespace filament;
using namespace math;

extern "C" DOTNET_EXPORT void *filament_ColorGrading_nCreateBuilder() {
    return (void *) new ColorGrading::Builder();
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nDestroyBuilder(void *nativeBuilder) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    delete builder;
}

extern "C" DOTNET_EXPORT void *filament_ColorGrading_nBuilderBuild(void *nativeBuilder, void *nativeEngine) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (void *) builder->build(*engine);
}
extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderQuality(void *nativeBuilder, int quality_) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    ColorGrading::QualityLevel quality = (ColorGrading::QualityLevel) quality_;
    builder->quality(quality);
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderToneMapping(void *nativeBuilder, int toneMapping_) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    ColorGrading::ToneMapping toneMapping = (ColorGrading::ToneMapping) toneMapping_;
    builder->toneMapping(toneMapping);
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderWhiteBalance(void *nativeBuilder, float temperature, float tint) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    builder->whiteBalance(temperature, tint);
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderContrast(void *nativeBuilder, float contrast) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    builder->contrast(contrast);
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderVibrance(void *nativeBuilder, float vibrance) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    builder->vibrance(vibrance);
}

extern "C" DOTNET_EXPORT void filament_ColorGrading_nBuilderSaturation(void *nativeBuilder, float saturation) {
    ColorGrading::Builder *builder = (ColorGrading::Builder *) nativeBuilder;
    builder->saturation(saturation);
}
