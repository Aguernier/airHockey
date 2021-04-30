#include <Arduino.h>
#include "Player.h"
#include "SevenSegments.h"
#include "SerialMP3Player.h"

using namespace Aguernier;

SevenSegments displayPlayer1(11, 10, 9, 22, 24, A2, A3, 0); 
SevenSegments displayPlayer2(2, 3, 4, 5, 6, 7, 8, 1);

Player player1(displayPlayer1, 13); 
Player player2(displayPlayer2, 12);

int Relay1 = A1;
#define REVERSELOW HIGH
#define REVERSEHIGH LOW

#define TX_MUSIC 27
#define RX_MUSIC 26

#define TX_ACTION 31
#define RX_ACTION 30

#define MUSIC_FOLDER 01

/**
 * MUSIC 
 */
#define MONSTER_KILL 1
#define UNSTOPABLE 2
#define GOD_LIKE 3
#define HOLY_SHIT 4
#define PREPARE_TO_FIGHT 5
#define FIRST_BLOOD 6 
#define HUMILATION 7
#define HEADSHOT 8
#define DOMINATING 9
#define RAMPAGE 10
#define MULTI_KILL 11
#define PERFECT 12
#define KILLING_SPREE 13

SerialMP3Player mp3Music(RX_MUSIC,TX_MUSIC);
SerialMP3Player mp3Action(RX_ACTION,TX_ACTION);

/*#define TX 11
#define RX 10

SerialMP3Player mp3Music(RX,TX);*/

void setup() {
    Serial.begin(9600);
    mp3Music.begin(9600);
    mp3Action.begin(9600);

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB.
    }

    player1.displayScore();
    player2.displayScore();

    pinMode(Relay1, OUTPUT);
    digitalWrite(Relay1, REVERSELOW);
    
    mp3Music.setVol(20);
    mp3Music.qVol();

    mp3Action.setVol(20);
    mp3Action.qVol();

    mp3Music.qTTracks();

    int randomSong = rand() % 10 + 1;

    mp3Music.play();
    mp3Action.play(PREPARE_TO_FIGHT);

}

void loop() {

    if (player1.getScore() >= 0 || player1.getScore() < 10) {
        player1.displayScore();
        delay(10);
    }

    if (player2.getScore() >= 0 || player2.getScore() < 10) {
        player2.displayScore();
        delay(10);
    }

    // on ajout le score quand le bouton est poussé
    //player1.addSensorListener();
    //player2.addSensorListener();
    
    if (player1.scored() == true || player2.scored() == true) {
        int diffScore = Player::diffScore(player1.getScore(), player2.getScore());
        Serial.print(diffScore);
        if (diffScore == 1 && (player1.getScore() == 0 || player2.getScore() == 0)) {
            mp3Action.play(FIRST_BLOOD);
        } else {
            switch (diffScore)
            {
                case 0:
                    mp3Action.play(KILLING_SPREE);
                case 1:
                case -9:
                    mp3Action.play(HEADSHOT);
                    break;
                case 2:
                case -8:
                    mp3Action.play(HOLY_SHIT);
                    break;
                case 3:
                case -7:
                    mp3Action.play(KILLING_SPREE);
                    break;
                case 4:
                case -6:
                    mp3Action.play(RAMPAGE);
                    break;
                case 5:
                case -5:
                    mp3Action.play(HUMILATION);
                    break;
                case 6:
                case -4:
                    mp3Action.play(DOMINATING);
                    break;
                case 7:
                case -3:
                    mp3Action.play(RAMPAGE);
                    break;
                case 8:
                case -2:
                    mp3Action.play(MONSTER_KILL);
                    break;
                case 9:
                case -1:
                    mp3Action.play(GOD_LIKE);
                    break;
                default:
                    break;
            }
        }
    }

   /*if (player2.scored() == true) {
        int diffScore = Player::diffScore(player1.getScore(), player2.getScore());
        Serial.print(diffScore);
    }*/

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

        mp3Action.play(PREPARE_TO_FIGHT);
    }
}