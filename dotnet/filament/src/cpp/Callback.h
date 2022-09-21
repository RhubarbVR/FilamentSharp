#pragma once

#include <filament/Engine.h>

struct ManagedBufferCallback {
    static void invoke(void* buffer, size_t n, void* user);
};
