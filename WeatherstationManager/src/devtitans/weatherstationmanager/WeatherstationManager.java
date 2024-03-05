package devtitans.weatherstationmanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.weatherstation.IWeatherstation;                      // Criado pelo AIDL

public class WeatherstationManager {
    private static final String TAG = "DevTITANS.WeatherstationManager";
    private IBinder binder;
    private IWeatherstation service;

    private static WeatherstationManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada. 
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private WeatherstationManager() {
        Log.d(TAG, "Nova (única) instância do WeatherstationManager ...");

        binder = ServiceManager.getService("devtitans.weatherstation.IWeatherstation/default");
        if (binder != null) {
            service = IWeatherstation.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Weatherstation acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Weatherstation!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static WeatherstationManager getInstance() {
        if (instance == null)
            instance = new WeatherstationManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getLuminosity() throws RemoteException {
        Log.d(TAG, "Executando método getLuminosity() ...");
        return service.getLuminosity();
    }

    public float getTemperature() throws RemoteException {
        Log.d(TAG, "Executando método getTemperature() ...");
        return service.getTemperature();
    }

    public int getRain() throws RemoteException {
        Log.d(TAG, "Executando método getRain() ...");
        return service.getRain();
    }

    public float getHumidity() throws RemoteException {
        Log.d(TAG, "Executando método getHumidity() ...");
        return service.getHumidity();
    }

    public float getPressure() throws RemoteException {
        Log.d(TAG, "Executando método getPressure() ...");
        return service.getPressure();
    }
    public float getGround() throws RemoteException {
        Log.d(TAG, "Executando método getPressure() ...");
        return service.getGround();
    }
    
}