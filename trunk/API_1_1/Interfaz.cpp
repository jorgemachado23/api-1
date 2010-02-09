#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Interfaz.h"
#include "Core.h"

namespace api {



    //Clase que contiene el procesamiento de paquetes para ser llevado a la inteligencia
    // artificial para su posterior identificacion

    using namespace std;

    /*********************************************************************/
    /*********************************************************************/
    /******************** Atributos de la clase **************************/
    /*********************************************************************/
    /*********************************************************************/

    /*    bool Interfaz::act_msn;

        bool Interfaz::act_torrent;*/

    /*******Contructor********/
    Interfaz::Interfaz(bool msn, bool torrent) {

        this->act_msn = msn;
        this->act_torrent = torrent;

    }

    /******Destructor*******/
    Interfaz::~Interfaz() {
    }

    int Interfaz::Inicio() {
        try {
            printf("/***********************************************************/\n");
            printf("/*****                   Menu API                      *****/\n");
            printf("/***********************************************************/\n");
            printf("/                                                           /\n");
            printf("/                                                           /\n");
            printf("/           1.Aplicaciones                                  /\n");
            printf("/                                                           /\n");
            printf("/           2.Excepciones IP                                /\n");
            printf("/                                                           /\n");
            printf("/           3.Limpiar Reglas                                /\n");
            printf("/                                                           /\n");
            printf("/           4.Salir                                         /\n");
            printf("/                                                           /\n");
            printf("/                                                           /\n");
            printf("/***********************************************************/\n");
            printf("/*****           Por favor elegir una opcion           *****/\n");
            printf("/***********************************************************/\n");

            int n;
            scanf("%d", &n);
            system("clear");

            switch (n) {
                case 1:
                    return Aplicaciones();
                    break;
                case 2:
                    return ExcepcionesIP();
                    break;
                case 3:
                    return Limpieza();
                    break;
                case 4:
                    break;
                default:
                    printf("opcion incorrecta\n");
                    break;
            }
            return 0;
        } catch (...) {

            printf("Error en la interfaz");
            return 0;

        }
    }

    int Interfaz::Aplicaciones() {
        printf("/***********************************************************/\n");
        printf("/*****                   Menu API                      *****/\n");
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        printf("/           1.Torrent                                       /\n");
        printf("/                                                           /\n");
        printf("/           2.MSN Messenger                                 /\n");
        printf("/                                                           /\n");
        printf("/           3.Salir                                         /\n");
        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);
        system("clear");

        switch (n) {
            case 1:
                return AppOpciones(n);
                break;
            case 2:
                return AppOpciones(n);
                break;
            case 3:
                return Inicio();
                break;
            default:
                printf("opcion incorrecta\n");
                return Aplicaciones();
                break;
        }
        return 0;
    }

    int Interfaz::AppOpciones(int app) {

        printf("/***********************************************************/\n");
        if (app == 1)
            printf("/*****             Filtro Torrent                      *****/\n");
        if (app == 2)
            printf("/*****             Filtro MSN Messenger                *****/\n");
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        if (((app == 1) && (this->act_torrent == false)) || ((app == 2) && (this->act_msn == false))) {
            printf("/           El estado actual es APAGADO                     /\n");
            printf("/                                                           /\n");
            printf("/           1.Activar                                       /\n");
        }
        if (((app == 1) && (this->act_torrent == true)) || ((app == 2) && (this->act_msn == true))) {
            printf("/           El estado actual es ENCENDIDO                   /\n");
            printf("/                                                           /\n");
            printf("/           1.Desactivar                                    /\n");
        }
        printf("/                                                           /\n");
        printf("/           2.Salir                                         /\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);
        system("clear");
        switch (n) {
            case 1:
                if (((app == 1) && (this->act_torrent == false)) || ((app == 2) && (this->act_msn == false))) {
                    if (app == 1)
                        this->act_torrent = true;
                    if (app == 2)
                        this->act_msn = true;
                    return Aplicaciones();
                }


                if (((app == 1) && (this->act_torrent == true)) || ((app == 2) && (this->act_msn == true))) {
                    if (app == 1)
                        this->act_torrent = false;
                    if (app == 2)
                        this->act_msn = false;
                    return Aplicaciones();
                }

                break;
            case 2:
                return Aplicaciones();
                break;
            default:
                printf("opcion incorrecta\n");
                break;
        }
        return 0;
    }

    int Interfaz::ExcepcionesIP() {

        printf("/***********************************************************/\n");
        printf("/*****                Excepciones IP                   *****/\n");
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        printf("/           1.Agregar                                       /\n");
        printf("/                                                           /\n");
        printf("/           2.Eliminar                                      /\n");
        printf("/                                                           /\n");
        printf("/           3.Salir                                         /\n");
        printf("/                                                           /\n");
        printf("/           Listado de IP                                   /\n");
        printf("/                                                           /\n");


        for (int i = 0; i < ip_exc.size(); i++) {
            if ((ip_exc.at(i).length()) > 0) {
                string formato = ip_exc.at(i);
                for (int j = formato.length(); j < 16; j++) {
                    formato = formato + " ";
                }

                cout << "/           " + formato + "                                /\n";
            }
        }

        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);
        system("clear");

        switch (n) {
            case 1:
                return AgregarIP();
                break;
            case 2:
                if (ip_exc.size() > 0)
                    return EliminarIP();
                else {
                    printf("/***********************************************************/\n");
                    printf("/*****          No hay ninguna IP en lista             *****/\n");
                    printf("/***********************************************************/\n");
                    return ExcepcionesIP();
                }
                break;
            case 3:
                return Inicio();
                break;
            default:
                printf("opcion incorrecta\n");
                return Aplicaciones();
                break;
        }
        return 0;

    }

    int Interfaz::AgregarIP() {
        printf("/***********************************************************/\n");
        printf("/*****            Introduzca una IP valida             *****/\n");
        printf("/***********************************************************/\n");

        string ip;
        cin >> ip;
        system("clear");

        int i = 0;
        int tope = 0;
        for (int i = 0; i < this->ip_exc.size(); i++) {
            if ((this->ip_exc.at(i)) == ip) {
                printf("/***********************************************************/\n");
                printf("/*****         Ya habia sido almacenada su IP          *****/\n");
                printf("/***********************************************************/\n");
                printf("\n");

                return ExcepcionesIP();

            }
            i++;
        }

        this->ip_exc.push_back(ip);

        printf("/***********************************************************/\n");
        printf("/*****           IP Guardada Exitosamente              *****/\n");
        printf("/***********************************************************/\n");
        printf("\n");


        return ExcepcionesIP();

    }

    int Interfaz::EliminarIP() {

        int tope;

        printf("/***********************************************************/\n");
        printf("/*****                Eliminar IP                      *****/\n");
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");

        for (int i = 0; i < this->ip_exc.size(); i++) {
            string formato = ip_exc.at(i);
            for (int j = formato.length(); j < 16; j++) {
                formato = formato + " ";
            }
            printf("/    %i)    ", i + 1);
            cout << formato + "                                 /\n";
            tope = i;
        }

        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);

        system("clear");

        if (n <= tope + 1)
            return ValidarEliminar(n - 1);
        else
            return ExcepcionesIP();


    }

    int Interfaz::ValidarEliminar(int val) {

        printf("/***********************************************************/\n");
        printf("/*****                Eliminar IP                      *****/\n");
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");
        printf("/    ¿Esta seguro que desea eliminar la IP?                 /\n");

        string formato = ip_exc.at(val);
        for (int j = formato.length(); j < 16; j++) {
            formato = formato + " ";
        }

        cout << "/           " + formato + "                                /\n";
        printf("/                                                           /\n");
        printf("/           1.Si                                            /\n");
        printf("/                                                           /\n");
        printf("/           2.No                                            /\n");
        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);

        switch (n) {
            case 1:
                for (int i = 0; i < this->ip_exc.size(); i++) {
                    if (val == i)
                        ip_exc.erase(ip_exc.begin() + val);

                }
                return ExcepcionesIP();
                break;
            case 2:
                return ExcepcionesIP();
                break;
            case 3:
                return Inicio();
                break;
            default:
                printf("opcion incorrecta\n");
                return ExcepcionesIP();
                break;
        }
        return 0;
    }

    int Interfaz::Limpieza() {
        Core core;
        core.Clean_Rules();
        return Inicio();
    }

}


