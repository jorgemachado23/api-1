#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
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

    /*******Contructor********/
    Core::Core() {
    }

    /********Destructor*******/
    Core::~Core() {
    }

    /***********************************************************************/
    /************************Funcion decToBinr******************************/
    /***Toma un areglo de enteros y devuelve su representacion binaria******/
    /**********Usando el compelemento a 2***********************************/

    int* Core::decToBin(char c, int binary[]) {
        int i;

        int decimal = (int) c;

        int flag = 0;

        int nBits = 8;
        /* Si es un número negativo, lo hacemos positivo y le restamos 1(*), */
        /* además activamos el flag para saber que es negativo */

        /* (*) El complemento a 2 es igual que el complemento a 1, que es cambiar */
        /* 1->0, 0->1, y luego sumando 1 en binario. Aquí restamos 1 en decimal y */
        /* luego pasamos a binario. */

        if (decimal < 0) {
            flag = 1;
            decimal = -decimal - 1;
        }

        /* Pasamos a binario, atendiendo a lo que vale flag, en lugar de añadir (decimal%2) */
        /* como es normal, le hacemos un XOR con flag, vemos la tabla de verdad de XOR */
        /* |    A    (xor)   B           =   X   |  */
        /* |     0      |        0       |   0   |  */
        /* |     0      |        1       |   1   |  */
        /* |     1      |        0       |   1   |  */
        /* |     1      |        1       |   0   |  */
        /* ------------------------------   */
        /* Por tanto, cuando flag vale 0, al encontrar un 0, pondremos un 0, y al encontrar un 1, ponemos un 1 */
        /*           Pero cuando flag vale 1, al encontrar un 0, pondremos un 1, y al encontrar un 1, ponemos un 0 */
        while (decimal > 0) {
            binary[--nBits] = flag^(decimal % 2);
            decimal /= 2;
        }

        /* Con esto terminamos de llenar el array, con 0 a la izquierda si es un número positivo */
        /* y con 1s si es un número negativo */
        while (nBits > 0)
            binary[--nBits] = flag;

        /* Devolvemos el array */
        return binary;
    }

    /***********************************************************************/
    /************************Funcion Clean_Rules****************************/
    /**********Deja el firewall con su configuracion inicial****************/
    /*****************Mediante comandos de consola**************************/

    void Core::Clean_Rules() {
        try {
            //flush de las reglas

            system("iptables -F");
            system("iptables -X");
            system("iptables -Z");
            system("iptables -t nat -F");

            /*Establecemos politica por defecto*/

            system("iptables -P INPUT ACCEPT");
            system("iptables -P OUTPUT ACCEPT");
            system("iptables -P FORWARD ACCEPT");
            system("iptables -t nat -P PREROUTING ACCEPT");
            system("iptables -t nat -P POSTROUTING ACCEPT");

        } catch (...) {
            printf("Error en la ejecucion de sentencias");
        }

    }


    /***********************************************************************/
    /***********************Funcion Add Rules*******************************/
    /*****Esta funcion se encarga de escribir y ejecutar la regla***********/
    /*****que va sobre el firewall cuando el sistema a identifcado**********/
    /***un protocolo no deseado anteriormente, por medio de la red neural***/
    /***********************************************************************/

    void Core::Add_Rules(string ip_entrada, string ip_salida, int p_entrada, int p_salida) {
        try {
            //ejecuto el comando arp y guardo en un archivo su salida

            system("arp -n > Lista_Ip.txt");

            FILE *file_in;

            //abro el archivo de salida para leerlo
            file_in = fopen("Lista_Ip.txt", "r");

            if (file_in != NULL) {

                const char *listIps[50];

                char *line; //guarda la linea de la lectura del archivo

                char *c;

                int pos = 0;
                //leo linea por linea
                do {
                    c = fgets(line, 100, file_in);

                    if (c != NULL) {
                        char *ip_address; //guarda la primera palabra de la linea

                        //tomo la primera palabra de la linea lo guardo en ip_address
                        ip_address = strtok(line, " ");

                        //comparo si es la palabra addres
                        //si no lo es, entonces es una direccion IP que debo almacenar
                        //en el vector con las IP locales que nos da el comando ARP

                        int x = strcmp(ip_address, "Address");

                        if (x != 0) {
                            //guardo la direccion IP en un vector

                            listIps[pos] = ip_address;

                            pos++;
                        }

                    }

                } while (c != NULL);

                //borro el archivo

                system("rm Lista_Ip.txt");

                //recorro el arreglo para saber si la ip es local
                for (int i = 0; i < 50; i++) {
                    string aux(ip_salida);

                    if (listIps[i] != NULL) {

                        int y = strcmp(listIps[i], "192.168.23.253");

                        if (y == 0) {
                            listIps[i] = aux.c_str();

                            string regla;

                            regla = "iptables -A OUTPUT -s ";

                            regla = regla + ip_entrada;

                            regla = regla + " -p tcp --dport ";

                            stringstream flujo;

                            flujo << p_salida;

                            string puerto = flujo.str();

                            regla = regla + puerto;

                            regla = regla + " -j DROP";

                            const char *comando = regla.c_str();

                            printf("%s\n\n", comando);
                        }
                    }

                }
            } else {
                printf("Error al leer el archivo");
            }

        } catch (...) {
            printf("Error en la ejecucion ");
        }

    }


} 