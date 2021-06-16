package com.yoki.render;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class RenderGLView extends GLSurfaceView implements GLSurfaceView.Renderer {
    private RenderNativeBridge mNativeBridge = new RenderNativeBridge();

    private long lastRenderTime = -1;

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
        mNativeBridge.init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        mNativeBridge.resize(width , height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        long deltaTime = 0;
        long currentTime = System.currentTimeMillis();
        if(lastRenderTime >= 0){
            deltaTime = currentTime - lastRenderTime;
        }
        //System.out.println("deltaTime = " + deltaTime);
        lastRenderTime = currentTime;
        mNativeBridge.update(deltaTime);

    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        mNativeBridge.destory();
    }
}//end class
