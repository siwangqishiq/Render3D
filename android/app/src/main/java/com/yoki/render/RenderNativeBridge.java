package com.yoki.render;

public final class RenderNativeBridge {
    static {
        System.loadLibrary("render3d");
    }

    public static native String stringFromJNI();

    public static native void init();

    public static native void update(long delta);

    public static native void destory();

    public static native void resize(int width , int height);
}
