#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream archivo;
ofstream archivo1;
string text;
void main_menu();
void score_reading();
void score_writing();
void score(int film);
void file_reading ();
void file_writing();
void status(int film);
void top_score_films();
void top_system(int film);
void verification (int choice, int topic);
void system_score (int film);
void movies_and_series_info (int choice);
void Films_catalog ();
void movies_or_series_catalog(int opcion_catalog);
int filter_system (int choice, int topic);
int filter_menu (int choice);
int Control_menu (int opcion_type);
void assign (int topic);
string title [6] {"", "", "pelicula", "serie", "PELICULAS", "SERIES"};
string topics [4][500] {
    {"0"},
    {"Genero", "Accion", "Apocaliptico", "Aventura", "Ciencia ficcion", "Comedia", "Drama", "Fantasia", "Infantil", "Misterio", "Musical", "Suspenso", "Telenovela", "Terror"},
    {"Año","2009", "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020", "2021", "2022", "2023"},
    {"Director", "Ruben Fleischer", "James Wan", "Craig Brewer", "Scott Derrickson", "Genndy Tartakovsky", "James DeMonaco", "Paul Hoen", "Colin Trevorrow", "Ariel Schulman", "David Ayer", "Christopher Landon", "Adrián Molina", "Pascal Laugier", "Anthony Russo", "Jon Turteltaub", "Lawrence Fowler", "Justin Dec", "Jeff Wadlow", "Sam Raimi", "Domee Shi", "Joel Crawford", "Parker Finn", "Damien Leone", "Juan Pablo Posada", " Larry Leichliter", "Álex Pina", "Suzanna Olson", "Charlie Brooker", "Jonathan M.Shiff", "Jason Rothenberg", "David S.Rosenthal", "Barry M.Berg", "Melissa Rosenberg", "Tom Kapinos", "Adrián Suar", "Greg Berlanti", "Baran bo Odar", "Roberto Aguirre-Sacasa", "Craig Mazin", "Lauren hissrich"}};
int opcion, control_return = 0, dato_position, limit, choice, topic, mark, puntaje, seleccion, acumulado, contador, score_temp, score_temp2, puntaje_total;
string movies_and_series_information [1000][9];
int score_info[4][1000];
int dataofcols = 9, dataofrows = 1000;

int main ()
{   
    main_menu();
    do
    {
        file_reading();
            cout << "\t\t\t\t\t\t\033[4;35mWELCOME TO UANflix\033[0m\n\n" << "\t\t\033[3;35m¿Que desea hacer?\033[0m\n" << "\t\t\t1. Ver todos los Films\n" << "\t\t\t2. Ver todas las peliculas\n" << "\t\t\t3. Ver todas las series\n" << "\t\t\t4. Top mejores Films " << endl;
                cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
            cin >> opcion;
            system("clear");
            if ( opcion > 0 && opcion < 5 ){
	            Control_menu (opcion);
            } else 
                cout << "Opcion no valida" << endl;
                cout<<"\033[7;35m...............................................................................................................................\033[0m"<<endl;
        cout << "              \033[3;35m ¿Que desea hacer?\033[0m\n" << "                    1.volver al menu principal\n" << "                    2.salir" << endl;
        cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;

        cin >> control_return;
        file_writing();
        system("clear");
    }
    while (control_return == 1);
    cout << "\n\033[1;31mHas salido del programa\033[0m" << endl;
  return 0;
}

void file_reading (){
        archivo.open("Data.txt", ios::in);
            for (int j = 0; j < dataofrows; j++) {
                for (int i = 0; i < dataofcols; i++) {
                    getline(archivo, text, ',');
                    movies_and_series_information[j][i] = text;
                }
            }
            for (int j = 0; j < 4; j++) {
                for (int i = 0; i < 50; i++) {
                    getline(archivo, text, ',');
                    score_info[j][i] = stoi(text);
                }
            }
        archivo.close();
}

void main_menu(){
    cout << "\033[1;44m[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]                [][]    [][][]    [][]            [][]    [][][][][][]            [][]    [][][][][][]    [][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]                [][]    [][][]    [][]            [][]    [][][][][][]            [][]    [][][][][][]    [][]\033[0m" << endl;
    cout << "\033[1;44m[][]    [][][][]    [][]    [][][][]    [][]      [][]    [][]    [][][][][][]    [][][][][][][][]    [][][][][][]    [][]    [][][][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]    [][][][]    [][]      [][]    [][]    [][][][][][]    [][][][][][][][]    [][][][][][]    [][]    [][][][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]                [][]    []  []    [][]          [][][]    [][][][][][][][]    [][][][][][][][]    [][][][][][]\033[0m" << endl;
    cout << "\033[1;44m[][]    [][][][]    [][]                [][]    []  []    [][]          [][][]    [][][][][][][][]    [][][][][][][][]    [][][][][][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]    [][][][]    [][]    [][]      [][]    [][][][][][]    [][][][][][][][]    [][][][][][]    [][]    [][][][]\n\033[0m" << "\033[1;44m[][]    [][][][]    [][]    [][][][]    [][]    [][]      [][]    [][][][][][]    [][][][][][][][]    [][][][][][]    [][]    [][][][]\033[0m" << endl;
    cout << "\033[1;44m[][]                [][]    [][][][]    [][]    [][][]    [][]    [][][][][][]            [][]            [][]    [][][][][][]    [][]\n\033[0m" << "\033[1;44m[][]                [][]    [][][][]    [][]    [][][]    [][]    [][][][][][]            [][]            [][]    [][][][][][]    [][]\n\033[0m" << "\033[1;44m[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\033[0m" << endl;
        cout << "\n                                                Pulsa enter para continuar......                                            " << endl;
        cin.get();
}

int Control_menu (int opcion_type){
    if (opcion_type == 1){ 
        cout << "\t\t\t\t\t\t\033[3;35mLista de Films\033[0m\n" << endl;
            Films_catalog();
            cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
                cout << "\t\t\t0. Filtro" << endl;
                cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
                cin >> choice;
                  system("clear");
                    if ( choice == 0){
            	    filter_menu (choice);
                    } else if ( choice > 0 ) {
                    verification(choice,0);    
                    }
    } else if (opcion_type == 2 || opcion_type == 3){
        cout << "\t\t\t\t\t\t" <<title[opcion_type + 2] << endl;
        movies_or_series_catalog (opcion_type);
        cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
        cin >> choice;
          system("clear");
        verification(choice,0);
    } else if (opcion_type == 4){
        top_score_films();

    }
    return 0;
}

void movies_and_series_info (int choice){ 
        for (int b = 1; b < dataofcols - 1; b++){
    	    cout << "\t\t\t" << movies_and_series_information[0][b] << ": " << movies_and_series_information[choice][b] << "\n";
        }
        score(choice);
        status(choice);
}

void Films_catalog (){
       for (int a = 1; movies_and_series_information[a][1] != ""; a++){
           
            cout << "\t\t\t" << a << "." << movies_and_series_information[a][1] << " [ " << movies_and_series_information[a][7] << " ]" << endl;
        }
}

void movies_or_series_catalog (int opcion_catalog){
        for (int i = 1; movies_and_series_information[i][1] != ""; i++) {
            if ( movies_and_series_information[i][7] == title [opcion_catalog]){
                cout << "\t\t\t" << "-" << movies_and_series_information[i][1] << "(" << stoi(movies_and_series_information[i][0]) << ")"<< endl;
            }
        }
}

int filter_menu (int choice){
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
    cout << "\t\t\t\t\t\t\033[3;35mFILTRO\033[0m\n" << "\t\t\033[3;35mDesea ver por:\033[0m\n" << "\t\t\t1.Genero\n" << "\t\t\t2.Año\n" << "\t\t\t3.Director" << endl;
    cin >> topic;
        assign (topic);
        system("clear");
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
    cout << "\t\t\t\t\t\t" << topics[topic][0] << endl;
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
             for (int i = 1; topics[topic][i] != ""; i++){
                cout << "\t\t\t" << i << "." << topics[topic][i] << endl;
        }
            cin >> choice;
            filter_system(choice,topic);
            
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
    return 0;
}

int filter_system (int choice, int topic){
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
            for (int i = 1; i < dataofrows; i++) {
                    if ( movies_and_series_information[i][dato_position] == topics[topic][choice]){
                        cout << "\t\t\t-" << movies_and_series_information[i][1] << "(" << stoi(movies_and_series_information[i][0]) << ")"<< endl;
                    }
                }
        cin >> choice;
        verification (choice,0);
    return 0;
}

void assign(int topic){

        if (topic == 1){
            dato_position = 4;
        } else if (topic == 2)    
            dato_position = 3;
        else if (topic == 3)   
            dato_position = 2;
}

void file_writing(){
    archivo1.open("Data.txt", ios::out);
            for (int j = 0; j < dataofrows; j++) {
                for (int i = 0; i < dataofcols; i++) {
                    archivo1 << movies_and_series_information[j][i] + ',';
                }
            }
            archivo1 << endl;
            for (int j = 0; j < 4; j++) {
                for (int i = 0; i < 50; i++) {
                    archivo1 << to_string(score_info[j][i]) + ',';
                }
                archivo1 << endl;
            }
    archivo1.close();
}

void score(int film){
    cout << "\t\t\t" << movies_and_series_information[0][8] << ": " << movies_and_series_information[film][8]<<endl;
    cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
    cout << "\n\t\t\033[3;35mQuieres puntuar la " << movies_and_series_information[film][7] << "\033[1;35m?\033[0m\n" << "\t\t\t1.SI\n" << "\t\t\t2.NO" << endl;
    cin >> seleccion;
    if ( seleccion == 1){
            system_score(film);
            top_system(film);
    }
}

void system_score (int film){
    int Control_score = 0;
    while (Control_score == 0){
         cout<<"\033[3;35m...............................................................................................................................\033[0m"<<endl;
        cout << "\t\t\033[3;35mingrese una puntacion del 1 al 100 (entero)\033[0m" << endl;
        cin >> puntaje;
            if ( puntaje > 0 && puntaje < 101 ){
                score_info[0][film] += puntaje;
                score_info[1][film]++;
                puntaje_total = score_info[0][film] / score_info[1][film];
                movies_and_series_information[film][8] = to_string(puntaje_total);
                cout << "\t\t\t" << movies_and_series_information[0][8] << ": " << movies_and_series_information[film][8] << endl;
                Control_score = 1;
            }else 
            cout << "\033[1;31mPuntuacion No Valida\033[0m" << endl;
    }
}

void status(int film){
    if ( movies_and_series_information [film][6] == "No vista"){
        cout<<"\033[1;35m...............................................................................................................................\033[0m"<<endl;
        cout << "\n\t\t\033[3;35mQuieres marcar la\033[0m " << movies_and_series_information[film][7] << " \033[3;35mcomo vista?\033[0m\n" << "\t\t\t1.SI\n" << "\t\t\t2.NO" << endl;
        cin >> mark;
        if ( mark == 1){
            movies_and_series_information [film][6] = "Vista";
            cout << "\t\t\tEstado: " << movies_and_series_information[film][6] << endl;
        }
    }
      system("clear");
}

void verification (int choice, int topic){
    bool control_choice;
        control_choice = true;
        while ( control_choice == true ){
            for (int i = 1; movies_and_series_information[i][0] != ""; i++) {
                if ( stoi(movies_and_series_information[i][0]) == choice){
                    movies_and_series_info(choice);
                    control_choice = false;
                }
            }
            if ( control_choice == true ){
                cout << "\033[1;31mOpcion No Valida\033[0m " << "\033[1;31mIntente de nuevo\033[0m" << endl;
                cin >> choice;
            }
        }
}

void top_score_films(){
    cout << "\t\t\t\t\t\t\033[3;35m Top Films\033[0m" << endl;
        for (int i = 1; i < 11; i++) {
            if (score_info[3][i] > 0){
            cout << "\t\t\t- " << movies_and_series_information[score_info[3][i]][1] << "[" << movies_and_series_information[score_info[3][i]][8] << "]" << endl;
            }else
                cout << endl;
        }
    
}

void top_system (int film){
    bool control = true;
    for (int count = 1; count != 51; count++) {
        if (score_info[3][count] == stoi(movies_and_series_information[film][0])){
            score_info[2][count] = stoi(movies_and_series_information[film][8]);
            score_info[3][count] = stoi(movies_and_series_information[film][0]);
            control = false;
        } 
        
    }
        
    if (control == true){ 
        score_info[2][score_info[3][0]] = stoi(movies_and_series_information[film][8]);
        score_info[3][score_info[3][0]] = stoi(movies_and_series_information[film][0]);
        score_info[3][0]++;
    }
    
    for (int i = 1; i <= 51; i++) {
        for (int j = 1; j <= 50; j++) {
            if( score_info[2][j] < score_info[2][j + 1]){
                score_temp = score_info[2][j];
                score_temp2 = score_info[3][j];
                score_info[2][j] = score_info[2][j + 1];
                score_info[3][j] = score_info[3][j + 1];
                score_info[2][j + 1] = score_temp;
                score_info[3][j + 1] = score_temp2;
            }
        }
    }
}

