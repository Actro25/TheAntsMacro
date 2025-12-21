#pragma once
enum class BuildingType {
    None,
    Shooters,
    Guardians,
    Carriers,
    Eaters,
    Meteorites,
    CrystalHoles,
    Viruses,
    Evolutions,
    OrdinaryCaves,
    WildAnimals,
    RuralContests,
    Ladybugs,
    Shells,
    FabricResources,
    WarCaves,
    HatchingAnimals,
    AntSlayers,
    AnimalCorms
};

struct BuildingStruct
{
    std::string name;
    POINT incenter;
    std::atomic<bool> isPlaced;
    const COLORREF Color;
    const BuildingType type;

    HWND ButtonColor;

    void FunctionCreate(std::string name, POINT incenter,
        bool isPlaced, HWND ButtonColor) {
        this->name = name;
        this->incenter = incenter;
        this->isPlaced = isPlaced;
        this->ButtonColor = ButtonColor;
    }
};


namespace HatchingAnimals {
    inline std::list<POINT> incenter;
    inline const COLORREF HatchingAnimalColor = RGB(255, 128, 0);
    inline HWND ButtonDiscoveryHatchingAnimalColor;
    inline BuildingType type = BuildingType::HatchingAnimals;
    inline int QuantityOfHatchingAnimalsBuilding = 0;
}

namespace AntSlayers {
    inline std::list<POINT> incenter;
    inline const COLORREF AntSlayerColor = RGB(0, 102, 51);
    inline HWND ButtonDiscoveryAntSlayerColor;
    inline BuildingType type = BuildingType::AntSlayers;;
    inline int QuantityOfAntSlayerBuilding = 0;
}

namespace AnimalCorms {
    inline std::list<POINT> incenter;
    inline const COLORREF AnimalCormColor = RGB(102, 102, 0);
    inline HWND ButtonDiscoveryAnimalCormColor;
    inline BuildingType type = BuildingType::AnimalCorms;
    inline int QuantityOfAnimalCormBuilding = 0;
}