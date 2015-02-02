#include "SharedObject.h"

jstring platformABI(JNIEnv* env, jobject thiz)
{
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
#if defined(__ARM_NEON__)
#define ABI "armeabi-v7a/NEON"
#else
#define ABI "armeabi-v7a"
#endif
#else
#define ABI "armeabi"
#endif
#elif defined(__i386__)
#define ABI "x86"
#else
#define ABI "unknown"
#endif
    return (*env).NewStringUTF("This library was compiled with ABI: " ABI ".");
}
