  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/


  /*Declaration des structure et de l'arbre */

  #include <stdio.h>
  #include <stdlib.h>

  typedef int bool ;
  typedef char * string255 ;
  typedef char * string2 ;

  #define True 1
  #define False 0

  /** Structures statiques **/

  typedef struct Tcb Type_Tcb  ;
  typedef Type_Tcb * Typestr_Tcb ;
  typedef string2 Type1_Tcb  ;
  typedef bool Type2_Tcb  ;
  struct Tcb
    {
      Type1_Tcb Champ1 ;
      Type2_Tcb Champ2 ;
    };

  Type1_Tcb Struct1_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ1 ;
    }

  Type2_Tcb Struct2_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tcb ( Typestr_Tcb S, Type1_Tcb Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tcb ( Typestr_Tcb S, Type2_Tcb Val )
    {
       S->Champ2 = Val ;
    }


  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Arbres de recherche binaire **/

  typedef Typestr_Tcb Typeelem_ATcb   ;
  typedef struct Noeud_ATcb * Pointeur_ATcb ;

  struct Noeud_ATcb
    {
      Typeelem_ATcb  Val ;
      Pointeur_ATcb Fg ;
      Pointeur_ATcb Fd ;
      Pointeur_ATcb Pere ;
     } ;

  Typeelem_ATcb Info_ATcb( Pointeur_ATcb P )
    { return P->Val;   }

  Pointeur_ATcb Fg_ATcb( Pointeur_ATcb P)
    { return P->Fg ; }

  Pointeur_ATcb Fd_ATcb( Pointeur_ATcb P)
    { return P->Fd ; }

  Pointeur_ATcb Pere_ATcb( Pointeur_ATcb P)
    { return P->Pere ; }

  void Aff_info_ATcb ( Pointeur_ATcb P, Typeelem_ATcb Val)
    {
      Typeelem_ATcb _Temp ;
      _Temp = malloc(sizeof(Typestr_Tcb));
      _Temp->Champ1 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATcb( Pointeur_ATcb *P)
    {
      *P = (struct Noeud_ATcb *) malloc( sizeof( struct Noeud_ATcb))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tcb));
      (*P)->Val->Champ1 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATcb( Pointeur_ATcb P)
    { free( P ) ; }


  /** Implémentation **\: LISTE DE CHAINES DE CARACTERES**/

  /** Listes lin?aires cha?n?es **/

  typedef string255 Typeelem_Ls   ;
  typedef struct Maillon_Ls * Pointeur_Ls ;

  struct Maillon_Ls
    {
      Typeelem_Ls  Val ;
      Pointeur_Ls Suiv ;
    } ;

  Pointeur_Ls Allouer_Ls (Pointeur_Ls *P)
    {
      *P = (struct Maillon_Ls *) malloc( sizeof( struct Maillon_Ls)) ;
      (*P)->Val = malloc(255 * sizeof(string255));
      (*P)->Suiv = NULL;
    }

  void Aff_val_Ls(Pointeur_Ls P, Typeelem_Ls Val)
    {
      strcpy( P->Val , Val );
    }

  void Aff_adr_Ls( Pointeur_Ls P,  Pointeur_Ls Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Ls Suivant_Ls(  Pointeur_Ls P)
    { return( P->Suiv ) ;  }

  Typeelem_Ls Valeur_Ls( Pointeur_Ls P)
    { return( P->Val) ; }

  void Liberer_Ls ( Pointeur_Ls P)
    { free (P);}

  /** Variables du programme principal **/
  Typestr_Tcb R;
  Pointeur_ATcb S;
  Pointeur_Ls W_list;
  string255 Mot1;
  string255 Requitous;
  string255 Inter;
  string255 Str;
  int Nbr_arbre;
  int Nbr_mot;
  bool Trouv_s;
  int _Px1;
  string255 _Sx;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);

      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }

  char *Caract ( string255 Ch , int I )
    {
      char *s = malloc(2);
      s[0] = Ch[I-1];
      s[1] = '\0';
      return  s;
    }

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }


  /** Prototypes des fonctions **/

  void Insertion (Pointeur_ATcb *Racine , string255 *Mot);
  void Parcour (Pointeur_ATcb *Ptr_ecr , string255 *Resultat);
  string2  Card (Pointeur_ATcb *Root2) ;
  bool  Bool (Pointeur_ATcb *Root3) ;
  void Inserer_inferieur (Pointeur_ATcb *Ptr , string255 *Expression , int *I);
  void Insertion_egale (Pointeur_ATcb *Pointer , string255 *Word , int *K);
  bool  Existe (string255 *Kalima , string2 *Harf) ;
  int  Emplacement (string255 *Chain , string2 *Ch) ;
  string255  Cpi_chaine (string255 *Chai , int *A , int *B) ;
  int  Nb_occ (string255 *Sentence , string2 *Let) ;
  bool  Valid (string255 *Tst , string255 *Req) ;
  void Requete (Pointeur_ATcb *Ptr2 , string255 *Resultat2 , string255 *Research , bool *Trouv_t);
  void Intro (int *K);

  /******************************************************************************/
  void Insertion (Pointeur_ATcb *Racine , string255 *Mot)
    {
      /** Variables locales **/
      Pointeur_ATcb P;
      Pointeur_ATcb N;
      Typestr_Tcb Str;
      int I;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     if( ( *Racine == NULL )) {
       Creernoeud_ATcb(&*Racine ) ;
       Aff_struct1_Tcb(Str  , Caract(*Mot , 1 ) ) ;
       Aff_struct2_Tcb(Str  , False ) ;
       Aff_info_ATcb(*Racine , Str ) ;
       P  =  *Racine ;
       for( I  =  2 ;I <=  Longchaine(*Mot ) ; ++I){
         Creernoeud_ATcb(&N ) ;
         Aff_struct1_Tcb(Str  , Caract(*Mot , I ) ) ;
         Aff_struct2_Tcb(Str  , False ) ;
         Aff_info_ATcb(N , Str ) ;
         Aff_fg_ATcb(P , N ) ;
         P  =  N ;

       } ;
       Aff_fg_ATcb(P , NULL ) ;
       Aff_fd_ATcb(P , NULL ) ;
       Aff_struct2_Tcb(Str  , True ) ;
       Aff_info_ATcb(P , Str ) ;
       }
     else
       {
       if( (strcmp( Card ( & *Racine ), Caract(*Mot , 1 )) > 0  )) {
         Creernoeud_ATcb(&P ) ;
         Aff_fd_ATcb(P , *Racine ) ;
         *Racine  =  P ;
         Aff_struct1_Tcb(Str  , Caract(*Mot , 1 ) ) ;
         if( ( Longchaine(*Mot ) == 1 )) {
           Aff_fg_ATcb(*Racine , NULL ) ;
           Aff_struct2_Tcb(Str  , True ) ;
           Aff_info_ATcb(*Racine , Str ) ;
           }
         else
           {
           Aff_struct2_Tcb(Str  , False ) ;
           Aff_info_ATcb(*Racine , Str ) ;
           P  =  *Racine ;
           for( I  =  2 ;I <=  Longchaine(*Mot ) ; ++I){
             Creernoeud_ATcb(&N ) ;
             Aff_struct1_Tcb(Str  , Caract(*Mot , I ) ) ;
             Aff_struct2_Tcb(Str  , False ) ;
             Aff_info_ATcb(N , Str ) ;
             Aff_fg_ATcb(P , N ) ;
             P  =  N ;

           } ;
           Aff_struct2_Tcb(Str  , True ) ;
           Aff_info_ATcb(P , Str ) ;
           Aff_fg_ATcb(P , NULL ) ;
           Aff_fd_ATcb(P , NULL ) ;

         } }
       else
         {
         if( (strcmp( Card ( & *Racine ), Caract(*Mot , 1 )) < 0  )) {
           _Px1 =  1 ;
           Inserer_inferieur ( & *Racine , & *Mot , &_Px1) ;
           }
         else
           {
           _Px2 =  1 ;
           Insertion_egale ( & *Racine , & *Mot , &_Px2) ;

         }
       }
     } ;

    }
  /******************************************************************************/
  void Parcour (Pointeur_ATcb *Ptr_ecr , string255 *Resultat)
    {
      /** Variables locales **/
      Pointeur_ATcb K;
      Typestr_Tcb Str;
      string255 Resultat_1;
      string255 _Sx;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     Resultat_1 = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     if( ( *Ptr_ecr != NULL )) {
       strcpy (Resultat_1,   *Resultat) ;
       strcpy (_Sx, *Resultat);
       strcpy (*Resultat,  strcat(_Sx, Card ( & *Ptr_ecr ))) ;
       if( ( Bool ( & *Ptr_ecr ) == True )) {
         strcpy (_Sx, "->");
         strcpy (*Resultat,  strcat(_Sx, *Resultat)) ;
         printf ( " %s", *Resultat ) ;

       } ;
       _Px1 =  Fg_ATcb(*Ptr_ecr ) ;
       Parcour ( &_Px1, & *Resultat ) ;
       _Px2 =  Fd_ATcb(*Ptr_ecr ) ;
       Parcour ( &_Px2, & Resultat_1 ) ;

     } ;

    }
  /******************************************************************************/
  string2  Card (Pointeur_ATcb *Root2)
    {
      /** Variables locales **/
      string2  Card2 ;

      /** Corps du module **/
     Card2 = malloc(2 * sizeof(string2));
     strcpy (Card2,   Struct1_Tcb(Info_ATcb(*Root2 )  )) ;

     return Card2 ;
    }
  /******************************************************************************/
  bool  Bool (Pointeur_ATcb *Root3)
    {
      /** Variables locales **/
      bool  Bool2 ;

      /** Corps du module **/
     Bool2  =  Struct2_Tcb(Info_ATcb(*Root3 )  ) ;

     return Bool2 ;
    }
  /******************************************************************************/
  void Inserer_inferieur (Pointeur_ATcb *Ptr , string255 *Expression , int *I)
    {
      /** Variables locales **/
      Pointeur_ATcb N;
      Pointeur_ATcb Q;
      Pointeur_ATcb S;
      Pointeur_ATcb T;
      Typestr_Tcb Str;
      int J;
      bool Test;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;
      Pointeur_ATcb _Px3;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     N  =  *Ptr ;
     Q  =  *Ptr ;
     Test  =  False ;
     while( ( Fd_ATcb(N ) != NULL ) && ( Test == False ))  {
       _Px1 =  Fd_ATcb(N ) ;
       if( (strcmp( Card ( &_Px1), Caract(*Expression , *I )) < 0  )) {
         Q  =  N ;
         N  =  Fd_ATcb(N ) ;
         }
       else
         {
         Test  =  True ;

       }
     } ;
     if( ( Fd_ATcb(N ) != NULL )) {
       _Px2 =  Fd_ATcb(N ) ;
       if( (strcmp( Card ( &_Px2), Caract(*Expression , *I )) == 0  )) {
         _Px3 =  Fd_ATcb(N ) ;
         Insertion_egale ( &_Px3, & *Expression , & *I ) ;
         }
       else
         {
         Creernoeud_ATcb(&S ) ;
         Aff_struct1_Tcb(Str  , Caract(*Expression , *I ) ) ;
         Aff_struct2_Tcb(Str  , False ) ;
         Aff_info_ATcb(S , Str ) ;
         Q  =  Fd_ATcb(N ) ;
         Aff_fd_ATcb(N , S ) ;
         Aff_fd_ATcb(S , Q ) ;
         if( ( Longchaine(*Expression ) - *I + 1 > 1 )) {
           for( J  =  *I + 1 ;J <=  Longchaine(*Expression ) ; ++J){
             Creernoeud_ATcb(&T ) ;
             Aff_struct1_Tcb(Str  , Caract(*Expression , J ) ) ;
             Aff_struct2_Tcb(Str  , False ) ;
             Aff_info_ATcb(T , Str ) ;
             Aff_fg_ATcb(S , T ) ;
             Aff_fd_ATcb(T , NULL ) ;
             S  =  T ;

           } ;

         } ;
         Aff_struct2_Tcb(Str  , True ) ;
         Aff_info_ATcb(S , Str ) ;
         Aff_fg_ATcb(S , NULL ) ;

       } }
     else
       {
       Creernoeud_ATcb(&S ) ;
       Aff_struct1_Tcb(Str  , Caract(*Expression , *I ) ) ;
       Aff_struct2_Tcb(Str  , False ) ;
       Aff_info_ATcb(S , Str ) ;
       Q  =  Fd_ATcb(N ) ;
       Aff_fd_ATcb(N , S ) ;
       Aff_fd_ATcb(S , Q ) ;
       if( ( Longchaine(*Expression ) - *I + 1 > 1 )) {
         for( J  =  *I + 1 ;J <=  Longchaine(*Expression ) ; ++J){
           Creernoeud_ATcb(&T ) ;
           Aff_struct1_Tcb(Str  , Caract(*Expression , J ) ) ;
           Aff_struct2_Tcb(Str  , False ) ;
           Aff_info_ATcb(T , Str ) ;
           Aff_fg_ATcb(S , T ) ;
           Aff_fd_ATcb(T , NULL ) ;
           S  =  T ;

         } ;

       } ;
       Aff_struct2_Tcb(Str  , True ) ;
       Aff_info_ATcb(S , Str ) ;
       Aff_fg_ATcb(S , NULL ) ;

     }
    }
  /******************************************************************************/
  void Insertion_egale (Pointeur_ATcb *Pointer , string255 *Word , int *K)
    {
      /** Variables locales **/
      Pointeur_ATcb R;
      Pointeur_ATcb Per;
      Pointeur_ATcb P;
      Pointeur_ATcb N;
      Typestr_Tcb Str;
      int J;
      int H;
      bool Sortir;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     J  =  *K ;
     R  =  *Pointer ;
     Sortir  =  False ;
     while( ( R != NULL ) && ( J <= Longchaine(*Word ) ) && ( Sortir == False ))  {
       if( (strcmp( Card ( & R ), Caract(*Word , J )) == 0  )) {
         Per  =  R ;
         R  =  Fg_ATcb(R ) ;
         J  =  J + 1 ;
         }
       else
         {
         Sortir  =  True ;

       }
     } ;
     if( ( J > Longchaine(*Word ) )) {
       Aff_struct1_Tcb(Str  , Caract(*Word , J - 1 ) ) ;
       Aff_struct2_Tcb(Str  , True ) ;
       Aff_info_ATcb(Per , Str ) ;
       }
     else
       {
       if( ( R != NULL )) {
         if( (strcmp( Card ( & R ), Caract(*Word , J )) > 0  )) {
           P  =  Per ;
           for( H  =  J ;H <=  Longchaine(*Word ) ; ++H){
             Creernoeud_ATcb(&N ) ;
             Aff_struct1_Tcb(Str  , Caract(*Word , H ) ) ;
             Aff_struct2_Tcb(Str  , False ) ;
             Aff_info_ATcb(N , Str ) ;
             Aff_fg_ATcb(P , N ) ;
             P  =  N ;

           } ;
           Aff_struct2_Tcb(Str  , True ) ;
           Aff_info_ATcb(N , Str ) ;
           Aff_fg_ATcb(N , NULL ) ;
           Aff_fd_ATcb(N , NULL ) ;
           Aff_fd_ATcb(Fg_ATcb(Per ) , R ) ;
           }
         else
           {
           Inserer_inferieur ( & R , & *Word , & J ) ;

         } }
       else
         {
         P  =  Per ;
         for( H  =  J ;H <=  Longchaine(*Word ) ; ++H){
           Creernoeud_ATcb(&N ) ;
           Aff_struct1_Tcb(Str  , Caract(*Word , H ) ) ;
           Aff_struct2_Tcb(Str  , False ) ;
           Aff_info_ATcb(N , Str ) ;
           Aff_fg_ATcb(P , N ) ;
           P  =  N ;

         } ;
         Aff_struct2_Tcb(Str  , True ) ;
         Aff_info_ATcb(N , Str ) ;

       }
     }
    }
  /**********************************************************************/
  bool  Existe (string255 *Kalima , string2 *Harf)
    {
      /** Variables locales **/
      bool  Existe2 ;
      int Il;
      bool Trouv;

      /** Corps du module **/
     Existe2  =  False ;
     Trouv  =  False ;
     for( Il  =  1 ;Il <=  Longchaine(*Kalima ) ; ++Il) {
       if(strcmp( Caract(*Kalima , Il ), *Harf) == 0 ) {
         Existe2  =  True ;

       }
     }
     return Existe2 ;
    }
  /*********************************************************************/
  int  Emplacement (string255 *Chain , string2 *Ch)
    {
      /** Variables locales **/
      int  Emplacement2 ;
      int I;
      bool Trov;

      /** Corps du module **/
     if( Existe ( & *Chain , & *Ch )) {
       Emplacement2  =  0 ;
      /* si 0 et retourné alors la lettre n'existe pas dans le mot */
       I  =  1 ;
       Trov  =  False ;
       while( ( I <= Longchaine(*Chain ) ) && ! ( Trov ))  {
         if( (strcmp( Caract(*Chain , I ), *Ch) == 0  )) {
           Trov  =  True ;
           Emplacement2  =  I ;

         } ;
         I  =  I + 1 ;

       } ;

     }
     return Emplacement2 ;
    }
  /********************************************************************/
  /***********************************************************************/
  string255  Cpi_chaine (string255 *Chai , int *A , int *B)
    {
      /** Variables locales **/
      string255  Cpi_chaine2 ;
      int Iter;
      string255 Str_inter;
      string255 _Sx;

      /** Corps du module **/
     Str_inter = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     Cpi_chaine2 = malloc(255 * sizeof(string255));
     strcpy (Str_inter,   "") ;
     for( Iter  =  *A ;Iter <=  *B ; ++Iter){
       strcpy (_Sx, Str_inter);
       strcpy (Str_inter,  strcat(_Sx, Caract(*Chai , Iter ))) ;

     } ;
     strcpy (Cpi_chaine2,   Str_inter) ;

     return Cpi_chaine2 ;
    }
  /***************************************************************/
  /*  nombre d'occurence d'une lettre dans une chaine */

  int  Nb_occ (string255 *Sentence , string2 *Let)
    {
      /** Variables locales **/
      int  Nb_occ2 ;
      int I;

      /** Corps du module **/
     Nb_occ2  =  0 ;
     for( I  =  1 ;I <=  Longchaine(*Sentence ) ; ++I){
       if( (strcmp( Caract(*Sentence , I ), *Let) == 0  )) {
         Nb_occ2  =  Nb_occ2 + 1 ;

       }
     }
     return Nb_occ2 ;
    }
  /************************************************************/
  /* fonction qui verefie si le mot est valid selon req : requete donnée */

  bool  Valid (string255 *Tst , string255 *Req)
    {
      /** Variables locales **/
      bool  Valid2 ;
      string255 Tst_1;
      string255 Tst_inter;
      string255 Tst_term;
      string255 Pre_tst;
      string255 Fin_tst;
      string255 Pre_req;
      string255 Fin_req;
      string255 Req_1;
      string255 Req_inter;
      string255 Req_term;
      int Ik;
      int Jr;
      int Jm;
      bool Faute;
      bool Faute2;
      bool Check;
      string2 Eto;
      string2 Qs;
      int Occ;
      int Jk;
      int T;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;
      int _Px9;
      int _Px10;
      int _Px11;
      int _Px12;
      int _Px13;
      int _Px14;
      int _Px15;

      /** Corps du module **/
     Tst_1 = malloc(255 * sizeof(string255));
     Tst_inter = malloc(255 * sizeof(string255));
     Tst_term = malloc(255 * sizeof(string255));
     Pre_tst = malloc(255 * sizeof(string255));
     Fin_tst = malloc(255 * sizeof(string255));
     Pre_req = malloc(255 * sizeof(string255));
     Fin_req = malloc(255 * sizeof(string255));
     Req_1 = malloc(255 * sizeof(string255));
     Req_inter = malloc(255 * sizeof(string255));
     Req_term = malloc(255 * sizeof(string255));
     Eto = malloc(2 * sizeof(string2));
     Qs = malloc(2 * sizeof(string2));
     strcpy (Eto,   "*") ;
     strcpy (Qs,   "?") ;
     Valid2  =  True ;
     if(strcmp( Caract(*Tst , 1 ), Caract(*Req , 1 )) != 0 ) {
       Valid2  =  False ;
       }
     else
       {
       if( ( ! ( Existe ( & *Req , & Eto ) ) && ! ( Existe ( & *Req , & Qs ) ) && (strcmp( *Tst, *Req) != 0  ) )) {
         Valid2  =  False ;
         }
       else
         {
        /* 2eme cas */
         if( ! ( Existe ( & *Req , & Eto ) )) {
           if( ( Longchaine(*Tst ) != Longchaine(*Req ) )) {
             Valid2  =  False ;
             }
          /*cas avec des ? seulement  */
           else
             {
             Ik  =  2 ;
             Faute  =  False ;
             while( ( ( Ik <= Longchaine(*Tst ) ) && ( Faute == False ) )) {
               ;
               if(strcmp( Caract(*Req , Ik ), Qs) == 0 ) {
                 Ik  =  Ik + 1 ;
                 }
               else
                 {
                 if(strcmp( Caract(*Tst , Ik ), Caract(*Req , Ik )) != 0 ) {
                   Valid2  =  False ;
                   Faute  =  True ;
                   }
                 else
                   {
                   Ik  =  Ik + 1 ;

                 }
               }
             }
           } }
        /* existence de *        dans la requete  */
         else
           {
           if( ( Nb_occ ( & *Req , & Eto ) == 1 )) {
             if( Emplacement ( & *Req , & Eto ) == Longchaine(*Req )) {
               _Px1 =  1 ;
               _Px2 =  Longchaine(*Req ) - 1 ;
               strcpy (Req_1,   Cpi_chaine ( & *Req , &_Px1, &_Px2)) ;
               _Px3 =  1 ;
               _Px4 =  Longchaine(*Req ) - 1 ;
               strcpy (Tst_1,   Cpi_chaine ( & *Tst , &_Px3, &_Px4)) ;
               Valid2  =  Valid ( & Tst_1 , & Req_1 ) ;
               }
             else
               {
               _Px5 =  1 ;
               _Px6 =  Emplacement ( & *Req , & Eto ) - 1 ;
               strcpy (Req_inter,   Cpi_chaine ( & *Req , &_Px5, &_Px6)) ;
               _Px7 =  1 ;
               _Px8 =  Emplacement ( & *Req , & Eto ) - 1 ;
               strcpy (Tst_inter,   Cpi_chaine ( & *Tst , &_Px7, &_Px8)) ;
               _Px9 =  Emplacement ( & *Req , & Eto ) + 1 ;
               _Px10 =  Longchaine(*Req ) ;
               strcpy (Req_term,   Cpi_chaine ( & *Req , &_Px9, &_Px10)) ;
               _Px11 =  Longchaine(*Tst ) - Longchaine(Req_term ) + 1 ;
               _Px12 =  Longchaine(*Tst ) ;
               strcpy (Tst_term,   Cpi_chaine ( & *Tst , &_Px11, &_Px12)) ;
               Valid2  =  Valid ( & Tst_inter , & Req_inter ) && Valid ( & Tst_term , & Req_term );
             } }
          /* existence multiple */
           else
             {
             Jr  =  1 ;
             Jm  =  1 ;
             Check  =  False ;
             while( ( Jr <= Longchaine(*Req ) ) && ( ! Check ))  {
               if( (strcmp( Caract(*Req , Jr ), Qs) == 0  ))   {
                 Jm  =  Jm + 1 ;
                 }
               else
                 {
                 if( (strcmp( Caract(*Req , Jr ), Eto) == 0  ))   {
                   T  =  Jm ;
                   while( ( ( T <= ( Longchaine(*Tst ) + 1 ) ) && ( ! Check ) ))  {
                     _Px13 =  Longchaine(*Tst ) ;
                     strcpy (Tst_inter,   Cpi_chaine ( & *Tst , & T , &_Px13)) ;
                     _Px14 =  Jr + 1 ;
                     _Px15 =  Longchaine(*Req ) ;
                     strcpy (Req_inter,   Cpi_chaine ( & *Req , &_Px14, &_Px15)) ;
                     if( Valid ( & Tst_inter , & Req_inter )) {
                       Valid2  =  True ;
                       Check  =  True ;

                     } ;
                     T  =  T + 1 ;

                   } ;
                   if( ( ! Check ))   {
                     Valid2  =  False ;
                     Check  =  True ;

                   } ;
                   }
                 else
                   {
                   if( ( Jm > Longchaine(*Tst ) ))   {
                     Valid2  =  False ;
                     Check  =  True ;
                     }
                   else
                     {
                     Check  =  True;
                   }
                 }
               }
             } ;

           }
         }
       }
     }
     return Valid2 ;
    }
  /***********************************************************************/
  void Requete (Pointeur_ATcb *Ptr2 , string255 *Resultat2 , string255 *Research , bool *Trouv_t)
    {
      /** Variables locales **/
      Pointeur_ATcb K;
      Typestr_Tcb Str;
      string255 Resultat2_1;
      string255 _Sx;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     Resultat2_1 = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     if( ( *Ptr2 != NULL )) {
       strcpy (Resultat2_1,   *Resultat2) ;
       strcpy (_Sx, *Resultat2);
       strcpy (*Resultat2,  strcat(_Sx, Card ( & *Ptr2 ))) ;
       if( ( Bool ( & *Ptr2 ) == True )) {
         if( ( Valid ( & *Resultat2 , & *Research ) )) {
           *Trouv_t  =  True ;
           printf ( " %s", *Resultat2 ) ;

         } ;

       } ;
       _Px1 =  Fg_ATcb(*Ptr2 ) ;
       Requete ( &_Px1, & *Resultat2 , & *Research , & *Trouv_t ) ;
       _Px2 =  Fd_ATcb(*Ptr2 ) ;
       Requete ( &_Px2, & Resultat2_1 , & *Research , & *Trouv_t ) ;

     }
    }
  void Intro (int *K)
    {

      /** Corps du module **/
     printf ( "                %s \n", "**************************************************" ) ;
     printf ( "                %s \n", "** Republique Algerienne Democratique Populaire**" ) ;
     printf ( "                %s \n", "**         TP 2 - ALSDD - 2019                 **" ) ;
     printf ( "                %s \n", "**                PAR                          **" ) ;
     printf ( "                %s \n", "**         BENAZIZA Chems Eddine               **" ) ;
     printf ( "                %s \n", "**                  &                          **" ) ;
     printf ( "                %s \n", "**         BENAKMOUM Oussama                   **" ) ;
     printf ( "                %s \n", "**         GROUPE : 07                         **" ) ;
     printf ( "                %s \n", "**************************************************" ) ;

    }
      void ins_dectionnaire ()
  {
    R = malloc(sizeof(Typestr_Tcb));
    R->Champ1 = malloc(2 * sizeof(string2));
#define TAILLE_MAX 1000
    Pointeur_ATcb p;
    p = NULL;
    FILE* fichier = NULL;
    string255 chaine;
    chaine = malloc(255 * sizeof(string255));
    fichier = fopen("dectionnaire.txt", "r");
   while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
    Insertion(& p ,& chaine);
    }
   string255 chaine2 = "";
   chaine2 = malloc(255 * sizeof(string255));
    Parcour(&p,&chaine2);
    //fclose(fichier);

    return 0;
  }




  int main(int argc, char *argv[])
    {
    int choix;
    Intro ( &_Px1) ;
    printf("\n\n");
    printf("\n faites votre choix : \n ");
    printf("  1-generer des mots aleatoires. \n");
    printf("   2-utilser le dictionnare. \n");
    printf("choix : ");
    scanf("%d",&choix);
        if (choix == 1){
     printf("  ************************************************************************************************************");
     printf("\n  on va generer, afficher, faire des requetes de recherche dans 10 arbres differents.(attention au MAJISCULE)* \n");
     printf("  ************************************************************************************************************\n");
     system("PAUSE");

     R = malloc(sizeof(Typestr_Tcb));
     R->Champ1 = malloc(2 * sizeof(string2));
     Mot1 = malloc(255 * sizeof(string255));
     Requitous = malloc(255 * sizeof(string255));
     Inter = malloc(255 * sizeof(string255));
     Str = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     _Px1 =  3 ;
     for( Nbr_arbre  =  1 ;Nbr_arbre <=  10 ; ++Nbr_arbre){
       printf ( " %s", "\n _____________________________________________________________________________________________________ \n" ) ;
       printf ( " %s", "Arbre ---> " );
       printf ( " %d", Nbr_arbre ) ;
       S  =  NULL ;
       strcpy (Requitous,   "") ;
       printf ( "\n %s \n", " LES MOTS GENERES :  " ) ;
       for( Nbr_mot  =  1 ;Nbr_mot <=  15 ; ++Nbr_mot){
         strcpy (Str,   Aleachaine(Aleanombre(10 ) + 1 )) ;
         Insertion ( & S , & Str ) ;
         strcpy (_Sx, "->");
         strcpy (Str,  strcat(_Sx, Str)) ;
         printf ( " %s", Str ) ;

       } ;
       strcpy (Mot1,   "") ;
       printf ( "\n %s \n", "Les mots lus en ordre de l arbre : " ) ;
       printf ( " %s", "" ) ;
       Parcour ( & S , & Mot1 ) ;
       printf ( "\n %s \n", "*********************************************" ) ;
       printf ( " %s", "Saisir la requete  :  " ) ;
       while( (strcmp( Requitous, "") == 0  ))  {
         scanf ( " %[^\n]", Requitous ) ;

       } ;
       strcpy (Inter,   "") ;
       Trouv_s  =  False ;
      /*   Initialiser une variable intermediaire */
       Requete ( & S , & Inter , & Requitous , & Trouv_s ) ;
       if( ( Trouv_s == False ))   {
         printf ( " %s", "il n existe aucun mot qui convient a votre requete ):" ) ;

       } ;
       printf ( " %s", "" ) ;
       printf ( " %s", "\n ****************************************** \n" ) ;

     } ;
     }
    else {printf("\n les mots generés du dictionnaire : \n");
            ins_dectionnaire();}


      system("PAUSE");
      return 0;
    }
