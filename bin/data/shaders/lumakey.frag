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
//    vec4    lColor = vec4(1.0f,1.0f,1.0f,1.0f);
//    float   luminance = vec3(0.2126f, 0.7152f, 0.0722f) * lColor.rgb;
//    float   lMinSmooth = uni_h1 - uni_smoothing;
//    float   lMaxSmooth = uni_h2 + uni_smoothing;
//
//    if (luminance > uni_h1 && luminance < uni_h2)
//        lColor = vec4(0.0f);
//    else if (luminance > lMinSmooth && luminance < uni_h1)
//        lColor[3] = smoothstep(uni_h1, lMinSmooth, luminance); // fix alpha
//    else if (luminance > uni_h2 && luminance < lMaxSmooth)
//        lColor[3] = smoothstep(uni_h2, lMaxSmooth, luminance); // fix alpha
//    out_Color = lColor * vec4(lColor.aaa, 1.0f);
    
    vec4    texColor = texture(tex0, out_texCoord);
    float   luminance = (0.2126 * texColor.r) + (0.7152 * texColor.g) + (0.0722 * texColor.b);
    
    float lMinSmooth = u_min - u_smooth;
    float lMaxSmooth = u_max + u_smooth;

// ORIGINAL CODE
//    if (luminance > u_min && luminance < u_max)
//        texColor = vec4(0.0f);
//    else if (luminance > lMinSmooth && luminance < u_min)
//        texColor[3] = smoothstep(u_min, lMinSmooth, luminance); // fix alpha
//    else if (luminance > u_max && luminance < lMaxSmooth)
//        texColor[3] = smoothstep(u_max, lMaxSmooth, luminance); // fix alpha
    
// ELOI HACK ... JUST 1 PARAMETER
//    if (luminance < u_max)
//        texColor = vec4(0.0f,0.0f,0.0f,1.0f);
    //else
        texColor[3] = smoothstep(u_max, lMaxSmooth, luminance); // fix alpha
    
    out_Color = texColor * vec4(texColor.aaa, 1.0f);

//    out_Color = vec4(1.0f,0.0f,0.0f,1.0f);
//    out_Color = texture(tex0, out_texCoord);
//    out_Color = vec4(luminance,luminance,luminance,1.0f);
    
}
