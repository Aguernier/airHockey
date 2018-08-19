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
        if (m_type == 0) {
            switch (number) {
                case 0:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, LOW);
                break;

                case 1:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 2:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, HIGH);
                break;

                case 3:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, HIGH);
                break;

                case 4:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 5:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 6:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 7:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 8:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 9:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case -1:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;
            }
        } else {
            switch (number) {
                case 0:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, HIGH);
                break;

                case 1:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 2:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, LOW);
                break;

                case 3:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, LOW);
                break;

                case 4:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 5:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 6:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 7:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;

                case 8:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, LOW);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case 9:
                digitalWrite(m_A, LOW);
                digitalWrite(m_B, LOW);
                digitalWrite(m_C, LOW);
                digitalWrite(m_D, LOW);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, LOW);
                digitalWrite(m_G, LOW);
                break;

                case -1:
                digitalWrite(m_A, HIGH);
                digitalWrite(m_B, HIGH);
                digitalWrite(m_C, HIGH);
                digitalWrite(m_D, HIGH);
                digitalWrite(m_E, HIGH);
                digitalWrite(m_F, HIGH);
                digitalWrite(m_G, HIGH);
                break;
            }
        }
    }
}