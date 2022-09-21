#include "Export.h"
#include <filament/Color.h>

using namespace filament;

extern "C" DOTNET_EXPORT LinearColor filament_Color_ToLinearAccurate(sRGBColor color) {
    return Color::toLinear<ACCURATE>(color);
}

extern "C" DOTNET_EXPORT LinearColor filament_Color_cct(float K) {
    return Color::cct(K);
}

extern "C" DOTNET_EXPORT LinearColor filament_Color_illuminantD(float K) {
    return Color::illuminantD(K);
}
