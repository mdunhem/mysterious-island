//--------------------------------------------------------------------------
// POV-Ray 3.7 Include File "mysterious_colors.inc"
// author:  Mikael Dunhem
// CS 355 - Summer 2017
//--------------------------------------------------------------------------

#include "colors.inc"

#local RockFloat = <0.72, 0.56, 0.3>;
#local RockDensity = 1.5;
#local LightSandColor = color rgb <0.97, 0.88, 0.62>;
#local SandColor = color rgb <0.75, 0.55, 0.35>;
#local GrassDensity = 1.0;
#local GrassScale = 1.0;
#local G1 = GrassDensity * <0.54, 0.6, 0.23>;
#local G2 = GrassDensity * <0.29, 0.48, 0.13>;
#local G3 = GrassDensity * <0.45, 0.63, 0.1>;
#local G4 = GrassDensity * <0.4, 0.5, 0.2>;
#local MonsterBodyBaseColor = color rgb <0.7, 1, 0.15>;

// ----------- Exports ---------------------

#declare Transparent = rgbt 1;
#declare Opaque = rgbt 0;
#declare SkyColor = color rgb <0.19, 0.3, 0.8>;
#declare WaterColor = color rgb <0.2, 0.2, 0.2>;
#declare MossyDarkGreenGrass = color rgb GrassDensity * <0.2, 0.2, 0.1>;
#declare FlameRedColor = color rgb <0.35, 0, 0>;
#declare FlameOrangeColor = color rgb <0.75, 0.25, 0>;
#declare MonsterMouthColor = color rgb <1, 0.7, 0.15>;

#declare RockColorMap = color_map {
    [ 0.019 color 0.721 * RockFloat + <0, 0, 0> ]
    [ 0.067 color 0.937 * RockFloat + <0, 0, 0> ]
    [ 0.118 color 0.811 * RockFloat + <0, 0, 0> ]
    [ 0.196 color 0.892 * RockFloat + <0, 0, 0> ]
    [ 0.211 color 0.754 * RockFloat + <0, 0, 0> ]
    [ 0.276 color 0.895 * RockFloat + <0, 0, 0> ]
    [ 0.346 color 0.793 * RockFloat + <0, 0, 0> ]
    [ 0.358 color 0.874 * RockFloat + <0, 0, 0> ]
    [ 0.411 color 0.748 * RockFloat + <0, 0, 0> ]
    [ 0.477 color 0.790 * RockFloat + <0, 0, 0> ]
    [ 0.521 color 0.832 * RockFloat + <0, 0, 0> ]
    [ 0.594 color 0.757 * RockFloat + <0, 0, 0> ]
    [ 0.615 color 0.892 * RockFloat + <0, 0, 0> ]
    [ 0.675 color 0.829 * RockFloat + <0, 0, 0> ]
    [ 0.706 color 0.958 * RockFloat + <0, 0, 0> ]
    [ 0.768 color 0.850 * RockFloat + <0, 0, 0> ]
    [ 0.804 color 0.736 * RockFloat + <0, 0, 0> ]
    [ 0.879 color 0.703 * RockFloat + <0, 0, 0> ]
    [ 0.947 color 0.883 * RockFloat + <0, 0, 0> ]
    [ 0.951 color 0.883 * RockFloat + <0, 0, 0> ]
}

#declare CloudColorMap = color_map {
    [ 0.0 rgb <0.5, 0.5, 0.5> ]
    [ 0.3 rgb <0.9, 0.9, 0.9> ]
    [ 0.5 rgbt <1, 1, 1, 1> ]
    [ 1.0 rgbt <1, 1, 1, 1> ]
}

#declare SandPigment = pigment {
    gradient y
    pigment_map {
        [ 0.0 LightSandColor ]
        [ 0.3 SandColor ]
        [ 1.0 SandColor ]
    }
    warp { turbulence 0.5 }
}

#declare RockPigment = pigment {
    wrinkles
    pigment_map {
        [ 0.00 rgb RockDensity * 0.2 * <0.40, 0.23, 0.15> ]
        [ 0.05 rgb RockDensity * 0.4 * <0.70, 0.70, 0.55> ]
        [ 0.20 rgb RockDensity * 0.6 * <0.90, 0.73, 0.65> ]
        [ 1.00 rgb RockDensity * 0.8 * <1.00, 0.83, 0.75> ]
    }
    warp { turbulence 0.5 }
    scale 0.2
}

#declare GrassPigment = pigment {
    bumps scale 0.5
    pigment_map {
        [ 0.0 granite color_map { [ 0.3 color G1 ] [ 0.6 color G2 ] } scale GrassScale * <0.05, 0.05, 0.25> rotate 45 * y ]
        [ 0.3 granite color_map { [ 0.3 color G2 ] [ 0.6 color G3 ] } scale GrassScale * <0.05, 0.05, 0.25> rotate 22 * y ]
        [ 0.6 granite color_map { [ 0.3 color G3 ] [ 0.6 color G4 ] } scale GrassScale * <0.05, 0.05, 0.25> ]
        [ 1.0 granite color_map { [ 0.3 color G4 ] [ 0.6 color G1 ] } scale GrassScale * <0.05, 0.05, 0.25> rotate -30 * y ]
    }
    warp { turbulence 0.1 }
}

#declare MonsterScalyPigment = pigment {
    wrinkles
    pigment_map {
        [ 0.0 MonsterBodyBaseColor * 1 ]
        [ 0.3 MonsterBodyBaseColor * 0.6 ]
        [ 0.6 MonsterBodyBaseColor * 0.8 ]
        [ 1.0 MonsterBodyBaseColor * 1 ]
    }
}
