#version 410

// In
smooth in vec2      out_texCoord;

// Uni
uniform sampler2D   tex0;

uniform float       u_red;
uniform float       u_green;
uniform float       u_blue;

// Out
out vec4            out_Color;

void    main()
{
    vec4    texColor = texture(tex0, out_texCoord);
    out_Color = vec4(texColor[0] * u_red, texColor[1]*u_green, texColor[2]*u_blue, 1.0f);
}
