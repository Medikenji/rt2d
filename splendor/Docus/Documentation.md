# Splendor projectplan

## Nolan Bijmholt

##### Inhoud

- Spel idee
- Assets en visuele ideeën
- Klassendiagram

---

### Spel idee

Ik wil een 2D rogue lite maken waarin de speler vrij over 2 assen kan bewegen.
Er zijn meerdere typen vijanden die proberen de speler aan te raken door naar zijn positie te gaan.
Er is een punten systeem. Je begint met 0 punten en 1 vijand in de scène. Wanneer je alle vijanden hebt uitgeschakeld krijg je 1 punt en neemt de moeilijkheidsgraad toe.

**_Dit gebeurt door:_**

**1. Het aantal vijanden gaat omhoog.**

- Het spel begint dus met 1 vijand en dit zal op lopen tot een maximaal aantal. Het type vijand zal door blijven veranderen.

**2. Het vijand type wordt lastiger.**

- Ik heb tot nu toe 4 verschillende vijand typen. Deze voegen variatie toe. Ook kun je niet visueel zien welk type een vijand is kun je dit wel merken door hoe die beweegt.

**3. De snelheid van het spel gaat omhoog.**

- Er is een vermenigvuldiger voor de snelheid van de speler en vijanden die omhoog gaat om de pacing van het spel omhoog te brengen.

Je schakelt vijanden uit door jouw muis of de lijn die van de speler naar de muis wordt getrokken over de vijanden te leggen. Dit moet voor een kort aantal seconden voordat ze verdwijnen.
Ik hoop dat ik met deze gameplay componenten een simpel maar ook interessant en leuk spel te kan maken.

---

### Assets en visuele ideeën

Ik heb maar 2 assets nodig voor dit spel.

#### De speler sprite:

![playerspriteimage](Documentation_Files\player.png "playery.png")

#### De vijand sprite:

![enemyspriteimage](Documentation_Files\enemy.png "enemy.png")

Deze sprites zijn best klein op het scherm en daarom zijn ze simplistisch. De vijand flikkerd ook snel en daarom bestaat hij uit alle RGB kleuren tegelijk voor een in mijn ogen interessant effect.

---

### Klassendiagram

![klassendiagram](Documentation_Files\klassendiagram.png "klassendiagram 06-12-23")
