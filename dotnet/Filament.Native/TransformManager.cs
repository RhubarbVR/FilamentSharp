using System;
using System.Runtime.InteropServices;

namespace Filament.Native
{
    public static class TransformManager
    {
        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nHasComponent")]
        public static extern bool HasComponent(IntPtr nativeTransformManager, int entity);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nGetInstance")]
        public static extern int GetInstance(IntPtr nativeTransformManager, int entity);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nCreate")]
        public static extern int Create(IntPtr nativeTransformManager, int entity);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nDestroy")]
        public static extern void Destroy(IntPtr nativeTransformManager, int entity);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nSetParent")]
        public static extern void SetParent(IntPtr nativeTransformManager, int instance, int newParent);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nGetWorldTransform")]
        public static extern void GetWorldTransform(IntPtr nativeTransformManager, int instance, float[] result);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nSetTransform")]
        public static extern void SetTransform(IntPtr nativeTransformManager, int instance, float[] result);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nOpenLocalTransformTransaction")]
        public static extern void OpenLocalTransformTransaction(IntPtr nativeTransformManager);

        [DllImport("libfilament-dotnet", EntryPoint = "filament_TransformManager_nCommitLocalTransformTransaction")]
        public static extern void CommitLocalTransformTransaction(IntPtr nativeTransformManager);
    }
}
