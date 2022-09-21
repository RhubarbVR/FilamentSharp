#include "../Export.h"

#include <image/ImageSampler.h>
#include <image/LinearImage.h>

using namespace image;

extern "C" DOTNET_EXPORT void *filament_Image_ImageSampler_ResampleImage(void *nativeImage, int width, int height, int filter) {
    LinearImage *image = (LinearImage *) nativeImage;
    LinearImage newImage = image::resampleImage(*image, width, height, ImageSampler{
            .horizontalFilter = Filter(filter),
            .verticalFilter = Filter(filter)
    });

    return new LinearImage(newImage);
}