#include <jni.h>
#include <string>
#include <vector>
#include "App.h"

#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <memory>

#include "TriangleApp.h"
#include "CubeApp.h"
#include "PlatformAndroid.h"
#include "Skybox.h"

#include "gl.h"

// extern std::string show_platform();

// extern "C"
// JNIEXPORT jstring JNICALL
// Java_com_yoki_render_YokiBridge_stringFromJNI(JNIEnv *env, jclass clazz) {
//     std::string hello = "Hello from 耀西";
//     hello += show_platform();
//     return env->NewStringUTF(hello.c_str());
// }


AAssetManager* assetManager = nullptr;
static App *app = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_yoki_render_RenderNativeBridge_init(JNIEnv *env, jobject thiz) {
    // app = new TriangleApp();
    //app = new CubeApp();
    app = new SykBoxTestApp();

    app->setResLoader(std::make_shared<AndroidResLoader>());
    app->setInput(std::make_shared<AndroidInput>());

    app->init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yoki_render_RenderNativeBridge_resize(JNIEnv *env,jobject thiz , jint width , jint height) {
    app->resize(width , height);

    std::string content = app->resLoader->loadAssetsText("hello.txt");
//    LOGE("%s" , content.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yoki_render_RenderNativeBridge_update(JNIEnv *env,jobject thiz ,jlong delta_time) {
    app->update(delta_time);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yoki_render_RenderNativeBridge_destory(JNIEnv *env,jobject thiz) {
    app->destory();
    delete app;
    app = nullptr;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_yoki_render_RenderNativeBridge_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from 耀西";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_yoki_render_RenderNativeBridge_setAssetManager(JNIEnv *env, jclass clazz, jobject mgr) {
    assetManager = AAssetManager_fromJava(env , mgr);
}