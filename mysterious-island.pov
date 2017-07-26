//--------------------------------------------------------------------------
// POV-Ray 3.7 Scene File "mysterious-island.pov"
// author:  Mikael Dunhem
// CS 355 - Summer 2017
//
// Main rendering file. Lays out the whole scene based on objects defined
// in other files.
//--------------------------------------------------------------------------

#version 3.7;
global_settings { assumed_gamma 1.0 }
#default { finish { ambient 0.1 diffuse 0.9 } }

// POV-Ray definitions
#include "textures.inc"

// Local definitions
#include "include/mysterious_environment.inc"
#include "include/mysterious_colors.inc"
#include "include/mysterious_objects.inc"

//--------------------------------------------------------------------------
// Camera
//--------------------------------------------------------------------------

camera {
    location <1, 2, -15>
    look_at <1, 0, 0>
}

//--------------------------------------------------------------------------
// Sky
//--------------------------------------------------------------------------

/**
 * Area light source
 */
light_source { <30, 200, -150>, 1 }

/**
 * Orb Spotlight
 */
light_source {
    <-3, 3, -9>
    White
    spotlight
    point_at <-2, 1.75, -5.0>
    radius 4
    tightness 10
    falloff 10
}

/**
 * Blue sky
 */
sky_sphere { pigment { SkyColor } }

/**
 * Clouds
 */
object { Clouds }

//--------------------------------------------------------------------------
// Environment
//--------------------------------------------------------------------------

/**
 * Foreground island
 */
union {
    difference {
        object { Island }
        object {
            Cave
            scale 0.2
            rotate <0, -30, 0>
            translate <2, 1.5, -4.3>
        }
    }
    object {
        Fire
        translate <13.5, 1, -10.5>
        scale 0.4
    }
    object {
        Orb
        translate <-2.0, 1.75, -5.0>
    }
}


/**
 * Background island
 */
object {
    Island
    rotate y * 120
    scale <12.5, 9, 10>
    translate <250, 0, 440>
}

/**
 * Ocean
 */
object { Ocean }

//--------------------------------------------------------------------------
// Monsters
//--------------------------------------------------------------------------

/**
 * Foreground monsters
 */
object {
    Monster
    scale 0.3
    rotate y * 20
    translate <0, -0.35, -10>
}
object {
    Monster
    scale 0.3
    rotate y * 170
    translate <4, -0.6, -10>
}

/**
 * Background monster
 */
object {
    Monster
    scale 0.3
    rotate y * 70
    translate <11, -0.35, 3>
}
