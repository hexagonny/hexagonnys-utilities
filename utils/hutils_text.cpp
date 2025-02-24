#include "hutils.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::string;

#define SCREEN_WIDTH  50
#define SCREEN_HEIGHT 30

namespace hUtils {

    namespace Text{

        void toLine(char character)
        {
            cout << string(SCREEN_WIDTH, character) << '\n';
        }

        void toCentered(string text, bool numbered, int colorCode, bool isBold)
        {
            int appliedScreenWidth = SCREEN_WIDTH;
            int padding = (appliedScreenWidth - text.length()) / 2;
            if(padding < 0) padding = 0;
            
            if(numbered){
                static int count = 1;
                text = std::to_string(count++) + ". " + text;
            }

            cout<<color(colorCode, isBold)
                <<std::setw(padding + text.length())<<text<<'\n'
                <<defaultText();
        }

        void toRight(string text, int colorCode, bool isBold)
        {
            cout<<color(colorCode, isBold)
                <<std::setw(SCREEN_WIDTH)<<text<<'\n'
                <<defaultText();
        }

        void toLeft(string text, int tab, int colorCode, bool isBold)
        {
            cout<<color(colorCode, isBold);
            
            if(tab >= 1){
                for(int i = 1; i <= tab; ++i){
                    cout<<'\t';
                }
            }

            cout<<text<<'\n'
                <<defaultText();
        }

        string toLowerCase(string text)
        {
            transform(text.begin(), text.end(), text.begin(), ::tolower);
            return text;
        }

        string color(int textColor, bool isBold)
        {
            if((textColor >= 30 && textColor <= 37) || (textColor >= 90 && textColor <= 97)){
                return "\033[" + string(isBold ? "1;" : "") + std::to_string(textColor) + "m";
            }
            return "";
        }

        string defaultText()
        {
            return "\033[0m";
        }

        void clearAll()
        {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }

        void clearLine(int line)
        {
            cout<<"\033["<<line<<";1H";
            cout<<"\033[J";
        }
    }

}