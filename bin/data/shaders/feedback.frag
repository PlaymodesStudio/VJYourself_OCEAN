#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform sampler2D   tex1;
uniform float       u_scale;
uniform float       u_mixAmmount;
uniform vec2        u_resolution;
uniform float       u_dryWet;
uniform float       u_originX;
uniform float       u_originY;

//uniform float       uni_h1;
//uniform float       uni_h2;
//uniform float       uni_smoothing;

// Out
out vec4            out_Color;

void    main()
{
    vec2 uvOk = gl_FragCoord.xy / u_resolution;
    vec2 uv = uvOk;
    
    uv[0] = uv[0] - u_originX;
    uv[1] = uv[1] - u_originY;
    uv *= u_scale;
    uv[0] = uv[0] + u_originX;
    uv[1] = uv[1] + u_originY;

    
    vec4 cam = texture(tex0, uvOk);
    vec4 buf = texture(tex1, uv);
    
//    cam[1] = 0;
//    cam[2] = 0;
    
    out_Color.rgb = cam.rgb * u_mixAmmount +  buf.rgb * (1.0-u_mixAmmount);
    out_Color[3] = 1.0;
    
}
