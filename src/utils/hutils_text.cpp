#include "hutils.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::string;

#define SCREEN_WIDTH  50
#define SCREEN_HEIGHT 30

namespace hUtils {

    Text text;

    void Text::toLine(char character)
    {
        cout << string(SCREEN_WIDTH, character) << '\n';
    }

    void Text::toCentered(string text, int colorCode, int number)
    {
        int appliedScreenWidth = SCREEN_WIDTH;
        int padding = (appliedScreenWidth - text.length()) / 2;
        if(padding < 0) padding = 0;

        if (number >= 1) {
            text = std::to_string(number) + ". " + text;
        }
    
        std::cout << color(colorCode)
                  << std::string(padding, ' ')
                  << text
                  << defaultText()
                  << '\n';
    }

    void Text::toRight(string text, int colorCode)
    {
        cout << color(colorCode)
             << std::setw(SCREEN_WIDTH)<<text<<'\n'
             << defaultText();
    }

    void Text::toLeft(string text, int tab, int colorCode, int number)
    {
        cout << color(colorCode);
        
        if(tab >= 1){
            for(int i = 1; i <= tab; ++i){
                cout<<'\t';
            }
        }

        if(number >= 1){
            text = std::to_string(number) + ". " + text;
        }

        cout<<text<<'\n'
            <<defaultText();
    }

    string Text::toLowerCase(string text)
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        return text;
    }

    string Text::color(int textColor)
    {
        if((textColor >= 30 && textColor <= 37) || (textColor >= 90 && textColor <= 97)){
            return "\033[" + std::to_string(textColor) + "m";
        }
        return "";
    }

    string Text::defaultText()
    {
        return "\033[0m";
    }

    void Text::clearAll()
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void Text::clearLine(int line)
    {
        cout<<"\033["<<line<<";1H";
        cout<<"\033[J";
    }
}