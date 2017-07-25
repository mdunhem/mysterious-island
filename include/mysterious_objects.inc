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

#local MonsterEye = union {
    // Sclera (white part of eye)
    sphere {
        <0, 0, 0>, 0.15
        scale <1, 1, 0.3>
        texture {
            pigment { White }
            finish { phong 1 }
        }
    }
    // Pupil
    sphere {
        <0, 0, 0>, 0.08
        texture {
            pigment { Black }
            finish { phong 0.1 }
        }
        translate <0, 0, -0.025>
    }
}

#local MonsterMouth = prism {
    0.00, 2.00, 4
    <1.00, 2.00>,
    <0.00, 0.00>,
    <-1.00, 2.00>,
    <1.00, 2.00>
    pigment { MonsterMouthColor }
    rotate y * 90
    rotate x * 90
    translate <4.8, 3, -1>
}

#local MonsterBody = object {
    sphere_sweep {
        b_spline
        19,
        <1.50, 4.00, 0>, 0.01,
        <-0.90, 2.00, 0>, 0.07,
        <0.20, 1.00, 0>, 0.25,
        <-0.50, 1.00, 0>, 0.30,
        <-0.50, 0.00, 0>, 0.15,
        <0.50, 0.00, 0>, 0.45,
        <0.50, 1.00, 0>, 0.15,
        <1.00, 1.50, 0>, 0.20,
        <1.60, 1.50, 0>, 0.35,
        <1.50, 0.30, 0>, 0.30,
        <2.40, 0.00, 0>, 0.20,
        <2.70, 1.80, 0>, 0.40,
        <3.70, 1.50, 0>, 0.15,
        <3.00, 0.50, 0>, 0.30,
        <4.00, 0.00, 0>, 0.20,
        <4.50, 1.50, 0>, 0.30,
        <4.20, 3.00, 0>, 0.60,
        <5.50, 3.20, 0>, 0.80,
        <6.50, 3.50, 0>, 0.90
        tolerance 0.1
        texture { MonsterBodyTexture }
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

#declare Monster = union {
    difference {
        object { MonsterBody }
        object { MonsterMouth }
    }
    object {
        MonsterEye
        translate <4.8, 3.50, -0.65>
    }
    object {
        MonsterEye
        translate <4.8, 3.50, -0.65>
        scale <1, 1, -1>
    }
}
