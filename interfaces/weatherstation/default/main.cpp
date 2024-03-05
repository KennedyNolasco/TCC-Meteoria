#include "weatherstation_service.h"

using namespace aidl::devtitans::weatherstation; // SmartlampService (smartlamp_service.cpp)
using namespace std;                             // std::shared_ptr
using namespace ndk;                             // ndk::SharedRefBase

int main()
{
    LOG(INFO) << "Iniciando Weatherstation AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<WeatherstationService> weatherstation_service = SharedRefBase::make<WeatherstationService>();

    const string instance = std::string() + IWeatherstation::descriptor + "/default"; // devtitans.weatherstation.IWeatherstation/default
    binder_status_t status = AServiceManager_addService(weatherstation_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "Weatherstation AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE; // Não deve chegar nunca aqui
}