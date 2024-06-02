#include <jelly/hardware/hello_hidl/1.0/IHello.h>
#include <hidl/LegacySupport.h>

#define LOG_TAG "hello_hidl"
#include <log/log.h>

using android::sp;
using jelly::hardware::hello_hidl::V1_0::IHello;
using android::hardware::Return;
using android::hardware::hidl_string;

int main(){
    android::sp<IHello> hw_device = IHello::getService();
    if (hw_device == nullptr) {
              ALOGD("failed to get hello-hidl");
              return -1;
        }
    ALOGD("success to get hello-hidl....");
    Return<uint32_t> total = hw_device->addition_hidl(3,4);
    hw_device->write("hello");
    sleep(2);
    hw_device->read([&](hidl_string result){
        ALOGD("%s\n", result.c_str());
    });
    return 0;
} 
