#include <android/binder_manager.h>
#include <aidl/devtitans/weatherstation/IWeatherstation.h>
#include <iostream>                             // std::cout e std::endl (end-line)

using namespace aidl::devtitans::weatherstation;     // IWeatherstation
using namespace std;                            // std::shared_ptr
using namespace ndk;                            // ndk::SpAIBinder

int main() {
    shared_ptr<IWeatherstation> service;
    service = IWeatherstation::fromBinder(SpAIBinder(AServiceManager_getService("devtitans.weatherstation.IWeatherstation/default")));
    
    if (!service) {
        cout << "Erro acessando o serviço!" << endl;
        return 1;
    }

    int32_t _aidl_return;
    float _aidl_return2;
    ScopedAStatus status = service->getLuminosity(&_aidl_return);
    int luminosity = static_cast<int32_t>(_aidl_return);
    cout << "Luminosidade: " << luminosity << endl;
    status = service->getHumidity(&_aidl_return2);
    float humidity = static_cast<float>(_aidl_return2);
    cout << "Humidade: " << humidity << endl;
    status = service->getTemperature(&_aidl_return2);
    float temperature = static_cast<float>(_aidl_return2);
    cout << "Temperatura: " << temperature << endl;
    status = service->getRain(&_aidl_return);
    int rain = static_cast<int32_t>(_aidl_return);
    cout << "Sensor de chuva: " << rain << endl;
    status = service->getPressure(&_aidl_return2);
    float pressure = static_cast<float>(_aidl_return2);
    cout << "Pressão: " << pressure << endl;
    status = service->getGround(&_aidl_return2);
    float ground = static_cast<float>(_aidl_return2);
    cout << "Humidade do Solo: " << ground << endl;
    
    return 0;
}