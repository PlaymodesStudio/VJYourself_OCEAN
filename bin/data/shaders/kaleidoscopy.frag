









#version 410
const float tau = 6.28318530718;
precision highp float;

// In
smooth in vec2      out_texCoord;


// Uni
uniform sampler2D   tex0;
uniform float       sides; // 1 to 32 ?
uniform float       angle; // -1 to 1
uniform float       rotation;
uniform float       slidex; // 0 to 1
uniform float       slidey; // 0 to 1

// Out
out vec4            out_Color;

void    main()
{
    // normalize to the center
    vec2 center = vec2(0.5);
    vec2 loc = out_texCoord;
    float r = distance(vec2(0.5), loc);
    float a = atan((loc.y-center.y),(loc.x-center.x));
    a += angle*2*3.1416;
    float modRotation = rotation - angle;
    
    // kaleidoscope
    a = mod(a, tau/sides);
    a = abs(a - tau/sides/2.);
    
    loc.x = r * cos(a + tau * modRotation);
    loc.y = r * sin(a + tau * modRotation);
    
    loc = (center + loc);
    
    loc.x = mod(loc.x + slidex, 1.0);
    loc.y = mod(loc.y + slidey, 1.0);
    
    out_Color = texture(tex0, loc);
    
    
}
