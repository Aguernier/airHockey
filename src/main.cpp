#include <Arduino.h>
#include "Player.h"
#include "SevenSegments.h"

using namespace Aguernier;

Player player1, player2;
SevenSegments displayPlayer1(11, 10, 9, 22, 24, A2, A3, 0); 
SevenSegments displayPlayer2(2, 3, 4, 5, 6, 7, 8, 1);

void setup() {


    Serial.begin(9600);

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB.
    }

    // put your setup code here, to run once:
    displayPlayer2.displayNomber(0);
    displayPlayer1.displayNomber(0);
}

void loop() {

    // put your main code here, to run repeatedly:
}