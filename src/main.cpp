/*===========================================================================*/
/**
 * @file main.cpp
 *
 *  Describe the purpose of this software module in here
 *
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Divide this file content using an abstraction layers concept
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - @todo Update list of other applicable standards
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include <iostream>
#include <memory>
#include "person.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
class Logger {
private:
    // El único objeto de la clase
    inline static Logger* instance = nullptr;

    // Constructor privado → nadie puede hacer Logger log;
    Logger() {
        std::cout << "Logger inicializado\n";
    }

public:
    // Prohibir copia y asignación (C++11+)
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Método para obtener la instancia única
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    // Ejemplo de método
    void log(const std::string& msg) {
        std::cout << "[LOG]: " << msg << std::endl;
    }
};

class Car {
public:
    Car(const std::string& n) : name(n) {
        std::cout << name << " creado\n";
    }
    ~Car() {
        std::cout << name << " destruido\n";
    }
    void run() const { std::cout << "corriendo en un " << name << "\n"; }
private:
    std::string name;
};

// Clase genérica Stack
template <typename T>
class Stack {
private:
    T data[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(T value) {
        if (top < 99) data[++top] = value;
    }

    T pop() {
        if (top >= 0) return data[top--];
        throw std::out_of_range("Stack vacío");
    }

    bool empty() const { return top == -1; }
};

/***************************************************************************//**
* @fn         max
* @brief      Return the maximum of two entries
* @param [in] a
* @param [in] b
* @return     The max between a and b
******************************************************************************/
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

/***************************************************************************//**
* @fn         myMax
* @brief      Return the maximum of two entries
* @param [in] a
* @param [in] b
* @return     The max between a and b
******************************************************************************/
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

/***************************************************************************//**
* @fn         main
* @brief      The main entry point
* @param [in] void
* @return     0 -success, -1 -Error
******************************************************************************/
int main(int argc, char* argv[]) {
    std::cout << "=== " << argv[0] << " ===" << std::endl;

    // if (argc > 1) {
    //     std::cout << "Argumentos recibidos:" << std::endl;
    //     for (int i = 1; i < argc; ++i) {
    //         std::cout << "  [" << i << "] " << argv[i] << std::endl;
    //     }
    // } else {
    //     std::cout << "No se pasaron argumentos." << std::endl;
    // }

    // // TODO: acá va la lógica de tu programa
    // std::cout << "Programa base corriendo correctamente." << std::endl;

    // Reservamos memoria dinámicamente
    int* ptr = new int(42);
    std::cout << "Valor: " << *ptr << std::endl;

    Person p1("Alice", 30);
    Person p2("Bob", 25);

    p1.greet();
    p2.greet();

    Logger* log1 = Logger::getInstance();
    log1->log("Hola mundo");

    Logger* log2 = Logger::getInstance();
    log2->log("Este es el mismo objeto");

    // Comprobamos que apuntan al mismo lugar
    if (log1 == log2) {
        std::cout << "Es el mismo Singleton\n";
    }

    std::cout << "máximo:" << max(3, 5);

    // unique_ptr crea y gestiona el objeto automáticamente
    std::unique_ptr<Car> car1 = std::make_unique<Car>("R18");
    car1->run();

    std::cout << "Max int: " << myMax(3, 7) << std::endl;        // int
    std::cout << "Max double: " << myMax(3.5, 2.1) << std::endl; // double
    std::cout << "Max char: " << myMax('a', 'z') << std::endl;   // char

    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << intStack.pop() << std::endl; // 20
    std::cout << intStack.pop() << std::endl; // 10

    Stack<std::string> stringStack;
    stringStack.push("Hola");
    stringStack.push("Mundo");
    std::cout << stringStack.pop() << std::endl; // Mundo
    std::cout << stringStack.pop() << std::endl; // Hola
    
    return 0;
}
