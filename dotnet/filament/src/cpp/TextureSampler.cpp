#include "Export.h"
#include <filament/TextureSampler.h>

using namespace filament;

extern "C" DOTNET_EXPORT int filament_TextureSampler_nCreateSampler(int min, int max, int s, int t, int r) {
    return TextureSampler(static_cast<TextureSampler::MinFilter>(min),
                          static_cast<TextureSampler::MagFilter>(max), static_cast<TextureSampler::WrapMode>(s),
                          static_cast<TextureSampler::WrapMode>(t),
                          static_cast<TextureSampler::WrapMode>(r)).getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nCreateCompareSampler(int mode, int function) {
    return TextureSampler(static_cast<TextureSampler::CompareMode>(mode),
                          static_cast<TextureSampler::CompareFunc>(function)).getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetMinFilter(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getMinFilter());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetMinFilter(int sampler_, int filter) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setMinFilter(static_cast<TextureSampler::MinFilter>(filter));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetMagFilter(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getMagFilter());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetMagFilter(int sampler_, int filter) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setMagFilter(static_cast<TextureSampler::MagFilter>(filter));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetWrapModeS(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getWrapModeS());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetWrapModeS(int sampler_, int mode) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setWrapModeS(static_cast<TextureSampler::WrapMode>(mode));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetWrapModeT(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getWrapModeT());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetWrapModeT(int sampler_, int mode) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setWrapModeT(static_cast<TextureSampler::WrapMode>(mode));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetWrapModeR(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getWrapModeR());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetWrapModeR(int sampler_, int mode) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setWrapModeR(static_cast<TextureSampler::WrapMode>(mode));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetCompareMode(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getCompareMode());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetCompareMode(int sampler_, int mode) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setCompareMode(static_cast<TextureSampler::CompareMode>(mode),
                           sampler.getCompareFunc());
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nGetCompareFunction(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return static_cast<int>(sampler.getCompareFunc());
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetCompareFunction(int sampler_, int function) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setCompareMode(sampler.getCompareMode(), static_cast<TextureSampler::CompareFunc>(function));
    return sampler.getSamplerParams().u;
}

extern "C" DOTNET_EXPORT float filament_TextureSampler_nGetAnisotropy(int sampler_) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    return sampler.getAnisotropy();
}

extern "C" DOTNET_EXPORT int filament_TextureSampler_nSetAnisotropy(int sampler_, float anisotropy) {
    TextureSampler &sampler = reinterpret_cast<TextureSampler &>(sampler_);
    sampler.setAnisotropy(anisotropy);
    return sampler.getSamplerParams().u;
}
