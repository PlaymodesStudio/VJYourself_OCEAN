#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform float       u_min;
uniform float       u_max;
uniform float       u_gamma;

// Out
out vec4            out_Color;

void    main()
{
    vec3 invGammaV = vec3(1.0/u_gamma,1.0/u_gamma,1.0/u_gamma);

    vec4 texColor = texture(tex0, out_texCoord);
    
    vec3 resultC = texColor.rgb;
    vec3 resultA = max(resultC - vec3(u_min),vec3(0.0)) / (vec3(u_max)-vec3(u_min));
    vec3 result = min(resultA,vec3(1.0));
    vec3 resGamma = pow(result,invGammaV);
    

    out_Color = vec4(1.0*resGamma,1.0);

    
}
