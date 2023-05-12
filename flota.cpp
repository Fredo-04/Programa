#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GestionDeTransporte;
class Vehiculo;
class Auto;
class Minivan;
class Camion;

class GestionDeTransporte {
    private:
        string destino;
        int duracion;
        int cantpasajeros;
        float precio;
    public:
        GestionDeTransporte(string _destino, int _duracion, int _cantpasajeros) {
            this->destino = _destino;
            this->duracion = _duracion; //en horas
            this->cantpasajeros = _cantpasajeros; 
        }
        ~GestionDeTransporte(){}
        string getDestino() { 
            return this ->destino; 
        }
        int getDuracion() { 
            return this ->duracion; 
        }
        int getCantpasajeros() { 
            return this ->cantpasajeros; 
        }
};
class Vehiculo{
    private:
        string static marca;
        string static modelo;
    public:
        Vehiculo() {}
        ~Vehiculo(){}
        string& getModelo() { 
            return this ->modelo; 
        }
        string& getMarca() { 
            return this ->marca; 
        }
};
string Vehiculo::marca = "Toyota";
string Vehiculo::modelo = "Hyunday";
class Auto: public Vehiculo{
    private:
    int asientos;
    int consumo; //x hora
    int capacidad_gasolina;
    public:
    Auto(int _asientos, int _capacidad_gasolina, int  _consumo): Vehiculo(){
        this->consumo = _consumo;//consumo por hora
        this->capacidad_gasolina = _capacidad_gasolina; 
        this->asientos = _asientos;
    }
    ~Auto(){}
    int getAsientos() { 
        return this ->asientos; 
    }
    int getConsumo() { 
        return this ->consumo; 
    }
    int getCapacidad_gasolina() { 
        return this ->capacidad_gasolina; 
    }
};

class Minivan: public Vehiculo{
    private:
    int asientos;
    int consumo; //x hora
    int capacidad_gasolina;
    public:
    Minivan(int _asientos, int _capacidad_gasolina, int  _consumo): Vehiculo(){
        this->consumo = _consumo;//consumo por hora
        this->capacidad_gasolina = _capacidad_gasolina; 
        this->asientos = _asientos;
    }
    ~Minivan(){}
    int getAsientos() { 
        return this ->asientos; 
    }
    int getConsumo() { 
        return this ->consumo; 
    }
    int getCapacidad_gasolina() { 
        return this ->capacidad_gasolina; 
    }
};

class Camion: public Vehiculo{
    private:
    int asientos;
    int consumo; //x hora
    int capacidad_gasolina;
    public:
    Camion( int _asientos, int _capacidad_gasolina, int  _consumo): Vehiculo(){
        this->consumo = _consumo;//consumo por hora
        this->capacidad_gasolina = _capacidad_gasolina; 
        this->asientos = _asientos;
    }
    ~Camion(){}
    int getAsientos() { 
        return this ->asientos; 
    }
    int getConsumo() { 
        return this ->consumo; 
    }
    int getCapacidad_gasolina() { 
        return this ->capacidad_gasolina; 
    }
};
void simularMision(GestionDeTransporte mision) {
            string vehiculo;
            while(vehiculo != "auto" && vehiculo != "minivan" && vehiculo!= "camion"){
            cout<<"indique que vehiculo va a llevar (auto, minivan, camion)"<<endl;
            cout<<"auto: marca = toyota, modelo = yaris, asientos = 4, capacidad gasolina = 50, consumo x hora = 10 "<<endl;
            cout<<"minivan: marca = Honda, modelo = WV -R, asientos = 9, capacidad gasolina = 75, consumo x hora = 17 "<<endl;
            cout<<"camion: marca = volvo, modelo = fmx, asientos = 20, capacidad gasolina = 110, consumo x hora = 20 "<<endl;
            cin >> vehiculo;
            }
            if (vehiculo == "auto"){
                Auto auto1(4, 50,10);
                float combustible_necesario = mision.getDuracion() * auto1.getConsumo();
                if (auto1.getCapacidad_gasolina() >= combustible_necesario) {
                    cout << "El auto " << auto1.getMarca()<<" "<< auto1.getModelo() << " tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                    if (mision.getCantpasajeros() > auto1.getAsientos()){
                        cout<<"pero no tiene suficientes asientos para la tripulacion\n";
                    }
                } 
                else {
                    cout << "El auto " << auto1.getMarca()<<" "<< auto1.getModelo() << " no tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                }
            }
            if (vehiculo == "camion"){
                Camion camion1(20, 110, 20);
                float combustible_necesario = mision.getDuracion() * camion1.getConsumo();
                if (camion1.getCapacidad_gasolina() >= combustible_necesario) {
                    cout << "El camion " << camion1.getMarca()<<" "<< camion1.getModelo() << " tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                    if (mision.getCantpasajeros() > camion1.getAsientos()){
                        cout<<"pero no tiene suficientes asientos para la tripulacion\n";
                    }
                } 
                else {
                    cout << "El camion " << camion1.getMarca()<<" "<< camion1.getModelo() << " no tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                }
            }
            if (vehiculo == "minivan"){
                Minivan minivan1(9,75,17);
                float combustible_necesario = mision.getDuracion() * minivan1.getConsumo();
                if (minivan1.getCapacidad_gasolina() >= combustible_necesario) {
                    cout << "La minivan " << minivan1.getMarca()<<" "<< minivan1.getModelo() << " tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                    if (mision.getCantpasajeros() > minivan1.getAsientos()){
                        cout<<"pero no tiene suficientes asientos para los pasajeros \n";
                    }
                } 
                else {
                    cout << "La minivan " << minivan1.getMarca()<<" "<< minivan1.getModelo() << " no tiene suficiente combustible para completar la misión a " << mision.getDestino() << endl;
                }
            }
            cout<<"\n";
        }
int main(){
    GestionDeTransporte recorrido1("Plaza Vea", 5,6);
    simularMision(recorrido1);//probar con auto
    simularMision(recorrido1);//probar con minivan
    simularMision(recorrido1);//probar con camion

}