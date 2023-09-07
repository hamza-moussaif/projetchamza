#include "PROJETh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//intialisation listepatient
void initListepatient(ListePatients* liste)
{
    liste->head = liste->tail = NULL;
}
/****************************************************************************/
//initialisation liste consultation
void initListeconsultation(ListeConsultations* liste)
{
    liste->head = liste->tail = NULL;

}
/****************************************************************************/
//creation d'un noeud patient

PatientNoeud* creerNoeudPatient(PatientNoeud* prev, PatientNoeud* next, Patient* patient)
{
    PatientNoeud* nv = malloc(sizeof(PatientNoeud));
    if(nv == NULL) exit(EXIT_FAILURE);
    strcpy(nv->patient.nom,patient->nom);
    strcpy(nv->patient.prenom,patient->prenom);
    strcpy(nv->patient.telephone,patient->telephone);
    strcpy(nv->patient.email,patient->email);
    strcpy(nv->patient.etat_civil,patient->etat_civil);
    strcpy(nv->patient.cin,patient->cin);
    nv->patient.age=patient->age;
    nv->suivant = next;
    nv->precedent = prev;
    return nv;
}
/**********************************************************************/

//creation d'un noeud consultation
ConsultationNoeud* creerNoeudConsultation(ConsultationNoeud* prev, ConsultationNoeud* next, Consultation* consultation)
{
    ConsultationNoeud* nouveau = (ConsultationNoeud*)malloc(sizeof(ConsultationNoeud));
    if (nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->consultation = *consultation;
    nouveau->suivant = next;
    nouveau->precedent = prev;
    return nouveau;
}


/**********************************************************************/
//Ajouter un patient dans une liste des patients

void ajouterPatient(ListePatients* liste, Patient* patient)
{
    PatientNoeud* courant = liste->head;
    PatientNoeud* precedent = NULL;
    PatientNoeud* nouveau;

    while (courant != NULL)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    nouveau = creerNoeudPatient(precedent, courant, patient);

    if (precedent == NULL)
    {
        liste->head = nouveau;
        liste->tail = nouveau;  // Initialisation de la queue de la liste
    }
    else
    {
        precedent->suivant = nouveau;
        if (courant == NULL)
            liste->tail = nouveau;  // Mise à jour de la queue de la liste
        else
            courant->precedent = nouveau;
    }
}

/**********************************************************************/
//Ajouter une consultation
void ajouterConsultation(ListeConsultations* liste, Consultation* consultation)
{
    ConsultationNoeud* courant = liste->head;
    ConsultationNoeud* precedent = NULL;
    ConsultationNoeud* nouveau;

    while (courant != NULL)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    nouveau = creerNoeudConsultation(precedent, courant, consultation);
    if (precedent == NULL)
    {
        liste->head = nouveau;
        liste->tail = nouveau;
    }
    else
    {
        precedent->suivant = nouveau;
        if (courant == NULL)
            liste->tail = nouveau;
        else
            courant->precedent = nouveau;
    }
}
/**********************************************************************/
 //Définir une fonction qui lit un fichier(patients.txt) et stocke les données dans une liste doublement chainée des patients ;
void lireFichierPatients(ListePatients *liste)
{
    char ligne[256];
    Patient *patient = malloc(sizeof(Patient));
    FILE* fichier= fopen("./patient.txt", "r");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

     while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

        char* token = strtok(ligne, " ");
        if (token != NULL) {
            strcpy(patient->nom, token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(patient->prenom, token);
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(patient->telephone, token);
                    token = strtok(NULL, " ");
                    if (token != NULL) {
                        strcpy(patient->cin, token);
                        token = strtok(NULL, " ");
                        if (token != NULL) {
                            strcpy(patient->email, token);
                            token = strtok(NULL, " ");
                            if (token != NULL) {
                                strcpy(patient->etat_civil, token);
                                token = strtok(NULL, " ");
                                if (token != NULL) {
                                    patient->age = atoi(token);
                                }
                            }
                        }
                    }
                }
            }
        }
        ajouterPatient(liste,patient);
    }
    fclose(fichier);
    afficherPatient(liste);
}
/**********************************************************************/
//Définir une fonction qui lit un fichier(consultations.txt) et stocke les données dans une liste doublement chainée des consultations
void lireFichierconsultaion(ListeConsultations* liste)
{
    FILE* fichier = fopen("./consultations.txt", "r");
    char ligne[300];
     char* token;
    Consultation *consultaion = malloc(sizeof(Consultation));

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        consultaion = malloc(sizeof(Consultation));
        token = strtok(ligne, " ");
        if (token != NULL)
        {

            consultaion->dateConsultation.jour=atoi(token) ;
            token = strtok(NULL, " ");
            if (token != NULL)
            {

                consultaion->dateConsultation.mois=atoi(token) ;
                token = strtok(NULL, " ");
                if (token != NULL)
                {

                    consultaion->dateConsultation.annee=atoi(token) ;
                    token = strtok(NULL, " ");
                    if (token != NULL)
                    {

                        consultaion->dateConsultation.heure=atoi(token) ;
                        token = strtok(NULL, " ");
                        if (token != NULL)
                        {

                            consultaion->dateConsultation.minutes=atoi(token) ;
                            token = strtok(NULL, " ");
                            if (token != NULL)
                            {

                                strcpy(consultaion->patient.nom, token);
                                token = strtok(NULL, " ");
                                if (token != NULL)
                                {

                                    strcpy(consultaion->patient.prenom, token);
                                    token = strtok(NULL, " ");
                                    if (token != NULL)
                                    {

                                        strcpy(consultaion->patient.telephone, token);
                                        token = strtok(NULL, " ");
                                        if (token != NULL)
                                        {

                                            strcpy(consultaion->patient.cin, token);
                                            token = strtok(NULL, " ");
                                            if (token != NULL)
                                            {

                                                strcpy(consultaion->patient.email, token);
                                                token = strtok(NULL, " ");
                                                if (token != NULL)
                                                {

                                                    strcpy(consultaion->patient.etat_civil, token);
                                                    token = strtok(NULL, " ");
                                                    if (token != NULL)
                                                    {

                                                        consultaion->patient.age = atoi(token);
                                                        token = strtok(NULL, " ");
                                                        if (token != NULL)
                                                        {
                                                            strcpy(consultaion->etat, token);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ajouterConsultation(liste,consultaion);
    }
    fclose(fichier);
    afficherConsultations(liste);
}

/**********************************************************************/
 //Saisir un patient
Patient saisiePatient()
{
    char temp[100];
    Patient patient;
    printf("Nom : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.nom,temp);
    printf("Prenom : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.prenom,temp);
    printf("Telephone : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.telephone,temp);
    printf("CIN : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.cin,temp);
    printf("E-mail : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.email,temp);
    printf("Etat Civil : ");
    fflush(stdin);
    gets(temp);
    strcpy(patient.etat_civil,temp);
    printf("Age : ");
    fflush(stdin);
    gets(temp);
    patient.age = atoi(temp);
    return patient;
}

/**********************************************************************/
// Saisir une consultation
Consultation saisieConsultation()
{
    char Temp[100];
    int etat;
    Consultation consultation;
    //date
    printf("\tJour :");
    fflush(stdin);
    gets(Temp);
    consultation.dateConsultation.jour = atoi(Temp);
    printf("\tMois :");
    fflush(stdin);
    gets(Temp);
    consultation.dateConsultation.mois = atoi(Temp);
    printf("\tAnnee :");
    fflush(stdin);
    gets(Temp);
    consultation.dateConsultation.annee = atoi(Temp);
    //consultation
    printf("\tHeure :");
    fflush(stdin);
    gets(Temp);
    consultation.dateConsultation.heure = atoi(Temp);
    printf("\tMinutes :");
    fflush(stdin);
    gets(Temp);
    consultation.dateConsultation.minutes = atoi(Temp);
    consultation.patient = saisiePatient();
    do
    {
        printf("\tEtat (1 pour effectue, 2 pour annule) :");
        fflush(stdin);
        gets(Temp);
        etat = atoi(Temp);
        switch(etat)
        {
        case 1:
            strcpy(consultation.etat,"effectue");
            break;
        case 2:
            strcpy(consultation.etat,"annule");
            break;
        }
    }while(etat < 1 && etat > 2);
    return consultation;
}
/****************************************************************************/
//Définir une fonction qui sauvegarde la liste doublement chaînée dans patients dans le fichier texte « patient.txt »
void SauvegardeFichierPatient(ListePatients *listePatients )
{
    PatientNoeud* courant;
    Patient patient;
    FILE* fpatients = fopen("patient.txt","a");
    for(courant = listePatients->head; courant != NULL; courant = courant->suivant)
    {
        patient = courant->patient;

        fprintf(fpatients,"%s %s %s %s %s %s %d\n",patient.nom, patient.prenom, patient.telephone, patient.cin, patient.email, patient.etat_civil, patient.age);
    }
    fclose(fpatients);

}

/****************************************************************************/
// Définir une fonction qui sauvegarde la liste doublement chaînée des consultations dans le fichier texte « consulations.txt »
void SauvegardeFichierConsultations(ListeConsultations *ListeConsultations )
{
    ConsultationNoeud* courant;
    Consultation consultation;
    Date date;
    Patient patient;
   FILE* fconsultations = fopen("consultations.txt","a");

    for(courant = ListeConsultations->head ;courant!= NULL; courant = courant->suivant)
    {
        consultation = courant->consultation;
        date = consultation.dateConsultation;
        patient = consultation.patient;
        fprintf(fconsultations, "\n");
        fprintf(fconsultations,"%d %d %d %d %d %s %s %s %s %s %s %d %s",date.jour, date.mois, date.annee, date.heure, date.minutes, patient.nom, patient.prenom, patient.telephone, patient.cin, patient.email, patient.etat_civil, patient.age, consultation.etat);
    }
    fclose(fconsultations);
}

/***************************************************************************/
//Supprimer un patient

void supprimerPatient(ListePatients *liste)
{
    char cin[256];  // Déclarer cin comme un tableau de caractères suffisamment grand pour stocker l'entrée
    PatientNoeud *courant = liste->head;
    printf("Saisir le CIN : ");
    scanf("%s", cin);

    while (courant != NULL && strcmp(courant->patient.cin, cin) != 0)
        courant = courant->suivant;

    if (courant == NULL)
    {
        printf("Le patient n'a pas été trouvé dans la liste.\n");
        return;
    }

    if (courant->precedent == NULL && courant->suivant == NULL)
    {
        liste->head = NULL;
        liste->tail = NULL;
    }
    else if (courant->precedent == NULL)
    {
        liste->head = courant->suivant;
        liste->head->precedent = NULL;
    }
    else if (courant->suivant == NULL)
    {
        liste->tail = courant->precedent;
        liste->tail->suivant = NULL;
    }
    else
    {
        courant->suivant->precedent = courant->precedent;
        courant->precedent->suivant = courant->suivant;
    }

    free(courant);
}

/***************************************************************************/
//Supprimer une consultation

void supprimerConsultation(ListeConsultations* liste, Date date)
{
    ConsultationNoeud *courant = liste->head;
    int flag;
    while (courant != NULL)
    {
        flag=0;
        if(courant->consultation.dateConsultation.annee != date.annee )
        flag++;
            if (courant->consultation.dateConsultation.mois !=  date.mois)
               flag++;
            if(courant->consultation.dateConsultation.jour !=  date.jour)
                    flag++;
            if ( courant->consultation.dateConsultation.heure !=  date.heure)
                        flag++;
            if ( courant->consultation.dateConsultation.minutes != date.minutes)
                            flag++;


    if(flag==0){
        break;
    }
    courant = courant->suivant;
    }

    if(courant->precedent == NULL && courant->suivant==NULL)
    {
        liste->head=NULL;
        liste->tail=NULL;

    }
    else if(courant->precedent==NULL)
    {
        liste->head=courant->suivant;
        liste->head->precedent=NULL;
    }
    else if(courant->suivant==NULL)
    {
       liste->tail=courant->precedent;
        liste->tail->suivant=NULL;
    }
    else
    {
        courant->suivant->precedent=courant->precedent;
        courant->precedent->suivant=courant->suivant;
    }

    free(courant);
}
/***************************************************************************/
//recherche par nom____i
PatientNoeud* chercherPatientParNom(ListePatients* liste,char* nom) {
    PatientNoeud* patientnoeud = liste->head;
    while (patientnoeud != NULL) {
        if (strcmp(patientnoeud->patient.nom, nom) == 0) {
            return patientnoeud;
        }
        patientnoeud = patientnoeud->suivant;
    }
    return NULL;
}
/***************************************************************************/
//recherche par cin____ii

PatientNoeud* chercherPatientParCIN(ListePatients* liste, char* cin) {
    PatientNoeud* patientnoeud = liste->head;
    while (patientnoeud != NULL) {
        if (strcmp(patientnoeud->patient.cin, cin) == 0) {

            return patientnoeud;
        }else
        patientnoeud = patientnoeud->suivant;
    }
    return NULL;
}
/***************************************************************************/
//recherche soit cin/nom____h
void afficherConsultationsCIN(ListeConsultations* liste, char* cin)
{
    ConsultationNoeud* courant = liste->head;
    while(courant != NULL)
    {
        if(strcmp(courant->consultation.patient.cin,cin)==0)
        {
            afficherConsultation(courant);
        }
        courant = courant->suivant;
    }
}
/***************************************************************************/
void afficherConsultationsNom(ListeConsultations* liste, char* nom)
{
    ConsultationNoeud* courant = liste->head;
    while(courant != NULL)
    {
        if(strcmp(courant->consultation.patient.nom,nom)==0)
        {
            afficherConsultation(courant);
        }
        courant = courant->suivant;
    }
}
/***************************************************************************/
void afficherConsultationsCIN_Nom(ListeConsultations* liste)
{
    int choix;
    char cin[20], nom[50];
    printf("Taper le numero pour choisir:\n");
    printf("\t1) par cin\n");
    printf("\t2) par nom\n");
    printf("\t\tVotre choix : ");
    scanf("%d",&choix);
    if(choix==1)
    {
        system("cls");
        printf("cin : ");
        scanf("%s",cin);
        afficherConsultationsCIN(liste, cin) ;
    }
    else if(choix==2)
    {
        system("cls");
        printf("nom : ");
        scanf("%s",nom);
        afficherConsultationsNom(liste, nom) ;
    }
}
/***************************************************************************/
//recherche par date____i
void afficherConsultationsDate(ListeConsultations *liste, int jour, int mois, int annee) {
    ConsultationNoeud* consultationnoeud = liste->head;
    while (consultationnoeud != NULL) {
        if (consultationnoeud->consultation.dateConsultation.jour== jour && consultationnoeud->consultation.dateConsultation.mois == mois && consultationnoeud->consultation.dateConsultation.annee == annee) {
            printf("Consultation du patient %s %s le %02d/%02d/%04d  A %02d:%02d\n",consultationnoeud->consultation.patient.nom,consultationnoeud->consultation.patient.prenom, consultationnoeud->consultation.dateConsultation.jour,consultationnoeud->consultation.dateConsultation.mois,consultationnoeud->consultation.dateConsultation.annee, consultationnoeud->consultation.dateConsultation.heure, consultationnoeud->consultation.dateConsultation.minutes);
        }
        consultationnoeud = consultationnoeud->suivant;
    }
}
/****************************************************************************/
void afficherConsultationsAnnule(ListeConsultations *liste, int jour, int mois, int annee)
{
    ConsultationNoeud* consultationnoeud = liste->head;
    while (consultationnoeud != NULL) {
        if (consultationnoeud->consultation.dateConsultation.jour == jour && consultationnoeud->consultation.dateConsultation.mois == mois && consultationnoeud->consultation.dateConsultation.annee == annee && strcmp(consultationnoeud->consultation.etat,"annule")==0)
        {
            printf("Consultation du patient %s %s le %02d/%02d/%04d  A %02d:%02d est annule\n",consultationnoeud->consultation.patient.nom,consultationnoeud->consultation.patient.prenom, consultationnoeud->consultation.dateConsultation.jour,consultationnoeud->consultation.dateConsultation.mois,consultationnoeud->consultation.dateConsultation.annee, consultationnoeud->consultation.dateConsultation.heure, consultationnoeud->consultation.dateConsultation.minutes);
        }
        consultationnoeud = consultationnoeud->suivant;
    }
}
/****************************************************************************/
void afficherPatient(ListePatients *liste)
{
  PatientNoeud* courant = liste->head;
    while(courant != NULL)
    {
        printf("\nNom : %s\n",courant->patient.nom);
        printf("Prenom : %s\n",courant->patient.prenom);
        printf("Telephone : %s\n",courant->patient.telephone);
        printf("CIN : %s\n",courant->patient.cin);
        printf("E-mail : %s\n",courant->patient.email);
        printf("Etat civile : %s\n",courant->patient.etat_civil);
        printf("Age : %d\n",courant->patient.age);
        printf("/***************************/\n");

        courant = courant->suivant;
    }

}
/****************************************************************************/
void afficherPatients(PatientNoeud *courant)
{
        printf("\nNom : %s\n",courant->patient.nom);
        printf("Prenom : %s\n",courant->patient.prenom);
        printf("Telephone : %s\n",courant->patient.telephone);
        printf("CIN : %s\n",courant->patient.cin);
        printf("E-mail : %s\n",courant->patient.email);
        printf("Etat civile : %s\n",courant->patient.etat_civil);
        printf("Age : %d\n",courant->patient.age);
        printf("/***************************/\n");
}
/****************************************************************************/
void afficherConsultations(ListeConsultations *liste)
{
    ConsultationNoeud* courant = liste->head;
    while(courant != NULL)
    {
        afficherConsultation(courant);
        courant = courant->suivant;
    }
}
/****************************************************************************/
void afficherConsultation(ConsultationNoeud *courant)
{
    printf("\nDate : %02d/%02d/%d ", courant->consultation.dateConsultation.jour,
            courant->consultation.dateConsultation.mois, courant->consultation.dateConsultation.annee);
    printf("%02d:%02d\n", courant->consultation.dateConsultation.heure,
            courant->consultation.dateConsultation.minutes);
    printf("Nom : %s\n",courant->consultation.patient.nom);
    printf("Prenom : %s\n",courant->consultation.patient.prenom);
    printf("Telephone : %s\n",courant->consultation.patient.telephone);
    printf("CIN : %s\n",courant->consultation.patient.cin);
    printf("E-mail : %s\n",courant->consultation.patient.email);
    printf("Etat civile : %s\n",courant->consultation.patient.etat_civil);
    printf("Age : %d\n",courant->consultation.patient.age);
    printf("Sceance %s\n",courant->consultation.etat);

    printf("/***************************/\n");
}

/*****************************************************************************

ListeConsultations* trieConsultation(ListeConsultations* liste)
{
    ConsultationNoeud *Noeud = liste->head, *courant = malloc(sizeof(ConsultationNoeud));
    ListeConsultations* nvListe;
    int jour,mois,annee,heure,minutes;
    nvListe->head = courant;
    printf("Veuillez saisir la date du jour \n");
    printf("jour : ");
    scanf("%d",&jour);
    printf("mois : ");
    scanf("%d",&mois);
    printf("anne : ");
    scanf("%d",&annee);
    printf("heure : ");
    scanf("%d",&heure);
    printf("min : ");
    scanf("%d",&minutes);

    while (Noeud != NULL) {
        if (Noeud->consultation.dateConsultation.jour >= jour && Noeud->consultation.dateConsultation.mois >= mois && Noeud->consultation.dateConsultation.annee == annee && (strcmp(Noeud->consultation.etat,"annule")!=0))
        {
            courant->consultation=Noeud->consultation;
            printf("Consultation du patient %s %s le %02d/%02d/%04d  A %02d:%02d\n",Noeud->consultation.patient.nom,Noeud->consultation.patient.prenom, Noeud->consultation.dateConsultation.jour,Noeud->consultation.dateConsultation.mois,Noeud->consultation.dateConsultation.annee, Noeud->consultation.dateConsultation.heure, Noeud->consultation.dateConsultation.minutes);
            courant = courant->suivant;
        }
        Noeud = Noeud->suivant;
    }
    nvListe->tail = courant;

}
*/
