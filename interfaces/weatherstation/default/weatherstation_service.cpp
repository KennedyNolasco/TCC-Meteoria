#include "weatherstation_service.h"

namespace aidl::devtitans::weatherstation
{
    ndk::ScopedAStatus WeatherstationService::connect(int32_t *_aidl_return)
    {
        *_aidl_return = this->weatherstation.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus WeatherstationService::getHumidity(float *_aidl_return2)
    {
        *_aidl_return2 = this->weatherstation.getHumidity();
        LOG(INFO) << "getHumidity(): " << *_aidl_return2;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus WeatherstationService::getRain(int32_t *_aidl_return)
    {
        *_aidl_return = this->weatherstation.getRain();
        LOG(INFO) << "getRain(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus WeatherstationService::getLuminosity(int32_t *_aidl_return)
    {
        *_aidl_return = this->weatherstation.getLuminosity();
        LOG(INFO) << "getLuminosity(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }
    ndk::ScopedAStatus WeatherstationService::getPressure(float *_aidl_return2)
    {
        *_aidl_return2 = this->weatherstation.getPressure();
        LOG(INFO) << "getPressure(): " << *_aidl_return2;
        return ndk::ScopedAStatus::ok();
    }
    ndk::ScopedAStatus WeatherstationService::getTemperature(float *_aidl_return2)
    {
        *_aidl_return2 = this->weatherstation.getTemperature();
        LOG(INFO) << "getTemperature(): " << *_aidl_return2;
        return ndk::ScopedAStatus::ok();
    }
    ndk::ScopedAStatus WeatherstationService::getGround(float *_aidl_return2)
    {
        *_aidl_return2 = this->weatherstation.getGround();
        LOG(INFO) << "getGround(): " << *_aidl_return2;
        return ndk::ScopedAStatus::ok();
    }
}