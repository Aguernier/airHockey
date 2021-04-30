#include "Player.h"
#include "Arduino.h"

namespace Aguernier 
{
    Player::Player(SevenSegments sevenSegments, int sensor) : m_sevenSegments(sevenSegments), m_sensor(sensor)
    {
        pinMode(m_sensor, INPUT);
        m_push = false;
    }

    void Player::addScore()
    {
        m_score++;
    }

    int Player::getScore()
    {
        return m_score;
    }

    void Player::resetScore()
    {
        m_score = 0;
    }

    void Player::displayScore()
    {
        m_sevenSegments.displayNomber(m_score);
    }

    void Player::display(int number)
    {
        m_sevenSegments.displayNomber(number);
    }

    void Player::addSensorListener()
    {
        if (digitalRead(m_sensor) == 1) {
            m_push = true;
        }
        if (m_push == true && digitalRead(m_sensor) == 0) {
            addScore();
            m_push = false;
        }
    }

    bool Player::scored()
    {
        if (digitalRead(m_sensor) == 1) {
            m_push = true;
            return false;
        }
        if (m_push == true && digitalRead(m_sensor) == 0) {
            addScore();
            m_push = false;
            return true;
        }
        return false;
    }

    int Player::diffScore(int score1, int score2) 
    {
        /* if (score2 > score1) {
            return score2 - score1;
        } */
        return score1 - score2;
    }
}



