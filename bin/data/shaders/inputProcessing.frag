#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform float       u_width;
uniform int        u_xory;
uniform float       u_min;
uniform float       u_max;
uniform float       u_smooth;
uniform float       u_LevMin;
uniform float       u_LevMax;
uniform float       u_LevGamma;


// Out
out vec4            out_Color;

void    main()
{
    vec4    gradientColor;
    vec4    levelsColor;
    vec4    texColor = texture(tex0, out_texCoord);
    
    // gradient
    if(u_xory==0)
    {
        float gradientValue1 = smoothstep(0.0,u_width, out_texCoord.x) ;
        float gradientValue2 = 1.0 - (smoothstep(1.0-u_width,1.0, out_texCoord.x));
        gradientColor = texColor * gradientValue2 * gradientValue1 ; //* gradientValue2 * gradientValue1;
    }
    else
    {
        float gradientValue1 = smoothstep(0.0,u_width, out_texCoord.y) ;
        float gradientValue2 = 1.0 - (smoothstep(1.0-u_width,1.0, out_texCoord.y));
        gradientColor = texColor * gradientValue2 * gradientValue1 ; //* gradientValue2 * gradientValue1;
    }
    
    // levels
    
    vec3 invGammaV = vec3(1.0/u_LevGamma,1.0/u_LevGamma,1.0/u_LevGamma);
    
    vec3 resultC = gradientColor.rgb;
    vec3 resultA = max(resultC - vec3(u_LevMin),vec3(0.0)) / (vec3(u_LevMax)-vec3(u_LevMin));
    vec3 result = min(resultA,vec3(1.0));
    vec3 resGamma = pow(result,invGammaV);
    levelsColor = vec4(resGamma,1.0);

    // luma
    float  luminance = (0.2126 * levelsColor.r) + (0.7152 * levelsColor.g) + (0.0722 * levelsColor.b);

    float lMinSmooth = u_min - u_smooth;
    float lMaxSmooth = u_max + u_smooth;

    levelsColor[3] = smoothstep(u_max, lMaxSmooth, luminance); // fix alpha

    levelsColor = levelsColor * vec4(texColor.aaa, 1.0f);
    
    out_Color = levelsColor;

    
}
