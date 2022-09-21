#include "Export.h"
#include <filament/Camera.h>
#include <utils/Entity.h>

#include <math/mat4.h>

using namespace filament;

extern "C" DOTNET_EXPORT void filament_Camera_nSetProjection(void *nativeCamera, int projection, float left, float right,
                                               float bottom, float top, float near, float far) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setProjection((Camera::Projection) projection, left, right, bottom, top, near, far);
}

extern "C" DOTNET_EXPORT void filament_Camera_nSetProjectionFov(void *nativeCamera, float fovInDegrees, float aspect,
                                                  float near, float far, int fov) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setProjection(fovInDegrees, aspect, near, far, (Camera::Fov) fov);
}

extern "C" DOTNET_EXPORT void filament_Camera_nSetLensProjection(void *nativeCamera, float focalLength, float aspect,
                                                   float near, float far) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setLensProjection(focalLength, aspect, near, far);
}

// FIXME

//extern "C" DOTNET_EXPORT JNIEXPORT void JNICALL
//Java_com_google_android_filament_Camera_nSetScaling(JNIEnv* env, jclass,
//jlong nativeCamera, jdoubleArray inScaling_) {
//Camera *camera = (Camera *) nativeCamera;
//jdouble *inScaling = env->GetDoubleArrayElements(inScaling_, NULL);
//camera->setScaling(*reinterpret_cast<const filament::math::double4*>(inScaling));
//env->ReleaseDoubleArrayElements(inScaling_, inScaling, JNI_ABORT);
//}
//

extern "C" DOTNET_EXPORT void filament_Camera_nSetCustomProjection(void *nativeCamera, float *m, float *c, float near, float far) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setCustomProjection(
            filament::math::mat4(
                    m[0], m[1], m[2], m[3],
                    m[4], m[5], m[6], m[7],
                    m[8], m[9], m[10], m[11],
                    m[12], m[13], m[14], m[15]
            ),
            filament::math::mat4(
                    c[0], c[1], c[2], c[3],
                    c[4], c[5], c[6], c[7],
                    c[8], c[9], c[10], c[11],
                    c[12], c[13], c[14], c[15]
            ),
            near, far
    );
}

//extern "C" DOTNET_EXPORT void filament_Camera_nSetScaling(void *nativeCamera, floatArray inScaling_) {
//    Camera *camera = (Camera *) nativeCamera;
//    float *inScaling = env->GetDoubleArrayElements(inScaling_, NULL);
//    camera->setScaling(*reinterpret_cast<const filament::math::double4 *>(inScaling));
//    env->ReleaseDoubleArrayElements(inScaling_, inScaling, JNI_ABORT);
//}

extern "C" DOTNET_EXPORT void filament_Camera_nLookAt(void *nativeCamera, float eye_x, float eye_y, float eye_z,
                                        float center_x, float center_y, float center_z, float up_x,
                                        float up_y, float up_z) {
    Camera *camera = (Camera *) nativeCamera;
    camera->lookAt({eye_x, eye_y, eye_z}, {center_x, center_y, center_z}, {up_x, up_y, up_z});
}

extern "C" DOTNET_EXPORT float filament_Camera_nGetNear(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getNear();
}

extern "C" DOTNET_EXPORT float filament_Camera_nGetCullingFar(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getCullingFar();
}

extern "C" DOTNET_EXPORT void filament_Camera_nSetModelMatrix(void *nativeCamera, float *m) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setModelMatrix(
            filament::math::mat4f(
                    m[0], m[1], m[2], m[3],
                    m[4], m[5], m[6], m[7],
                    m[8], m[9], m[10], m[11],
                    m[12], m[13], m[14], m[15]
            )
    );
}

extern "C" DOTNET_EXPORT void filament_Camera_nGetProjectionMatrix(void *nativeCamera, filament::math::mat4f *outMatrix) {
    Camera *camera = (Camera *) nativeCamera;
    *outMatrix = filament::math::mat4f(camera->getProjectionMatrix());
}

extern "C" DOTNET_EXPORT void filament_Camera_nGetCullingProjectionMatrix(void *nativeCamera, filament::math::mat4f *outMatrix) {
    Camera *camera = (Camera *) nativeCamera;
    *outMatrix = filament::math::mat4f(camera->getCullingProjectionMatrix());
}

//
//extern "C" DOTNET_EXPORT JNIEXPORT void JNICALL
//Java_com_google_android_filament_Camera_nGetScaling(JNIEnv *env, jclass,
//jlong nativeCamera, jdoubleArray out_) {
//Camera *camera = (Camera *) nativeCamera;
//jdouble *out = env->GetDoubleArrayElements(out_, NULL);
//const filament::math::double4& s = camera->getScaling();
//std::copy_n(&s[0], 4, out);
//env->ReleaseDoubleArrayElements(out_, out, 0);
//}
//
extern "C" DOTNET_EXPORT void filament_Camera_nGetModelMatrix(void *nativeCamera, filament::math::mat4f *outMatrix) {
    Camera *camera = (Camera *) nativeCamera;
    *outMatrix = filament::math::mat4f(camera->getModelMatrix());
}

//extern "C" DOTNET_EXPORT void filament_Camera_nGetPosition(void *nativeCamera,
//                                             floatArray out_) {
//    Camera *camera = (Camera *) nativeCamera;
//    float *out = env->GetFloatArrayElements(out_, NULL);
//    reinterpret_cast<filament::math::float3 &>(*out) = camera->getPosition();
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}
//
//extern "C" DOTNET_EXPORT void filament_Camera_nGetLeftVector(void *nativeCamera,
//                                               floatArray out_) {
//    Camera *camera = (Camera *) nativeCamera;
//    float *out = env->GetFloatArrayElements(out_, NULL);
//    reinterpret_cast<filament::math::float3 &>(*out) = camera->getLeftVector();
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}
//
//extern "C" DOTNET_EXPORT void filament_Camera_nGetUpVector(void *nativeCamera,
//                                             floatArray out_) {
//    Camera *camera = (Camera *) nativeCamera;
//    float *out = env->GetFloatArrayElements(out_, NULL);
//    reinterpret_cast<filament::math::float3 &>(*out) = camera->getUpVector();
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}
//
//extern "C" DOTNET_EXPORT void filament_Camera_nGetForwardVector(void *nativeCamera, floatArray out_) {
//    Camera *camera = (Camera *) nativeCamera;
//    float *out = env->GetFloatArrayElements(out_, NULL);
//    reinterpret_cast<filament::math::float3 &>(*out) = camera->getForwardVector();
//    env->ReleaseFloatArrayElements(out_, out, 0);
//}

extern "C" DOTNET_EXPORT void filament_Camera_nSetExposure(void *nativeCamera,
                                             float aperture, float shutterSpeed,
                                             float sensitivity) {
    Camera *camera = (Camera *) nativeCamera;
    camera->setExposure(aperture, shutterSpeed, sensitivity);
}

extern "C" DOTNET_EXPORT float filament_Camera_nGetAperture(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getAperture();
}

extern "C" DOTNET_EXPORT float filament_Camera_nGetShutterSpeed(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getShutterSpeed();
}

extern "C" DOTNET_EXPORT float filament_Camera_nGetSensitivity(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getSensitivity();
}

extern "C" DOTNET_EXPORT int filament_Camera_nGetEntity(void *nativeCamera) {
    Camera *camera = (Camera *) nativeCamera;
    return camera->getEntity().getId();
}
