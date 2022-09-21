#include "../Export.h"
#include <filament/Engine.h>
#include <image/LinearImage.h>

using namespace filament;
using namespace image;

extern "C" DOTNET_EXPORT void *filament_Image_LinearImage_Create(int width, int height, int channels) {
    return new LinearImage(width, height, channels);
}

extern "C" DOTNET_EXPORT void filament_Image_LinearImage_Destroy(void *nativeImage) {
    LinearImage *image = (LinearImage *) nativeImage;
    delete image;
}

extern "C" DOTNET_EXPORT void
filament_Image_LinearImage_SetPixelData(void *nativeImage, int column, int row, float r, float g, float b, float a) {
    LinearImage *image = (LinearImage *) nativeImage;

    float *ref = image->getPixelRef(column, row);
    int channels = image->getChannels();

    ref[0] = r;

    if (channels >= 2) {
        ref[1] = g;
    }

    if (channels >= 3) {
        ref[2] = b;
    }

    if (channels >= 4) {
        ref[3] = a;
    }
}
