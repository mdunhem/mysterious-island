//--------------------------------------------------------------------------
// POV-Ray 3.7 Include File "mysterious_environment.inc"
// author:  Mikael Dunhem
// CS 355 - Summer 2017
//
// Defines objects used to lay out the environment
//--------------------------------------------------------------------------

#include "colors.inc"
#include "include/mysterious_textures.inc"
#include "include/mysterious_colors.inc"

#local BaseIsland = height_field {
    png "include/mountain-background.png"
    translate <-0.5, 0, -0.5>
    scale <16, 10, 16>
}

// ----------- Exports ---------------------

#declare Clouds = plane {
    y, 500 hollow
    texture {
        CloudTexture
        scale 20
    }
}

#declare Island = object {
    BaseIsland
    texture {
        MountainTexture
        scale 7.0
    }
}

#declare BackgroundIsland = object {
    BaseIsland
    rotate y * 120
    scale <12.5, 9, 10>
    translate <250, 0, 440>
    texture {
        Sapphire_Agate
        scale 20
    }
}

#declare Ocean = plane {
    y, 0.01
    texture { WaterTexture }
}
