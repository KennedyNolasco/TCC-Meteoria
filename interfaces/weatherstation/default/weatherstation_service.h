#pragma once

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <android/binder_manager.h>

#include <aidl/devtitans/weatherstation/BnWeatherstation.h> // Criado pelo AIDL automaticamente

#include "weatherstation_lib.h" // Classe Smartlamp (biblioteca)

using namespace devtitans::weatherstation;

namespace aidl::devtitans::weatherstation
{

    class WeatherstationService : public BnWeatherstation
    {
    public:
        ndk::ScopedAStatus connect(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getHumidity(float *_aidl_return2) override;
        ndk::ScopedAStatus getRain(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getPressure(float *_aidl_return2) override;
        ndk::ScopedAStatus getTemperature(float *_aidl_return2) override;
        ndk::ScopedAStatus getLuminosity(int32_t *_aidl_return) override;
        ndk::ScopedAStatus getGround(float *_aidl_return2) override;

    private:
        Weatherstation weatherstation; // Biblioteca
    };

}