cmake_minimum_required(VERSION 3.10)
project(filament-dotnet)

# ==================================================================================================
# .net bindings
# ==================================================================================================
set(TARGET filament-dotnet)

set(CXX_STANDARD "-std=c++17")
if (WIN32)
    set(CXX_STANDARD "/std:c++17")
endif ()

set(WRAPPER_SOURCE_FILES
        src/cpp/Camera.cpp
        src/cpp/ColorGrading.cpp
        src/cpp/Engine.cpp
        src/cpp/EntityManager.cpp
        src/cpp/Fence.cpp
        src/cpp/IndexBuffer.cpp
        src/cpp/IndirectLight.cpp
        src/cpp/LightManager.cpp
        src/cpp/Material.cpp
        src/cpp/MaterialInstance.cpp
        src/cpp/MathUtils.cpp
        src/cpp/RenderableManager.cpp
        src/cpp/Renderer.cpp
        src/cpp/RenderTarget.cpp
        src/cpp/Scene.cpp
        src/cpp/SkyBox.cpp
        src/cpp/Stream.cpp
        src/cpp/SurfaceOrientation.cpp
        src/cpp/SwapChain.cpp
        src/cpp/Texture.cpp
        src/cpp/TextureSampler.cpp
        src/cpp/TransformManager.cpp
        src/cpp/VertexBuffer.cpp
        src/cpp/View.cpp
        src/cpp/Callback.cpp
        src/cpp/Callback.h
        src/cpp/Colors.cpp
        src/cpp/MeshIO/MeshReader.cpp
        src/cpp/Image/KtxBundle.cpp
        src/cpp/Image/KtxUtility.cpp
        src/cpp/Image/LinearImage.cpp
        src/cpp/Image/ImageSampler.cpp)

add_library(${TARGET} SHARED ${WRAPPER_SOURCE_FILES})
target_link_libraries(${TARGET} filament filameshio image sdl2)

set(INSTALL_TYPE LIBRARY)
if (WIN32 OR CYGWIN)
    set(INSTALL_TYPE RUNTIME)
endif ()
install(TARGETS ${TARGET} ${INSTALL_TYPE} DESTINATION lib/${DIST_DIR})
set(LIB_SUFFIX ".so")
if (APPLE)
    set(LIB_SUFFIX ".dylib")
elseif (WIN32)
    set(LIB_SUFFIX ".dll")
endif ()
install(CODE "execute_process(COMMAND ${CMAKE_STRIP} -x ${CMAKE_INSTALL_PREFIX}/lib/${DIST_DIR}/lib${TARGET}${LIB_SUFFIX})")
