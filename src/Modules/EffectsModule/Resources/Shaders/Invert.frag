//#version 120

uniform sampler2DRect tex0;
uniform float amount;

void main()
{
    vec2 position = (gl_FragCoord.xy );
    
    vec4 color =  texture2DRect(tex0, position);
    
    color[0] = 1.0 - color[0];
    color[1] = 1.0 - color[1];
    color[2] = 1.0 - color[2];
    
    gl_FragColor = color;
}
