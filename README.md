# TP THREADS POSIX
Team : Goodwin Jean-Paul & Ahmed Sahim

Ce readme contient le compte rendu des exercices de la partie TD

#Exercice 1

1) 
Les actions Ai ne sont jamais simultanées.
Nous avons besoin "d'un chapeau" + "un jeton" (modelisation des sémaphores)
p = prendre un jeton     v=mettre un jeton

Il faut initialiser p1, qui met directement un jeton
p1 : V(S1) loop     p(S1) , A1,V(S1) end loop
p2 : loop           p(S1) , A2,V(S1) end loop
p3 : loop           p(S1) , A3,V(S1) end loop
problème : si les 3 processus veulent un jeton il faudra prendre 3 chapeaux
  
2)

p1 : V(S1) loop     P(S1), A1, V(S2) end loop
p1 : loop           P(S1), A1, V(S2) end loop
p1 : loop           P(S1), A1, V(S2) end loop

3)
p1 : V(S1) loop     P(S1), A1, V(S2) end loop
p2 : loop           P(S2), A2, V(S1) end loop
p3 : loop           P(S2), A3, V(S1) end loop

5) (question bonus)
p1 : V(S1) loop V(S123) V(S123) V(S123)     P(S123), P(S1), A1, V(S1), P(S23), P(S23) end loop
p2 : loop                                   P(S123), P(S1), P(S1), A2, V(S1), V(S23) end loop
p3 : loop                                   P(S123), P(S123), P(S1), A3, V(S1) V(S23) end loop

#Exercice 2




