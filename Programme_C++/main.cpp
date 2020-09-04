#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    //Tant qu'on n'a pas extrait toutes les lettres du mot
    while (mot.size() != 0)
    {
        //On choisit un numéro de lettre au hasard dans le mot
        position = rand() % mot.size();
        //On ajoute la lettre dans le mot mélangé
        melange += mot[position];
        //On retire cette lettre du mot mystère
        //Pour ne pas la prendre une deuxième fois
        mot.erase(position, 1);
    }

    //On renvoie le mot mélangé
    return melange;
}

int main() {
    string motMystere, motMelange, motUtilisateur, rejouer;

    //Initialisation des nombres aléatoires
    srand(time(0));

    do {
        //1 : On demande de saisir un mot
        cout << "Saisissez un mot" << endl;
        cin >> motMystere;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;


        //2 : On récupère le mot avec les lettres mélangées dans motMelange
        motMelange = melangerLettres(motMystere);

        //3 : On demande à l'utilisateur quel est le mot mystère
        int essais(1);
        do {
            cout << endl << "Quel est ce mot ? " << motMelange << endl;
            cin >> motUtilisateur;

            if (motUtilisateur == motMystere) {
                cout << "Bravo !" << endl;
                cout << "Vous avez gagnez en " << essais << " essais." << endl;
                cout << "Voulez-vous faire une autre partie ? (o/n)" << endl;
                cin >> rejouer;
            } else {
                essais++;
                cout << "Ce n'est pas le mot !" << endl;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
                motMelange = melangerLettres(motMystere);
            }
        } while (motUtilisateur != motMystere);
        //On recommence tant qu'il n'a pas trouvé

    } while (rejouer == "o");

}