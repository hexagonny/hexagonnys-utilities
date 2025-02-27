#ifndef HUTILS_H
#define HUTILS_H

#pragma once

#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

#include <string>

#ifndef HUTIL_API
#define HUTIL_API
#endif

namespace hUtils {

    // --- SYSTEM UTILITIES ---
    HUTIL_API void setConsoleWindowSize();  //  Adjust console size.
    HUTIL_API void pause();                 //  Cross-platform system pause.
    HUTIL_API void sleep(int milliseconds); //  Sleep for a given duration.

    // --- TEXT UTILITIES ---
    namespace Text
    {
        HUTIL_API void toLine            (char character = '-'); //  Print a line of repeated characters
        HUTIL_API void toCentered        (std::string text,      //  Prints centered text.
                                          int colorCode = 0,
                                          int number = 0);      
        HUTIL_API void toRight           (std::string text,      //  Moves text to the right.
                                          int colorCode = 0);  
        HUTIL_API void toLeft            (std::string text,      //  Moves text to the left.
                                          int tab = 0,
                                          int colorCode = 0,
                                          int number = 0);
        HUTIL_API std::string toLowerCase(std::string text);     //  Convert string to lowercase.

        HUTIL_API std::string color      (int textColor = 0);    //  Get ANSI color codes.
        HUTIL_API std::string defaultText();                     //  Reset text color.
        HUTIL_API void clearAll();                               //  Clears every output in the terminal.
        HUTIL_API void clearLine         (int line);             //  Clears an assigned line and below it.
    };
}

// --- LOGGER UTILITIES ---
struct Logger
{
    int filesMoved = 0, foldersRemoved = 0, foldersCreated = 0, errors = 0, warnings = 0;

    HUTIL_API void logAction     (const std::string& message);
    HUTIL_API void logSuccess    (const std::string& message);
    HUTIL_API void logMoved      (const std::string& message); //  filesMoved
    HUTIL_API void logRemoved    (const std::string& message); //  filesRemoved
    HUTIL_API void logCreated    (const std::string& message); //  foldersCreated
    HUTIL_API void logError      (const std::string& message); //  errors
    HUTIL_API void logWarning    (const std::string& message); //  warnings
    HUTIL_API void displaySummary();
};

extern Logger logger;

#endif