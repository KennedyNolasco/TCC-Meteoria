package devtitans.weatherstation;

@VintfStability
interface IWeatherstation {    
        int connect();
        float getHumidity();
        int getRain();
        float getPressure();
        float getTemperature();
        int getLuminosity();
        float getGround();
}