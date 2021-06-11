package com.yoki.render;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class RenderGLView extends GLSurfaceView implements GLSurfaceView.Renderer {
    public RenderGLView(Context context) {
        super(context);
        initView();
    }

    public RenderGLView(Context context, AttributeSet attrs) {
        super(context, attrs);
        initView();
    }

    private void initView() {
        setEGLContextClientVersion(3);
        setEGLConfigChooser(8, 8, 8, 8, 16, 8);
        setRenderer(this);

//        setRenderMode(RENDERMODE_WHEN_DIRTY);
        setRenderMode(RENDERMODE_CONTINUOUSLY);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        RenderNativeBridge.init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        RenderNativeBridge.resize(width , height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        RenderNativeBridge.update(1);
    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        RenderNativeBridge.destory();
    }
}//end class
