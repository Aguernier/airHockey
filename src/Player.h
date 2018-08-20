#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "SevenSegments.h"

namespace Aguernier
{
    class Player
    {
        public:
        Player(SevenSegments sevenSegments, int sensor);
        void addScore();
        int getScore();
        void resetScore();
        void displayScore();
        void display(int number);
        void addSensorListener();

        private:
        int m_score;
        SevenSegments m_sevenSegments;
        int m_sensor;
        bool m_push;
    };
}

#endif