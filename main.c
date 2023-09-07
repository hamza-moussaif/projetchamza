#include "PROJETh.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

/*************************************************************** */
int menu(void)
{
    int choix;
    printf("Taper le numero de la tache a effectuer :\n");
    printf("\t1) Afficher la liste des patients\n");
    printf("\t2) Afficher les consultations d un patient (soit par CIN ou par nom)\n");
    printf("\t3) Afficher les consultations par jour (on donne la date souhaitee)\n");
    printf("\t4) Afficher les consultations annulees dans un jour donnee\n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t5) Ajouter un patient\n");
    printf("\t6) Ajouter une consultation\n");
    printf("\t7) Supprimer un patient\n");
    printf("\t8) Supprimer une consultation\n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t9) Chercher un patient par nom\n");
    printf("\t10) Chercher un patient par CIN\n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t0) Quitter\n");
    printf("\t\tVotre choix : ");
    scanf("%d", &choix);
    system("cls");
    return choix;
}
  /*************************************************************** */
    /** FONCTION ATTENTE **/

void att()
{
    int i , j   ;

    char msg[23] = "M E R C I - M A D A M E";

    for(j=0;j<4;j++)
     {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t");

         for(i=0;i<23;i++)
         {
           printf(" %c",msg[i]);
           Sleep( 55 );
         }

     }
}

/*************************************************************** */
int main()
{
    int jour,mois,anne;
    Date date;
    char cin[20],nom[50] ;
    int choix;
    Patient *patient;
    Patient p;
    Consultation *consultation;
    Consultation c;
    ListeConsultations *listeConsultations;
    ListePatients *listePatients;
    listePatients = malloc(sizeof(listePatients));
    listeConsultations = malloc(sizeof(listeConsultations));
    initListepatient(listePatients );
    initListeconsultation(listeConsultations);

    do
    {
        system("color F0");
        choix = menu();
        switch(choix)
        {
            case 1:
                afficherPatient(listePatients);
                system("pause");
                system("cls");
                break;
            case 2:
                afficherConsultationsCIN_Nom(listeConsultations);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\t saisir la date souhaiter\n");
                printf("jour : ");
                scanf("%d",&jour);
                printf("mois : ");
                scanf("%d",&mois);
                printf("anne : ");
                scanf("%d",&anne);
                system("cls");
                afficherConsultationsDate(listeConsultations, jour,  mois, anne);
                system("pause");
                system("cls");
                break;
            case 4:
                printf("\t saisir la date souhaiter\n");
                printf("jour : ");
                scanf("%d",&jour);
                printf("mois : ");
                scanf("%d",&mois);
                printf("anne : ");
                scanf("%d",&anne);
                system("cls");
                afficherConsultationsAnnule(listeConsultations, jour, mois, anne);
                system("pause");
                system("cls");
                break;
            case 5:
                p = saisiePatient();
                patient = &p;
                ajouterPatient(listePatients, &p);
                system("pause");
                system("cls");
                break;
            case 6:
                c = saisieConsultation();
                consultation = &c;
                ajouterConsultation(listeConsultations,consultation);
                system("pause");
                system("cls");
                break;
            case 7:
                supprimerPatient(listePatients);
                system("pause");
                system("cls");
                break;
            case 8:
                printf("jour : ");
                scanf("%d",&date.jour);
                printf("mois : ");
                scanf("%d",&date.mois);
                printf("anne : ");
                scanf("%d",&date.annee);
                printf("heure : ");
                scanf("%d",&date.heure);
                printf("min : ");
                scanf("%d",&date.minutes);

                supprimerConsultation(listeConsultations,date);
                system("pause");
                system("cls");
                break;
            case 9:
                printf("Nom : ");
                scanf("%s",nom);
                afficherPatients(chercherPatientParNom(listePatients, nom));
                system("pause");
                system("cls");
                break;
            case 10:
                printf("CIN : ");
                scanf("%s",cin);
                 afficherPatients(chercherPatientParCIN(listePatients, cin));
                system("pause");
                system("cls");
                break;
            case 11:
                lireFichierPatients(listePatients);
                afficherPatient(listePatients);
                system("pause");
                system("cls");
                lireFichierconsultaion(listeConsultations);
                afficherConsultations(listeConsultations);
                system("pause");
                system("cls");
                break;
                  case 12:
                SauvegardeFichierPatient(listePatients);
                system("pause");
                system("cls");
                SauvegardeFichierConsultations(listeConsultations);
                system("pause");
                system("cls");
                break;
            case 0:
                att();
                printf("\n\n\n\n");
                system("pause");
                system("cls");
                printf("\tChere Professeur Bouchra Honnit,\n\n");
                printf("\tNous tenons a vous exprimer notre profonde gratitude pour votre enseignement exceptionnel en programmation.\n \tGrace a votre passion, votre devouement et vos connaissances approfondies,");
                printf("nous avons acquis  des competences\n\t precieuses qui nous ont ouvert de nouvelles perspectives. Votre patience et votre soutien constant ont ete\n\t inestimables pour notre parcours d'apprentissage.");
                printf("Nous sommes sincerement reconnaissants d'avoir eu la chance\n\t de beneficier de vos cours. Merci infiniment pour votre influence positive et inspirante dans nos \n\tvies academiques.\n");
                printf("\n\tCordialement,");
                printf("\n\n\n\n");
                printf("\t********************************");
                printf("\n\t Hamza Moussaif\t Taha Benzakour\n\t Mamoun Chadili\t Saad Douar\n");
                printf("\t********************************\n\n");
                system("pause");

                break;
            default:
                //trieConsultation(listeConsultations);
                printf("\n CHOIX ERRONEE\n");
                system("pause");
                system("cls");
        }
    }while(choix!=0);
    return 0;
}

