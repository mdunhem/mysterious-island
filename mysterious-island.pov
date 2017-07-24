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
object { Island }

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
