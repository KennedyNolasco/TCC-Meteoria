#include "weatherstation_lib.h"

using namespace std;           // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base; // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devtitans::weatherstation
{ // Entra no pacote devtitans::weatherstation

    Weatherstation::Weatherstation()
    {
        delay = 1000000000;
        lastAttempt = delay; // tempo de 1s (em nanossegundo)
        humidity = -1;
        temperature = -27300;
        pressure = -1;
        luminosity = -1;
        rain = -1;
        ground = -1;
    }

    int Weatherstation::connect()
    {
        char dirPath[] = "/sys/kernel/weatherstation";
        struct stat dirStat;
        if (stat(dirPath, &dirStat) == 0)
            if (S_ISDIR(dirStat.st_mode))
                return 1; // Se o diretório existir, retorna 1

        // Diretório não existe, vamos verificar a propriedade
        bool allowSimulated = GetBoolProperty("devtitans.weatherstation.allow_simulated", true);
        if (!allowSimulated)
            return 0; // Dispositivo não encontrado
        else
            return 2; // Usando valores simulados
    }

    string Weatherstation::readFileValue(string file)
    {
        int connected = this->connect();

        if (connected == 2)
        { // Usando valores simulados
            if (file == "weather")
            {
                // Retorna valores aleatório entre 0 e 100
                random_device dev;
                mt19937 rng(dev());
                uniform_int_distribution<mt19937::result_type> dist100(0, 100);
                string values = to_string(dist100(rng)) + " " + to_string(dist100(rng)) + " " + to_string(dist100(rng)) + " " + to_string(dist100(rng)) + " " + to_string(dist100(rng)) + " " + to_string(dist100(rng));

                return values;
            }
        }

        else if (connected == 1)
        { // Conectado. Vamos solicitar o valor ao dispositivo
            string values;
            string filename = string("/sys/kernel/weatherstation/") + file;
            ifstream file(filename); // Abre o arquivo do módulo do kernel

            if (file.is_open())
            {                          // Verifica se o arquivo foi aberto com sucesso
                getline(file, values); // Lê os valores dos sensores
                file.close();

                return values;
            }
        }

        // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
        return NULL;
    }

    void Weatherstation::updateSensorValues()
    {
        string values = this->readFileValue("weather");

        istringstream sensorValuesStream(values);

        /*
            Tenta ler os valores do arquivo e atribuir as variáveis correspondentes (na ordem pré-definida).
            Se não for possível, todos os valores recebem um indicativo de erro
        */
        if (!(sensorValuesStream >> humidity >> rain >> pressure >> temperature >> luminosity >> ground))
        {
            humidity = -1;
            temperature = -27300;
            pressure = -1;
            luminosity = -1;
            rain = -1;
            ground = -1;
        }
    }

    float Weatherstation::getHumidity()
    {

        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        float value = (float)humidity / 100;
        return value;
    }

    int Weatherstation::getLuminosity()
    {
        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        return luminosity;
    }

    int Weatherstation::getRain()
    {
        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        return rain;
    }

    float Weatherstation::getPressure()
    {
        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        float value = (float)pressure / 100;
        return value;
    }

    float Weatherstation::getTemperature()
    {
        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        float value = (float)temperature / 100;
        return value;
    }

    float Weatherstation::getGround()
    {
        if (read_mutex.try_lock())
        {
            if (getTimestamp() - lastAttempt > delay)
            {
                lastAttempt = getTimestamp();
                updateSensorValues();
            }

            read_mutex.unlock();
        }

        float value = (float)ground / 100;
        return value;
    }

    long long int Weatherstation::getTimestamp()
    {
        nanoseconds ns = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
        return ns.count();
    }
}
