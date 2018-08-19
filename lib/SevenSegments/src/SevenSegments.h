#ifndef DEF_SEVEN_SEGMENTS
#define DEF_SEVEN_SEGMENTS

/*
  Showing number 0-9 on a Common Anode 7-pinment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
      A
     ---
  F |   | B
    | G |
     ---
  E |   | C
    |   |
     ---
      D
  This example code is in the public domain.
*/

namespace Aguernier 
{
    class SevenSegments
    {
        public:
        SevenSegments(int A, int B, int C, int D, int E, int F, int G, int type);
        void displayNomber(int number);

        private:
        int m_A;
        int m_B; 
        int m_C; 
        int m_D;
        int m_E; 
        int m_F; 
        int m_G;
        int m_type;
    };
}


#endif