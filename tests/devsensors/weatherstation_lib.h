#pragma once // Inclui esse cabeçalho apenas uma vez

#include <fstream>                   // Classe ifstream
#include <android-base/properties.h> // Função GetBoolProperty
#include <sys/stat.h>                // Função e struct stat
#include <random>                    // Geração de números aleatórios (valores simulados)
#include <string>                    // Usada para dividir os valores lidos do arquivo entre as variáveis
#include <sstream>                   // Usada para dividir os valores lidos do arquivo entre as variáveis
#include <chrono>

using namespace std;         // Permite usar string diretamente ao invés de std::string
using namespace std::chrono; // Para usar funçã

namespace devtitans::weatherstation
{ // Pacote weatherstation

    class Weatherstation
    {
    public:
        /**
         * Verifica se o diretório /sys/kernel/weatherstation existe. Se existir
         * o dispositivo WeatherStation está conectado via USB. Caso contrário,
         * verifica a propriedade devtitans.weatherstation.allow_simulated
         * para ver se valores simulados podem ser usados.
         *
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         *      2: simulado (disp. não encontrado, mas usando valores simulados)
         */

        Weatherstation();

        int connect();

        /*
         * Ler o valor de umidade do ar
         */
        float getHumidity();

        /*
         * Lê o valor sensor de precipitação (chuva)
         */
        int getRain();

        /*
         * Lê o valor da pressão atmosférica
         */
        float getPressure();

        /*
         * Lê o valor da temperatura
         */
        float getTemperature();

        /**
         * Lê o valor de luminosidade
         */
        int getLuminosity();

        /**
         * Lê o valor de umidade do solo
         */
        float getGround();

    private:
        int humidity, temperature, pressure, luminosity, rain, ground;
        long long int lastAttempt, delay;
        /**
         * Métodos para ler valores escritos no arquivo {weather} do diretório /sys/kernel/weatherstation.
         */
        string readFileValue(string file);

        /**
         * Atualiza os valores lidos dos sensores todos de uma única vez
         */
        void updateSensorValues();

        /* Retorna o valor do timestamp em um dado instante.*/
        long long int getTimestamp();
    };

} // namespace