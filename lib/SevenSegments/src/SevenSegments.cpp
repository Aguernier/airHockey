#include "SevenSegments.h"
#include "Arduino.h"

namespace Aguernier
{
    SevenSegments::SevenSegments(int A, int B, int C, int D, int E, int F, int G, int type):
    m_A(A), m_B(B), m_C(C), m_D(D), m_E(E), m_F(F), m_G(G), m_type(type)
    {
        pinMode(m_A, OUTPUT);
        pinMode(m_B, OUTPUT);
        pinMode(m_C, OUTPUT);
        pinMode(m_D, OUTPUT);
        pinMode(m_E, OUTPUT);
        pinMode(m_F, OUTPUT);
        pinMode(m_G, OUTPUT);
    }

    void SevenSegments::displayNomber(int number)
    {
        int on, off;
        if (m_type == 0) {
            on = HIGH;
            off = LOW;
        } else {
            on = LOW;
            off = HIGH;
        }

        switch (number) {
            case 0:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, on);
            digitalWrite(m_F, on);
            digitalWrite(m_G, off);
            break;

            case 1:
            digitalWrite(m_A, off);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, off);
            digitalWrite(m_E, off);
            digitalWrite(m_F, off);
            digitalWrite(m_G, off);
            break;

            case 2:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, off);
            digitalWrite(m_D, on);
            digitalWrite(m_E, on);
            digitalWrite(m_F, off);
            digitalWrite(m_G, on);
            break;

            case 3:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, off);
            digitalWrite(m_F, off);
            digitalWrite(m_G, on);
            break;

            case 4:
            digitalWrite(m_A, off);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, off);
            digitalWrite(m_E, off);
            digitalWrite(m_F, on);
            digitalWrite(m_G, on);
            break;

            case 5:
            digitalWrite(m_A, on);
            digitalWrite(m_B, off);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, off);
            digitalWrite(m_F, on);
            digitalWrite(m_G, on);
            break;

            case 6:
            digitalWrite(m_A, on);
            digitalWrite(m_B, off);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, on);
            digitalWrite(m_F, on);
            digitalWrite(m_G, on);
            break;

            case 7:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, off);
            digitalWrite(m_E, off);
            digitalWrite(m_F, off);
            digitalWrite(m_G, off);
            break;

            case 8:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, on);
            digitalWrite(m_F, on);
            digitalWrite(m_G, on);
            break;

            case 9:
            digitalWrite(m_A, on);
            digitalWrite(m_B, on);
            digitalWrite(m_C, on);
            digitalWrite(m_D, on);
            digitalWrite(m_E, off);
            digitalWrite(m_F, on);
            digitalWrite(m_G, on);
            break;

            case -1:
            digitalWrite(m_A, off);
            digitalWrite(m_B, off);
            digitalWrite(m_C, off);
            digitalWrite(m_D, off);
            digitalWrite(m_E, off);
            digitalWrite(m_F, off);
            digitalWrite(m_G, off);
            break;
        }
    }
}