#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;
uniform sampler2D   tex1;
uniform sampler2D   tex2;
uniform float       u_scale;
uniform float       u_mixAmmount;
uniform vec2        u_resolution;
uniform float       u_dryWet;
//uniform float       uni_h1;
//uniform float       uni_h2;
//uniform float       uni_smoothing;

// Out
out vec4            out_Color;

void    main()
{
    vec2 uvOk = gl_FragCoord.xy / u_resolution;
    vec2 uv = uvOk;
    
    uv[0] = uv[0] - 0.5;
    uv[1] = uv[1] - 0.5;
    uv *= u_scale;
    uv[0] = uv[0] + 0.5;
    uv[1] = uv[1] + 0.5;
    
    vec4 cam = texture(tex0, uvOk);
    vec4 buf = texture(tex1, uv);
    vec4 realT = texture(tex2,uvOk);
    
//    cam[1] = 0;
//    cam[2] = 0;
    
    out_Color.rgb = cam.rgb * u_mixAmmount +  buf.rgb * (1.0-u_mixAmmount);
    out_Color.rgb = (out_Color.rgb*u_dryWet) + ((1.0-u_dryWet)*realT.rgb);
    out_Color[3] = 1.0;
    
}
