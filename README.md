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
1) Ordre d'exécution  : A1 -> A2 -> B1 -> B2 </br></br>

2)P(X){ </br>
call toto  </br>
if(X==0)V(S1)  </br>
P(S1) </br>
compteur ++; </br>
V(S1) </br> </br>

while(compteur!=N)
if (X==0) P(S1),V(S2)  </br>
P(S2) </br>
compteur -- ; </br>
V(S2); </br>
Call ls </br>
}

#MSI, MESI
<table>
<tr>
  <td>Action processeur</td><td>Etat P1</td><td>Etat P2</td><td>Etat P3</td><td>Action Bus</td><td>Origine donnée</td>
</tr>
<tr>
  <td>1</td><td>S</td><td></td><td></td><td>BusRd</td><td>Mémoire</td>
</tr>
<tr>
  <td>2</td><td>S</td><td></td><td>S</td><td>BusRd</td><td>Bus(P1)</td>
</tr>
<tr>
  <td>3</td><td>I</td><td></td><td>M</td><td>BusRd</td><td>P3</td>
</tr>
<tr>
  <td>4</td><td>S</td><td></td><td>S</td><td>BusRd+flush</td><td>Bus(P3)</td>
</tr>
<tr>
  <td>5</td><td>S</td><td>S</td><td>S</td><td>BusRd</td><td>Bus(P2/P3)</td>
</tr>
</table>
<br></br>

<table>
<tr>
  <td>Action processeur</td><td>Etat P1</td><td>Etat P2</td><td>Etat P3</td><td>Action Bus</td><td>Origine donnée</td>
</tr>
<tr>
  <td>1</td><td>E</td><td></td><td></td><td>BusRd</td><td>Mémoire</td>
</tr>
<tr>
  <td>2</td><td>S</td><td></td><td>E</td><td>BusRd</td><td>Bus(P1)</td>
</tr>
<tr>
  <td>3</td><td>I</td><td></td><td>M</td><td>BusRdx</td><td>P3</td>
</tr>
<tr>
  <td>4</td><td>E</td><td></td><td>S</td><td>BusRd+flush</td><td>Bus(P3)</td>
</tr>
<tr>
  <td>5</td><td>S</td><td>S</td><td>S</td><td>BusRd+flush(P1)+flush(P3)</td><td>Bus(P1/P3)</td>
</tr>
</table>








