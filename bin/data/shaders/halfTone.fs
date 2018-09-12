

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




float colorSteps = 8.;
float scale = 0.25;
float timeFactor = 0.03;
float blur = 1.;

float rgbToGray(vec4 rgba) {
    const vec3 W = vec3(0.2125, 0.7154, 0.0721);
    return dot(rgba.xyz, W);
}

vec2 rotateCoord(vec2 uv, float rads) {
    uv *= mat2(cos(rads), sin(rads), -sin(rads), cos(rads));
    return uv;
}

float halftoneDots(vec2 uv, float rows, float curRadius, float curRotation, float invert) {
    // update layout params
    // get original coordinate, translate & rotate
    uv = rotateCoord(uv, curRotation);
    // calc row index to offset x of every other row
    float rowIndex = floor(uv.y * rows);
    float oddEven = mod(rowIndex, 2.);
    // create grid coords
    vec2 uvRepeat = fract(uv * rows) - 0.5;
    if(oddEven == 1.) {                            // offset x by half
        uvRepeat = fract(vec2(0.5, 0.) + uv * rows) - vec2(0.5, 0.5);
    }
    // adaptive antialiasing, draw, invert
    float aa = iResolution.y * rows * 0.00001;
    float col = smoothstep(curRadius - aa, curRadius + aa, length(uvRepeat));
    if(invert == 1.) col = 1. - col;
    return col;
}

float halftoneLines(vec2 uv, float rows, float curThickness, float curRotation, float invert) {
    // get original coordinate, translate & rotate
    uv = rotateCoord(uv, curRotation);
    // create grid coords
    vec2 uvRepeat = fract(uv * rows);
    // adaptive antialiasing, draw, invert
    float aa = iResolution.y * 0.0003;
    float col = smoothstep(curThickness - aa, curThickness + aa, length(uvRepeat.y - 0.5));
    if(invert == 1.) col = 1. - col;
    return col;
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // coords
    vec2 uvDraw = (2. * fragCoord - iResolution.xy) / iResolution.y;
    vec2 uv = fragCoord.xy / iResolution.xy;
    uv.x = 1. - uv.x; // mirror
    
    // get texture color
    vec4 color = texture(iChannel0, uv);
    
    if(blur == 1.) {
        // get samples around pixel for averaged color
        float stepH = 1.;
        float stepV = 1.;
        vec4 colors[9];
        float stepX = stepH/iResolution.x;
        float stepY = stepV/iResolution.y;
        colors[0] = texture(iChannel0, uv + vec2(-stepX, stepY));
        colors[1] = texture(iChannel0, uv + vec2(0, stepY));
        colors[2] = texture(iChannel0, uv + vec2(stepX, stepY));
        colors[3] = texture(iChannel0, uv + vec2(-stepX, 0));
        colors[4] = texture(iChannel0, uv);
        colors[5] = texture(iChannel0, uv + vec2(stepX, 0));
        colors[6] = texture(iChannel0, uv + vec2(-stepX, -stepY));
        colors[7] = texture(iChannel0, uv + vec2(0, -stepY));
        colors[8] = texture(iChannel0, uv + vec2(stepX, -stepY));
        
        // apply color steps to original color
        color = vec4(0.);
        for(int i=0; i < 9; i++) {
            color += colors[i];
        }
        color = vec4((color.rgb / 9.), 1.);
    }
    
    // color = vec4(vec3(1. - uv.x), 1.); // test gradient
    float luma = rgbToGray(color) * 1.;
    float lumaIndex = floor(luma * colorSteps);
    float lumaFloor = lumaIndex / colorSteps;
    
    // time
    float time = iTime * timeFactor;
    
    // posterize -> halftone gradient configurations
    float halftoneCol = 0.;
    if(lumaIndex == 0.) {
        halftoneCol = halftoneDots(uvDraw, scale * 50., 0.1, 0.2 + time, 1.);
    } else if(lumaIndex == 1.) {
        halftoneCol = halftoneLines(uvDraw, scale * 84., 0.08, 2. - time, 1.);
    } else if(lumaIndex == 2.) {
        halftoneCol = halftoneDots(uvDraw, scale * 120., 0.45, 0.8 + time, 0.);
    } else if(lumaIndex == 3.) {
        halftoneCol = halftoneDots(uvDraw, scale * 60., 0.37, 0.5 - time, 1.);
    } else if(lumaIndex == 4.) {
        halftoneCol = halftoneLines(uvDraw, scale * 40., 0.18, 2. + time, 0.);
    } else if(lumaIndex == 5.) {
        halftoneCol = halftoneDots(uvDraw, scale * 60., 0.34, 0.5 - time, 0.);
    } else if(lumaIndex == 6.) {
        halftoneCol = halftoneLines(uvDraw, scale * 84., 0.15, 2. + time, 0.);
    } else if(lumaIndex >= 7.) {
        halftoneCol = halftoneDots(uvDraw, scale * 50., 0.1, 0.2 - time, 0.);
    }
    fragColor = vec4(vec3(halftoneCol),1.0);
}


