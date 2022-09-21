#include "Export.h"
#include <filament/Color.h>
#include <filament/View.h>
#include <filament/Viewport.h>

using namespace filament;

extern "C" DOTNET_EXPORT void filament_View_nSetName(void *nativeView, const char *name) {
    View *view = (View *) nativeView;
    view->setName(name);
}

extern "C" DOTNET_EXPORT void filament_View_nSetScene(void *nativeView, void *nativeScene) {
    View *view = (View *) nativeView;
    Scene *scene = (Scene *) nativeScene;
    view->setScene(scene);
}

extern "C" DOTNET_EXPORT void filament_View_nSetCamera(void *nativeView, void *nativeCamera) {
    View *view = (View *) nativeView;
    Camera *camera = (Camera *) nativeCamera;
    view->setCamera(camera);
}

extern "C" DOTNET_EXPORT void *filament_View_nGetCamera(void *nativeView) {
    View *view = (View *) nativeView;
    return (void *) &view->getCamera();
}

extern "C" DOTNET_EXPORT void filament_View_nSetDebugCamera(void *nativeView, void *nativeCamera) {
    View *view = (View *) nativeView;
    Camera *camera = (Camera *) nativeCamera;
    view->setDebugCamera(camera);
}

extern "C" DOTNET_EXPORT void filament_View_nSetColorGrading(void *nativeView, void *nativeColorGrading) {
    View *view = (View *) nativeView;
    ColorGrading *colorGrading = (ColorGrading *) nativeColorGrading;
    view->setColorGrading(colorGrading);
}

extern "C" DOTNET_EXPORT void filament_View_nSetViewport(void *nativeView, int left, int bottom, int width, int height) {
    View *view = (View *) nativeView;
    view->setViewport({left, bottom, (uint32_t) width, (uint32_t) height});
}

extern "C" DOTNET_EXPORT void filament_View_nSetVisibleLayers(void *nativeView, int select, int value) {
    View *view = (View *) nativeView;
    view->setVisibleLayers((uint8_t) select, (uint8_t) value);
}

extern "C" DOTNET_EXPORT void filament_View_nSetShadowingEnabled(void *nativeView, bool enabled) {
    View *view = (View *) nativeView;
    view->setShadowingEnabled(enabled);
}

extern "C" DOTNET_EXPORT void filament_View_nSetRenderTarget(void *nativeView, void *nativeTarget) {
    View *view = (View *) nativeView;
    view->setRenderTarget((RenderTarget *) nativeTarget);
}

extern "C" DOTNET_EXPORT void filament_View_nSetSampleCount(void *nativeView, int count) {
    View *view = (View *) nativeView;
    view->setSampleCount((uint8_t) count);
}

extern "C" DOTNET_EXPORT void *filament_View_nGetDirectionalLightCamera(void *nativeView) {
    View *view = (View *) nativeView;
    return (void *) view->getDirectionalLightCamera();
}

extern "C" DOTNET_EXPORT int filament_View_nGetSampleCount(void *nativeView) {
    View *view = (View *) nativeView;
    return view->getSampleCount();
}

extern "C" DOTNET_EXPORT void filament_View_nSetAntiAliasing(void *nativeView, int type) {
    View *view = (View *) nativeView;
    view->setAntiAliasing(View::AntiAliasing(type));
}

extern "C" DOTNET_EXPORT int filament_View_nGetAntiAliasing(void *nativeView) {
    View *view = (View *) nativeView;
    return (int) view->getAntiAliasing();
}

extern "C" DOTNET_EXPORT void filament_View_nSetDithering(void *nativeView, int dithering) {
    View *view = (View *) nativeView;
    view->setDithering((View::Dithering) dithering);
}

extern "C" DOTNET_EXPORT int filament_View_nGetDithering(void *nativeView) {
    View *view = (View *) nativeView;
    return (int) view->getDithering();
}

extern "C" DOTNET_EXPORT void filament_View_nSetDynamicResolutionOptions(void *nativeView, bool enabled, bool homogeneousScaling,
                                                           float minScale, float maxScale, int quality) {
    View *view = (View *) nativeView;
    View::DynamicResolutionOptions options;
    options.enabled = enabled;
    options.homogeneousScaling = homogeneousScaling;
    options.minScale = filament::math::float2{minScale};
    options.maxScale = filament::math::float2{maxScale};
    options.quality = (View::QualityLevel) quality;
    view->setDynamicResolutionOptions(options);
}

extern "C" DOTNET_EXPORT void filament_View_nSetShadowType(void *nativeView, int type) {
    View *view = (View *) nativeView;
    view->setShadowType((View::ShadowType) type);
}

extern "C" DOTNET_EXPORT void filament_View_nSetVsmShadowOptions(void *nativeView, int anisotropy, bool mipmapping, float exponent, float minVarianceScale, float lightBleedReduction) {
    View *view = (View *) nativeView;
    View::VsmShadowOptions options;
    options.anisotropy = (uint8_t)anisotropy;
    options.mipmapping = (bool)mipmapping;
    //options.exponent = exponent;
    options.minVarianceScale = minVarianceScale;
    options.lightBleedReduction = lightBleedReduction;
    view->setVsmShadowOptions(options);
}

extern "C" DOTNET_EXPORT void filament_View_nSetRenderQuality(void *nativeView, int hdrColorBufferQuality) {
    View *view = (View *) nativeView;
    View::RenderQuality renderQuality;
    renderQuality.hdrColorBuffer = View::QualityLevel(hdrColorBufferQuality);
    view->setRenderQuality(renderQuality);
}

extern "C" DOTNET_EXPORT void filament_View_nSetDynamicLightingOptions(void *nativeView, float zLightNear, float zLightFar) {
    View *view = (View *) nativeView;
    view->setDynamicLightingOptions(zLightNear, zLightFar);
}

extern "C" DOTNET_EXPORT void filament_View_nSetPostProcessingEnabled(void *nativeView, bool enabled) {
    View *view = (View *) nativeView;
    view->setPostProcessingEnabled(enabled);
}

extern "C" DOTNET_EXPORT bool filament_View_nIsPostProcessingEnabled(void *nativeView) {
    View *view = (View *) nativeView;
    return static_cast<bool>(view->isPostProcessingEnabled());
}

extern "C" DOTNET_EXPORT void filament_View_nSetFrontFaceWindingInverted(void *nativeView, bool inverted) {
    View *view = (View *) nativeView;
    view->setFrontFaceWindingInverted(inverted);
}

extern "C" DOTNET_EXPORT bool filament_View_nIsFrontFaceWindingInverted(void *nativeView) {
    View *view = (View *) nativeView;
    return static_cast<bool>(view->isFrontFaceWindingInverted());
}

extern "C" DOTNET_EXPORT void filament_View_nSetAmbientOcclusion(void *nativeView, int ordinal) {
    View *view = (View *) nativeView;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    view->setAmbientOcclusion((View::AmbientOcclusion) ordinal);
#pragma clang diagnostic pop
}

extern "C" DOTNET_EXPORT int filament_View_nGetAmbientOcclusion(void *nativeView) {
    View *view = (View *) nativeView;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return (int) view->getAmbientOcclusion();
#pragma clang diagnostic pop
}

extern "C" DOTNET_EXPORT void filament_View_nSetAmbientOcclusionOptions(
        void *nativeView, float radius, float bias, float power, float resolution, float intensity,
        float bilateralThreshold,
        int quality, int lowPassFilter, int upsampling, bool enabled, float minHorizonAngleRad,
        float ssctLightConeRad, float ssctStartTraceDistance,
        float ssctContactDistanceMax,
        float ssctIntensity, float ssctLightDirX, float ssctLightDirY,
        float ssctLightDirZ,
        float ssctDepthBias, float ssctDepthSlopeBias, int ssctSampleCount,
        int ssctRayCount, bool ssctEnabled) {
    View *view = (View *) nativeView;
    View::AmbientOcclusionOptions options = view->getAmbientOcclusionOptions();
    options.radius = radius;
    options.power = power;
    options.bias = bias;
    options.resolution = resolution;
    options.intensity = intensity;
    options.bilateralThreshold = bilateralThreshold;
    options.quality = (View::QualityLevel) quality;
    options.lowPassFilter = (View::QualityLevel) lowPassFilter;
    options.upsampling = (View::QualityLevel) upsampling;
    options.enabled = (bool) enabled;
    options.minHorizonAngleRad = minHorizonAngleRad;
    options.ssct.lightConeRad = ssctLightConeRad;
    options.ssct.shadowDistance = ssctStartTraceDistance;
    options.ssct.contactDistanceMax = ssctContactDistanceMax;
    options.ssct.intensity = ssctIntensity;
    options.ssct.lightDirection = math::float3{ssctLightDirX, ssctLightDirY, ssctLightDirZ};
    options.ssct.depthBias = ssctDepthBias;
    options.ssct.depthSlopeBias = ssctDepthSlopeBias;
    options.ssct.sampleCount = (uint8_t) ssctSampleCount;
    options.ssct.rayCount = (uint8_t) ssctRayCount;
    options.ssct.enabled = (bool) ssctEnabled;
    view->setAmbientOcclusionOptions(options);
}

extern "C" DOTNET_EXPORT void filament_View_nSetBloomOptions(
        void *nativeView, void *nativeTexture,
        float dirtStrength, float strength, int resolution, float anamorphism, int levels,
        int blendMode, bool threshold, bool enabled, float highlight, bool lensFlare, bool starburst,
        float chromaticAberration, int ghostCount, float ghostSpacing, float ghostThreshold, float haloThickness,
        float haloRadius, float haloThreshold) {
    View *view = (View *) nativeView;
    Texture *dirt = (Texture *) nativeTexture;
    View::BloomOptions options = {
            .dirt = dirt,
            .dirtStrength = dirtStrength,
            .strength = strength,
            .resolution = (uint32_t) resolution,
            .anamorphism = anamorphism,
            .levels = (uint8_t) levels,
            .blendMode = (View::BloomOptions::BlendMode) blendMode,
            .threshold = (bool) threshold,
            .enabled = (bool) enabled,
            .highlight = highlight,
            .lensFlare = (bool)lensFlare,
            .starburst = (bool)starburst,
            .chromaticAberration = chromaticAberration,
            .ghostCount = (uint8_t)ghostCount,
            .ghostSpacing = ghostSpacing,
            .ghostThreshold = ghostThreshold,
            .haloThickness = haloThickness,
            .haloRadius = haloRadius,
            .haloThreshold = haloThreshold
    };
    view->setBloomOptions(options);
}

extern "C" DOTNET_EXPORT void filament_View_nSetFogOptions(void *nativeView,
                                             float distance, float maximumOpacity, float height,
                                             float heightFalloff, float r,
                                             float g, float b, float density, float inScatteringStart,
                                             float inScatteringSize, bool fogColorFromIbl, bool enabled) {
    View *view = (View *) nativeView;
    View::FogOptions options = {
            .distance = distance,
            .maximumOpacity = maximumOpacity,
            .height = height,
            .heightFalloff = heightFalloff,
            .color = math::float3{r, g, b},
            .density = density,
            .inScatteringStart = inScatteringStart,
            .inScatteringSize = inScatteringSize,
            .fogColorFromIbl = (bool) fogColorFromIbl,
            .enabled = (bool) enabled
    };
    view->setFogOptions(options);
}

extern "C" DOTNET_EXPORT void filament_View_nSetBlendMode(void *nativeView, int blendMode) {
    View *view = (View *) nativeView;
    view->setBlendMode((View::BlendMode) blendMode);
}

extern "C" DOTNET_EXPORT void filament_View_nSetDepthOfFieldOptions(void *nativeView, float cocScale,
                                                      float maxApertureDiameter, bool enabled, int filter,
                                                      bool nativeResolution, int foregroundRingCount,
                                                      int backgroundRingCount, int fastGatherRingCount,
                                                      int maxForegroundCOC, int maxBackgroundCOC) {
    View *view = (View *) nativeView;
    View::DepthOfFieldOptions::Filter eFilter{};
    if (filter == 1) {
        // View::DepthOfFieldOptions::Filter::MEDIAN value is actually 2
        eFilter = View::DepthOfFieldOptions::Filter::MEDIAN;
    }
    view->setDepthOfFieldOptions({.cocScale = cocScale,
        .maxApertureDiameter = maxApertureDiameter, .enabled = (bool)enabled, .filter = eFilter,
        .nativeResolution = (bool)nativeResolution,
        .foregroundRingCount = (uint8_t)foregroundRingCount,
        .backgroundRingCount = (uint8_t)backgroundRingCount,
        .fastGatherRingCount = (uint8_t)fastGatherRingCount,
        .maxForegroundCOC = (uint8_t)maxForegroundCOC,
        .maxBackgroundCOC = (uint8_t)maxBackgroundCOC,
    });
}

extern "C" DOTNET_EXPORT void filament_View_nSetVignetteOptions(void *nativeView, float midPoint, float roundness,
                                                  float feather, float r, float g, float b, float a,
                                                  bool enabled) {
    View *view = (View *) nativeView;
    view->setVignetteOptions({.midPoint = midPoint, .roundness = roundness, .feather = feather,
                                     .color = LinearColorA{r, g, b, a}, .enabled = (bool) enabled});
}

extern "C" DOTNET_EXPORT void filament_View_nSetTemporalAntiAliasingOptions(void *nativeView, float feedback, float filterWidth,
                                                              bool enabled) {
    View *view = (View *) nativeView;
    view->setTemporalAntiAliasingOptions({
                                                 .filterWidth = filterWidth, .feedback = feedback, .enabled = (bool) enabled});
}

extern "C" DOTNET_EXPORT bool filament_View_nIsShadowingEnabled(void *nativeView) {
    View *view = (View *) nativeView;
    return (bool) view->isShadowingEnabled();
}

extern "C" DOTNET_EXPORT void filament_View_nSetScreenSpaceRefractionEnabled(void *nativeView, bool enabled) {
    View *view = (View *) nativeView;
    view->setScreenSpaceRefractionEnabled((bool) enabled);
}

extern "C" DOTNET_EXPORT bool filament_View_nIsScreenSpaceRefractionEnabled(void *nativeView) {
    View *view = (View *) nativeView;
    return (bool) view->isScreenSpaceRefractionEnabled();
}

extern "C" DOTNET_EXPORT void filament_View_nGetViewport(void *nativeView, int &left, int &bottom, int &width, int &height) {
    View *view = (View *) nativeView;
    Viewport viewport = view->getViewport();

    left = viewport.left;
    bottom = viewport.bottom;
    width = viewport.width;
    height = viewport.height;
}
