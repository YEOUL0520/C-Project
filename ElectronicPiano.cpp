/*
* 파일명: "ElectronicPiano.cpp"
* 프로그램의 목적 및 기본 기능:
*   -입력한 음에 맞추어 음을 출력하는 전자 피아노 프로그램
* 프로그램 작성자: 류효정 (2022년 03월 22일)
* 최종 수정 및 보완: 류효정 (2022년 03월 22일)
* ===========================================================================
* 프로그램 수정/보완 이력
* ===========================================================================
* 프로그램 수정/보완작업자       일자            수정/보완 내용
* 류효정                       2022.03.22      음 출력 완료
* ===========================================================================
*/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int mappingKey_to_Freq(int ch, int alt_on);
int main(void)
{
    char ch, alt_on = 0;
    int duration = 100;
    int freq;
    printf("\nSimple Electirc Piano !!\n");
    printf("'A'~'J' are mapped into C,D,E,F,G,A,B code in octave 8,\n");
    printf("'Z'~'M' are mapped into C,D,E,F,G,A,B code in octave 7,\n");
    printf("'q'~'u' are mapped into C,D,E,F,G,A,B code in octave 6,\n");
    printf("'a'~'j' are mapped into C,D,E,F,G,A,B code in octave 5,\n");
    printf("'z'~'m' are mapped into C,D,E,F,G,A,B code in octave 4, respectively.\n");
    printf("input next key :\n");
    while ((ch = _getch()) != 27)
    {
        alt_on = 0;
        if (GetAsyncKeyState(VK_MENU) & 0x8000)
            alt_on = 1;
        freq = mappingKey_to_Freq(ch, alt_on);
        if (freq != -1)
        {
            printf("input key (%c): freq (%3d)\n", ch, freq);
            Beep(freq, duration);
        }
        else
        {
            printf("input key (%c) is wrong key input..\n", ch);
        }
    }
}
int mappingKey_to_Freq(int ch, int alt_on)
{
    int Key_to_Freq[2][2][26] = {
       {
            //alt_on = 0
            {523,392,330,660,1323,698,784,880,-1,988,-1,-1,494,440,-1,-1,1048,1396,588,1568,1976,349,1176,294,1760,262},
            {4186,3136,2637,5274,-1,5588,6272,7040,-1,7902,-1,-1,3951,3520,-1,-1,-1,-1,4699,-1,-1,2794,-1,2349,-1,2093}
         },
         {
             //alt_on = 1
             {554,415,330,660,1323,740,830,932,-1,988,-1,-1,494,466,-1,-1,1109,1480,622,1661,1976,370,1245,311,1865,277},
             {4435,3322,2637,5274,-1,5920,6645,7459,-1,7902,-1,-1,3951,3729,-1,-1,-1,-1,4978,-1,-1,2960,-1,2489,-1,2217}
          }

    };

    if (alt_on == 0)
    {
        if (ch >= 97 && ch <= 122)
        {
            int key1 = ch - 97;
            return Key_to_Freq[0][0][key1];
        }
        else if (ch >= 65 && ch <= 90)
        {
            int key2 = ch - 65;
            return Key_to_Freq[0][1][key2];
        }
        else
        {
            return -1;
        }
    }
    else if (alt_on == 1)
    {
        if (ch >= 97 && ch <= 122)
        {
            int key1 = ch - 97;
            return Key_to_Freq[1][0][key1];
        }
        else if (ch >= 65 && ch <= 90)
        {
            int key2 = ch - 65;
            return Key_to_Freq[1][1][key2];
        }
        else
        {
            return -1;
        }
    }
}