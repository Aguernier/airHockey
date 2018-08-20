#include <Arduino.h>
#include "Player.h"
#include "SevenSegments.h"

using namespace Aguernier;

SevenSegments displayPlayer1(11, 10, 9, 22, 24, A2, A3, 0); 
SevenSegments displayPlayer2(2, 3, 4, 5, 6, 7, 8, 1);

Player player1(displayPlayer1, 13); 
Player player2(displayPlayer2, 12);

int Relay1 = A1;
#define REVERSELOW HIGH
#define REVERSEHIGH LOW

void setup() {
    Serial.begin(9600);

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB.
    }

    player1.displayScore();
    player2.displayScore();

    pinMode(Relay1, OUTPUT);
    digitalWrite(Relay1, REVERSELOW);
}

void loop() {

    player1.addSensorListener();
    player2.addSensorListener();
    
    if (player1.getScore() == 9 || player2.getScore() == 9) {
        int cpt = 0;

        digitalWrite(Relay1, REVERSEHIGH);

        while (cpt < 50) {
            player1.displayScore();
            delay(25);
            player1.display(-1);
            delay(25);

            player2.displayScore();
            delay(25);
            player2.display(-1);
            delay(25);

            cpt++;
        }

        digitalWrite(Relay1, REVERSELOW);

        player1.resetScore();
        player2.resetScore();
    }

    if (player1.getScore() >= 0 || player1.getScore() < 10) {
        player1.displayScore();
        delay(10);
    }

    if (player2.getScore() >= 0 || player2.getScore() < 10) {
        player2.displayScore();
        delay(10);
    }
}