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

#local MonsterPoint01 = <1.50, 4.00, 0>;
#local MonsterPoint02 = <-0.90, 2.00, 0>;
#local MonsterPoint03 = <0.20, 1.00, 0>;
#local MonsterPoint04 = <-0.50, 1.00, 0>;
#local MonsterPoint05 = <-0.50, 0.00, 0>;
#local MonsterPoint06 = <0.50, 0.00, 0>;
#local MonsterPoint07 = <0.50, 1.00, 0>;
#local MonsterPoint08 = <1.00, 1.50, 0>;
#local MonsterPoint09 = <1.60, 1.50, 0>;
#local MonsterPoint10 = <1.50, 0.30, 0>;
#local MonsterPoint11 = <2.40, 0.00, 0>;
#local MonsterPoint12 = <2.70, 1.80, 0>;
#local MonsterPoint13 = <3.70, 1.50, 0>;
#local MonsterPoint14 = <3.00, 0.50, 0>;
#local MonsterPoint15 = <4.00, 0.00, 0>;
#local MonsterPoint16 = <4.50, 1.50, 0>;
#local MonsterPoint17 = <4.20, 3.50, 0>;
#local MonsterPoint18 = <6.50, 2.50, 0>;

#local MonsterEye = union {
    // Sclera (white part of eye)
    sphere {
        <0, 0, 0>, 0.10
        scale <1, 1, 0.3>
        texture {
            pigment { White }
            finish { phong 1 }
        }
    }
    // Pupil
    sphere {
        <0, 0, 0>, 0.05
        texture {
            pigment { Black }
            finish { phong 0.1 }
        }
        translate <0, 0, -0.025>
    }
}

#local MonsterMouth = sphere {
    <0, 0, 0>, 0.50
    scale <1, 0.2, 2>
    rotate <0, 0, -30>
    translate <5, 2.85, 0>
    pigment { MonsterMouthColor }
}

#local MonsterBody = object {
    sphere_sweep {
        b_spline
        18,
        MonsterPoint01, 0.01,
        MonsterPoint02, 0.07,
        MonsterPoint03, 0.25,
        MonsterPoint04, 0.30,
        MonsterPoint05, 0.15,
        MonsterPoint06, 0.45,
        MonsterPoint07, 0.15,
        MonsterPoint08, 0.20,
        MonsterPoint09, 0.35,
        MonsterPoint10, 0.30,
        MonsterPoint11, 0.20,
        MonsterPoint12, 0.40,
        MonsterPoint13, 0.15,
        MonsterPoint14, 0.30,
        MonsterPoint15, 0.20,
        MonsterPoint16, 0.30,
        MonsterPoint17, 0.50,
        MonsterPoint18, 0.50
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
        translate <4.5, 3.10, -0.43>
    }
    object {
        MonsterEye
        translate <4.5, 3.10, -0.43>
        scale <1, 1, -1>
    }
}
