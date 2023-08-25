#include <iostream>
#include <cstdlib>
#include <algorithm> // ослы добавили
#include <locale> // типо добавлено

#ifdef __linux__
    #include <cstring>
#endif

int main() {
    std::string userInput;
    
    std::cout << "Введите текст: ";
    std::cin >> userInput;

    // Приведение текста к нижнему регистру
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    
    if (userInput == "иа") {
        std::cout << "ВЫ ЗАРАЖЕНЫ ИА ВИРУСОМ." << std::endl;

        #ifdef __linux__
            system("zenity --warning --text=\"<span font_desc=\\\"Bold 20\\\">ВЫ ЗАРАЖЕНЫ ИА ВИРУСОМ.</span>\"");
        #elif _WIN32
            system("powershell -command \"Add-Type -AssemblyName System.Windows.Forms; [System.Windows.Forms.MessageBox]::Show('ВЫ ЗАРАЖЕНЫ ИА ВИРУСОМ.', 'Предупреждение', 'OK', [System.Windows.Forms.MessageBoxIcon]::Warning)\"");
   system("pause");
        #endif
    }
    
    #ifdef _WIN32
        // локаль утф8 для пользователей ******s
        setlocale(LC_ALL, ".UTF-8");
    #endif

    return 0;
}
