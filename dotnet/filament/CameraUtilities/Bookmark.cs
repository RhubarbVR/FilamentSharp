using System;
using System.Diagnostics;
using System.Numerics;

namespace Filament.CameraUtilities
{
    /// <summary>
    /// Opaque memento to a viewing position and orientation (e.g. the "home" camera position).
    /// </summary>
    /// <remarks>
    /// This little struct is meant to be passed around by value and can be used to track camera
    /// animation between waypoints. In map mode this implements Van Wijk interpolation.
    /// </remarks>
    public struct Bookmark
    {
        public Mode Mode;
        public MapParams Map;
        public OrbitParams Orbit;
        public FlightParams Flight;

        /// <summary>
        /// Interpolates between two bookmarks. The t argument must be between 0 and 1 (inclusive), and
        /// the two endpoints must have the same mode (ORBIT or MAP).
        /// </summary>
        public static Bookmark Interpolate(Bookmark a, Bookmark b, float time)
        {
            Bookmark result = new Bookmark();

            if (a.Mode == Mode.Map) {
                Debug.Assert(b.Mode == Mode.Map);

                float rho = MathF.Sqrt(2.0f);
                float rho2 = 2, rho4 = 4;
                float ux0 = a.Map.Center.X, uy0 = a.Map.Center.Y, w0 = a.Map.Extent;
                float ux1 = b.Map.Center.X, uy1 = b.Map.Center.Y, w1 = b.Map.Extent;
                float dx = ux1 - ux0;
                float dy = uy1 - uy0;
                float d2 = dx * dx + dy * dy;
                float d1 = MathF.Sqrt(d2);
                float b0 = (w1 * w1 - w0 * w0 + rho4 * d2) / (2.0f * w0 * rho2 * d1);
                float b1 = (w1 * w1 - w0 * w0 - rho4 * d2) / (2.0f * w1 * rho2 * d1);
                float r0 = MathF.Log(MathF.Sqrt(b0 * b0 + 1.0f) - b0);
                float r1 = MathF.Log(MathF.Sqrt(b1 * b1 + 1f) - b1);
                float dr = r1 - r0;
                bool valid = dr != 0;
                float s = ((valid ? dr : MathF.Log(w1 / w0)) / rho);
                s = time * s;

                // this performs Van Wijk interpolation to animate between two waypoints on a map.
                if (valid) {
                    var coshr0 = MathF.Cosh(r0);
                    var u = w0 / (rho2 * d1) * (coshr0 * MathF.Tanh(rho * s + r0) - MathF.Sinh(r0));

                    result.Map.Center.X = (ux0 + u * dx);
                    result.Map.Center.Y = (uy0 + u * dy);
                    result.Map.Extent = (w0 * coshr0 / MathF.Cosh(rho * s + r0));

                    return result;
                }

                // for degenerate cases, fall back to a simplified interpolation method.
                result.Map.Center.X = ux0 + time * dx;
                result.Map.Center.Y = uy0 + time * dy;
                result.Map.Extent = (w0 * MathF.Exp(rho * s));

                return result;
            }

            Debug.Assert(b.Mode == Mode.Orbit);

            result.Orbit.Phi = MathUtils.Lerp(a.Orbit.Phi, b.Orbit.Phi, time);
            result.Orbit.Theta = MathUtils.Lerp(a.Orbit.Theta, b.Orbit.Theta, time);
            result.Orbit.Distance = MathUtils.Lerp(a.Orbit.Distance, b.Orbit.Distance, time);
            result.Orbit.Pivot = Vector3.Lerp(a.Orbit.Pivot, b.Orbit.Pivot, time);

            return result;
        }

        /// <summary>
        /// Recommends a duration for animation between two MAP endpoints. The return value is a unitless multiplier.
        /// </summary>
        public static float Duration(Bookmark a, Bookmark b)
        {
            Debug.Assert(a.Mode == Mode.Orbit && b.Mode == Mode.Orbit);

            float rho = MathF.Sqrt(2.0f);
            float rho2 = 2, rho4 = 4;
            float ux0 = a.Map.Center.X, uy0 = a.Map.Center.Y, w0 = a.Map.Extent;
            float ux1 = b.Map.Center.X, uy1 = b.Map.Center.Y, w1 = b.Map.Extent;
            float dx = ux1 - ux0, dy = uy1 - uy0, d2 = dx * dx + dy * dy, d1 = MathF.Sqrt(d2);
            float b0 = (w1 * w1 - w0 * w0 + rho4 * d2) / (2.0f * w0 * rho2 * d1);
            float b1 = (w1 * w1 - w0 * w0 - rho4 * d2) / (2.0f * w1 * rho2 * d1);
            float r0 = MathF.Log(MathF.Sqrt(b0 * b0 + 1.0f) - b0);
            float r1 = MathF.Log(MathF.Sqrt(b1 * b1 + 1f) - b1);
            float dr = r1 - r0;
            bool valid = dr != 0;
            float s = (valid ? dr : MathF.Log(w1 / w0)) / rho;

            return MathF.Abs(s);
        }

        public struct MapParams
        {
            public float Extent;
            public Vector2 Center;
        }

        public struct OrbitParams
        {
            public float Phi;
            public float Theta;
            public float Distance;
            public Vector3 Pivot;
        }

        public struct FlightParams
        {
            public float Pitch;
            public float Yaw;
            public Vector3 Position;
        }
    }
}
