#include "weatherstation_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devtitans::weatherstation {      // Entra no pacote devtitans::hello

void WeatherstationClient::start(int argc, char **argv) {
    cout << "Cliente WeatherStation!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-humidity, get-luminosity, get-rain, get-ground, get-pressure, get-temperature" << endl;
        exit(1);
    }

    Weatherstation weatherstation;             // Classe da biblioteca Weatherstation

    if (!strcmp(argv[1], "get-humidity")) {
        cout << "Humidade do Ar: " << weatherstation.getHumidity() << endl;
    }
   
    else if (!strcmp(argv[1], "get-luminosity")) {
        cout << "Luminosidade atual: " << weatherstation.getLuminosity() << endl;
    }

    else if (!strcmp(argv[1], "get-rain")) {
        cout << "Valor do sensor de chuva: " << weatherstation.getRain() << endl;
    }

    else if (!strcmp(argv[1], "get-pressure")) {
        cout << "Pressao: " << weatherstation.getPressure() << endl;
    }

    else if (!strcmp(argv[1], "get-temperature")) {
        cout << "Temperatura: " << weatherstation.getTemperature() << endl;
    }

    else if (!strcmp(argv[1], "get-ground")) {
        cout << "Humidade do Solo: " << weatherstation.getGround() << endl;
    }
    
    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devtitans::weatherstation; // Permite usar HelloCpp diretamente ao invés de devtitans::hello::HelloCpp

int main(int argc, char **argv) {
    WeatherstationClient client;               // Variável hello, da classe HelloCpp, do pacote devtitans::hello
    client.start(argc, argv);             // Executa o método printHello
    return 0;
}