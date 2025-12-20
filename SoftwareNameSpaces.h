#pragma once
namespace Shooters {
    inline POINT incenter;
    inline std::atomic<bool> ShooterHexagons{ false };
    inline const COLORREF ShootersColor = RGB(0, 0, 255);
    inline HWND ButtonDiscoveryShootersColor;
}

namespace Guardians {
    inline POINT incenter = { 0, 0 };
    inline std::atomic<bool> GuardianHexagons{ false };
    inline const COLORREF GuardianColor = RGB(255, 0, 0);
    inline HWND ButtonDiscoveryGuardiansColor;
}

namespace Carriers {
    inline POINT incenter;
    inline std::atomic<bool> CarrierHexagons{ false };
    inline const COLORREF CarriersColor = RGB(0, 255, 0);
    inline HWND ButtonDiscoveryCarriersColor;
}

namespace Eaters {
    inline POINT incenter;
    inline std::atomic<bool> EateHexagons{ false };
    inline const COLORREF EateColor = RGB(0, 255, 255);
    inline HWND ButtonDiscoveryEateColor;
}

namespace Meteorites {
    inline POINT incenter;
    inline std::atomic<bool> MeteoritHexagons{ false };
    inline const COLORREF MeteoritColor = RGB(127, 0, 255);
    inline HWND ButtonDiscoveryMeteoritColor;
}

namespace CrystalHoles {
    inline POINT incenter;
    inline std::atomic<bool> CrystalHoleHexagons{ false };
    inline const COLORREF CrystalHoleColor = RGB(178, 102, 255);
    inline HWND ButtonDiscoveryCrystalHoleColor;
}

namespace Viruses {
    inline POINT incenter;
    inline std::atomic<bool> VirusesHexagons{ false };
    inline const COLORREF VirusesColor = RGB(18, 198, 243);
    inline HWND ButtonDiscoveryVirusesColor;
}

namespace Evolutions {
    inline POINT incenter;
    inline std::atomic<bool> EvolutionsHexagons{ false };
    inline const COLORREF EvolutionsColor = RGB(255, 102, 102);
    inline HWND ButtonDiscoveryEvolutionsColor;
}

namespace OrdinaryCaves {
    inline POINT incenter;
    inline std::atomic<bool> OrdinaryCaveHexagons{ false };
    inline const COLORREF OrdinaryCaveColor = RGB(102, 178, 255);
    inline HWND ButtonDiscoveryOrdinaryCaveColor;
}

namespace WildAnimals {
    inline POINT incenter;
    inline std::atomic<bool> WildAnimalHexagons{ false };
    inline const COLORREF WildAnimalBaseColor = RGB(255, 255, 153);
    inline HWND ButtonDiscoveryWildAnimalColor;
}

namespace RuralContests {
    inline POINT incenter;
    inline std::atomic<bool> RuralContestHexagons{ false };
    inline const COLORREF RuralContestsColor = RGB(255, 51, 153);
    inline HWND ButtonDiscoveryRuralContestColor;
}

namespace Ladybugs {
    inline POINT incenter;
    inline std::atomic<bool> LadybugHexagons{ false };
    inline const COLORREF LadybugColor = RGB(204, 0, 0);
    inline HWND ButtonDiscoveryLadybugColor;
}

namespace Shells {
    inline POINT incenter;
    inline std::atomic<bool> ShellHexagons{ false };
    inline const COLORREF ShellColor = RGB(255, 255, 204);
    inline HWND ButtonDiscoveryShellColor;
}

namespace FabricResources {
    inline POINT incenter;
    inline std::atomic<bool> FabricResourcesHexagons{ false };
    inline const COLORREF FabricResourcesColor = RGB(153, 255, 153);
    inline HWND ButtonDiscoveryFabricResourcesColor;
}

namespace WarCaves {
    inline POINT incenter;
    inline std::atomic<bool> WarCaveHexagons{ false };
    inline const COLORREF WarCaveColor = RGB(153, 0, 0);
    inline HWND ButtonDiscoveryWarCaveColor;
}

namespace HatchingAnimals {
    inline const COLORREF HatchingAnimalColor = RGB(255, 128, 0);
    inline HWND ButtonDiscoveryHatchingAnimalColor;
    inline int QuantityOfHatchingAnimalsBuilding = 0;
}

namespace AntSlayers {
    inline const COLORREF AntSlayerColor = RGB(0, 102, 51);
    inline HWND ButtonDiscoveryAntSlayerColor;
    inline int QuantityOfAntSlayerBuilding = 0;
}

namespace AnimalCorms {
    inline const COLORREF AnimalCormColor = RGB(102, 102, 0);
    inline HWND ButtonDiscoveryAnimalCormColor;
    inline int QuantityOfAnimalCormBuilding = 0;
}