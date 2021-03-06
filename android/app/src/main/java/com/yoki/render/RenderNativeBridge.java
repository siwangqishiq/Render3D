package com.yoki.render;

import android.content.res.AssetManager;

public final class RenderNativeBridge {
    static {
        System.loadLibrary("render3d");
    }

    public native String stringFromJNI();

    public native void init();

    public native void update(long delta);

    public native void destory();

    public native void resize(int width , int height);

    public native static void setAssetManager(AssetManager mgr);
}
