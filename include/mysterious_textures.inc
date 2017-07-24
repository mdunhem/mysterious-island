//--------------------------------------------------------------------------
// POV-Ray 3.7 Include File "mysterious_textures.inc"
// author:  Mikael Dunhem
// CS 355 - Summer 2017
//--------------------------------------------------------------------------

#include "include/mysterious_colors.inc"

#local Transparent = rgbt 1;

#local MountainSlope = normal {
    gradient x
    slope_map {
        [ 0.0 <0.5, 1> ]   // start in middle and slope up
        [ 0.4 <1.0, 0> ]   // flat slope at top of wave
        [ 0.65 <0.5, -1> ]   // slope down at mid point
        [ 0.85 <0.0, 0> ]   // flat slope at bottom
        [ 1.0 <0.5, 1> ]   // finish in middle and slope up
    }
    scale 0.15
    warp { turbulence 0.1 octaves 3 lambda 3.0 }
    scale 1.0/0.15
}

// Layered texture. First layer is sand, second is grass
#local MountainTextureBase =
    texture {
        pigment { SandPigment }
        normal {
            average
            normal_map {
                [ 0.5 MountainSlope 1.0 ]
                [ 0.5 wrinkles 1 scale 0.0025 ]
            }
        }
        finish  {
            ambient 0.15
            diffuse 0.8
        }
    }
    texture {
        pigment {
            gradient y
            pigment_map {
                [ 0.0 Transparent ]
                [ 0.22 MossyDarkGreenGrass ]
                [ 0.6 GrassPigment ]
                [ 1.0 GrassPigment ]
            }
            warp { turbulence 0.01 }
        }
    }

// ----------- Exports ---------------------

#declare WaterTexture = texture {
    pigment { WaterColor }
    normal {
        crackle 0.15
        turbulence 0.3
        scale 0.2
    }
    finish {
        ambient 0.15
        diffuse 0.55
        brilliance 6.0
        phong 0.8
        phong_size 120
        reflection 0.6
    }
}

#declare IslandTexture = texture {
    pigment {
        gradient y
        color_map { RockColorMap }
    }
}

#declare CloudTexture = texture {
    pigment {
        bozo
        turbulence 0.6
        octaves 19
        omega 0.7
        lambda 2
        color_map { CloudColorMap }
        scale 528
    }
    finish {
        ambient 1
        diffuse 0
    }
}

#declare MountainTexture = texture {
    gradient y
    texture_map {
        [ 0.0 MountainTextureBase ]
        [ 1 MountainTextureBase ]
    }
    translate y * -0.1
    warp {
        turbulence 0.03
        omega 0.8
        lambda 3
    }
}
