#ifndef PROJET_H_INCLUDED
#define PROJET_H_INC
#define FALSE 0
#define TRUE 1

//patient
typedef struct
{
    char nom[50];
    char prenom[50];
    char telephone[20];
    char cin[20];
    char email[100];
    char etat_civil[20];
    int age;
} Patient;

// consultation
//date
typedef struct
{
    int jour;
    int mois;
    int annee;
    int heure;
    int minutes;
} Date;

// consultation
typedef struct
{
    Date dateConsultation;
    Patient patient;
    char etat[20];
} Consultation;

// element consultation
typedef struct ConsultationNoeud
{
    Consultation consultation;
    struct ConsultationNoeud* suivant;
    struct ConsultationNoeud* precedent;
} ConsultationNoeud;

//element patient
typedef struct PatientNoeud
{
    Patient patient;
    struct PatientNoeud* suivant;
    struct PatientNoeud* precedent;
} PatientNoeud;

// liste doublement chaine consultation
typedef struct
{
    ConsultationNoeud* head;
    ConsultationNoeud* tail;
} ListeConsultations;

// liste doublement chaine patients
typedef struct
{
    PatientNoeud* head;
    PatientNoeud* tail;
} ListePatients;

//initialisation
void initListepatient(ListePatients*);
void initListeconsultation(ListeConsultations*);
//creation noeud
PatientNoeud* creerNoeudPatient(PatientNoeud*, PatientNoeud*, Patient* );
ConsultationNoeud* creerNoeudConsultation(ConsultationNoeud*, ConsultationNoeud*, Consultation*);
//ajout
void ajouterPatient(ListePatients*, Patient* );
void ajouterConsultation(ListeConsultations*, Consultation*);
//lire
void lireFichierPatients(ListePatients*);
void lireFichierconsultaion(ListeConsultations*);
//saisie
Consultation saisieConsultation();
Patient saisiePatient();
//affichage
void afficherPatient(ListePatients*);
void afficherPatients(PatientNoeud*);
//supprimer
void supprimerConsultation(ListeConsultations* ,Date );
void supprimerPatient(ListePatients*);
//recherche
PatientNoeud* chercherPatientParNom(ListePatients*,char*);
PatientNoeud* chercherPatientParCIN(ListePatients*, char*);
//affichage consultaion cin /nom/both
void afficherConsultationsCIN(ListeConsultations*, char*);
void afficherConsultationsNom(ListeConsultations*, char*);
void afficherConsultationsCIN_Nom(ListeConsultations* liste);
//affichage consultation
void afficherConsultation(ConsultationNoeud*);
void afficherConsultations(ListeConsultations *liste);
//afficher consultation date/annulation
void afficherConsultationsDate(ListeConsultations*, int, int, int);
void afficherConsultationsAnnule(ListeConsultations*, int, int, int);
//gestion dùordre de passage
ListeConsultations* trieConsultation(ListeConsultations* liste);

#endif // PROJETH_H_INCLUDED
