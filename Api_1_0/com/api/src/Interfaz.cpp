#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Interfaz.h"


namespace api {



    //Clase que contiene el procesamiento de paquetes para ser llevado a la inteligencia
    // artificial para su posterior identificacion 

    using namespace std;

    /*********************************************************************/
    /*********************************************************************/
    /******************** Atributos de la clase **************************/
    /*********************************************************************/
    /*********************************************************************/

    /*******Contructor********/
    Interfaz::Interfaz() {
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
            printf("/                                                           /\n");
            printf("/***********************************************************/\n");
            printf("/*****           Por favor elegir una opcion           *****/\n");
            printf("/***********************************************************/\n");

            int n;
            scanf("%d", &n);
            fflush(stdout);

            switch (n) {
                case 1:
                    return Aplicaciones();
                    break;
                case 2:
                    printf("opcion 2\n");
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


        switch (n) {
            case 1:
                return AppOpciones((char *)"Torrent      ");
                break;
            case 2:
                return AppOpciones((char *)"MSN Messenger");
                break;
            case 3:
                return Inicio();
                break;    
            default:
                printf("opcion incorrecta\n");
                break;
        }
        return 0;
    }

    int Interfaz::AppOpciones(char *app) {
        printf("/***********************************************************/\n");
        printf("/*****             Filtro %s                *****/\n",app);
        printf("/***********************************************************/\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        printf("/           1.Activar                                       /\n");
        printf("/                                                           /\n");
        printf("/           2.Desactivar                                    /\n");
        printf("/                                                           /\n");
        printf("/                                                           /\n");
        printf("/***********************************************************/\n");
        printf("/*****           Por favor elegir una opcion           *****/\n");
        printf("/***********************************************************/\n");

        int n;
        scanf("%d", &n);

        switch (n) {
            case 1:
                return Aplicaciones();
                break;
            case 2:
                printf("opcion 2\n");
                break;
            default:
                printf("opcion incorrecta\n");
                break;
        }
        return 0;
    }

}
