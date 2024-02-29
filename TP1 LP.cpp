// TP1 LP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <windows.h>
HANDLE console_color;
using namespace std;
const int M1 = 1, M2 = 2, M3 = 3, M4 = 4, M5 = 5, M6 = 6, M7 = 7, M8 = 8, M9 = 9, M10 = 'M', M11 = 'Q';
int reserv, chambre, i, j, y, a = 0;
char option;
string nomcli, prenomcli, emailcli, numtelcli, idres;
string tab[11][6];
string tabtemp[1][6];
string tabtemp2[1][6];
// cest le client arrive au hotel le status change de reserve par confirme

void dispcham() {
    cout << endl << " Les chambres disponibles sont: " << endl;
    cout << "--------------------------------" << endl;
    for (y = 1; y < 11; y++) {
        if (tab[y][5] == "Disponible") {
            cout << " " << y << " ";
        }
    }
    cout << endl << "--------------------------------" << endl;
}
void menu() {
    cout << endl;
    cout << "*-------------------------------------------------------------------------------------*" << endl;
    cout << endl;
    cout << " Selectionner une option" << endl;
    cout << " 1 - Faire une reservation                        7 - Chercher une client" << endl;
    cout << " 2 - Confirmer une reservation                    8 - Chercher une reservation" << endl;
    cout << " 3 - Annuler une reservation                      9 - Changer reservations" << endl;
    cout << " 4 - Check-out                                    M - Retourner au menu principal" << endl;
    cout << " 5 - Liste de chambres                            Q - Fermer le systeme" << endl;
    cout << " 6 - Liste de reservations" << endl;
    cout << endl << " Quel option voulez vous? ";

}
char coption(char option) {
    switch (option) {
    case '1': reserv = M1; break;
    case '2': reserv = M2; break;
    case '3': reserv = M3; break;
    case '4': reserv = M4; break;
    case '5': reserv = M5; break;
    case '6': reserv = M6; break;
    case '7': reserv = M7; break;
    case '8': reserv = M8; break;
    case '9': reserv = M9; break;
    case 'M': reserv = M10; break;
    case 'Q': reserv = M11; break;
    }
    return option;
}
void reserver() {
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 1 - Faire une reservation" << endl;
    dispcham();
    cout << endl << " Quel chambre sera reserve? ";
    cin >> chambre;
    i = chambre;
    if (tab[i][5] == "Disponible") {
        cout << " Nom du client: ";
        cin >> nomcli;
        transform(nomcli.begin(), nomcli.end(), nomcli.begin(), tolower);
        tab[i][0] = nomcli;
        cout << " Prenom client: ";
        cin >> prenomcli;
        transform(prenomcli.begin(), prenomcli.end(), prenomcli.begin(), tolower);
        tab[i][1] = prenomcli;
        cout << " Numero telephone: ";
        cin >> numtelcli;
        tab[i][2] = numtelcli;
        cout << " Email: ";
        cin >> emailcli;
        transform(emailcli.begin(), emailcli.end(), emailcli.begin(), tolower);
        tab[i][3] = emailcli;
        cout << " Le ID de reservation est: ";
        srand(time(NULL));
        a = rand() % 1000;
        idres = to_string(i) + to_string(a);
        tab[i][4] = idres;
        cout << idres << endl;;
        tab[i][5] = "Reserve";
        cout << endl << " Reservation faite!" << endl;
    }
    else
        cout << endl << " Chambre indisponible " << endl;
}
void confirmer() {
    bool conf = false;
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 2 - Confirmer une reservation" << endl;
    cout << endl << " Quel est le ID de reservation: ";
    cin >> idres;
    cout << endl;
    for (i = 1; i < 11; i++) {
        if (tab[i][4] == idres && tab[i][5] == "Reserve") {
            y = i;
            tab[y][5] = "Confirme";
            cout << " Nombre de chambre: " << y << endl;
            cout << " Nom du client: " << tab[y][0] << endl;
            cout << " Prenom client: " << tab[y][1] << endl;
            cout << " Numero telephone: " << tab[y][2] << endl;
            cout << " Email: " << tab[y][3] << endl;
            cout << " ID de reservation: " << tab[y][4] << endl;
            cout << " Status reservation: " << tab[y][5] << endl;
            conf = true;
        }
        else if (tab[i][4] == idres && tab[i][5] == "Confirme") {
            cout << " Reservation deja confirme" << endl;
            conf = true;
        }
    }
    if (conf == false) cout << " Reservation introuvable" << endl;
}
void annuler() {
    bool ann = false;
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 3 - Annuler une reservation" << endl;
    cout << endl << " Quel est le ID de reservation: ";
    cin >> idres;
    cout << endl;
    for (i = 1; i < 11; i++) {
        if (tab[i][4] == idres && tab[i][5] == "Reserve") {
            y = i;
            tab[y][0] = ' ';
            tab[y][1] = ' ';
            tab[y][2] = ' ';
            tab[y][3] = ' ';
            tab[y][4] = ' ';
            tab[y][5] = "Disponible";
            cout << " Reservation annule" << endl;
            ann = true;
        }
        else if (tab[i][4] == idres && tab[i][5] == "Confirme") {
            cout << " Impossible de annuler. Reservation deja confirme" << endl;
            ann = true;
        }
    }
    if (ann == false) cout << " Reservation introuvable" << endl;
}
void sortir() {
    bool sor = false;
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 4 - Check-out" << endl;
    cout << endl << " Quel est le ID de reservation: ";
    cin >> idres;
    cout << endl;
    for (i = 1; i < 11; i++) {
        if (tab[i][4] == idres && tab[i][5] == "Confirme") {
            y = i;
            tab[y][0] = ' ';
            tab[y][1] = ' ';
            tab[y][2] = ' ';
            tab[y][3] = ' ';
            tab[y][4] = ' ';
            tab[y][5] = "Disponible";
            cout << " Chambre vide" << endl;
            sor = true;
        }
        else if (tab[i][4] == idres && tab[i][5] == "Reserve") {
            cout << " Reservation pas encore confirme" << endl;
            sor = true;
        }
    }
    if (sor == false) cout << " Reservation introuvable" << endl;
}
void voir() {
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 5 - Voir liste de chambres" << endl;
    for (i = 1; i < 11; i++) {
        SetConsoleTextAttribute(console_color, 10);
        cout << endl << " Chambre " << i << endl;
        SetConsoleTextAttribute(console_color, 7);
        cout << " Nom du client: " << tab[i][0] << endl;
        cout << " Prenom client: " << tab[i][1] << endl;
        cout << " Numero telephone: " << tab[i][2] << endl;
        cout << " Email: " << tab[i][3] << endl;
        cout << " ID de reservation: " << tab[i][4] << endl;
        cout << " Status reservation: " << tab[i][5] << endl;
    }
}
void voirRes() {
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 6 - Voir liste de reservations" << endl;
    for (i = 1; i < 11; i++) {
        if (tab[i][5] == "Reserve" || tab[i][5] == "Confirme") {
            cout << endl << " Chambre " << i << endl;
            cout << " Nom du client: " << tab[i][0] << endl;
            cout << " Prenom client: " << tab[i][1] << endl;
            cout << " Numero telephone: " << tab[i][2] << endl;
            cout << " Email: " << tab[i][3] << endl;
            cout << " ID de reservation: " << tab[i][4] << endl;
            cout << " Status reservation: " << tab[i][5] << endl;
        }
    }
}
void chercherCli() {
    bool cherc = false;
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 7 - Chercher une client" << endl;
    cout << endl << " Quel est le nom du client: ";
    cin >> nomcli;
    transform(nomcli.begin(), nomcli.end(), nomcli.begin(), tolower);
    for (i = 1; i < 11; i++) {
        if (tab[i][0] == nomcli) {
            y = i;
            cout << endl << " Chambre: " << y << endl;
            cout << " Prenom client: " << tab[y][1] << endl;
            cout << " Numero telephone: " << tab[y][2] << endl;
            cout << " Email: " << tab[y][3] << endl;
            cout << " ID de reservation: " << tab[y][4] << endl;
            cout << " Status reservation: " << tab[y][5] << endl;
            cherc = true;
        }
    }
    if (cherc == false) cout << " Client introuvable" << endl;
}
void chercherRes() {
    bool cherr = false;
    cout << endl << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 8 - Chercher une reservation" << endl;
    cout << endl << " Quel est le ID reservation: ";
    cin >> idres;
    for (i = 1; i < 11; i++) {
        if (tab[i][4] == idres) {
            y = i;
            cout << endl << " Chambre: " << y << endl;
            cout << " Nom du client: " << tab[y][0] << endl;
            cout << " Prenom client: " << tab[y][1] << endl;
            cout << " Numero telephone: " << tab[y][2] << endl;
            cout << " Email: " << tab[y][3] << endl;
            cout << " ID de reservation: " << tab[y][4] << endl;
            cout << " Status reservation: " << tab[y][5] << endl;
            cherr = true;
        }
    }
    if (cherr == false) cout << endl << " Reservation introuvable" << endl;
}
void changer() {
    bool chan = false;
    cout << endl;
    cout << " Systeme de Gestion de Reservervation: Hotel" << endl;
    cout << endl << " 9 - Changer des reservations" << endl;
    cout << endl << " Quel est le ID de reservation: ";
    cin >> idres;
    for (i = 1; i < 11; i++) {
        if (tab[i][4] == idres && tab[i][5] == "Confirme") {
            cout << endl << " Reservation deja confirme " << endl;
            chan = true;
        }
        else if (tab[i][4] == idres && tab[i][5] == "Reserve") {
            chan = true;
            dispcham();
            cout << endl << " Quel est le nouveau numero de chambre? ";
            cin >> chambre;

            if (tab[chambre][5] == "Disponible") {

                tabtemp[0][0] = tab[i][0];
                tabtemp[0][1] = tab[i][1];
                tabtemp[0][2] = tab[i][2];
                tabtemp[0][3] = tab[i][3];
                tabtemp[0][4] = tab[i][4];
                tabtemp[0][5] = tab[i][5];


                tab[i][0] = tabtemp2[0][0];
                tab[i][1] = tabtemp2[0][1];
                tab[i][2] = tabtemp2[0][2];
                tab[i][3] = tabtemp2[0][3];
                tab[i][4] = tabtemp2[0][4];
                tab[i][5] = tabtemp2[0][5];

                i = chambre;
                tab[i][0] = tabtemp[0][0];
                tab[i][1] = tabtemp[0][1];
                tab[i][2] = tabtemp[0][2];
                tab[i][3] = tabtemp[0][3];
                tab[i][4] = tabtemp[0][4];
                tab[i][5] = tabtemp[0][5];

                cout << endl << " Chambre: " << i << endl;
                cout << " Nom du client: " << tab[i][0] << endl;
                cout << " Prenom client: " << tab[i][1] << endl;
                cout << " Numero telephone: " << tab[i][2] << endl;
                cout << " Email: " << tab[i][3] << endl;
                cout << " ID de reservation: " << tab[i][4] << endl;
                cout << " Status reservation: " << tab[i][5] << endl;

            }
            else
            {
                cout << endl << " Chambre indisponible " << endl;
            }
        }
    }
    if (chan == false) cout << endl << " Reservation introuvable" << endl;
}

int main()
{
    using namespace std;
    for (i = 1; i < 11; i++) {
        for (j = 0; j < 6; j++) {
            tab[i][5] = "Disponible";
        }
    }
    tabtemp[0][5] = "Disponible";
    tabtemp2[0][5] = "Disponible";
    reserv = M10;
    do {
        switch (reserv) {
        case M10:
            system("cls");
            cout << endl;
            cout << " Systeme de Gestion de Reservervation: Hotel" << endl;
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M1:
            system("cls");
            reserver();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M2:
            system("cls");
            confirmer();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M3:
            system("cls");
            annuler();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M4:
            system("cls");
            sortir();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M5:
            system("cls");
            voir();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M6:
            system("cls");
            voirRes();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M7:
            system("cls");
            chercherCli();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M8:
            system("cls");
            chercherRes();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        case M9:
            system("cls");
            changer();
            menu();
            cin >> option;
            option = toupper(option);
            coption(option); break;
        }
    } while (reserv != M11);
}

