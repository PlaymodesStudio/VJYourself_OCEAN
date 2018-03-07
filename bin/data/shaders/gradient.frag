#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform float       u_width;
uniform int        u_xory;

//uniform float       uni_h1;
//uniform float       uni_h2;
//uniform float       uni_smoothing;

// Out
out vec4            out_Color;

void    main()
{
    vec4    texColor = texture(tex0, out_texCoord);
    
    if(u_xory==0)
    {
        float gradientValue1 = smoothstep(0.0,u_width, out_texCoord.x) ;
        float gradientValue2 = 1.0 - (smoothstep(1.0-u_width,1.0, out_texCoord.x));
        out_Color = texColor * gradientValue2 * gradientValue1 * gradientValue2 * gradientValue1;
    }
    else
    {
        float gradientValue1 = smoothstep(0.0,u_width, out_texCoord.y) ;
        float gradientValue2 = 1.0 - (smoothstep(1.0-u_width,1.0, out_texCoord.y));
        out_Color = texColor * gradientValue2 * gradientValue1 * gradientValue2 * gradientValue1;
        
    }
}
