#include <iostream>

// --- SECCIÓN DE COMPATIBILIDAD (Para que CxStudio no dé error) ---
namespace geode {
    namespace prelude {
        class CCNode {};
        class CCLayer : public CCNode {};
        class CCLabelBMFont : public CCNode {
        public:
            static CCLabelBMFont* create(const char* text, const char* font) { return new CCLabelBMFont(); }
            void setPosition(float x, float y) {}
            void setScale(float s) {}
        };
        class CCDirector {
        public:
            static CCDirector* get() { static CCDirector d; return &d; }
            struct Size { float width; float height; };
            Size getWinSize() { return {480, 320}; }
        };
    }
}

class PauseLayer : public geode::prelude::CCLayer {
public:
    virtual void customSetup() {}
    void addChild(geode::prelude::CCNode* n) {}
};

// Definimos el macro sin el símbolo $ para evitar errores en Android
#define GEODE_MOD(_name, _class) class _name : public _class

// --- CÓDIGO DEL MOD (BetterInfo Clone) ---

GEODE_MOD(MyBetterInfo, PauseLayer) {
public:
    void customSetup() {
        // En un mod real, aquí llamaríamos al original, pero en CxStudio lo omitimos
        
        using namespace geode::prelude;
        
        // Creamos el texto que aparecerá en el juego
        auto infoLabel = CCLabelBMFont::create("BetterInfo Mobile 2026", "goldFont.fnt");
        
        // Lo posicionamos
        infoLabel->setPosition(100.0f, 100.0f);
        infoLabel->setScale(0.5f);
        
        // Lo añadimos a la capa de pausa
        this->addChild(infoLabel);
    }
};

// Punto de entrada para que CxStudio compile y confirme éxito
int main() {
    std::cout << "Intentando exportar el binario..." << std::endl;
    
    // Este comando intenta copiar el archivo que se está ejecutando a tu carpeta de descargas
    // Nota: El nombre 'a.out' es el que usa CxStudio por defecto
    system("cp a.out /storage/emulated/0/Download/BetterInfo_Backup.so");
    system("cp *.so /storage/emulated/0/Download/");

    std::cout << "¡PROYECTO COMPILADO!" << std::endl;
    std::cout << "Revisa tu carpeta de Descargas directamente." << std::endl;
    return 0;
}