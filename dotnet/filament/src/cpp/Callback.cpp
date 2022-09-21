#include "Export.h"
#include "Callback.h"

void ManagedBufferCallback::invoke(void*, size_t, void* user) {
    ManagedBufferCallback* data = reinterpret_cast<ManagedBufferCallback*>(user);
    delete data;
}