
   SOIT
       Insertion , Parcour , Inserer_inferieur , Insertion_egale UNE ACTION ;
       R UNE STRUCTURE ( CAR , BOOLEEN ) ;
       S DES POINTEURS VERS ARB DE ( CAR , BOOLEEN ) ;
       Card : FONCTION ( CAR ) ;
       Bool : FONCTION ( BOOLEEN ) ;
       Mot1 : CHAINE ;
      
   DEBUT
       S := NIL ;
       APPEL Insertion ( S , 'dez' ) ;
       APPEL Insertion ( S , 'ac' ) ;
       APPEL Insertion ( S , 'acb' ) ;
       APPEL Insertion ( S , 'ay' ) ;
       APPEL Insertion ( S , 'a' ) ;
       APPEL Insertion ( S , 'az' ) ;
       APPEL Insertion ( S , 'ab' ) ;
       APPEL Insertion ( S , 'ayzz' ) ;
       APPEL Insertion ( S , 'azerty' ) ;
       Mot1 := '' ;
       APPEL Parcour ( S , Mot1 ) ;
      
   FIN
  /******************************************************************************/
   ACTION Insertion ( Racine , Mot )
   SOIT
       Racine , P , N DES POINTEURS VERS ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Mot UNE CHAINE ;
       I : ENTIER ;
      
   DEBUT
  /*1er CAS : elle est vide*/
       SI ( Racine = NIL )
           CREERNOEUD ( Racine ) ;
           AFF_STRUCT ( Str , 1 , CARACT ( Mot , 1 ) ) ;
           AFF_STRUCT ( Str , 2 , FAUX ) ;
           AFF_INFO ( Racine , Str ) ;
           P := Racine ;
           POUR I := 2 , LONGCHAINE ( Mot )
               CREERNOEUD ( N ) ;
               AFF_STRUCT ( Str , 1 , CARACT ( Mot , I ) ) ;
               AFF_STRUCT ( Str , 2 , FAUX ) ;
               AFF_INFO ( N , Str ) ;
               AFF_FG ( P , N ) ;
               P := N ;
              
           FPOUR ;
           AFF_FG ( P , NIL ) ;
           AFF_FD ( P , NIL ) ;
           AFF_STRUCT ( Str , 2 , VRAI ) ;
           AFF_INFO ( P , Str ) ;
          
       SINON
           SI ( Card ( Racine ) > CARACT ( Mot , 1 ) )
               CREERNOEUD ( P ) ;
               AFF_FD ( P , Racine ) ;
               Racine := P ;
               AFF_STRUCT ( Str , 1 , CARACT ( Mot , 1 ) ) ;
               SI ( LONGCHAINE ( Mot ) = 1 )
                   AFF_FG ( Racine , NIL ) ;
                   AFF_STRUCT ( Str , 2 , VRAI ) ;
                   AFF_INFO ( Racine , Str ) ;
                  
               SINON
                   AFF_STRUCT ( Str , 2 , FAUX ) ;
                   AFF_INFO ( Racine , Str ) ;
                   P := Racine ;
                   POUR I := 2 , LONGCHAINE ( Mot )
                       CREERNOEUD ( N ) ;
                       AFF_STRUCT ( Str , 1 , CARACT ( Mot , I ) ) ;
                       AFF_STRUCT ( Str , 2 , FAUX ) ;
                       AFF_INFO ( N , Str ) ;
                       AFF_FG ( P , N ) ;
                       P := N ;
                      
                   FPOUR ;
                   AFF_STRUCT ( Str , 2 , VRAI ) ;
                   AFF_INFO ( P , Str ) ;
                   AFF_FG ( P , NIL ) ;
                   AFF_FD ( P , NIL ) ;
                  
               FSI
           SINON
               SI ( Card ( Racine ) < CARACT ( Mot , 1 ) )
                   APPEL Inserer_inferieur ( Racine , Mot , 1 ) ;
                  
               SINON
                   APPEL Insertion_egale ( Racine , Mot , 1 ) ;
                  
               FSI
           FSI
       FSI ;
      
   FIN
  /******************************************************************************/
   ACTION Parcour ( Zegour , Resultat )
   SOIT
       Zegour , K DES POINTEURS VERS ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Resultat , Resultat_1 : CHAINE ;
      
   DEBUT
       SI ( Zegour # NIL )
           Resultat_1 := Resultat ;
           Resultat := Resultat + Card ( Zegour ) ;
           SI ( Bool ( Zegour ) = VRAI )
               ECRIRE ( Resultat ) ;
              
           FSI ;
           APPEL Parcour ( FG ( Zegour ) , Resultat ) ;
           APPEL Parcour ( FD ( Zegour ) , Resultat_1 ) ;
          
       FSI ;
      
   FIN
  /******************************************************************************/
   FONCTION Card ( Root2 ) : CAR
   SOIT
       Root2 UN POINTEUR VERS ARB DE ( CAR , BOOLEEN ) ;
      
   DEBUT
       Card := STRUCT ( INFO ( Root2 ) , 1 ) ;
      
   FIN
  /******************************************************************************/
   FONCTION Bool ( Root3 ) : BOOLEEN
   SOIT
       Root3 UN POINTEUR VERS ARB DE ( CAR , BOOLEEN ) ;
      
   DEBUT
       Bool := STRUCT ( INFO ( Root3 ) , 2 ) ;
      
   FIN
  /******************************************************************************/
   ACTION Inserer_inferieur ( Ptr , Expression , I )
   SOIT
       Ptr , N , Q , S , T DES POINTEURS VERS ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Expression UNE CHAINE ;
       I , J : ENTIER ;
       Test : BOOLEEN ;
      
   DEBUT
       N := Ptr ;
       Q := Ptr ;
       Test := FAUX ;
       TANTQUE ( FD ( N ) # NIL ) ET ( Test = FAUX ) :
           SI ( Card ( FD ( N ) ) < CARACT ( Expression , I ) )
               Q := N ;
               N := FD ( N ) ;
              
           SINON
               Test := VRAI ;
              
           FSI
       FINTANTQUE ;
       SI ( FD ( N ) # NIL )
           SI ( Card ( FD ( N ) ) = CARACT ( Expression , I ) )
               APPEL Insertion_egale ( FD ( N ) , Expression , I ) ;
              
           SINON
               CREERNOEUD ( S ) ;
               AFF_STRUCT ( Str , 1 , CARACT ( Expression , I ) ) ;
               AFF_STRUCT ( Str , 2 , FAUX ) ;
               AFF_INFO ( S , Str ) ;
               Q := FD ( N ) ;
               AFF_FD ( N , S ) ;
               AFF_FD ( S , Q ) ;
               SI ( LONGCHAINE ( Expression ) - I + 1 > 1 )
                   POUR J := I + 1 , LONGCHAINE ( Expression )
                       CREERNOEUD ( T ) ;
                       AFF_STRUCT ( Str , 1 , CARACT ( Expression , J ) ) ;
                       AFF_STRUCT ( Str , 2 , FAUX ) ;
                       AFF_INFO ( T , Str ) ;
                       AFF_FG ( S , T ) ;
                       AFF_FD ( T , NIL ) ;
                       S := T ;
                      
                   FPOUR ;
                  
               FSI ;
               AFF_STRUCT ( Str , 2 , VRAI ) ;
               AFF_INFO ( S , Str ) ;
               AFF_FG ( S , NIL ) ;
              
           FSI
       SINON
           CREERNOEUD ( S ) ;
           AFF_STRUCT ( Str , 1 , CARACT ( Expression , I ) ) ;
           AFF_STRUCT ( Str , 2 , FAUX ) ;
           AFF_INFO ( S , Str ) ;
           Q := FD ( N ) ;
           AFF_FD ( N , S ) ;
           AFF_FD ( S , Q ) ;
           SI ( LONGCHAINE ( Expression ) - I + 1 > 1 )
               POUR J := I + 1 , LONGCHAINE ( Expression )
                   CREERNOEUD ( T ) ;
                   AFF_STRUCT ( Str , 1 , CARACT ( Expression , J ) ) ;
                   AFF_STRUCT ( Str , 2 , FAUX ) ;
                   AFF_INFO ( T , Str ) ;
                   AFF_FG ( S , T ) ;
                   AFF_FD ( T , NIL ) ;
                   S := T ;
                  
               FPOUR ;
              
           FSI ;
           AFF_STRUCT ( Str , 2 , VRAI ) ;
           AFF_INFO ( S , Str ) ;
           AFF_FG ( S , NIL ) ;
          
       FSI
   FIN
  /******************************************************************************/
   ACTION Insertion_egale ( Pointer , Word , K )
   SOIT
       Pointer , R , Per , P , N DES POINTEURS VERS ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Word UNE CHAINE ;
       K , J , H : ENTIER ;
       Sortir : BOOLEEN ;
      
   DEBUT
       J := K ;
       R := Pointer ;
       Sortir := FAUX ;
       TANTQUE ( R # NIL ) ET ( J <= LONGCHAINE ( Word ) ) ET ( Sortir = FAUX ) :
           SI ( Card ( R ) = CARACT ( Word , J ) )
               Per := R ;
               R := FG ( R ) ;
               J := J + 1 ;
              
           SINON
               Sortir := VRAI ;
              
           FSI
       FINTANTQUE ;
       SI ( J > LONGCHAINE ( Word ) )
           AFF_STRUCT ( Str , 1 , CARACT ( Word , J - 1 ) ) ;
           AFF_STRUCT ( Str , 2 , VRAI ) ;
           AFF_INFO ( Per , Str ) ;
          
       SINON
           SI ( R # NIL )
               SI ( Card ( R ) > CARACT ( Word , J ) )
                   P := Per ;
                   POUR H := J , LONGCHAINE ( Word )
                       CREERNOEUD ( N ) ;
                       AFF_STRUCT ( Str , 1 , CARACT ( Word , H ) ) ;
                       AFF_STRUCT ( Str , 2 , FAUX ) ;
                       AFF_INFO ( N , Str ) ;
                       AFF_FG ( P , N ) ;
                       P := N ;
                      
                   FPOUR ;
                   AFF_STRUCT ( Str , 2 , VRAI ) ;
                   AFF_INFO ( N , Str ) ;
                   AFF_FG ( N , NIL ) ;
                   AFF_FD ( N , NIL ) ;
                   AFF_FD ( FG ( Per ) , R ) ;
                  
               SINON
                   APPEL Inserer_inferieur ( R , Word , J ) ;
                  
               FSI
           SINON
               P := Per ;
               POUR H := J , LONGCHAINE ( Word )
                   CREERNOEUD ( N ) ;
                   AFF_STRUCT ( Str , 1 , CARACT ( Word , H ) ) ;
                   AFF_STRUCT ( Str , 2 , FAUX ) ;
                   AFF_INFO ( N , Str ) ;
                   AFF_FG ( P , N ) ;
                   P := N ;
                  
               FPOUR ;
               AFF_STRUCT ( Str , 2 , VRAI ) ;
               AFF_INFO ( N , Str ) ;
              
           FSI
       FSI
   FIN
