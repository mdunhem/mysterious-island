//--------------------------------------------------------------------------
// POV-Ray 3.7 Include File "mysterious_objects.inc"
// author:  Mikael Dunhem
// CS 355 - Summer 2017
//--------------------------------------------------------------------------

#include "include/mysterious_colors.inc"

#local OrangeFlameMedia = media {
    absorption 8
    emission 8
    method 3
    samples 30, 30
    intervals 1
    density {
        spherical
        warp { turbulence 0.275 lambda 2.75 }
        density_map {
            [ 0 Black ]
            [ 0.2 FlameRedColor ]
            [ 1 FlameOrangeColor ]
        }
    }
}

#local SmokeFlameMedia = media {
    absorption 3
    scattering { 1 .3 }
    method 3
    samples 30, 30
    intervals 1
    density {
        spherical
        warp { turbulence 0.275 lambda 2.75 }
        density_map {
            [ 0.25 Opaque ]
            [ 0.25 Transparent ]
            [ 0.63 Transparent ]
            [ 0.63 Opaque ]
        }
    }
}

// ----------- Exports ---------------------

#declare Fire = object {
    sphere {
        <0, 0.2, 0>, 1.5 hollow no_shadow
        texture { pigment { Transparent } }
        interior {
            media { OrangeFlameMedia }
            media { SmokeFlameMedia }
        }
    }
}
