#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform sampler2D   tex1;
uniform float       u_crossfade;
uniform int         u_mixMode;
uniform float       u_isChannel2;

// Out
out vec4            out_Color;

void    main()
{
    vec4    texColor = texture(tex0, out_texCoord);
    vec4    texColor2 = texture(tex1, out_texCoord);
    
    if(u_isChannel2!=1.0) texColor2 = vec4(0.0,0.0,0.0,1.0);
    
    if(u_mixMode==0)
    {
        float op1 = u_crossfade;
        float op2 = 1.0 - u_crossfade;
        out_Color = (texColor*op1) + (texColor2*op2);
    }
    else if(u_mixMode==1)
    {
        float op1 = (u_crossfade *2);
        if(op1>1.0) op1 = 1.0;
        float op2 = ((1.0 - u_crossfade) * 2);
        if(op2>1.0) op2 = 1.0;
        
        out_Color = max ((texColor*op1),(texColor2*op2));
    }
    else if(u_mixMode==2)
    {
        float op1 = (u_crossfade *2);
        if(op1>1.0) op1 = 1.0;
        float op2 = ((1.0 - u_crossfade) * 2);
        if(op2>1.0) op2 = 1.0;
        
        out_Color = ((texColor*op1) + (texColor2*op2));
    }
    
    
}

