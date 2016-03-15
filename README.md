# TP THREADS POSIX
Team : Goodwin Jean-Paul & Ahmed Sahim

Ce readme contient le compte rendu des exercices de la partie TD

#Exercice 1

1)</br>
Les actions Ai ne sont jamais simultanées.</br>
Nous avons besoin "d'un chapeau" + "un jeton" (modelisation des sémaphores)</br>
p = prendre un jeton     v=mettre un jeton</br>
Il faut initialiser p1, qui met directement un jeton</br>


p1 : V(S1) loop     p(S1) , A1,V(S1) end loop</br>
p2 : loop           p(S1) , A2,V(S1) end loop</br>
p3 : loop           p(S1) , A3,V(S1) end loop</br></br>

problème : si les 3 processus veulent un jeton il faudra prendre 3 chapeaux</br>
  
2)</br>
p1 : V(S1) loop     P(S1), A1, V(S2) end loop</br>
p1 : loop           P(S1), A1, V(S2) end loop</br>
p1 : loop           P(S1), A1, V(S2) end loop</br></br>


3)</br>
p1 : V(S1) loop     P(S1), A1, V(S2) end loop</br>
p2 : loop           P(S2), A2, V(S1) end loop</br>
p3 : loop           P(S2), A3, V(S1) end loop</br>


5)(question bonus)</br>
p1 : V(S1) loop V(S123) V(S123) V(S123)     P(S123), P(S1), A1, V(S1), P(S23), P(S23) end loop</br>
p2 : loop                                   P(S123), P(S1), P(S1), A2, V(S1), V(S23) end loop</br>
p3 : loop                                   P(S123), P(S123), P(S1), A3, V(S1) V(S23) end loop</br>

#Exercice 2





