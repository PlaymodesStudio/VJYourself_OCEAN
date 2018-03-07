#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform float       u_min;
uniform float       u_max;
uniform float       u_smooth;

//uniform float       uni_h1;
//uniform float       uni_h2;
//uniform float       uni_smoothing;

// Out
out vec4            out_Color;

void    main()
{

    
    vec4    texColor = texture(tex0, out_texCoord);
    texColor.g = 0.0;
    texColor.b = 0.0;
    
    out_Color = texColor;
    
    
}
