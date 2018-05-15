#version 410

// In
//in highp vec3 in_Vertex;
//in highp vec2 in_TexCoord;

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewProjectionMatrix;
//
in vec4 position;
in vec2 texcoord;

// Uni
//uniform highp mat4    uni_Matrix;

// this is something we're creating for this shader
out vec2 out_texCoord;


void    main()
{
    out_texCoord = texcoord;
    //    gl_Position = uni_Matrix * vec4(in_Vertex, 1.0f);
    gl_Position = modelViewProjectionMatrix * position;
}
